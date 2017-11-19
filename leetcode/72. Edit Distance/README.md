# [72. Edit Distance (Hard)](https://leetcode.com/problems/edit-distance)

Given two words `word1` and `word2`, find the minimum number of steps required to convert `word1` to `word2`. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character  
b) Delete a character  
c) Replace a character

## Solution 1. DP

For simplicity, I use `A` denoting `word1`, `B` denoting `word2`.

Considering the typical "longest common sequence (LCS)" problem, we can use the same DP strategy for this problem, that is, branching based on the equality of `A[i]` and `B[j]`.

* If `A[i]` equals `B[j]`, `dp[i + 1][j + 1] = dp[i][j]`.
* If `A[i]` doesn't equal `B[j]`, there can be three cases:
	* `1 + dp[i][j]`, meaning `A[0..(i - 1)]` and `B[0..(j - 1)]` is the base sub-case (i.e. of the smallest edit distance), and we replace one character at the end of `A[0..i]` and `B[0..j]`.
	* `1 + dp[i + 1][j]`, meaning `A[0..i]` and `B[0..(j - 1)]` is the base sub-case, and we delete one character at end of `A[0..i]`.
	* `1 + dp[i][j + 1]`, meaning `A[0..(i - 1)]` and `B[0..j]` is the base sub-case, and we delete one character at end of `B[0..j]`.

```cpp
// OJ: https://leetcode.com/problems/edit-distance
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minDistance(string A, string B) {
        if (A.empty() || B.empty()) return max(A.size(), B.size());
        int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) dp[i + 1][0] = i + 1;
        for (int j = 0; j < N; ++j) dp[0][j + 1] = j + 1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i] == B[j]) dp[i + 1][j + 1] = dp[i][j];
                else dp[i + 1][j + 1] = 1 + min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j]));
            }
        }
        return dp[M][N];
    }
};
```