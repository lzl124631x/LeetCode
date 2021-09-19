# [1143. Longest Common Subsequence (Medium)](https://leetcode.com/problems/longest-common-subsequence/)

<p>Given two strings <code>text1</code> and <code>text2</code>, return <em>the length of their longest <strong>common subsequence</strong>. </em>If there is no <strong>common subsequence</strong>, return <code>0</code>.</p>

<p>A <strong>subsequence</strong> of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.</p>

<ul>
	<li>For example, <code>"ace"</code> is a subsequence of <code>"abcde"</code>.</li>
</ul>

<p>A <strong>common subsequence</strong> of two strings is a subsequence that is common to both strings.</p>

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
	<li><code>1 &lt;= text1.length, text2.length &lt;= 1000</code></li>
	<li><code>text1</code> and <code>text2</code> consist of only lowercase English characters.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Karat](https://leetcode.com/company/karat), [Indeed](https://leetcode.com/company/indeed), [Adobe](https://leetcode.com/company/adobe), [VMware](https://leetcode.com/company/vmware)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Longest Palindromic Subsequence (Medium)](https://leetcode.com/problems/longest-palindromic-subsequence/)
* [Delete Operation for Two Strings (Medium)](https://leetcode.com/problems/delete-operation-for-two-strings/)
* [Shortest Common Supersequence  (Hard)](https://leetcode.com/problems/shortest-common-supersequence/)

## Solution 1. DP

Let `dp[i+1][j+1]` be the length of the longest common subsequence of `s[0..i]` and `t[0..j]`.

```
dp[i+1][j+1] = 1 + dp[i][j]                    // If s[i-1] == t[j-1]
             = max(dp[i+1][j], dp[i][j+1])     // If s[i-1] != t[j-1]
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

Since `dp[i+1][j+1]` is only dependent on `dp[i][j]`, `dp[i+1][j]` and `dp[i][j+1]`, we can reduce the space of `dp` array from `N * N` to `1 * N` with a temporary variable storing `dp[i][j]`.

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
        for (int i = 0; i < M; ++i) {
            int prev = 0;
            for (int j = 0; j < N; ++j) {
                int cur = dp[j + 1];
                if (s[i] == t[j]) dp[j + 1] = prev + 1;
                else dp[j + 1] = max(dp[j], dp[j + 1]);
                prev = cur; 
            }
        }
        return dp[N];
    }
};
```