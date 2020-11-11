# [1638. Count Substrings That Differ by One Character (Medium)](https://leetcode.com/problems/count-substrings-that-differ-by-one-character/)

<p>Given two strings <code>s</code> and <code>t</code>, find the number of ways you can choose a non-empty substring of <code>s</code> and replace a <strong>single character</strong> by a different character such that the resulting substring is a substring of <code>t</code>. In other words, find the number of substrings in <code>s</code> that differ from some substring in <code>t</code> by <strong>exactly</strong> one character.</p>

<p>For example, the underlined substrings in <code>"<u>compute</u>r"</code> and <code>"<u>computa</u>tion"</code> only differ by the <code>'e'</code>/<code>'a'</code>, so this is a valid way.</p>

<p>Return <em>the number of substrings that satisfy the condition above.</em></p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aba", t = "baba"
<strong>Output:</strong> 6
<strong>Explanation: </strong>The following are the pairs of substrings from s and t that differ by exactly 1 character:
("<u>a</u>ba", "<u>b</u>aba")
("<u>a</u>ba", "ba<u>b</u>a")
("ab<u>a</u>", "<u>b</u>aba")
("ab<u>a</u>", "ba<u>b</u>a")
("a<u>b</u>a", "b<u>a</u>ba")
("a<u>b</u>a", "bab<u>a</u>")
The underlined portions are the substrings that are chosen from s and t.
</pre>
​​<strong>Example 2:</strong>

<pre><strong>Input:</strong> s = "ab", t = "bb"
<strong>Output:</strong> 3
<strong>Explanation: </strong>The following are the pairs of substrings from s and t that differ by 1 character:
("<u>a</u>b", "<u>b</u>b")
("<u>a</u>b", "b<u>b</u>")
("<u>ab</u>", "<u>bb</u>")
​​​​The underlined portions are the substrings that are chosen from s and t.
</pre>
<strong>Example 3:</strong>

<pre><strong>Input:</strong> s = "a", t = "a"
<strong>Output:</strong> 0
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "abe", t = "bbc"
<strong>Output:</strong> 10
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 100</code></li>
	<li><code>s</code> and <code>t</code> consist of lowercase English letters only.</li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Trie](https://leetcode.com/tag/trie/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/)

## Solution 1.

Intuition: We can find each pair of `s[i] != t[j]`. Then try to extend both sides when `s[i + t] == t[j + t]`. If we have `left` steps extended on the left side and `right` steps on the right side, we have `(left + 1) * (right + 1)` options for this `{ i, j }` case.

Example:

```
s = xbabc
t = ybbbc
```

For `i = 2` and `j = 2`, we have `s[i] = a` and `t[j] = b` that doesn't match. Now look leftwards, we can extend left-side by 1 time due to `b`, and extend right-side by 2 times due to `bc`. So for this specific center `{ i = 2, j = 2 }`, we have `2 * 3 = 6` options.

```cpp
// OJ: https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
// Author: github.com/lzl124631x
// Time: O(MN * min(M, N))
// Space: O(1)
class Solution {
public:
    int countSubstrings(string s, string t) {
        int M = s.size(), N = t.size(), ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (s[i] == t[j]) continue;
                int left = 1, right = 1;
                while (i - left >= 0 && j - left >= 0 && s[i - left] == t[j - left]) ++left;
                while (i + right < M && j + right < N && s[i + right] == t[j + right]) ++right;
                ans += left * right;
            }
        }
        return ans;
    }
};
```

## Solution 2.

We can precompute the `left` and `right` values to save time.

```cpp
// OJ: https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int countSubstrings(string s, string t) {
        int M = s.size(), N = t.size(), ans = 0, left[101][101] = {}, right[101][101] = {};
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                left[i + 1][j + 1] = s[i] == t[j] ? left[i][j] + 1 : 0;
            }
        }
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                right[i][j] = s[i] == t[j] ? right[i + 1][j + 1] + 1 : 0;
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (s[i] != t[j]) ans += (1 + left[i][j]) * (1 + right[i + 1][j + 1]);
            }
        }
        return ans;
    }
};
```

## Solution 3.

Consider the following `s` and `t` and we are using `x` and `y` as the differing characters.

```
s=ab[x]c
t=ab[y]c
```

When we start from `i = 0, j = 0`, and reaches `i = 2, j = 2`, since `s[i] != t[j]`, `pre` is updated as `cur = 3`, and `cur` is reset to `0`. We add `3` to the answer which covers

```
ab[x]
ab[y]

b[x]
b[y]

[x]
[y]
```

When we reach `i = 3, j = 3`, we add `pre = 3` to answer again, which covers

```
ab[x]c
ab[y]c

b[x]c
b[y]c

[x]c
[y]c
```

So the `pre` is the same as the `left` value in previous solutions. The `right` value is achieved through adding the `pre` value repetitively for repeating right-side characters.

The `i` and `j` of `helper` function are the starting indexes of our scanning. Note that `0, 0` should be only included once so `j` starts from `1` in the second loop.

```cpp
// OJ: https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/count-substrings-that-differ-by-one-character/discuss/917985/JavaC%2B%2BPython-Time-O(nm)-Space-O(1)
class Solution {
    int helper(string s, string t, int i, int j) {
        int ans = 0, pre = 0, cur = 0;
        for (int n = s.size(), m = t.size(); i < n && j < m; ++i, ++j) {
            cur++;
            if (s[i] != t[j]) pre = cur, cur = 0;
            ans += pre;
        }
        return ans;
    }
public:
    int countSubstrings(string s, string t) {
        int ans = 0 ;
        for (int i = 0; i < s.size(); ++i) ans += helper(s, t, i, 0);
        for (int j = 1; j < t.size(); ++j) ans += helper(s, t, 0, j);
        return ans;
    }
};
```