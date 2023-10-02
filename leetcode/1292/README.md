# [1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold (Medium)](https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/)

<p>Given a <code>m x n</code>&nbsp;matrix <code>mat</code> and an integer <code>threshold</code>. Return the maximum side-length of a square with a sum less than or equal to <code>threshold</code> or return <strong>0</strong> if there is no such square.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/12/05/e1.png" style="width: 335px; height: 186px;">
<pre><strong>Input:</strong> mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> The maximum side length of square with sum less than 4 is 2 as shown.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
<strong>Output:</strong> 0
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
<strong>Output:</strong> 3
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], threshold = 40184
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>0 &lt;= mat[i][j] &lt;= 10000</code></li>
	<li><code>0 &lt;= threshold&nbsp;&lt;= 10^5</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Prefix Sum

```cpp
// OJ: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maxSideLength(vector<vector<int>>& A, int threshold) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<vector<int>> sum(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) {
            int s = 0;
            for (int j = 0; j < N; ++j) sum[i + 1][j + 1] = sum[i][j + 1] + (s += A[i][j]);
        }
        for (int i = 0; ans <= min(M, N) && i <= M - ans; ++i) {
            for (int j = 0; ans <= min(M, N) && j <= N - ans; ++j) {
                for (; ans <= min(M - i, N - j) && sum[i + ans][j + ans] - sum[i + ans][j] - sum[i][j + ans] + sum[i][j] <= threshold; ++ans);
            }
        }
        return ans - 1;
    }
};
```

## Solution 2. Binary Answer

```cpp
// OJ: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
// Author: github.com/lzl124631x
// Time: O(MN * log(min(M, N)))
// Space: O(MN)
class Solution {
    bool valid(vector<vector<int>> &sum, int len, int threshold) {
        for (int i = 0; i < sum.size() - len; ++i) {
            for (int j = 0; j < sum[0].size() - len; ++j) {
                if (sum[i + len][j + len] - sum[i + len][j] - sum[i][j + len] + sum[i][j] <= threshold) return true;
            }
        }
        return false;
    }
public:
    int maxSideLength(vector<vector<int>>& A, int threshold) {
        int M = A.size(), N = A[0].size(), L = 0, R = min(M, N);
        vector<vector<int>> sum(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) {
            int s = 0;
            for (int j = 0; j < N; ++j) sum[i + 1][j + 1] = sum[i][j + 1] + (s += A[i][j]);
        }
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(sum, M, threshold)) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};
```