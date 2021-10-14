# [316. Remove Duplicate Letters (Medium)](https://leetcode.com/problems/remove-duplicate-letters/)

<p>Given a string <code>s</code>, remove duplicate letters so that every letter appears once and only once. You must make sure your result is <strong>the smallest in lexicographical order</strong> among all possible results.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "bcabc"
<strong>Output:</strong> "abc"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "cbacdcbc"
<strong>Output:</strong> "acdb"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Note:</strong> This question is the same as 1081: <a href="https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/" target="_blank">https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/</a></p>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/)

**Similar Questions**:
* [Smallest K-Length Subsequence With Occurrences of a Letter (Hard)](https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/)

## Solution 1. Greedy

The first idea shall be greedy, namely picking the smallest letter whenever possible.

However we can easily give some counter example, e.g. `za`. We can't pick `a` since if we pick it, we don't have any `z` left to pick.

So if the count of a letter drop to `0`, we have to pick the current smallest letter we've seen.

Assume the index of it is `i`, then we should continue our greedy search from `i + 1`. (consider `abcab`)

Consider the following input whose result is `"bcda"`.

```
2 2 1 1 0 0 0 0
c b c b d a b c
  ^ ^   ^ ^
```

The number above each letter is the count of the same letters to its right.

We traverse from left to right:
1. For `s[0]=c`, it's the smallest so far, so `best = 0`.
1. For `s[1]=b`, it's the smallest so far, so `best = 1`.
1. For `s[2]=c`, it's not the smallest, skip.
1. For `s[3]=b`, it's the same as `s[best]`, skip.
1. For `s[4]=d`, the count of `d` is `0` so we must stop our greedy search here and pick `best = 1, s[best] = b`.
1. Then we continue our greedy search from `best + 1 = 2`.

```cpp
// OJ: https://leetcode.com/problems/remove-duplicate-letters/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        unordered_map<char, int> cnt;
        for (char c : s) cnt[c]++;
        int best = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] < s[best]) best = i;
            if (--cnt[s[i]] == 0) break;
        }
        string t = s.substr(best + 1);
        t.erase(remove(t.begin(), t.end(), s[best]), t.end());
        return s[best] + removeDuplicateLetters(t);
    }
};
```

## Solution 2. Greedy

Same idea as Solution 1, use iterative method instead of recursive.

```cpp
// OJ: https://leetcode.com/problems/remove-duplicate-letters/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        vector<int> rightCnt(s.size(), 0);
        unordered_map<char, int> cnt;
        unordered_set<char> added;
        string ans;
        int N = s.size(), i = 0;
        for (int j = N - 1; j >= 0; --j) rightCnt[j] = cnt[s[j]]++;
        while (i < N) {
            int best = -1;
            for (; i < N; ++i) {
                if (added.find(s[i]) != added.end()) continue;
                if (best == -1 || s[i] < s[best]) best = i;
                if (!rightCnt[i]) break;
            }
            if (best == -1) best = i;
            if (best >= N) break;
            ans += s[best];
            added.insert(s[best]);
            i = best + 1;
        }
        return ans;
    }
};
```

## Solution 3. Stack + Greedy

```cpp
// OJ: https://leetcode.com/problems/remove-duplicate-letters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) because there are at most 26 letters stored
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[26] = {}, used[26] = {};
        for (char c : s) cnt[c - 'a']++;
        string ans;
        for (char c : s) {
            --cnt[c - 'a'];
            if (used[c - 'a']) continue; // once used, don't use it again.
            while (ans.size() && ans.back() > c && cnt[ans.back() - 'a']) { // If the stack top `x` is greater than the current letter, and there are more letters `x` available, we pop `x`
                used[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(c);
            used[c - 'a'] = 1;
        }
        return ans;
    }
};
```