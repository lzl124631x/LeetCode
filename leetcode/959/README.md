# [959. Regions Cut By Slashes (Medium)](https://leetcode.com/problems/regions-cut-by-slashes/)

<p>In a N x N&nbsp;<code>grid</code> composed of 1 x 1 squares, each 1 x 1 square consists of a <code>/</code>, <code>\</code>, or blank space.&nbsp; These characters divide the square into contiguous regions.</p>

<p>(Note that backslash characters are escaped, so a <code>\</code>&nbsp;is represented as <code>"\\"</code>.)</p>

<p>Return the number of regions.</p>

<p>&nbsp;</p>

<div>
<div>
<div>
<div>
<div>
<ol>
</ol>
</div>
</div>
</div>
</div>
</div>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:
</strong><span id="example-input-1-1">[
&nbsp; " /",
&nbsp; "/ "
]</span>
<strong>Output: </strong><span id="example-output-1">2</span>
<strong>Explanation: </strong>The 2x2 grid is as follows:
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/1.png" style="width: 82px; height: 82px;">
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input:
</strong><span id="example-input-2-1">[
&nbsp; " /",
&nbsp; "  "
]</span>
<strong>Output: </strong><span id="example-output-2">1</span>
<strong>Explanation: </strong>The 2x2 grid is as follows:
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/2.png" style="width: 82px; height: 82px;">
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input:
</strong><span id="example-input-3-1">[
&nbsp; "\\/",
&nbsp; "/\\"
]</span>
<strong>Output: </strong><span id="example-output-3">4</span>
<strong>Explanation: </strong>(Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
The 2x2 grid is as follows:
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/3.png" style="width: 82px; height: 82px;">
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input:
</strong><span id="example-input-4-1">[
&nbsp; "/\\",
&nbsp; "\\/"
]</span>
<strong>Output: </strong><span id="example-output-4">5</span>
<strong>Explanation: </strong>(Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
The 2x2 grid is as follows:
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/4.png" style="width: 82px; height: 82px;">
</pre>

<div>
<p><strong>Example 5:</strong></p>

<pre><strong>Input:
</strong><span id="example-input-5-1">[
&nbsp; "//",
&nbsp; "/ "
]</span>
<strong>Output: </strong><span id="example-output-5">3</span>
<strong>Explanation: </strong>The 2x2 grid is as follows:
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/5.png" style="width: 82px; height: 82px;">
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= grid.length == grid[0].length &lt;= 30</code></li>
	<li><code>grid[i][j]</code> is either <code>'/'</code>, <code>'\'</code>, or <code>' '</code>.</li>
</ol>
</div>
</div>
</div>
</div>
</div>

**Companies**:  
[Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1. Union Find

Split each cell to 4 parts, top/right/bottom/left indexed by 0/1/2/3.

For each cell:
* If it's `' '`, connect all 4 sub-cells
* If it's `'/'`, connect top-left and bottom-right.
* If it's `'\'`, connect top-right and bottom-left.
* Connect the 4 sub-cells with the neighboring sub-cells. For example, connect the top sub-cell with the bottom sub-cell of the cell above.

```cpp
// OJ: https://leetcode.com/problems/regions-cut-by-slashes
// Author: github.com/lzl124631x
// Time: O(N^2 * log(N^2))
// Space: O(N^2)
class UnionFind {
    vector<int> id;
    int cnt;
public:
    UnionFind(int n) : id(n), cnt(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
        --cnt;
    }
    int getCount() { return cnt; }
};;
class Solution {
public:
    int regionsBySlashes(vector<string>& A) {
        int N = A.size(), dirs[4][2] = {{-1,0}, {0,1}, {1,0},{0,-1}}; // TRBL 0123
        UnionFind uf(4 * N * N);
        auto key = [&](int x, int y, int dir) { return 4 * (x * N + y) + dir; };
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == ' ') {
                    for (int k = 1; k < 4; ++k) uf.connect(key(i, j, 0), key(i, j, k));
                } else if (A[i][j] == '/') {
                    uf.connect(key(i, j, 0), key(i, j, 3));
                    uf.connect(key(i, j, 1), key(i, j, 2));
                } else {
                    uf.connect(key(i, j, 0), key(i, j, 1));
                    uf.connect(key(i, j, 2), key(i, j, 3));
                }
                for (int k = 0; k < 4; ++k) {
                    auto &[dx, dy] = dirs[k];
                    int a = i + dx, b = j + dy;
                    if (a < 0 || a >= N || b < 0 || b >= N) continue;
                    uf.connect(key(i, j, k), key(a, b, (k + 2) % 4));
                }
            }
        }
        return uf.getCount();
    }
};
```