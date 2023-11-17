# [2322. Minimum Score After Removals on a Tree (Hard)](https://leetcode.com/problems/minimum-score-after-removals-on-a-tree)

<p>There is an undirected connected tree with <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code> and <code>n - 1</code> edges.</p>

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code> where <code>nums[i]</code> represents the value of the <code>i<sup>th</sup></code> node. You are also given a 2D integer array <code>edges</code> of length <code>n - 1</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree.</p>

<p>Remove two <strong>distinct</strong> edges of the tree to form three connected components. For a pair of removed edges, the following steps are defined:</p>

<ol>
	<li>Get the XOR of all the values of the nodes for <strong>each</strong> of the three components respectively.</li>
	<li>The <strong>difference</strong> between the <strong>largest</strong> XOR value and the <strong>smallest</strong> XOR value is the <strong>score</strong> of the pair.</li>
</ol>

<ul>
	<li>For example, say the three components have the node values: <code>[4,5,7]</code>, <code>[1,9]</code>, and <code>[3,3,3]</code>. The three XOR values are <code>4 ^ 5 ^ 7 = <u><strong>6</strong></u></code>, <code>1 ^ 9 = <u><strong>8</strong></u></code>, and <code>3 ^ 3 ^ 3 = <u><strong>3</strong></u></code>. The largest XOR value is <code>8</code> and the smallest XOR value is <code>3</code>. The score is then <code>8 - 3 = 5</code>.</li>
</ul>

<p>Return <em>the <strong>minimum</strong> score of any possible pair of edge removals on the given tree</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/05/03/ex1drawio.png" style="width: 193px; height: 190px;" />
<pre>
<strong>Input:</strong> nums = [1,5,5,4,11], edges = [[0,1],[1,2],[1,3],[3,4]]
<strong>Output:</strong> 9
<strong>Explanation:</strong> The diagram above shows a way to make a pair of removals.
- The 1<sup>st</sup> component has nodes [1,3,4] with values [5,4,11]. Its XOR value is 5 ^ 4 ^ 11 = 10.
- The 2<sup>nd</sup> component has node [0] with value [1]. Its XOR value is 1 = 1.
- The 3<sup>rd</sup> component has node [2] with value [5]. Its XOR value is 5 = 5.
The score is the difference between the largest and smallest XOR value which is 10 - 1 = 9.
It can be shown that no other pair of removals will obtain a smaller score than 9.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/05/03/ex2drawio.png" style="width: 287px; height: 150px;" />
<pre>
<strong>Input:</strong> nums = [5,5,2,4,4,2], edges = [[0,1],[1,2],[5,2],[4,3],[1,3]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The diagram above shows a way to make a pair of removals.
- The 1<sup>st</sup> component has nodes [3,4] with values [4,4]. Its XOR value is 4 ^ 4 = 0.
- The 2<sup>nd</sup> component has nodes [1,0] with values [5,5]. Its XOR value is 5 ^ 5 = 0.
- The 3<sup>rd</sup> component has nodes [2,5] with values [2,2]. Its XOR value is 2 ^ 2 = 0.
The score is the difference between the largest and smallest XOR value which is 0 - 0 = 0.
We cannot obtain a smaller score than 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>3 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>edges</code> represents a valid tree.</li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation), [Tree](https://leetcode.com/tag/tree), [Depth-First Search](https://leetcode.com/tag/depth-first-search)

**Hints**:
* Consider iterating over the first edge to remove, and then doing some precalculations on the 2 resulting connected components.
* Will calculating the XOR of each subtree help?

## Solution 1.

* BFS from all leaf nodes inward. Node `a` is a child of node `b` if `a` is in the path from `b` to a leaf node during the BFS.
* Use bitmask to track the parent-child relationship. `children[u]` is a bitmask of all its children.
* `treeXor[u]` is the XOR value of all the nodes in the subtree rooted at `u`.
* Try each pairs of edge `(a,b)` and edge `(c,d)`. Based on the parent-child relationships between these 4 nodes, calculate the XOR values of the 3 parts.

```cpp
// OJ: https://leetcode.com/problems/minimum-score-after-removals-on-a-tree
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
// Ref: https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/solutions/2198665/python-3-explanation-with-pictures/
class Solution {
public:
    int minimumScore(vector<int>& A, vector<vector<int>>& E) {
        int N = A.size(), totalXor = 0;
        vector<vector<int>> G(N);
        vector<bitset<1000>> children(N);
        vector<int> treeXor = A, degree(N), seen(N); // treeXor[u] is the XOR value of all the nodes in the subtree rooted at `u`.
        for (auto &e : E) { // Build graph and cound degrees
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> q; // Traverse nodes from all leaves inward
        for (int i = 0; i < N; ++i) {
            totalXor ^= A[i];
            if (degree[i] == 1) q.push(i), seen[i] = 1;
        }
        while (q.size()) { // Calculate children[u] and treeXor[u]
            int u = q.front();
            q.pop();
            for (int v : G[u]) {
                if (seen[v]) continue;
                children[v].set(u);
                children[v] |= children[u];
                treeXor[v] ^= treeXor[u];
                if (--degree[v] == 1) {
                    seen[v] = 1;
                    q.push(v);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < N - 1; ++i) { // Try the first edge
            int a = E[i][0], b = E[i][1];
            if (children[a].test(b)) swap(a, b); // Make sure `a` is always a child of `b`.
            for (int j = 0; j < i; ++j) { // Try the second edge
                int c = E[j][0], d = E[j][1];
                if (children[c].test(d)) swap(c, d); // Make sure `c` is always a child of `d`
                array<int, 3> score;
                if (children[a].test(c)) score = {treeXor[c], treeXor[a] ^ treeXor[c], totalXor ^ treeXor[a] };
                else if (children[c].test(a)) score = {treeXor[a], treeXor[a] ^ treeXor[c], totalXor ^ treeXor[c] };
                else score = {treeXor[a], treeXor[c], treeXor[a] ^ treeXor[c] ^ totalXor };
                ans = min(ans, *max_element(begin(score), end(score)) - *min_element(begin(score), end(score)));
            }
        }
        return ans;
    }
};
```

## Solution 2. DFS

Similar to solution 1, but here we use DFS to calculate `treeXor` (as `X`) and `children` (as `C`).

```cpp
// OJ: https://leetcode.com/problems/minimum-score-after-removals-on-a-tree
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int minimumScore(vector<int>& A, vector<vector<int>>& E) {
        int N = A.size(), ans = INT_MAX;
        vector<vector<int>> G(N);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> X(N);
        vector<bitset<1000>> C(N);
        function<void(int, int)> dfs = [&](int u, int prev) {
            X[u] ^= A[u];
            C[u].set(u);
            for (int v : G[u]) {
                if (v == prev) continue;
                dfs(v, u);
                X[u] ^= X[v];
                C[u] |= C[v];
            }
        };
        dfs(0, -1);
        for (int i = 0; i < N - 1; ++i) {
            int a = E[i][0], b = E[i][1];
            if (C[b].test(a)) swap(a, b);
            for (int j = 0; j < i; ++j) {
                int c = E[j][0], d = E[j][1];
                if (C[d].test(c)) swap(c, d);
                array<int, 3> v;
                if (C[b].test(c)) v = {X[d], X[b] ^ X[d], X[0] ^ X[b]};
                else if (C[d].test(a)) v = {X[b], X[d] ^ X[b], X[0] ^ X[d]};
                else v = {X[b], X[d], X[0] ^ X[b] ^ X[d]};
                ans = min(ans, *max_element(begin(v), end(v)) - *min_element(begin(v), end(v)));
            }
        }
        return ans;
    }
};
```