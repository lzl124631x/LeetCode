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
  int minDistance(string word1, string word2) {
    int M = word1.size(), N = word2.size();
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (word1[i] == word2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
        else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
    return M + N - 2 * dp[M][N];
  }
};
```
