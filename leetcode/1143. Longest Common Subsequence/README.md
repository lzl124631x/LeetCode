# [1143. Longest Common Subsequence (Medium)](https://leetcode.com/problems/longest-common-subsequence/)

<p>Given two strings <code>text1</code> and <code>text2</code>, return the length of their longest common subsequence.</p>

<p>A <em>subsequence</em> of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not).&nbsp;A <em>common subsequence</em>&nbsp;of two strings is a subsequence that is common to both strings.</p>

<p>&nbsp;</p>

<p>If there is no common subsequence, return 0.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> text1 = "abcde", text2 = "ace" 
<strong>Output:</strong> 3  
<strong>Explanation:</strong> The longest common subsequence is "ace" and its length is 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> text1 = "abc", text2 = "abc"
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest common subsequence is "abc" and its length is 3.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> text1 = "abc", text2 = "def"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no such common subsequence, so the result is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text1.length &lt;= 1000</code></li>
	<li><code>1 &lt;= text2.length &lt;= 1000</code></li>
	<li>The input strings consist of lowercase English characters only.</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Longest Palindromic Subsequence (Medium)](https://leetcode.com/problems/longest-palindromic-subsequence/)
* [Delete Operation for Two Strings (Medium)](https://leetcode.com/problems/delete-operation-for-two-strings/)
* [Shortest Common Supersequence  (Hard)](https://leetcode.com/problems/shortest-common-supersequence/)

## Solution 1. DP

Let `dp[i][j]` be the length of the longest common subsequence of `s[0..(i-1)]` and `t[0..(j-1)]`.

```
dp[i][j] = 1 + dp[i-1][j-1]                If s[i-1] == t[j-1]
         = max(dp[i-1][j], dp[i][j-1])     If s[i-1] != t[j-1]
dp[i][0] = dp[0][i] = 0
```

```cpp
// OJ: https://leetcode.com/problems/longest-common-subsequence/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[M][N];
    }
};
```

## Solution 2. DP + Space Optimization

Since `dp[i][j]` is only dependent on `dp[i-1][j-1]`, `dp[i-1][j]` and `dp[i][j-1]`, we can reduce the space of `dp` array from `N * N` to `1 * N` with a temporary variable storing `dp[i-1][j-1]`.

```cpp
// OJ: https://leetcode.com/problems/longest-common-subsequence/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int M = s.size(), N = t.size();
        if (M < N) swap(M, N), swap(s, t);
        vector<int> dp(N + 1);
        for (int i = 1; i <= M; ++i) {
            int prev = 0;
            for (int j = 1; j <= N; ++j) {
                int cur = dp[j];
                if (s[i - 1] == t[j - 1]) dp[j] = 1 + prev;
                else dp[j] = max(dp[j], dp[j - 1]);
                prev = cur;
            }
        }
        return dp[N];
    }
};
```