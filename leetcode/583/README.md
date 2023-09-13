# [583. Delete Operation for Two Strings (Medium)](https://leetcode.com/problems/delete-operation-for-two-strings/)

<p>Given two strings <code>word1</code> and <code>word2</code>, return <em>the minimum number of <strong>steps</strong> required to make</em> <code>word1</code> <em>and</em> <code>word2</code> <em>the same</em>.</p>

<p>In one <strong>step</strong>, you can delete exactly one character in either string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> word1 = "sea", word2 = "eat"
<strong>Output:</strong> 2
<strong>Explanation:</strong> You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> word1 = "leetcode", word2 = "etco"
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word1.length, word2.length &lt;= 500</code></li>
	<li><code>word1</code> and <code>word2</code> consist of only lowercase English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Edit Distance (Hard)](https://leetcode.com/problems/edit-distance/)
* [Minimum ASCII Delete Sum for Two Strings (Medium)](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)
* [Longest Common Subsequence (Medium)](https://leetcode.com/problems/longest-common-subsequence/)

## Solution 1. Longest Common Subsequence

A variation of LCS problem. The result should be `M + N - 2 * len(LCS)`.

```cpp
// OJ: https://leetcode.com/problems/delete-operation-for-two-strings
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minDistance(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (s[i] == t[j]) dp[i + 1][j + 1] = 1 + dp[i][j];
                else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return M + N - 2 * dp[M][N];
    }
};
```

## Solution 2. DP

Let `dp[i + 1][j + 1]` be the minimum number of steps required for `A[0..i]` and `B[0..j]`.

```
for 0 <= i < M, 0 <= j < N:
dp[i+1][j+1] = dp[i][j]                         if s[i] == t[j]
         = 1 + min(dp[i+1][j], dp[i][j+1])      if s[i] != t[j]
```

Trivial cases:

```
dp[i][0] = i  for 0 <= i <= M
dp[0][j] = j  for 0 <= j <= N
```

These trivial cases can be simplified to

```
dp[i][j] = i + j   if i == 0 || j == 0,  for 0 <= i <= M and 0 <= j <= N
```

```cpp
// OJ: https://leetcode.com/problems/delete-operation-for-two-strings/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minDistance(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i <= M; ++i) dp[i][0] = i;
        for (int j = 1; j <= N; ++j) dp[0][j] = j;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j];
                else dp[i + 1][j + 1] = 1 + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[M][N];
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/delete-operation-for-two-strings/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minDistance(string A, string B) {
        int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (i == 0 || j == 0) dp[i][j] = i + j;
                else if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[M][N];
    }
};
```

## Solution 3. DP with Space Optimization

Since `dp[i+1][j+1]` is only dependent on `dp[i][j]`, `dp[i+1][j]` and `dp[i][j+1]`, we can reduce the size of the `dp` array from `M * N` to `N`, with an additional variable saving `dp[i][j]`.

```cpp
// OJ: https://leetcode.com/problems/delete-operation-for-two-strings/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M,N))
class Solution {
public:
    int minDistance(string s, string t) {
        int M = s.size(), N = t.size();
        if (M < N) swap(M, N), swap(s, t);
        vector<int> dp(N + 1);
        for (int i = 0; i <= M; ++i) {
            int prev = 0;
            for (int j = 0; j <= N; ++j) {
                int cur = dp[j];
                if (i == 0 || j == 0) dp[j] = i + j;
                else if (s[i - 1] == t[j - 1]) dp[j] = prev;
                else dp[j] = 1 + min(dp[j], dp[j - 1]);
                prev = cur;
            }
        }
        return dp[N];
    }
};
```