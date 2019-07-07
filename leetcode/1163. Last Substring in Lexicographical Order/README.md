# [1163. Last Substring in Lexicographical Order (Hard)](https://leetcode.com/problems/last-substring-in-lexicographical-order/)

<p>Given a string <code>s</code>, return the last substring of <code>s</code> in lexicographical order.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">"abab"</span>
<strong>Output: </strong><span id="example-output-1">"bab"</span>
<strong>Explanation: </strong>The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">"leetcode"</span>
<strong>Output: </strong><span id="example-output-2">"tcode"</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><font face="monospace">s</font> contains only lowercase English letters.</li>
</ol>


**Companies**:  
[Mathworks](https://leetcode.com/company/mathworks)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1. Brute Force

First, find the greatest character, with which the answer must start.

Push all the indexes of that character into a candidate vector, which are all the possible solutions.

Note that considering the case `"a............a"`, we only push if the character before the current index is not also the greatest character. This is because in that case, the previous index must yield better result than the current index (For example, for `"ddab"` and `"dab"`, we don't need to consider `"dab"`).

Now we have all the possible start indexes, we continue to look at the 2nd, 3rd, ... characters after the start indexes.

* If this start index can't afford `len` characters after it but others can, it should be ignored.
* For each start indexes `n`, we look at the `s[n + len]`, and find the greatest character. We only keep the start indexes that has the greatest character we just found at `s[n + len]`.

As we extending the `len`, the size of the available start indexes gets smaller and smaller until it becomes 1. The last start index left is the start index of the answer.

```cpp
// OJ: https://leetcode.com/problems/last-substring-in-lexicographical-order/
// Author: github.com/lzl124631x
// Time: O(VL) where V is the length of `v` and L is the max possible `len`.
//       It is strictly smaller than O(N^2)
// Space: O(N)
class Solution {
public:
    string lastSubstring(string s) {
        int start = 0, N = s.size();
        for (int i = 0; i < N; ++i) {
            if (s[i] > s[start]) start = i;
        }
        vector<int> v;
        for (int i = start; i < N; ++i) {
            if (s[i] == s[start] && (i == 0 || s[i - 1] != s[start])) v.push_back(i);
        }
        for (int len = 1; len <= N && v.size() > 1; ++len) {
            vector<int> next;
            char c = 'a';
            for (int n : v) {
                if (n + len >= N || s[n + len] < c) continue;
                if (s[n + len] > c) {
                    next.clear();
                    c = s[n + len];
                }
                next.push_back(n);
            }
            v = next;
        }
        return s.substr(v[0]);
    }
};
```

## Solution 2. Brute Force

For a substring `A` and all its prefix substrings, `A` must be the one lexicographically largest. So we don't need to consider the prefix substrings of `A`.

So for this question, we only need to consider the `N` suffix substrings of `s`.

We just brute-forcely compare all the suffix strings.

One optimization we do for the `"a.....a"` case is `if (i + j == N) break`. My reasoning is as follows.

When `i + j == N`, the string `i` is of pattern `ABA`, where `j` is the start index of the second string segment `A`.

Example
```
 i           j
[ddac](abac)[ddac]
```

Note that string `A` and `B` won't have any character greater than `s[i]` because otherwise `i` will be moved to that greater character first.

Since we've already moved to `s[j]`, it means there is no better solution between `i+1` and `j - 1`. So we only need to think about the indexes after `j`. For each `k` in `[j + 1, N)`, we can find a counterpart `t` in `[i + 1, i + N - j)`, and string `t` must be better than string `k` since they have the same prefix and string `t` is longer. And because string `t` is no better than string `i`, so we can ignore all indexes after `j`.

Note that this optimization can't pass test case `"a....ab"` though.

```cpp
// OJ: https://leetcode.com/problems/last-substring-in-lexicographical-order/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
// Ref: https://leetcode.com/problems/last-substring-in-lexicographical-order/discuss/360957/C%2B%2B-Brute-Force
class Solution {
public:
    string lastSubstring(string s) {
        int start = 0, N = s.size(), j;
        for (int i = 1; i < N; ++i) {
            for (j = 0; i + j < N; ++j) {
                if (s[start + j] == s[i + j]) continue;
                start = s[start + j] > s[i + j] ? start : i;
                break;
            }
            if (i + j == N) break;
        }
        return s.substr(start);
    }
};
```

## Solution 3. Brute Force

Same idea as Solution 2 but with different optimization.

We skip the start index `i` if both `s[i]` and `s[i - 1]` are the same as `s[start]` where `start` is the best start index currently found.

It's because in that case string `i - 1` must be lexicographically larger than string `i`.

This solution can pass the test case `"a....ab"`.

```cpp
// OJ: https://leetcode.com/problems/last-substring-in-lexicographical-order/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    string lastSubstring(string s) {
        int start = 0, N = s.size();
        for (int i = 1; i < N; ++i) {
            if (s[i] == s[start] && s[i - 1] == s[start]) continue;
            for (int j = 0; i + j < N; ++j) {
                if (s[start + j] == s[i + j]) continue;
                start = s[start + j] > s[i + j] ? start : i;
                break;
            }
        }
        return s.substr(start);
    }
};
```