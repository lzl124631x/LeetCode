# [1443. Minimum Time to Collect All Apples in a Tree (Medium)](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/)

<p>Given an undirected tree consisting of <code>n</code> vertices numbered from 0 to <code>n-1</code>, which has some apples in their&nbsp;vertices. You spend 1 second to walk over one&nbsp;edge of the tree.&nbsp;<em>Return the minimum time in seconds&nbsp;you have to spend&nbsp;in order to collect all apples in the tree starting at <strong>vertex 0</strong> and coming back to this vertex.</em></p>

<p>The edges of the undirected tree are given in the array <code>edges</code>, where <code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>]</code> means that exists an edge connecting the vertices <code>from<sub>i</sub></code> and <code>to<sub>i</sub></code>. Additionally, there is&nbsp;a boolean array <code>hasApple</code>, where <code>hasApple[i] = true</code>&nbsp;means that&nbsp;vertex <code>i</code> has an apple, otherwise, it does not have any apple.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/04/23/min_time_collect_apple_1.png" style="width: 300px; height: 212px;"></strong></p>

<pre><strong>Input:</strong> n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
<strong>Output:</strong> 8 
<strong>Explanation:</strong> The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/04/23/min_time_collect_apple_2.png" style="width: 300px; height: 212px;"></strong></p>

<pre><strong>Input:</strong> n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>edges.length == n-1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= from<sub>i</sub>, to<sub>i</sub> &lt;= n-1</code></li>
	<li><code>from<sub>i</sub>&nbsp;&lt; to<sub>i</sub></code></li>
	<li><code>hasApple.length == n</code></li>
</ul>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. Post-order Traversal

```cpp
// OJ: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    vector<vector<int>> G;
    vector<bool> seen;
    int dfs(int u, vector<bool> &hasApple) {
        seen[u] = true;
        int ans = 0;
        for (auto v : G[u]) {
            if (seen[v]) continue;
            ans += dfs(v, hasApple);
        }
        if (!ans && !hasApple[u]) return 0;
        return u == 0 ? ans : ans + 1;
    }
public:
    int minTime(int n, vector<vector<int>>& E, vector<bool>& hasApple) {
        seen.assign(n, false);
        G.assign(n, {});
        for (auto & e : E) G[e[0]].push_back(e[1]), G[e[1]].push_back(e[0]);
        return 2 * dfs(0, hasApple);
    }
};
```