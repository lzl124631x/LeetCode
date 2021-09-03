# [1981. Minimize the Difference Between Target and Chosen Elements (Medium)](https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/)

<p>You are given an <code>m x n</code> integer matrix <code>mat</code> and an integer <code>target</code>.</p>

<p>Choose one integer from <strong>each row</strong> in the matrix such that the <strong>absolute difference</strong> between <code>target</code> and the <strong>sum</strong> of the chosen elements is <strong>minimized</strong>.</p>

<p>Return <em>the <strong>minimum absolute difference</strong></em>.</p>

<p>The <strong>absolute difference</strong> between two numbers <code>a</code> and <code>b</code> is the absolute value of <code>a - b</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/03/matrix1.png" style="width: 181px; height: 181px;">
<pre><strong>Input:</strong> mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
<strong>Output:</strong> 0
<strong>Explanation:</strong> One possible choice is to:
- Choose 1 from the first row.
- Choose 5 from the second row.
- Choose 7 from the third row.
The sum of the chosen elements is 13, which equals the target, so the absolute difference is 0.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/03/matrix1-1.png" style="width: 61px; height: 181px;">
<pre><strong>Input:</strong> mat = [[1],[2],[3]], target = 100
<strong>Output:</strong> 94
<strong>Explanation:</strong> The best possible choice is to:
- Choose 1 from the first row.
- Choose 2 from the second row.
- Choose 3 from the third row.
The sum of the chosen elements is 6, and the absolute difference is 94.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/03/matrix1-3.png" style="width: 301px; height: 61px;">
<pre><strong>Input:</strong> mat = [[1,2,9,8,7]], target = 6
<strong>Output:</strong> 1
<strong>Explanation:</strong> The best choice is to choose 7 from the first row.
The absolute difference is 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 70</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 70</code></li>
	<li><code>1 &lt;= target &lt;= 800</code></li>
</ul>


**Similar Questions**:
* [Partition Equal Subset Sum (Medium)](https://leetcode.com/problems/partition-equal-subset-sum/)
* [Closest Subsequence Sum (Hard)](https://leetcode.com/problems/closest-subsequence-sum/)
* [Maximum Number of Points with Cost (Medium)](https://leetcode.com/problems/maximum-number-of-points-with-cost/)

## Solution 1. Bitmask DP

Use a `bitset<4901> bs` to represent the sums we can get. We use 4901 because there are at most 70 rows and values are at most 70, hence the sum is at most 4900.

`bs[i] == 1` means that we can get a sum `i`. For example, if `bs == 11010`, it means that we can get sums `1`, `3`, and `4`.

Initially `bs = 1`.

For each row `A[i]`, we can calculate a `bitset<4901> next` representing all the sums we can get using the numbers from `A[0]` to `A[i]`.

For each number `n` in `A[i]`, we do `next |= bs << n`.

Once finishing scanning a row `A[i]`, we swap `bs` and `next`. Eventually, `bs` represents the sums we can get.

### Complexity Analysis

Assume the matrix is of size `M x N` and the maximum value is `K`. So the `bitset` is of size `MK`.

For each row, we do sorting which takes `O(NlogN)` time. And for each of the `N` numbers in this row, we need to take `O(MK)` time for the bit manipulation.

So for each row, we need `O(M^2 * NK)`.

Eventually we at most go through all the possible sums in range `[M, MK]` and calculate the smallest absolute difference with `target`. This process takes `O(MK)` time.

So, overall this algorithm takes `O(M^2 * NK)` time and `O(MK)` space.

```cpp
// OJ: https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/
// Author: github.com/lzl124631x
// Time: O(M^2 * KN)
// Space: O(MK)
const int maxN = 4901; 
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& A, int target) {
        int M = A.size(), N = A[0].size(), minSum = 0, maxSum = 0;
        bitset<maxN> bs(1);
        for (auto &v : A) {
            bitset<maxN> next;
            int mx = 0, mn = INT_MAX;
            sort(begin(v), end(v));
            for (int i = 0; i < N; ++i) {
                while (i + 1 < N && v[i + 1] == v[i]) ++i;
                next |= bs << v[i];
                mx = max(mx, v[i]);
                mn = min(mn, v[i]);
            }
            maxSum += mx;
            minSum += mn;
            swap(next, bs);
        }
        int i = target, ans = INT_MAX;
        for (; i >= minSum && !bs[i]; --i);
        if (i >= minSum) ans = target - i;
        for (i = target; i <= maxSum && !bs[i]; ++i);
        if (i <= maxSum) ans = min(ans, i - target);
        return ans;
    }
};
```

Shorter but less efficient because we don't do sorting for each row, and need to go through all the `4900` numbers.

```cpp
// OJ: https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/
// Author: github.com/lzl124631x
// Time: O(M^2 * KN)
// Space: O(MK)
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& A, int target) {
        bitset<4901> bs = 1;
        int M = A.size(), N = A[0].size(), ans = INT_MAX;
        for (int i = 0; i < M; ++i) {
            bitset<4901> next;
            for (int j = 0; j < N; ++j) {
                next |= bs << A[i][j];
            }
            swap(next, bs);
        }
        for (int i = 1; i < 4901; ++i) {
            if (bs[i]) ans = min(ans, abs(i - target));
        }
        return ans;
    }
};
```