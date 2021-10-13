# [1001. Grid Illumination (Hard)](https://leetcode.com/problems/grid-illumination/)

<p>There is a 2D <code>grid</code> of size <code>n x n</code> where each cell of this grid has a lamp that is initially <strong>turned off</strong>.</p>

<p>You are given a 2D array of lamp positions <code>lamps</code>, where <code>lamps[i] = [row<sub>i</sub>, col<sub>i</sub>]</code> indicates that the lamp at <code>grid[row<sub>i</sub>][col<sub>i</sub>]</code> is <strong>turned on</strong>. Even if the same lamp is listed more than once, it is turned on.</p>

<p>When a lamp is turned on, it <strong>illuminates its cell</strong> and <strong>all other cells</strong> in the same <strong>row, column, or diagonal</strong>.</p>

<p>You are also given another 2D array <code>queries</code>, where <code>queries[j] = [row<sub>j</sub>, col<sub>j</sub>]</code>. For the <code>j<sup>th</sup></code> query, determine whether <code>grid[row<sub>j</sub>][col<sub>j</sub>]</code> is illuminated or not. After answering the <code>j<sup>th</sup></code> query, <strong>turn off</strong> the lamp at <code>grid[row<sub>j</sub>][col<sub>j</sub>]</code> and its <strong>8 adjacent lamps</strong> if they exist. A lamp is adjacent if its cell shares either a side or corner with <code>grid[row<sub>j</sub>][col<sub>j</sub>]</code>.</p>

<p>Return <em>an array of integers </em><code>ans</code><em>,</em><em> where </em><code>ans[j]</code><em> should be </em><code>1</code><em> if the cell in the </em><code>j<sup>th</sup></code><em> query was illuminated, or </em><code>0</code><em> if the lamp was not.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/19/illu_1.jpg" style="width: 750px; height: 209px;">
<pre><strong>Input:</strong> n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
<strong>Output:</strong> [1,0]
<strong>Explanation:</strong> We have the initial grid with all lamps turned off. In the above picture we see the grid after turning on the lamp at grid[0][0] then turning on the lamp at grid[4][4].
The 0<sup>th</sup>&nbsp;query asks if the lamp at grid[1][1] is illuminated or not (the blue square). It is illuminated, so set ans[0] = 1. Then, we turn off all lamps in the red square.
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/19/illu_step1.jpg" style="width: 500px; height: 218px;">
The 1<sup>st</sup>&nbsp;query asks if the lamp at grid[1][0] is illuminated or not (the blue square). It is not illuminated, so set ans[1] = 0. Then, we turn off all lamps in the red rectangle.
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/19/illu_step2.jpg" style="width: 500px; height: 219px;">
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
<strong>Output:</strong> [1,1]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
<strong>Output:</strong> [1,1,0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= lamps.length &lt;= 20000</code></li>
	<li><code>0 &lt;= queries.length &lt;= 20000</code></li>
	<li><code>lamps[i].length == 2</code></li>
	<li><code>0 &lt;= row<sub>i</sub>, col<sub>i</sub> &lt; n</code></li>
	<li><code>queries[j].length == 2</code></li>
	<li><code>0 &lt;= row<sub>j</sub>, col<sub>j</sub> &lt; n</code></li>
</ul>


**Companies**:  
[Dropbox](https://leetcode.com/company/dropbox)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [N-Queens (Hard)](https://leetcode.com/problems/n-queens/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/grid-illumination/
// Author: github.com/lzl124631x
// Time: O(MlogN) where M is the length of `A`.
// Space: O(M)
class Solution {
    int getSize(unordered_map<int, set<pair<int, int>>> &m, int key) {
        return m.count(key) ? m[key].size() : 0;
    }
    void erase(unordered_map<int, set<pair<int, int>>> &m, int key, pair<int, int> val) {
        m[key].erase(val);
        if (m[key].empty()) m.erase(key);
    }
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& A, vector<vector<int>>& Q) {
        vector<int> ans;
        unordered_map<int, set<pair<int, int>>> row, col, hill, dale;
        for (auto &v : A) {
            int x = v[0], y = v[1];
            if (row.count(x) && row[x].count({ x, y })) continue;
            row[x].emplace(x, y);
            col[y].emplace(x, y);
            hill[x + y].emplace(x, y);
            dale[x + n - 1 - y].emplace(x, y);
        }
        for (auto &q : Q) {
            int x = q[0], y = q[1];
            ans.push_back(getSize(row, x) + getSize(col, y) + getSize(hill, x + y) + getSize(dale, x + n - 1 - y) > 0);
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || a >= n || b < 0 || b >= n || row.count(a) == 0 || row[a].count({ a, b }) == 0) continue;
                    erase(row, a, {a, b});
                    erase(col, b, {a, b});
                    erase(hill, a + b, {a, b});
                    erase(dale, a + n - 1 - b, {a, b});
                }
            }
        }
        return ans;
    }
};
```