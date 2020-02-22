# [1358. Number of Substrings Containing All Three Characters (Medium)](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)

<p>Given a string <code>s</code>&nbsp;consisting only of characters <em>a</em>, <em>b</em> and <em>c</em>.</p>

<p>Return the number of substrings containing <b>at least</b>&nbsp;one occurrence of all these characters <em>a</em>, <em>b</em> and <em>c</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcabc"
<strong>Output:</strong> 10
<strong>Explanation:</strong> The substrings containing&nbsp;at least&nbsp;one occurrence of the characters&nbsp;<em>a</em>,&nbsp;<em>b</em>&nbsp;and&nbsp;<em>c are "</em>abc<em>", "</em>abca<em>", "</em>abcab<em>", "</em>abcabc<em>", "</em>bca<em>", "</em>bcab<em>", "</em>bcabc<em>", "</em>cab<em>", "</em>cabc<em>" </em>and<em> "</em>abc<em>" </em>(<strong>again</strong>)<em>. </em>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aaacb"
<strong>Output:</strong> 3
<strong>Explanation:</strong> The substrings containing&nbsp;at least&nbsp;one occurrence of the characters&nbsp;<em>a</em>,&nbsp;<em>b</em>&nbsp;and&nbsp;<em>c are "</em>aaacb<em>", "</em>aacb<em>" </em>and<em> "</em>acb<em>".</em><em> </em>
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "abc"
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 5 x 10^4</code></li>
	<li><code>s</code>&nbsp;only consists of&nbsp;<em>a</em>, <em>b</em> or <em>c&nbsp;</em>characters.</li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1. Sliding Window

```cpp
// OJ: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int cnt[3] = {0};
    bool valid() {
        for (int n : cnt) 
            if (!n) return false;
        return true;
    }
public:
    int numberOfSubstrings(string s) {
        int L = 0, R = 0, N = s.size(), ans = 0;
        while (R < N) { 
            if (!valid()) cnt[s[R++] - 'a']++;
            while (valid()) {
                ans += N - R + 1;
                cnt[s[L++] - 'a']--;
            }
        }
        return ans;
    }
};
```