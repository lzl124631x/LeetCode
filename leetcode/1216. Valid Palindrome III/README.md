# [1216. Valid Palindrome III (Hard)](https://leetcode.com/problems/valid-palindrome-iii/)

<p>Given a string <code>s</code> and an integer <code>k</code>, return <code>true</code> if <code>s</code> is a <code>k</code><strong>-palindrome</strong>.</p>

<p>A string is <code>k</code><strong>-palindrome</strong> if it can be transformed into a palindrome by removing at most <code>k</code> characters from it.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcdeca", k = 2
<strong>Output:</strong> true
<strong>Explanation:</strong> Remove 'b' and 'e' characters.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abbababa", k = 1
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Longest Common Subsequence (LCS)

```cpp
// OJ: https://leetcode.com/problems/valid-palindrome-iii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        string t(s.rbegin(), s.rend());
        int N = s.size();
        vector<int> dp(N + 1);
        for (int i = 0; i < N; ++i) {
            int prev = 0;
            for (int j = 0; j < N; ++j) {
                int cur = dp[j + 1];
                if (s[i] == t[j]) dp[j + 1] = 1 + prev;
                else dp[j + 1] = max(dp[j + 1], dp[j]);
                prev = cur;
            }
        }
        return dp[N] + k >= s.size();
    }
};
```