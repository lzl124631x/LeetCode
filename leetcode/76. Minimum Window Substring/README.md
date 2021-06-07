# [76. Minimum Window Substring (Hard)](https://leetcode.com/problems/minimum-window-substring/)

<p>Given two strings <code>s</code> and <code>t</code> of lengths <code>m</code> and <code>n</code> respectively, return <em>the <strong>minimum window substring</strong> of </em><code>s</code><em> such that every character in </em><code>t</code><em> (<strong>including duplicates</strong>) is included in the window. If there is no such substring</em><em>, return the empty string </em><code>""</code><em>.</em></p>

<p>The testcases will be generated such that the answer is <strong>unique</strong>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within the string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "ADOBECODEBANC", t = "ABC"
<strong>Output:</strong> "BANC"
<strong>Explanation:</strong> The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "a", t = "a"
<strong>Output:</strong> "a"
<strong>Explanation:</strong> The entire string s is the minimum window.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "a", t = "aa"
<strong>Output:</strong> ""
<strong>Explanation:</strong> Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == s.length</code></li>
	<li><code>n == t.length</code></li>
	<li><code>1 &lt;= m, n&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> and <code>t</code> consist of uppercase and lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you find an algorithm that runs in <code>O(m + n)</code> time?

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple), [LinkedIn](https://leetcode.com/company/linkedin), [Uber](https://leetcode.com/company/uber), [Adobe](https://leetcode.com/company/adobe), [ByteDance](https://leetcode.com/company/bytedance), [VMware](https://leetcode.com/company/vmware), [Lyft](https://leetcode.com/company/lyft)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Substring with Concatenation of All Words (Hard)](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)
* [Minimum Size Subarray Sum (Medium)](https://leetcode.com/problems/minimum-size-subarray-sum/)
* [Sliding Window Maximum (Hard)](https://leetcode.com/problems/sliding-window-maximum/)
* [Permutation in String (Medium)](https://leetcode.com/problems/permutation-in-string/)
* [Smallest Range Covering Elements from K Lists (Hard)](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/)
* [Minimum Window Subsequence (Hard)](https://leetcode.com/problems/minimum-window-subsequence/)

## Solution 1. Minimum Sliding Window

```cpp
// OJ: https://leetcode.com/problems/minimum-window-substring/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(C) where C is the range of characters
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target, cur;
        for (char c : t) target[c]++;
        int S = s.size(), T = target.size(), cnt = 0, i = 0, begin = -1, minLen = INT_MAX;
        for (int j = 0; j < S; ++j) {
            ++cur[s[j]];
            if (target.count(s[j]) && target[s[j]] == cur[s[j]]) ++cnt;
            while (cnt == T) {
                if (target.count(s[i]) && cur[s[i]] == target[s[i]]) --cnt;
                --cur[s[i]];
                if (cnt < T && (begin == -1 || minLen > j - i + 1)) {
                    begin = i;
                    minLen = j - i + 1;
                } 
                ++i;
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
// Space: O(C) where C is the range of characters
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