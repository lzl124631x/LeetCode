# [813. Largest Sum of Averages (Medium)](https://leetcode.com/problems/largest-sum-of-averages/)

<p>We partition a row of numbers <code>A</code>&nbsp;into at most <code>K</code> adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?</p>

<p>Note that our partition must use every number in A, and that scores are not necessarily integers.</p>

<pre><strong>Example:</strong>
<strong>Input:</strong> 
A = [9,1,2,3,9]
K = 3
<strong>Output:</strong> 20
<strong>Explanation:</strong> 
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
</pre>

<p>&nbsp;</p>

<p><strong>Note: </strong></p>

<ul>
	<li><code>1 &lt;= A.length &lt;= 100</code>.</li>
	<li><code>1 &lt;= A[i] &lt;= 10000</code>.</li>
	<li><code>1 &lt;= K &lt;= A.length</code>.</li>
	<li>Answers within <code>10^-6</code> of the correct answer will be accepted as correct.</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Let `dp[k][i]` be the maximum score for the subproblem with `k` groups and `A[0..i]` subarray.

Let `avg[i][j]` be the average of numbers in subarray `A[i..j]`.

```
dp[1][i] = avg[0][i]
dp[k][i] = max(dp[k][i], dp[k-1][j] + avg[j][i] | k-1 <= j <= i)    where k >= 2
```

```cpp
// OJ: https://leetcode.com/problems/largest-sum-of-averages/
// Author: github.com/lzl124631x
// Time: O(N^2 * K)
// Space: O(NK + N^2)
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int N = A.size();
        vector<vector<double>> avg(N + 1, vector<double>(N + 1));
        for (int i = 0; i < N; ++i) {
            int sum = 0;
            for (int j = i; j < N; ++j) {
                sum += A[j];
                avg[i][j] = (double)sum / (j - i + 1);
            }
        }
        vector<vector<double>> dp(K + 1, vector<double>(N));
        for (int i = 0; i < N; ++i) dp[1][i] = avg[0][i];
        for (int k = 2; k <= K; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = k - 1; j <= i; ++j) {
                    dp[k][i] = max(dp[k][i], dp[k - 1][j - 1] + avg[j][i]);
                }
            }
        }
        return dp[K][N - 1];
    }
};
```

## Solution 2. DP

Count `avg` on the fly.

```cpp
// OJ: https://leetcode.com/problems/largest-sum-of-averages/
// Author: github.com/lzl124631x
// Time: O(N^2 * K)
// Space: O(NK)
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int N = A.size();
        vector<vector<double>> dp(K + 1, vector<double>(N));
        double sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            dp[1][i] = sum / (i + 1);
        }
        for (int k = 2; k <= K; ++k) {
            for (int i = k - 1; i < N; ++i) {
                double sum = 0;
                for (int j = i; j >= k - 1; --j) {
                    sum += A[j];
                    dp[k][i] = max(dp[k][i], dp[k - 1][j - 1] + sum / (i - j + 1));
                }
            }
        }
        return dp[K][N - 1];
    }
};
```

## Solution 3. DP + Space Optimization

Since `dp[k][i]` is only dependent on `dp[k-1][j-1]` and `j <= i`, we can reduce the `dp` array to 1D array.

```cpp
// OJ: https://leetcode.com/problems/largest-sum-of-averages/
// Author: github.com/lzl124631x
// Time: O(N^2 * K)
// Space: O(N)
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int N = A.size();
        vector<double> dp(N);
        double sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            dp[i] = sum / (i + 1);
        }
        for (int k = 2; k <= K; ++k) {
            for (int i = N - 1; i >= k - 1; --i) {
                double sum = 0;
                dp[i] = 0;
                for (int j = i; j >= k - 1; --j) {
                    sum += A[j];
                    dp[i] = max(dp[i], dp[j - 1] + sum / (i - j + 1));
                }
            }
        }
        return dp[N - 1];
    }
};
```