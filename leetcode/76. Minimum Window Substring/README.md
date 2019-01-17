# [76. Minimum Window Substring (Hard)](https://leetcode.com/problems/minimum-window-substring/)

<p>Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).</p>

<p><strong>Example:</strong></p>

<pre><strong>Input: S</strong> = "ADOBECODEBANC", <strong>T</strong> = "ABC"
<strong>Output:</strong> "BANC"
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li>If there is no such window in S that covers all characters in T, return the empty string <code>""</code>.</li>
	<li>If there is such window, you are guaranteed that there will always be only one unique minimum window in S.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [LinkedIn](https://leetcode.com/company/linkedin), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple), [Uber](https://leetcode.com/company/uber), [Bloomberg](https://leetcode.com/company/bloomberg), [Airbnb](https://leetcode.com/company/airbnb), [Walmart Labs](https://leetcode.com/company/walmart-labs)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Substring with Concatenation of All Words (Hard)](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)
* [Minimum Size Subarray Sum (Medium)](https://leetcode.com/problems/minimum-size-subarray-sum/)
* [Sliding Window Maximum (Hard)](https://leetcode.com/problems/sliding-window-maximum/)
* [Permutation in String (Medium)](https://leetcode.com/problems/permutation-in-string/)
* [Smallest Range (Hard)](https://leetcode.com/problems/smallest-range/)
* [Minimum Window Subsequence (Hard)](https://leetcode.com/problems/minimum-window-subsequence/)

## Solution 1. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/minimum-window-substring/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string minWindow(string s, string t) {
        int cnt = 0, i = 0, j = 0, S = s.size(), T = t.size();
        int minLen = INT_MAX, begin = -1;
        unordered_map<char, int> m, seen;
        for (char c : t) m[c]++;
        while (j < S) {
            for (; j < S && cnt != T; ++j) {
                if (m.find(s[j]) == m.end()) continue;
                if (++seen[s[j]] <= m[s[j]]) ++cnt;
            }
            for (; cnt == T; ++i) {
                if (m.find(s[i]) == m.end()) continue;
                if (j - i < minLen) {
                    minLen = j - i;
                    begin = i;
                }
                if (--seen[s[i]] < m[s[i]]) --cnt;
            }
        }
        return begin == -1 ? "" : s.substr(begin, minLen);
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/minimum-window-substring/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/30941/here-is-a-10-line-template-that-can-solve-most-substring-problems
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for (char c : t) ++m[c];
        int begin = 0, end = 0, head = 0, cnt = t.size(), len = INT_MAX;
        while (end < s.size()) {
            if (m[s[end++]]-- > 0) --cnt;
            while (!cnt) {
                if (end - begin < len) len = end - (head = begin);
                if (m[s[begin++]]++ == 0) ++cnt;
            }
        }
        return len == INT_MAX ? "" : s.substr(head, len);
    }
};
```