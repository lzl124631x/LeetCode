# [583. Delete Operation for Two Strings (Medium)](https://leetcode.com/problems/delete-operation-for-two-strings)

Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

**Example 1:**
```
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
```

**Note:**
1. The length of given words won't exceed 500.
2. Characters in given words can only be lower-case letters.

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
dp[i+1][j+1] = dp[i][j]                         if s[i] == t[j]
         = 1 + min(dp[i+1][j], dp[i][j+1])      if s[i] != t[j]
dp[i+1][0] = i+1
dp[0][j+1] = j+1
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
        for (int i = 0; i < M; ++i) dp[i + 1][0] = i + 1;
        for (int j = 0; j < N; ++j) dp[0][j + 1] = j + 1;
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
    int minDistance(string A, string B) {
        int M = A.size(), N = B.size();
        if (M < N) swap(M, N), swap(A, B);
        vector<int> dp(N + 1);
        for (int i = 0; i <= M; ++i) {
            int prev = 0;
            for (int j = 0; j <= N; ++j) {
                int cur = dp[j];
                if (i == 0 || j == 0) dp[j] = i + j;
                else if (A[i - 1] == B[j - 1]) dp[j] = prev;
                else dp[j] = 1 + min(dp[j], dp[j - 1]);
                prev = cur;
            }
        }
        return dp[N];
    }
};
```