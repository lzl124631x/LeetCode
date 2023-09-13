# [221. Maximal Square (Medium)](https://leetcode.com/problems/maximal-square/)

<p>Given an <code>m x n</code> binary <code>matrix</code> filled with <code>0</code>'s and <code>1</code>'s, <em>find the largest square containing only</em> <code>1</code>'s <em>and return its area</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/max1grid.jpg" style="width: 400px; height: 319px;">
<pre><strong>Input:</strong> matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/max2grid.jpg" style="width: 165px; height: 165px;">
<pre><strong>Input:</strong> matrix = [["0","1"],["1","0"]]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> matrix = [["0"]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>matrix[i][j]</code> is <code>'0'</code> or <code>'1'</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Visa](https://leetcode.com/company/visa), [Microsoft](https://leetcode.com/company/microsoft), [IBM](https://leetcode.com/company/ibm), [Google](https://leetcode.com/company/google), [Twitter](https://leetcode.com/company/twitter), [Apple](https://leetcode.com/company/apple), [Booking.com](https://leetcode.com/company/bookingcom), [Indeed](https://leetcode.com/company/indeed)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Matrix](https://leetcode.com/tag/matrix/)

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
// Time: O(M * N^2)
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

## Solution 3. Bottom-up DP

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
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == '0') continue;
                dp[i + 1][j + 1] = 1 + min({ dp[i][j], dp[i + 1][j], dp[i][j + 1] });
                ans = max(ans, dp[i + 1][j + 1]);
            }
        }
        return ans * ans;
    }
};
```

## Solution 4. Bottom-up DP with Space Optimization

```
   dp[i][j]    dp[i][j + 1]

            \   |

dp[i+1][j] --  dp[i + 1][j + 1]
```

Given the dependency above, we can use a `2 * N` array to store the DP values.

```cpp
// OJ: https://leetcode.com/problems/maximal-square/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
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

Or via swapping arrays.

```cpp
// OJ: https://leetcode.com/problems/maximal-square/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<int> dp(N + 1), next;
        for (int i = 0; i < M; ++i) {
            next.assign(N + 1, 0);
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == '0') continue;
                next[j + 1] = 1 + min({ dp[j], dp[j + 1], next[j] });
                ans = max(ans, next[j + 1]);
            }
            swap(next, dp);
        }
        return ans * ans;
    }
};
```

Or: Use a `prev` variable to store the `dp[i][j]`, then we can further reduce the `dp` array to 1D array.

```cpp
// OJ: https://leetcode.com/problems/maximal-square/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<int> dp(N + 1, 0);
        for (int i = 0; i < M; ++i) {
            int prev = 0;
            for (int j = 0; j < N; ++j) {
                int cur = dp[j + 1];
                if (A[i][j] == '1') dp[j + 1] = 1 + min({ prev, dp[j], dp[j + 1] });
                else dp[j + 1] = 0;
                prev = cur;
                ans = max(ans, dp[j + 1]);
            }
        }
        return ans * ans;
    }
};
```