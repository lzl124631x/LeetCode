# [1074. Number of Submatrices That Sum to Target (Hard)](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/)

<p>Given a <code>matrix</code>, and a <code>target</code>, return the number of non-empty submatrices that sum to <font face="monospace">target</font>.</p>

<p>A submatrix <code>x1, y1, x2, y2</code> is the set of all cells <code>matrix[x][y]</code> with <code>x1 &lt;= x &lt;= x2</code> and <code>y1 &lt;= y &lt;= y2</code>.</p>

<p>Two submatrices <code>(x1, y1, x2, y2)</code> and <code>(x1', y1', x2', y2')</code> are different if they have some coordinate&nbsp;that is different: for example, if <code>x1 != x1'</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>matrix = <span id="example-input-1-1">[[0,1,0],[1,1,1],[0,1,0]]</span>, target = <span id="example-input-1-2">0</span>
<strong>Output: </strong><span id="example-output-1">4</span>
<strong>Explanation: </strong>The four 1x1 submatrices that only contain 0.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>matrix = <span id="example-input-2-1">[[1,-1],[-1,1]]</span>, target = <span id="example-input-2-2">0</span>
<strong>Output: </strong><span id="example-output-2">5</span>
<strong>Explanation: </strong>The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
</pre>
</div>

<p>&nbsp;</p>

<p><strong><strong>Note:</strong></strong></p>

<ol>
	<li><code>1 &lt;= matrix.length &lt;= 300</code></li>
	<li><code>1 &lt;= matrix[0].length &lt;= 300</code></li>
	<li><code>-1000 &lt;= matrix[i] &lt;= 1000</code></li>
	<li><code>-10^8 &lt;= target &lt;= 10^8</code></li>
</ol>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

## Solution 1.

Let `sum[i][j]` be the sum of all elements in submatrix `(0,0)` to `(i-1,j-1)`.

For each pair of columns `i, j`, `sum[k][j] - sum[k][i]` is the sum of all elements in submatrix `(0,i)` to `(k-1,j-1)`.

We can loop `k` from `1` to `M`, and use the solution of [560. Subarray Sum Equals K (Medium)](https://leetcode.com/problems/subarray-sum-equals-k/) to count the submatrixes that starts at column `i` and ends at (inclusive) column `j-1` and sums to `target`.

```cpp
// OJ: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
// Author: github.com/lzl124631x
// Time: O(M * N^2)
// Space: O(MN)
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int M = matrix.size(), N = matrix[0].size(), ans = 0;
        vector<vector<int>> sum(M + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        for (int i = 0; i < N; ++i) {
           for (int j = i + 1; j <= N; ++j) {
               unordered_map<int, int> m {{ 0, 1 }};
               for (int k = 1; k <= M; ++k) {
                   int val = sum[k][j] - sum[k][i];
                   ans += m[val - target];
                   m[val]++;
               }
           }
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
// Author: github.com/lzl124631x
// Time: O(M^2 * N)
// Space: O(N)
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int T) {
        int M = A.size(), N = A[0].size(), ans = 0;
        for (int i = 0; i < M; ++i) {
            vector<int> sum(N);
            for (int j = i; j < M; ++j) {
                unordered_map<int, int> cnt;
                cnt[0] = 1;
                int total = 0;
                for (int k = 0; k < N; ++k) {
                    sum[k] += A[j][k];
                    total += sum[k];
                    ans += cnt[total - T];
                    cnt[total]++;
                }
            }
        }
        return ans;
    }
};
```