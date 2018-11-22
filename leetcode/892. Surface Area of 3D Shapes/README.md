# [892. Surface Area of 3D Shapes (Easy)](https://leetcode.com/problems/surface-area-of-3d-shapes/)

<p>On a&nbsp;<code>N&nbsp;*&nbsp;N</code>&nbsp;grid, we place some&nbsp;<code>1 * 1 * 1&nbsp;</code>cubes.</p>

<p>Each value&nbsp;<code>v = grid[i][j]</code>&nbsp;represents a tower of&nbsp;<code>v</code>&nbsp;cubes placed on top of grid cell&nbsp;<code>(i, j)</code>.</p>

<p>Return the total surface area of the resulting shapes.</p>

<p>&nbsp;</p>

<div>
<div>
<div>
<ul>
</ul>
</div>
</div>
</div>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[2]]</span>
<strong>Output: </strong><span id="example-output-1">10</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[[1,2],[3,4]]</span>
<strong>Output: </strong><span id="example-output-2">34</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[[1,0],[0,2]]</span>
<strong>Output: </strong><span id="example-output-3">16</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong><span id="example-input-4-1">[[1,1,1],[1,0,1],[1,1,1]]</span>
<strong>Output: </strong><span id="example-output-4">32</span>
</pre>

<div>
<p><strong>Example 5:</strong></p>

<pre><strong>Input: </strong><span id="example-input-5-1">[[2,2,2],[2,1,2],[2,2,2]]</span>
<strong>Output: </strong><span id="example-output-5">46</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ul>
	<li><code>1 &lt;= N &lt;= 50</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 50</code></li>
</ul>
</div>
</div>
</div>
</div>
</div>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/surface-area-of-3d-shapes/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = grid.size(), area = 0;
        for (int i = 0; i < N; ++i) {
            int prev = 0;
            for (int j = 0; j < N; ++j) {
                if (grid[i][j]) area += 2;
                area += abs(grid[i][j] - prev);
                prev = grid[i][j];
            }
            area += prev;
        }
        for (int i = 0; i < N; ++i) {
            int prev = 0;
            for (int j = 0; j < N; ++j) {
                area += abs(grid[j][i] - prev);
                prev = grid[j][i];
            }
            area += prev;
        }
        return area;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/surface-area-of-3d-shapes/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
private:
    int dirs[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}};
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = grid.size(), area = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!grid[i][j]) continue;
                area += 2;
                for (auto &dir : dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    int h = x < 0 || x >= N || y < 0 || y >= N ? 0 : grid[x][y];
                    area += max(grid[i][j] - h, 0);
                }
            }
        }
        return area;
    }
};
```