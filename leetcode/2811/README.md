# [2811. Check if it is Possible to Split Array (Medium)](https://leetcode.com/problems/check-if-it-is-possible-to-split-array)

<p>You are given an array <code>nums</code> of length <code>n</code> and an integer <code>m</code>. You need to determine if it is possible to split the array into <code>n</code> <strong>non-empty</strong> arrays by performing a series of steps.</p>

<p>In each step, you can select an existing array (which may be the result of previous steps) with a length of <strong>at least two</strong> and split it into <strong>two </strong>subarrays, if, <strong>for each </strong>resulting subarray, <strong>at least</strong> one of the following holds:</p>

<ul>
	<li>The length of the subarray is one, or</li>
	<li>The sum of elements of the subarray is <strong>greater than or equal</strong> to <code>m</code>.</li>
</ul>

<p>Return <code>true</code><em> if you can split the given array into </em><code>n</code><em> arrays, otherwise return</em> <code>false</code>.</p>

<p><strong>Note:</strong> A subarray is <em>a contiguous non-empty sequence of elements within an array</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2, 2, 1], m = 4
<strong>Output:</strong> true
<strong>Explanation:</strong> We can split the array into [2, 2] and [1] in the first step. Then, in the second step, we can split [2, 2] into [2] and [2]. As a result, the answer is true.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2, 1, 3], m = 5 
<strong>Output:</strong> false
<strong>Explanation: </strong>We can try splitting the array in two different ways: the first way is to have [2, 1] and [3], and the second way is to have [2] and [1, 3]. However, both of these ways are not valid. So, the answer is false.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [2, 3, 3, 2, 3], m = 6
<strong>Output:</strong> true
<strong>Explanation:</strong> We can split the array into [2, 3, 3, 2] and [3] in the first step. Then, in the second step, we can split [2, 3, 3, 2] into [2, 3, 3] and [2]. Then, in the third step, we can split [2, 3, 3] into [2] and [3, 3]. And in the last step we can split [3, 3] into [3] and [3]. As a result, the answer is true.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>1 &lt;= m &lt;= 200</code></li>
</ul>


**Companies**:
[MoneyLion](https://leetcode.com/company/moneylion)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Greedy](https://leetcode.com/tag/greedy)

**Hints**:
* It can be proven that if you can split more than one element as a subarray, then you can split exactly one element.

## Solution 1. DP

Let `dp[i][j]` be whether `A[i][j]` is a valid split.

```
dp[i][i] = true

dp[i][j] = sum(i, j) >= m && dp[i][k] && dp[k+1][j]
            where i <= k < j
```

Note that the above formula doesn't cover the case that `A.size() == 2`. We should always return `true` if `A.size() == 2`.

```cpp
// OJ: https://leetcode.com/problems/check-if-it-is-possible-to-split-array
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    bool canSplitArray(vector<int>& A, int m) {
        if (A.size() <= 2) return true;
        int N = A.size();
        vector<int> sum(N + 1);
        vector<vector<bool>> dp(N, vector<bool>(N));
        for (int i = 0; i < N; ++i) {
            sum[i + 1] = sum[i] + A[i];
            dp[i][i] = true;
        }
        for (int i = N - 2; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) {
                if (sum[j + 1] - sum[i] < m) continue;
                for (int k = i; k < j && !dp[i][j]; ++k) {
                    dp[i][j] = dp[i][k] && dp[k + 1][j];
                }
            }
        }
        return dp[0][N - 1];
    }
};
```

## Solution 2. Greedy

As long as we can find a subarray of length 2 whose sum `>= m`, we can return `true`.

Corner case is `A.size() <= 2` where we can directly return `true`.

```cpp
// OJ: https://leetcode.com/problems/check-if-it-is-possible-to-split-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canSplitArray(vector<int>& A, int m) {
        if (A.size() <= 2) return true;
        int N = A.size();
        for (int i = 0; i + 1 < N; ++i) {
            if (A[i] + A[i + 1] >= m) return true;
        }
        return false;
    }
};
```