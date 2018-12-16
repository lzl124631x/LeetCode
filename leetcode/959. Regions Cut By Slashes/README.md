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

## Solution 1.

For a square, if it's split by a `\` or `/`, the left region (the one touches the left border) is denoted as `0`, the right region is denoted as `1`.

```cpp
// OJ: https://leetcode.com/problems/regions-cut-by-slashes/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
private:
    unordered_set<int> seen;
    int ans = 0, N;
    int hash(int i, int j, int pos) {
        return i + j  * 100 + pos * 10000;
    }
    void insert(queue<int> &q, int h) {
        if (seen.find(h) != seen.end()) return;
        q.push(h);
        seen.insert(h);
    }
    int bfs(vector<string>& grid, int i, int j, int pos) {
        int h = hash(i, j, pos);
        if (seen.find(h) != seen.end()) return 0;
        seen.insert(h);
        queue<int> q;
        q.push(h);
        while (q.size()) {
            int val = q.front();
            q.pop();
            i = val % 100;
            j = val / 100 % 100;
            pos = val / 10000;
            if (grid[i][j] == '\\') {
                if (pos == 0) {
                    if (j - 1 >= 0) insert(q, hash(i, j - 1, 1));
                    if (i + 1 < N) insert(q, hash(i + 1, j, grid[i + 1][j] == '\\' ? 1 : 0));
                } else {
                    if (i - 1 >= 0) insert(q, hash(i - 1, j, grid[i - 1][j] == '\\' ? 0 : 1));
                    if (j + 1 < N) insert(q, hash(i, j + 1, 0));
                }
            } else if (grid[i][j] == '/') {
                if (pos == 0) {
                    if (j - 1 >= 0) insert(q, hash(i, j - 1, 1));
                    if (i - 1 >= 0) insert(q, hash(i - 1, j, grid[i - 1][j] == '\\' ? 0 : 1));
                } else {
                    if (j + 1 < N) insert(q, hash(i, j + 1, 0));
                    if (i + 1 < N) insert(q, hash(i + 1, j, grid[i + 1][j] == '\\' ? 1 : 0));
                }
            } else {
                insert(q, hash(i, j, 1 - pos));
                if (i - 1 >= 0) insert(q, hash(i - 1, j, grid[i - 1][j] == '\\' ? 0 : 1));
                if (j + 1 < N) insert(q, hash(i, j + 1, 0));
                if (i + 1 < N) insert(q, hash(i + 1, j, grid[i + 1][j] == '\\' ? 1 : 0));
                if (j - 1 >= 0) insert(q, hash(i, j - 1, 1));
            }
        }
        return 1;
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        N = grid.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                ans += bfs(grid, i, j, 0);
                ans += bfs(grid, i, j, 1);
            }
        }
        return ans;
    }
};
```