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

Let `dp(i, j)` be the answer to subproblem where we split `A[0] ~ A[j-1]` `i` times.

So `1 <= i <= m` and `1 <= j <= N`.

Our goal is `dp(m, N)`.

```
dp(i, j) = min {
  max(dp(i-1, j-1), S(i-1,i)),
  max(dp(i-2, j-1), S(i-2,i)),
  ...
  max(dp(2, j-1), S(2, i)),
  max(dp(1, j-1), S(1, i))
}
```
where `S(a, b) = A[a] + A[a+1] + ... + A[b-1]`.

Special cases:

1. `dp(i, j)` is meaningless if `i > j`.
2. `dp(i, j) = max(A[0], A[1], ..., A[j-1])` if `i == j`.
3. `dp(1, j) = S(0, j)`.

```cpp
// OJ: https://leetcode.com/problems/split-array-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N^2 * M)
// Space: O(NM)
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int N = nums.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(N + 1, LLONG_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= N && i <= m; ++i) dp[i][i] = max(dp[i - 1][i - 1], (long long)nums[i - 1]);
        for (int i = 2; i <= N; ++i) dp[1][i] = dp[1][i - 1] + nums[i - 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                long long s = 0;
                for (int k = j - 1; k >= 0; --k) {
                    long long val = min(dp[i][j], max(s += nums[k], dp[i - 1][k]));
                    if (val > dp[i][j]) break;
                    dp[i][j] = val;
                }
            }
        }
        return dp[m][N];
    }
};
```

## Solution 2. Binary Search

```cpp
// OJ: https://leetcode.com/problems/split-array-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N * log(S)) where S is sum of nums.
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/61324/clear-explanation-8ms-binary-search-java
class Solution {
private:
    bool isValid(int M, vector<int> &nums, int m) {
        int sum = 0, cnt = 1;
        for (int n : nums) {
            if (sum + n > M) {
                sum = n;
                ++cnt;
                if (cnt > m) return false;
            } else {
                sum += n;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int N = nums.size(), maxNum = INT_MIN, sum = 0;
        for (int n : nums) {
            maxNum = max(maxNum, n);
            sum += n;
        }
        if (m == 1) return sum;
        int L = maxNum, R = sum;
        while (L <= R) {
            int M = (L + R) / 2;
            if (isValid(M, nums, m)) {
                R = M - 1;
            } else {
                L = M + 1;
            }
        }
        return L;
    }
};
```