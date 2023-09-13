# [1156. Swap For Longest Repeated Character Substring (Medium)](https://leetcode.com/problems/swap-for-longest-repeated-character-substring/)

<p>Given a string <code>text</code>, we are allowed to swap two of the characters in the string. Find the length of the longest substring with repeated characters.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> text = "ababa"
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa", which its length is 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> text = "aaabaaa"
<strong>Output:</strong> 6
<strong>Explanation:</strong> Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa", which its length is 6.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> text = "aaabbaaa"
<strong>Output:</strong> 4
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> text = "aaaaa"
<strong>Output:</strong> 5
<strong>Explanation:</strong> No need to swap, longest repeated character substring is "aaaaa", length is 5.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> text = "abcdef"
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 20000</code></li>
	<li><code>text</code> consist of lowercase English characters only.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/swap-for-longest-repeated-character-substring/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int cnt[26] = {};
    int maxRep(string &s, char c) {
        int ans = 0, prev = -1, mid = -1;
        for (int i = 0; i <= s.size(); ++i) {
            if (i < s.size() && s[i] == c) continue;
            int len = i - prev - 1;
            if (mid != -1 && len - 1 == cnt[c - 'a']) --len;
            ans = max(ans, len);
            prev = mid;
            mid = i;
        }
        return ans;
    }
public:
    int maxRepOpt1(string s) {
        int ans = 0;
        for (char c : s) cnt[c - 'a']++;
        for (char c = 'a'; c <= 'z'; ++c) {
            ans = max(ans, maxRep(s, c));
        }
        return ans;
    }
};
```