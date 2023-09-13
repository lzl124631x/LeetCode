# [1876. Substrings of Size Three with Distinct Characters (Easy)](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/)

<p>A string is <strong>good</strong> if there are no repeated characters.</p>

<p>Given a string <code>s</code>​​​​​, return <em>the number of <strong>good substrings</strong> of length <strong>three </strong>in </em><code>s</code>​​​​​​.</p>

<p>Note that if there are multiple occurrences of the same substring, every occurrence should be counted.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "xyzzaz"
<strong>Output:</strong> 1
<strong>Explanation:</strong> There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aababcabc"
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code>​​​​​​ consists of lowercase English letters.</li>
</ul>


**Companies**:  
[Quora](https://leetcode.com/company/quora)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i+ 2 < s.size(); ++i) {
            ans += s[i] != s[i+1] && s[i+1] != s[i+2] && s[i] != s[i+2];
        }
        return ans;
    }
};
```