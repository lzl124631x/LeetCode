# [221. Maximal Square (Medium)](https://leetcode.com/problems/maximal-square/submissions/)

<p>Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input: 
</strong>
1 0 1 0 0
1 0 <font color="red">1</font> <font color="red">1</font> 1
1 1 <font color="red">1</font> <font color="red">1</font> 1
1 0 0 1 0

<strong>Output: </strong>4
</pre>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Maximal Rectangle (Hard)](https://leetcode.com/problems/maximal-rectangle/)
* [Largest Plus Sign (Medium)](https://leetcode.com/problems/largest-plus-sign/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/maximal-square/
// Author: github.com/lzl124631x
// Time: O((MN)^2)
// Space: O(1)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int M = A.size(), N = A[0].size(), ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int k = 0;
                bool stop = false;
                for (; i + k < M && j + k < N; ++k) {
                    for (int t = 0; t < k + 1 && !stop; ++t) {
                        if (A[i + t][j + k] == '0') stop = true;
                    }
                    for (int t = 0; t < k + 1 && !stop; ++t) {
                        if (A[i + k][j + t] == '0') stop = true;
                    }
                    if (stop) break;
                }
                ans = max(ans, k);
            }
        }
        return ans * ans;
    }
};
```

## Solution 2. Use the 1D subproblem

This problem is trivial on 1D array.

Let `row[i][j]` be the length of consecutive 1s ending at `A[i][j]` in `i`th row.

Let `col[i][j]` be the length of consecutive 1s ending at `A[i][j]` in `j`th column.

With these two arrays, for each `matrix[i][j]`, the side length of the square whose bottom right corner is at `matrix[i][j]` is at most `min(row[i][j], col[i][j])`. Then we keep probing the `col[i][k]` where `k < j` to keep tighten the limit.

```cpp
// OJ: https://leetcode.com/problems/maximal-square/
// Author: github.com/lzl124631x
// Time: O(MN^2)
// Space: O(MN)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<vector<int>> row(M, vector<int>(N, 0)), col(M, vector<int>(N, 0));
        for (int i = 0; i < M; ++i) {
            int start = -1;
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == '0') start = j;
                row[i][j] = j - start;
            }
        }
        for (int j = 0; j < N; ++j) {
            int start = -1;
            for (int i = 0; i < M; ++i) {
                if (A[i][j] == '0') start = i;
                col[i][j] = i - start;
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int end = min(row[i][j], col[i][j]), k = 0;
                while (k < end) {
                    ++k;
                    if (j - k < 0) break;
                    end = min(end, col[i][j - k]);
                }
                ans = max(ans, k);
            }
        }
        return ans * ans;
    }
};
```

## Solution 3. DP

Let `dp[i + 1][j + 1]` be the side length of the maximal square whose bottom right corner is at `matrix[i][j]`. Then we have:

```
dp[i + 1][j + 1] = min(dp[i][j], dp[i][j + 1], dp[i + 1][j]) + 1
```

```cpp
// OJ: https://leetcode.com/problems/maximal-square/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == '0') continue;
                ans = max(ans, dp[i + 1][j + 1] = min({ dp[i][j], dp[i][j + 1], dp[i + 1][j] }) + 1);
            }
        }
        return ans * ans;
    }
};
```

## Solution 4. DP

```
   dp[i][j]    dp[i][j + 1]

            \   |

dp[i+1][j] --  dp[i + 1][j + 1]
```

Given the dependency above, we can use a `2 * N` array to store the DP values.

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<vector<int>> dp(2, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[(i + 1) % 2][j + 1] = A[i][j] == '0' ? 0 : min({ dp[i % 2][j], dp[i % 2][j + 1], dp[(i + 1) % 2][j] }) + 1;
                ans = max(ans, dp[(i + 1) % 2][j + 1]);
            }
        }
        return ans * ans;
    }
};
```

## Solution 5. DP

Use `prev` to store the `dp[i][j]`, then we can further reduce the `dp` array to 1D array.

```cpp
// OJ: https://leetcode.com/problems/maximal-square/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<int> dp(N + 1, 0);
        for (int i = 0; i < M; ++i) {
            int prev = 0;
            for (int j = 0; j < N; ++j) {
                int cur = dp[j + 1];
                if (A[i][j] == '1') dp[j + 1] = 1 + min({dp[j], dp[j + 1], prev});
                else dp[j + 1] = 0;
                prev = cur;
                ans = max(ans, dp[j + 1]);
            }
        }
        return ans * ans;
    }
};
```