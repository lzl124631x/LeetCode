# [407. Trapping Rain Water II (Hard)](https://leetcode.com/problems/trapping-rain-water-ii/)

<p>Given an <code>m x n</code> matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.</p>

<p><b>Example:</b></p>

<pre>Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.
</pre>

<p><img src="https://assets.leetcode.com/uploads/2018/10/13/rainwater_empty.png" style="width: 100%; max-width: 500px;"></p>

<p>The above image represents the elevation map <code>[[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]</code> before the rain.</p>

<p>&nbsp;</p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/13/rainwater_fill.png" style="width: 100%; max-width: 500px;"></p>

<p>After the rain, water is trapped between the blocks. The total volume of water trapped is 4.</p>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 110</code></li>
	<li><code>0 &lt;= heightMap[i][j] &lt;= 20000</code></li>
</ul>


**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Trapping Rain Water (Hard)](https://leetcode.com/problems/trapping-rain-water/)

## Solution 1. Heap

```cpp
// OJ: https://leetcode.com/problems/trapping-rain-water-ii/
// Author: github.com/lzl124631x
// Time: O(MNlog(MN))
// Space: O(MN)
// Ref: https://discuss.leetcode.com/topic/60914/concise-c-priority_queue-solution
class Solution {
    typedef array<int, 3> Point;
public:
    int trapRainWater(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}, ans = 0, maxH = INT_MIN;
        priority_queue<Point, vector<Point>, greater<>> pq;
        vector<vector<bool>> seen(M, vector<bool>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == 0 || i == M - 1 || j == 0 || j == N - 1) {
                    pq.push({ A[i][j], i, j });
                    seen[i][j] = true;
                }
            }
        }
        while (pq.size()) {
            auto [h, x, y] = pq.top();
            pq.pop();
            maxH = max(maxH, h);
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= M || b < 0 || b >= N || seen[a][b]) continue;
                seen[a][b] = true;
                if (A[a][b] < maxH) ans += maxH - A[a][b];
                pq.push({ A[a][b], a, b });
            }
        }
        return ans;
    }
};
```