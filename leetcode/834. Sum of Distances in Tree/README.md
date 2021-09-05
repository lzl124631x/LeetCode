# [834. Sum of Distances in Tree (Hard)](https://leetcode.com/problems/sum-of-distances-in-tree/)

<p>There is an undirected connected tree with <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code> and <code>n - 1</code> edges.</p>

<p>You are given the integer <code>n</code> and the array <code>edges</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree.</p>

<p>Return an array <code>answer</code> of length <code>n</code> where <code>answer[i]</code> is the sum of the distances between the <code>i<sup>th</sup></code> node in the tree and all other nodes.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-sumdist1.jpg" style="width: 304px; height: 224px;">
<pre><strong>Input:</strong> n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
<strong>Output:</strong> [8,12,6,10,10,10]
<strong>Explanation:</strong> The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-sumdist2.jpg" style="width: 64px; height: 65px;">
<pre><strong>Input:</strong> n = 1, edges = []
<strong>Output:</strong> [0]
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-sumdist3.jpg" style="width: 144px; height: 145px;">
<pre><strong>Input:</strong> n = 2, edges = [[1,0]]
<strong>Output:</strong> [1,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>The given input represents a valid tree.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Distribute Coins in Binary Tree (Medium)](https://leetcode.com/problems/distribute-coins-in-binary-tree/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/sum-of-distances-in-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    vector<vector<int>> G;
    vector<int> cnt, ans;
    int root = 0;
    int getSum(int u, int prev = -1, int d = 0) {
        int ans = d;
        for (int v : G[u]) {
            if (v == prev) continue;
            ans += getSum(v, u, d + 1);
        }
        return ans;
    }
    int updateCount(int u, int prev = -1) {
        int ans = 0;
        for (int v : G[u]) {
            if (v == prev) continue;
            ans += updateCount(v, u);
        }
        return cnt[u] = ans + 1;
    }
    void updateAns(int u, int prev = -1) {
        if (prev != -1) ans[u] = ans[prev] + cnt[root] - 2 * cnt[u];
        for (int v : G[u]) {
            if (v == prev) continue;
            updateAns(v, u);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& E) {
        if (n == 1) return {0};
        G.assign(n, vector<int>());
        cnt.assign(n, 0);
        ans.assign(n, 0);
        vector<int> indegree(n);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
            ++indegree[u];
            ++indegree[v];
        }
        for (; indegree[root] != 1; ++root); // pick a leaf node as root
        ans[root] = getSum(root); // get the sum of distances of this node `root`
        updateCount(root); // update the cnt[i] which is the number of nodes in the subtree with `i` as the subtree root
        updateAns(root); // update the answer: ans[u] = ans[prev] + cnt[root] - 2 * cnt[u]
        return ans;
    }
};
```


## TODO

Simplify code according to https://leetcode.com/problems/sum-of-distances-in-tree/solution/