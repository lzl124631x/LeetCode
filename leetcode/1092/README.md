# [1092. Shortest Common Supersequence  (Hard)](https://leetcode.com/problems/shortest-common-supersequence/)

<p>Given two strings <code>str1</code> and <code>str2</code>,&nbsp;return the shortest string that has both <code>str1</code>&nbsp;and <code>str2</code>&nbsp;as subsequences.&nbsp;&nbsp;If multiple answers exist, you may return any of them.</p>

<p><em>(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen <u>anywhere</u> from T) results in the string S.)</em></p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>str1 = <span id="example-input-1-1">"abac"</span>, str2 = <span id="example-input-1-2">"cab"</span>
<strong>Output: </strong><span id="example-output-1">"cabac"</span>
<strong>Explanation: </strong>
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= str1.length, str2.length &lt;= 1000</code></li>
	<li><code>str1</code> and <code>str2</code> consist of lowercase English letters.</li>
</ol>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Longest Common Subsequence (Medium)](https://leetcode.com/problems/longest-common-subsequence/)

## Solution 1. DP

Let `dp[i][j]` be the length of the shortest common supersequence of `s[0..(i-1)]` and `t[0..(j-1)]`.

```
dp[i][j] = 1 + dp[i-1][j-1]                   if s[i-1] == t[j-1]
           1 + min(dp[i-1][j], dp[i][j-1])    if s[i-1] != t[j-1]
dp[0][i] = dp[i][0] = i
```

`dp[M][N]` is the length of the shortest common supersequence of `s` and `t`.

With this `dp` array, we can construct the shortest common supersequence.

```cpp
// OJ: https://leetcode.com/problems/shortest-common-supersequence/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 1; i <= N; ++i) dp[0][i] = i;
        for (int i = 1; i <= M; ++i) dp[i][0] = i;
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        string ans(dp[M][N], ' ');
        for (int i = M, j = N, k = ans.size() - 1; k >= 0; --k) {
            if (i && j && s[i - 1] == t[j - 1]) ans[k] = s[--i], --j;
            else if (i && dp[i][j] == dp[i - 1][j] + 1) ans[k] = s[--i];
            else ans[k] = t[--j];
        }
        return ans;
    }
};
```

## Solution 2. LCS

Let `dp[i][j]` be the length of longest common subsequence of `s[0..(i-1)]` and `t[0..(j-1)]`.

```
dp[i][j] = 1 + dp[i-1][j-1]                   if s[i-1] == t[j-1]
           max(dp[i-1][j], dp[i][j-1])        if s[i-1] != t[j-1]
dp[0][i] = dp[i][0] = 0 
```

`dp[M][N]` is the length of the LCS of `s` and `t`, and `M + N - dp[M][N]` is the length of the shortest common supersequence.

We can use `dp` array to construct the shortest common supersequence as well.

```cpp
// OJ: https://leetcode.com/problems/shortest-common-supersequence/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
// Ref: https://leetcode.com/problems/shortest-common-supersequence/discuss/312757/JavaPython-3-O(mn)-clean-DP-code-w-picture-comments-and-analysis.
class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        string ans(M + N - dp[M][N], ' ');
        for (int i = M, j = N, k = ans.size() - 1; k >= 0; --k) {
            if (i && j && s[i - 1] == t[j - 1]) ans[k] = s[--i], --j;
            else if (i && dp[i][j] == dp[i - 1][j]) ans[k] = s[--i];
            else ans[k] = t[--j];
        }
        return ans;
    }
};
```