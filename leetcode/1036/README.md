# [1036. Escape a Large Maze (Hard)](https://leetcode.com/problems/escape-a-large-maze/)

<p>There is a 1 million by 1 million grid on an XY-plane, and the coordinates of each grid square are <code>(x, y)</code>.</p>

<p>We start at the <code>source = [s<sub>x</sub>, s<sub>y</sub>]</code> square and want to reach the <code>target = [t<sub>x</sub>, t<sub>y</sub>]</code> square. There is also an array of <code>blocked</code> squares, where each <code>blocked[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> represents a blocked square with coordinates <code>(x<sub>i</sub>, y<sub>i</sub>)</code>.</p>

<p>Each move, we can walk one square north, east, south, or west if the square is <strong>not</strong> in the array of <code>blocked</code> squares. We are also not allowed to walk outside of the grid.</p>

<p>Return <code>true</code><em> if and only if it is possible to reach the </em><code>target</code><em> square from the </em><code>source</code><em> square through a sequence of valid moves</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
<strong>Output:</strong> false
<strong>Explanation:</strong> The target square is inaccessible starting from the source square because we cannot move.
We cannot move north or east because those squares are blocked.
We cannot move south or west because we cannot go outside of the grid.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> blocked = [], source = [0,0], target = [999999,999999]
<strong>Output:</strong> true
<strong>Explanation:</strong> Because there are no blocked cells, it is possible to reach the target square.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= blocked.length &lt;= 200</code></li>
	<li><code>blocked[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt; 10<sup>6</sup></code></li>
	<li><code>source.length == target.length == 2</code></li>
	<li><code>0 &lt;= s<sub>x</sub>, s<sub>y</sub>, t<sub>x</sub>, t<sub>y</sub> &lt; 10<sup>6</sup></code></li>
	<li><code>source != target</code></li>
	<li>It is guaranteed that <code>source</code> and <code>target</code> are not blocked.</li>
</ul>


**Companies**:  
[Uber](https://leetcode.com/company/uber), [UiPath](https://leetcode.com/company/uipath)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. DFS

If we can search a point whose distance to the `source` is `>= 200`, then we know that `source` must not be enclosed by the blocked points. The same for the `target` point. If both direction are not blocked, we can return `true`.

If `source` meets `target` within this search process, we can return `true`.

Otherwise, we return `false`.

```cpp
// OJ: https://leetcode.com/problems/escape-a-large-maze/
// Author: github.com/lzl124631x
// Time: O(?)
// Space: O(?)
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_map<int, unordered_set<int>> blk;
        for (auto &b : blocked) blk[b[0]].insert(b[1]);
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        auto check = [&](vector<int> &from, vector<int> &to) -> int { // 0 -> blocked, 1 -> source & target met, 2 -> from is not enclosed by blocked points
            unordered_map<int, unordered_set<int>> seen;
            function<int(int, int, int)> dfs = [&](int x, int y, int dist) {
                if (x == to[0] && y == to[1]) return 1;
                if (dist >= 200) return 2;
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || b < 0 || a >= 1e6 || b >= 1e6 || (blk.count(a) && blk[a].count(b)) || seen[a].count(b)) continue;
                    seen[a].insert(b);
                    int ans = dfs(a, b, abs(a - from[0]) + abs(b - from[1]));
                    if (ans) return ans;
                }
                return 0;
            };
            return dfs(from[0], from[1], 0);
        };
        int a = check(source, target);
        return a == 1 || (a == 2 && check(target, source));
    }
};
```