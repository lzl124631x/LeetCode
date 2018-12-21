# [427. Construct Quad Tree (Easy)](https://leetcode.com/problems/construct-quad-tree/)

<p>We want to use quad trees to store an <code>N x N</code> boolean grid. Each cell in the grid can only be true or false. The root node represents the whole grid. For each node, it will be subdivided into four children nodes <strong>until the values in the region it represents are all the same</strong>.</p>

<p>Each node has another two boolean attributes : <code>isLeaf</code> and <code>val</code>. <code>isLeaf</code> is true if and only if the node is a leaf node. The <code>val</code> attribute for a leaf node contains the value of the region it represents.</p>

<p>Your task is to use a quad tree to represent a given grid. The following example may help you understand the problem better:</p>

<p>Given the <code>8 x 8</code> grid below, we want to construct the corresponding quad tree:</p>

<p><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/01/962_grid.png" style="height:27%; max-height:300px; max-width:299px; width:27%"></p>

<p>It can be divided according to the definition above:</p>

<p><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/01/962_grid_divided.png" style="height:100%; max-height:300px; max-width:1107px; width:100%"></p>

<p>&nbsp;</p>

<p>The corresponding quad tree should be as following, where each node is represented as a <code>(isLeaf, val)</code> pair.</p>

<p>For the non-leaf&nbsp;nodes,&nbsp;<code>val</code> can be arbitrary, so it is represented as <code>*</code>.</p>

<p><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/01/962_quad_tree.png" style="height:100%; max-height:300px; max-width:836px; width:100%"></p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>N</code> is less than <code>1000</code> and guaranteened to be a power of 2.</li>
	<li>If you want to know more about the quad tree, you can refer to its <a href="https://en.wikipedia.org/wiki/Quadtree">wiki</a>.</li>
</ol>


**Companies**:  
[Uber](https://leetcode.com/company/uber)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/construct-quad-tree/
// Author: github.com/lzl124631x
// Time: O(logN * N^2)
// Space: O(logN)
class Solution {
private:
    Node *dfs(vector<vector<int>> &grid, int x, int y, int N) {
        bool same = true;
        for (int i = 0; i < N && same; ++i) {
            for (int j = 0; j < N && same; ++j) {
                same = grid[x][y] == grid[x + i][y + j];
            }
        }
        if (same) return new Node(grid[x][y], true, NULL, NULL, NULL, NULL);
        return new Node(true, false,
                             dfs(grid, x, y, N / 2),
                             dfs(grid, x, y + N / 2, N / 2),
                             dfs(grid, x + N / 2, y, N / 2),
                             dfs(grid, x + N / 2, y + N / 2, N / 2));
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, grid.size());
    }
};
```