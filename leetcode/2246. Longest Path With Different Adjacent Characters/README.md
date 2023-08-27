# [2246. Longest Path With Different Adjacent Characters (Hard)](https://leetcode.com/problems/longest-path-with-different-adjacent-characters)

<p>You are given a <strong>tree</strong> (i.e. a connected, undirected graph that has no cycles) <strong>rooted</strong> at node <code>0</code> consisting of <code>n</code> nodes numbered from <code>0</code> to <code>n - 1</code>. The tree is represented by a <strong>0-indexed</strong> array <code>parent</code> of size <code>n</code>, where <code>parent[i]</code> is the parent of node <code>i</code>. Since node <code>0</code> is the root, <code>parent[0] == -1</code>.</p>
<p>You are also given a string <code>s</code> of length <code>n</code>, where <code>s[i]</code> is the character assigned to node <code>i</code>.</p>
<p>Return <em>the length of the <strong>longest path</strong> in the tree such that no pair of <strong>adjacent</strong> nodes on the path have the same character assigned to them.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/25/testingdrawio.png" style="width: 201px; height: 241px;">
<pre><strong>Input:</strong> parent = [-1,0,0,1,1,2], s = "abacbe"
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest path where each two adjacent nodes have different characters in the tree is the path: 0 -&gt; 1 -&gt; 3. The length of this path is 3, so 3 is returned.
It can be proven that there is no longer path that satisfies the conditions. 
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/25/graph2drawio.png" style="width: 201px; height: 221px;">
<pre><strong>Input:</strong> parent = [-1,0,0,0], s = "aabc"
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest path where each two adjacent nodes have different characters is the path: 2 -&gt; 0 -&gt; 3. The length of this path is 3, so 3 is returned.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == parent.length == s.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= parent[i] &lt;= n - 1</code> for all <code>i &gt;= 1</code></li>
	<li><code>parent[0] == -1</code></li>
	<li><code>parent</code> represents a valid tree.</li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [HRT](https://leetcode.com/company/hrt)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/)

**Similar Questions**:
* [Diameter of Binary Tree (Easy)](https://leetcode.com/problems/diameter-of-binary-tree/)
* [Longest Univalue Path (Medium)](https://leetcode.com/problems/longest-univalue-path/)
* [Choose Edges to Maximize Score in a Tree (Medium)](https://leetcode.com/problems/choose-edges-to-maximize-score-in-a-tree/)

## Solution 1. Post-order DFS

```cpp
// OJ: https://leetcode.com/problems/longest-path-with-different-adjacent-characters
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestPath(vector<int>& P, string s) {
        int N = P.size(), ans = 0;
        vector<vector<int>> G(N);
        for (int i = 1; i < N; ++i) G[P[i]].push_back(i);
        function<int(int, int)> dfs = [&](int u, int prev) {
            int a = 0, b = 0;
            for (int v : G[u]) {
                if (v == prev) continue;
                int d = dfs(v, u);
                if (s[u] == s[v]) continue;
                if (d > a) b = a, a = d;
                else if (d > b) b = d;
            }
            ans = max(ans, 1 + a + b);
            return 1 + max(a, b);
        };
        dfs(0, -1);
        return ans;
    }
};
```