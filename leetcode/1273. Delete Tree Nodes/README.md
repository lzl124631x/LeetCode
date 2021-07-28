# [1273. Delete Tree Nodes (Medium)](https://leetcode.com/problems/delete-tree-nodes/)

<p>A tree rooted at node 0 is given as follows:</p>

<ul>
	<li>The number of nodes is <code>nodes</code>;</li>
	<li>The value of the <code>i</code>-th node is <code>value[i]</code>;</li>
	<li>The parent of the <code>i</code>-th node is <code>parent[i]</code>.</li>
</ul>

<p>Remove every subtree whose sum of values of nodes is zero.</p>

<p>After doing so, return the number of nodes remaining in the tree.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/07/02/1421_sample_1.PNG" style="width: 403px; height: 347px;">
<pre><strong>Input:</strong> nodes = 7, parent = [-1,0,0,1,2,2,2], value = [1,-2,4,0,-2,-1,-1]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nodes = 7, parent = [-1,0,0,1,2,2,2], value = [1,-2,4,0,-2,-1,-2]
<strong>Output:</strong> 6
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nodes = 5, parent = [-1,0,1,0,0], value = [-672,441,18,728,378]
<strong>Output:</strong> 5
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nodes = 5, parent = [-1,0,0,1,1], value = [-686,-842,616,-739,-746]
<strong>Output:</strong> 5
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nodes &lt;= 10^4</code></li>
	<li><code>parent.length == nodes</code></li>
	<li><code>0 &lt;= parent[i] &lt;= nodes - 1</code></li>
	<li><code>parent[0] == -1</code>&nbsp;which indicates that <code>0</code> is the root.</li>
	<li><code>value.length == nodes</code></li>
	<li><code>-10^5 &lt;= value[i] &lt;= 10^5</code></li>
	<li>The given input is <strong>guaranteed</strong> to represent a <strong>valid tree</strong>.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/delete-tree-nodes/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    vector<vector<int>> G;
    pair<int, int> dfs(int u, vector<int> &value) {
        int sum = value[u], cnt = 1;
        for (int v : G[u]) {
            auto [c, s] = dfs(v, value);
            sum += s;
            cnt += c;
        }
        if (sum == 0) cnt = 0;
        return { cnt, sum };
    }
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        G.assign(nodes, {});
        for (int i = 1; i < nodes; ++i) {
            G[parent[i]].push_back(i);
        }
        return dfs(0, value).first;
    }
};
```