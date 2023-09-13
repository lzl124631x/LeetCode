# [1591. Strange Printer II (Hard)](https://leetcode.com/problems/strange-printer-ii/)

<p>There is a strange printer with the following two special requirements:</p>

<ul>
	<li>On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.</li>
	<li>Once the printer has used a color for the above operation, <strong>the same color cannot be used again</strong>.</li>
</ul>

<p>You are given a <code>m x n</code> matrix <code>targetGrid</code>, where <code>targetGrid[row][col]</code> is the color in the position <code>(row, col)</code> of the grid.</p>

<p>Return <code>true</code><em> if it is possible to print the matrix </em><code>targetGrid</code><em>,</em><em> otherwise, return </em><code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/08/15/sample_1_1929.png" style="width: 483px; height: 138px;"></p>

<pre><strong>Input:</strong> targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/08/15/sample_2_1929.png" style="width: 483px; height: 290px;"></p>

<pre><strong>Input:</strong> targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
<strong>Output:</strong> true
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible to form targetGrid because it is not allowed to print the same color in different turns.</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> targetGrid = [[1,1,1],[3,1,3]]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == targetGrid.length</code></li>
	<li><code>n == targetGrid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 60</code></li>
	<li><code>1 &lt;= targetGrid[row][col] &lt;= 60</code></li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Strange Printer (Hard)](https://leetcode.com/problems/strange-printer/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/strange-printer-ii/
// Author: github.com/lzl124631x
// Time: O(C^2 * MN)
// Space: O(MN)
class Solution {
    bool removable(vector<vector<int>> &G, vector<vector<int>> &pos, int c) {
        for (int i = pos[c][0]; i <= pos[c][2]; ++i) {
            for (int j = pos[c][1]; j <= pos[c][3]; ++j) {
                if (G[i][j] != c && G[i][j] != 0) return false;
            }
        }
        for (int i = pos[c][0]; i <= pos[c][2]; ++i) {
            for (int j = pos[c][1]; j <= pos[c][3]; ++j) G[i][j] = 0;
        }
        return true;
    }
public:
    bool isPrintable(vector<vector<int>>& G) {
        int M = G.size(), N = G[0].size();
        vector<vector<int>> pos(61, {M, N, 0, 0});
        unordered_set<int> colors, remove;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int c = G[i][j];
                colors.insert(c);
                pos[c][0] = min(pos[c][0], i);
                pos[c][1] = min(pos[c][1], j);
                pos[c][2] = max(pos[c][2], i);
                pos[c][3] = max(pos[c][3], j);
            }
        }
        while (colors.size()) {
            for (int c : colors) {
                if (removable(G, pos, c)) remove.insert(c);
            }
            if (remove.empty()) return false;
            for (int c : remove) colors.erase(c);
            remove.clear();
        }
        return true;
    }
};
```

## Solution 2. Topological Sort

```cpp
// OJ: https://leetcode.com/problems/strange-printer-ii/
// Author: github.com/lzl124631x
// Time: O(CMN + C^2)
// Space: O(C^2)
class Solution {
    bool hasCircle(int c, unordered_map<int, unordered_set<int>> &dep, vector<int> &state) {
        if (state[c] != -1) return !state[c];
        state[c] = 0;
        for (int d : dep[c]) {
            if (state[d] == 1) continue;
            if (state[d] == 0) return true;
            if (hasCircle(d, dep, state)) return true;
        }
        state[c] = 1;
        return false;
    }
public:
    bool isPrintable(vector<vector<int>>& G) {
        int M = G.size(), N = G[0].size();
        unordered_set<int> colors;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) colors.insert(G[i][j]);
        }
        unordered_map<int, unordered_set<int>> dep(61); // dependency graph: If dep[i] contains j, then color j covers color i.
        for (int i : colors) {
            int minx = M, miny = N, maxx = -1, maxy = -1;
            for (int x = 0; x < M; ++x) {
                for (int y = 0; y < N; ++y) {
                    if (G[x][y] != i) continue;
                    minx = min(minx, x);
                    miny = min(miny, y);
                    maxx = max(maxx, x);
                    maxy = max(maxy, y);
                }
            }
            for (int x = minx; x <= maxx; ++x) {
                for (int y = miny; y <= maxy; ++y) {
                    if (G[x][y] != i) dep[i].insert(G[x][y]);
                }
            }
        }
        vector<int> state(61, -1); // -1 unvisited, 0 visiting, 1 visited
        for (int i : colors) {
            if (hasCircle(i, dep, state)) return false;
        }
        return true;
    }
};
```