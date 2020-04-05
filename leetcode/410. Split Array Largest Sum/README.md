# [410. Split Array Largest Sum (Hard)](https://leetcode.com/problems/split-array-largest-sum/)

<p>Given an array which consists of non-negative integers and an integer <i>m</i>, you can split the array into <i>m</i> non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these <i>m</i> subarrays.
</p>

<p><b>Note:</b><br>
If <i>n</i> is the length of array, assume the following constraints are satisfied:
</p><ul>
<li>1 ≤ <i>n</i> ≤ 1000</li>
<li>1 ≤ <i>m</i> ≤ min(50, <i>n</i>)</li>
</ul>
<p></p>

<p><b>Examples: </b>
</p><pre>Input:
<b>nums</b> = [7,2,5,10,8]
<b>m</b> = 2

Output:
18

Explanation:
There are four ways to split <b>nums</b> into two subarrays.
The best way is to split it into <b>[7,2,5]</b> and <b>[10,8]</b>,
where the largest sum among the two subarrays is only 18.
</pre>
<p></p>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Let `dp[m][i]` be the answer to the subproblem with `m` subarrays within `A[0..i]`.

Let `sum[i][j]` be the sum of numbers in `A[i..j]`.

```
dp[1][i] = sum[0][i]
dp[k][i] = min(max(dp[k-1][j-1], sum[j][i]) | m - 1 <= j <= i)
```

```cpp
// OJ: https://leetcode.com/problems/split-array-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N^2 * M)
// Space: O(N^2 + NM)
class Solution {
    typedef long long LL;
public:
    int splitArray(vector<int>& A, int M) {
        int N = A.size();
        vector<vector<LL>> sum(N, vector<LL>(N, 0)), dp(M + 1, vector<LL>(N, INT_MAX));
        for (int i = 0; i < N; ++i) {
            LL s = 0;
            for (int j = i; j < N; ++j) {
                sum[i][j] = (s += A[j]);
            }
        }
        for (int i = 0; i < N; ++i) dp[1][i] = sum[0][i];
        for (int m = 2; m <= M; ++m) {
            for (int i = m - 1; i < N; ++i) {
                for (int j = m - 1; j <= i; ++j) {
                    dp[m][i] = min(dp[m][i], max(dp[m - 1][j - 1], sum[j][i]));
                }
            }
        }
        return dp[M][N - 1];
    }
};
```

## Solution 2. DP

We can compute `sum` on the fly.

```cpp
// OJ: https://leetcode.com/problems/split-array-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N^2 * M)
// Space: O(NM)
class Solution {
    typedef long long LL;
public:
    int splitArray(vector<int>& A, int M) {
        int N = A.size();
        vector<vector<LL>> dp(M + 1, vector<LL>(N, INT_MAX));
        LL s = 0;
        for (int i = 0; i < N; ++i) dp[1][i] = (s += A[i]);
        for (int m = 2; m <= M; ++m) {
            for (int i = m - 1; i < N; ++i) {
                LL sum = 0;
                for (int j = i; j >= m - 1; --j) {
                    sum += A[j];
                    dp[m][i] = min(dp[m][i], max(dp[m - 1][j - 1], sum));
                }
            }
        }
        return dp[M][N - 1];
    }
};
```

## Solution 3. DP + Space Optimization

Given the `dp` dependency, we can just use 1D `dp` array.

```cpp
// OJ: https://leetcode.com/problems/split-array-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N^2 * M)
// Space: O(N)
class Solution {
    typedef long long LL;
public:
    int splitArray(vector<int>& A, int M) {
        int N = A.size();
        vector<LL> dp(N, INT_MAX);
        LL s = 0;
        for (int i = 0; i < N; ++i) dp[i] = (s += A[i]);
        for (int m = 2; m <= M; ++m) {
            for (int i = N - 1; i >= m - 1; --i) {
                LL sum = 0;
                dp[i] = INT_MAX;
                for (int j = i; j >= m - 1; --j) {
                    sum += A[j];
                    dp[i] = min(dp[i], max(dp[j - 1], sum));
                }
            }
        }
        return dp[N - 1];
    }
};
```

## Solution 4. Binary Answer

The answer is between the maximum element and the sum of all the elements.

```cpp
// OJ: https://leetcode.com/problems/split-array-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N * log(S)) where S is sum of nums.
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/61324/clear-explanation-8ms-binary-search-java
class Solution {
    typedef long long LL;
    int split(vector<int> &A, LL M) {
        LL cnt = 0, sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            if (sum > M) {
                sum = A[i];
                ++cnt;
            }
        }
        return cnt + 1;
    }
public:
    int splitArray(vector<int>& A, int m) {
        LL sum = accumulate(begin(A), end(A), (LL)0);
        if (m == 1) return sum;
        LL L = *max_element(begin(A), end(A)), R = sum;
        while (L <= R) {
            LL M = (L + R) / 2;
            int n = split(A, M);
            if (n <= m) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
```