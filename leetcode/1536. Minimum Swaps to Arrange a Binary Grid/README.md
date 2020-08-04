# [1536. Minimum Swaps to Arrange a Binary Grid (Medium)](https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/)

<p>Given an <code>n&nbsp;x n</code>&nbsp;binary <code>grid</code>, in one step you can choose two <strong>adjacent rows</strong> of the grid and swap them.</p>

<p>A grid is said to be <strong>valid</strong> if all the cells above the main diagonal are <strong>zeros</strong>.</p>

<p>Return <em>the minimum number of steps</em> needed to make the grid valid, or <strong>-1</strong> if the grid cannot be valid.</p>

<p>The main diagonal of a grid is the diagonal that starts at cell <code>(1, 1)</code> and ends at cell <code>(n, n)</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/28/fw.jpg" style="width: 750px; height: 141px;">
<pre><strong>Input:</strong> grid = [[0,0,1],[1,1,0],[1,0,0]]
<strong>Output:</strong> 3
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/16/e2.jpg" style="width: 270px; height: 270px;">
<pre><strong>Input:</strong> grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> All rows are similar, swaps have no effect on the grid.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/16/e3.jpg" style="width: 200px; height: 200px;">
<pre><strong>Input:</strong> grid = [[1,0,0],[1,1,0],[1,1,1]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 200</code></li>
	<li><code>grid[i][j]</code> is <code>0</code> or <code>1</code></li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

First store the max index of the `1` in each row into a `vector<int> v`.

Then we can from the first item to the last item in `v`:
* if `v[i] <= i`, this row is good. Skip
* Otherwise, we find the minimal `j` (`i + 1 < j < N`) that satisfies `v[j] <= i`.
  - If we can't find it, no row can be placed at this `i`-th row. Return `-1`.
  - Otherwise, we move `v[j]` to `v[i]` and the `v[k]` (`i <= k < j`) are moved downwards. And we add `j - i` steps of swaps to the answer.

```cpp
// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int minSwaps(vector<vector<int>>& G) {
        int N = G.size(), ans = 0;
        vector<int> v(N);
        for (int i = 0; i < N; ++i) {
            int len = 0;
            for (int j = N - 1; j >= 0; --j) {
                if (G[i][j] == 0) continue;
                len = j + 1;
                break;
            }
            v[i] = len;
        }
        for (int i = 0; i < N; ++i) {
            if (v[i] <= i + 1) continue;
            int j = i + 1;
            while (j < N && v[j] > i + 1) ++j; 
            if (j == N) return -1; 
            int tmp = v[j];
            for (int k = j; k > i; --k) v[k] = v[k - 1];
            v[i] = tmp;
            ans += j - i;
        }
        return ans;
    }
};
```