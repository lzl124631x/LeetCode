# [1278. Palindrome Partitioning III (Hard)](https://leetcode.com/problems/palindrome-partitioning-iii/)

<p>You are given a string&nbsp;<code>s</code> containing lowercase letters and an integer <code>k</code>. You need to :</p>

<ul>
	<li>First, change some characters of <code>s</code>&nbsp;to other lowercase English letters.</li>
	<li>Then divide <code>s</code>&nbsp;into <code>k</code> non-empty disjoint substrings such that each substring is palindrome.</li>
</ul>

<p>Return the minimal number of characters that you need to change&nbsp;to divide the string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abc", k = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong>&nbsp;You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aabbc", k = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong>&nbsp;You can split the string into "aa", "bb" and "c", all of them are palindrome.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "leetcode", k = 8
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= s.length &lt;= 100</code>.</li>
	<li><code>s</code>&nbsp;only contains lowercase English letters.</li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Let `dp[k][i][j]` be the minimal number of changes needed for `s[i..j]` with `k` divides.

```
dp[1][i][i] = 0
dp[1][i][j] = dp[1][i + 1][j - 1]       If s[i] == s[j]
            = 1 + dp[1][i + 1][j - 1]   If s[i] != s[j]

dp[k][i][j] = min( dp[k-1][i][t] + dp[1][t+1][j] | i + k - 1 <= t < j )
```

```cpp
// OJ: https://leetcode.com/problems/palindrome-partitioning-iii/
// Author: github.com/lzl124631x
// Time: O(K * N^3)
// Space: O(K * N^3)
class Solution {
    typedef long long LL;
    inline void setMin(LL &a, LL b) { a = min(a, b); }
public:
    int palindromePartition(string s, int K) {
        int N = s.size();
        vector<vector<vector<LL>>> dp(K + 1, vector<vector<LL>>(N, vector<LL>(N, 1e9)));
        for (int i = 0; i < N; ++i) dp[1][i][i] = 0;
        for (int i = N - 2; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) {
                dp[1][i][j] = (s[i] != s[j]) + (i + 1 <= j - 1 ? dp[1][i + 1][j - 1] : 0);
            }
        }
        for (int k = 2; k <= K; ++k) {
            for (int i = N - 2; i >= 0; --i) {
                for (int j = i + k - 1; j < N; ++j) {
                    for (int t = i + k - 2; t < j; ++t) {
                        setMin(dp[k][i][j], dp[k - 1][i][t] + dp[1][t + 1][j]);
                    }
                }
            }
        }
        return dp[K][0][N - 1];
    }
};
```

## Solution 2. DP

In Solution 1, for the `k >= 2` cases, we don't need to iterate all `i, j` combinations.

Let `pal[i][j]` be the minimum changes needed to make `s[i..j]` palindrome.

Let `dp[k][i]` be the minimum changes needed for `s[0..i]` with `k` divides. 

```
pal[i][i] = 0
pal[i][j] = dp[1][i + 1][j - 1]       If s[i] == s[j]
          = 1 + dp[1][i + 1][j - 1]   If s[i] != s[j]

dp[1][i] = pal[0][i]
dp[k][i] = min( dp[k-1][j] + pal[j+1][i] | k-2 <= j < i )
```

```cpp
// OJ: https://leetcode.com/problems/palindrome-partitioning-iii/
// Author: github.com/lzl124631x
// Time: O(K * N^2)
// Space: O(K * N^2)
class Solution {
    typedef long long LL;
    inline void setMin(LL &a, LL b) { a = min(a, b); }
public:
    int palindromePartition(string s, int K) {
        int N = s.size();
        vector<vector<LL>> pal(N, vector<LL>(N));
        vector<vector<LL>> dp(K + 1, vector<LL>(N, 1e9));
        for (int i = N - 2; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) {
                pal[i][j] = (s[i] != s[j]) + pal[i + 1][j - 1];
            }
        }
        for (int i = 0; i < N; ++i) dp[1][i] = pal[0][i];
        for (int k = 2; k <= K; ++k) {
            for (int i = k - 1; i < N; ++i) {
                for (int j = k - 2; j < i; ++j) {
                    setMin(dp[k][i], dp[k - 1][j] + pal[j + 1][i]);
                }
            }
        }
        return dp[K][N - 1];
    }
};
```