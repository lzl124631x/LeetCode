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
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [LinkedIn](https://leetcode.com/company/linkedin), [Google](https://leetcode.com/company/google), [Adobe](https://leetcode.com/company/adobe), [Uber](https://leetcode.com/company/uber), [Apple](https://leetcode.com/company/apple), [Snapchat](https://leetcode.com/company/snapchat), [VMware](https://leetcode.com/company/vmware), [Microsoft](https://leetcode.com/company/microsoft), [Flipkart](https://leetcode.com/company/flipkart), [ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

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
        unordered_map<char, int> target, cnt;
        int len = INT_MAX, i = 0, N = s.size(), matched = 0, begin = 0;
        for (char c : t) target[c]++;
        for (int j = 0; j < N; ++j) {
            if (++cnt[s[j]] <= target[s[j]]) ++matched;
            while (matched == t.size()) {
                if (j - i + 1 < len) {
                    len = j - i + 1;
                    begin = i;
                }
                if (--cnt[s[i]] < target[s[i]]) --matched;
                ++i;
            }
        }
        return len == INT_MAX ? "" : s.substr(begin, len);
    }
};
```

## Solution 2. Shrinkable Slinding Window

```cpp
// OJ: https://leetcode.com/problems/minimum-window-substring/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(C) where C is the range of characters
// Ref: https://discuss.leetcode.com/topic/30941/here-is-a-10-line-template-that-can-solve-most-substring-problems
class Solution {
public:
    string minWindow(string s, string t) {
        int cnt[128] = {};
        for (char c : t) cnt[c]++;
        int N = s.size(), i = 0, j = 0, start = -1, minLen = INT_MAX, matched = 0;
        while (j < N) {
            matched += --cnt[s[j++]] >= 0;
            while (matched == t.size()) {
                if (j - i < minLen) minLen = j - i, start = i;
                matched -= ++cnt[s[i++]] > 0;
            }
        }
        return start == -1 ? "" : s.substr(start, minLen);
    }
};
```