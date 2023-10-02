# [2077. Paths in Maze That Lead to Same Room (Medium)](https://leetcode.com/problems/paths-in-maze-that-lead-to-same-room/)

<p>A maze consists of <code>n</code> rooms numbered from <code>1</code> to <code>n</code>, and some rooms are connected by corridors. You are given a 2D integer array <code>corridors</code> where <code>corridors[i] = [room1<sub>i</sub>, room2<sub>i</sub>]</code> indicates that there is a corridor connecting <code>room1<sub>i</sub></code> and <code>room2<sub>i</sub></code>, allowing a person in the maze to go from <code>room1<sub>i</sub></code> to <code>room2<sub>i</sub></code> <strong>and vice versa</strong>.</p>

<p>The designer of the maze wants to know how confusing the maze is. The <strong>confusion</strong> <strong>score</strong> of the maze is the number of different cycles of <strong>length 3</strong>.</p>

<ul>
	<li>For example, <code>1 → 2 → 3 → 1</code> is a cycle of length 3, but <code>1 → 2 → 3 → 4</code> and <code>1 → 2 → 3 → 2 → 1</code> are not.</li>
</ul>

<p>Two cycles are considered to be <strong>different</strong> if one or more of the rooms visited in the first cycle is <strong>not</strong> in the second cycle.</p>

<p>Return <em>the</em> <em><strong>confusion</strong><strong> score</strong> of the maze.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2021/11/14/image-20211114164827-1.png" style="width: 440px; height: 350px;">
<pre><strong>Input:</strong> n = 5, corridors = [[1,2],[5,2],[4,1],[2,4],[3,1],[3,4]]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
One cycle of length 3 is 4 → 1 → 3 → 4, denoted in red.
Note that this is the same cycle as 3 → 4 → 1 → 3 or 1 → 3 → 4 → 1 because the rooms are the same.
Another cycle of length 3 is 1 → 2 → 4 → 1, denoted in blue.
Thus, there are two different cycles of length 3.
</pre>

<p><strong>Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2021/11/14/image-20211114164851-2.png" style="width: 329px; height: 250px;">
<pre><strong>Input:</strong> n = 4, corridors = [[1,2],[3,4]]
<strong>Output:</strong> 0
<strong>Explanation:</strong>
There are no cycles of length 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= corridors.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>corridors[i].length == 2</code></li>
	<li><code>1 &lt;= room1<sub>i</sub>, room2<sub>i</sub> &lt;= n</code></li>
	<li><code>room1<sub>i</sub> != room2<sub>i</sub></code></li>
	<li>There are no duplicate corridors.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Number of Connected Components in an Undirected Graph (Medium)](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)
* [Reachable Nodes In Subdivided Graph (Hard)](https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/)
* [Find if Path Exists in Graph (Easy)](https://leetcode.com/problems/find-if-path-exists-in-graph/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/paths-in-maze-that-lead-to-same-room/
// Author: github.com/lzl124631x
// Time: O(N^3 + E)
// Space: O(N^2)
class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& A) {
        bool G[1001][1001] = {};
        for (auto &e : A) {
            int u = e[0] - 1, v = e[1] - 1;
            G[u][v] = G[v][u] = true;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!G[i][j]) continue;
                for (int k = j + 1; k < n; ++k) {
                    ans += G[i][k] && G[j][k];
                }
            }
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/paths-in-maze-that-lead-to-same-room/
// Author: github.com/lzl124631x
// Time: O(VE)
// Space: O(V^2)
class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& A) {
        bool G[1001][1001] = {};
        for (auto &e : A) {
            int u = e[0] - 1, v = e[1] - 1;
            G[u][v] = G[v][u] = true;
        }
        int ans = 0;
        for (auto &e : A) {
            int u = e[0] - 1, v = e[1] - 1;
            if (u > v) swap(u, v);
            for (int i = v + 1; i < n; ++i) {
                ans += G[i][u] && G[i][v];
            }
        }
        return ans;
    }
};
```