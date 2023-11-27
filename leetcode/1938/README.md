# [1938. Maximum Genetic Difference Query (Hard)](https://leetcode.com/problems/maximum-genetic-difference-query)

<p>There is a rooted tree consisting of <code>n</code> nodes numbered <code>0</code> to <code>n - 1</code>. Each node&#39;s number denotes its <strong>unique genetic value</strong> (i.e. the genetic value of node <code>x</code> is <code>x</code>). The <strong>genetic difference</strong> between two genetic values is defined as the <strong>bitwise-</strong><strong>XOR</strong> of their values. You are given the integer array <code>parents</code>, where <code>parents[i]</code> is the parent for node <code>i</code>. If node <code>x</code> is the <strong>root</strong> of the tree, then <code>parents[x] == -1</code>.</p>

<p>You are also given the array <code>queries</code> where <code>queries[i] = [node<sub>i</sub>, val<sub>i</sub>]</code>. For each query <code>i</code>, find the <strong>maximum genetic difference</strong> between <code>val<sub>i</sub></code> and <code>p<sub>i</sub></code>, where <code>p<sub>i</sub></code> is the genetic value of any node that is on the path between <code>node<sub>i</sub></code> and the root (including <code>node<sub>i</sub></code> and the root). More formally, you want to maximize <code>val<sub>i</sub> XOR p<sub>i</sub></code>.</p>

<p>Return <em>an array </em><code>ans</code><em> where </em><code>ans[i]</code><em> is the answer to the </em><code>i<sup>th</sup></code><em> query</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/29/c1.png" style="width: 118px; height: 163px;" />
<pre>
<strong>Input:</strong> parents = [-1,0,1,1], queries = [[0,2],[3,2],[2,5]]
<strong>Output:</strong> [2,3,7]
<strong>Explanation: </strong>The queries are processed as follows:
- [0,2]: The node with the maximum genetic difference is 0, with a difference of 2 XOR 0 = 2.
- [3,2]: The node with the maximum genetic difference is 1, with a difference of 2 XOR 1 = 3.
- [2,5]: The node with the maximum genetic difference is 2, with a difference of 5 XOR 2 = 7.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/29/c2.png" style="width: 256px; height: 221px;" />
<pre>
<strong>Input:</strong> parents = [3,7,-1,2,0,7,0,2], queries = [[4,6],[1,15],[0,5]]
<strong>Output:</strong> [6,14,7]
<strong>Explanation: </strong>The queries are processed as follows:
- [4,6]: The node with the maximum genetic difference is 0, with a difference of 6 XOR 0 = 6.
- [1,15]: The node with the maximum genetic difference is 1, with a difference of 15 XOR 1 = 14.
- [0,5]: The node with the maximum genetic difference is 2, with a difference of 5 XOR 2 = 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= parents.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= parents[i] &lt;= parents.length - 1</code> for every node <code>i</code> that is <strong>not</strong> the root.</li>
	<li><code>parents[root] == -1</code></li>
	<li><code>1 &lt;= queries.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= node<sub>i</sub> &lt;= parents.length - 1</code></li>
	<li><code>0 &lt;= val<sub>i</sub> &lt;= 2 * 10<sup>5</sup></code></li>
</ul>


**Companies**:
[Media.net](https://leetcode.com/company/medianet)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation), [Trie](https://leetcode.com/tag/trie)

**Similar Questions**:
* [Maximum XOR With an Element From Array (Hard)](https://leetcode.com/problems/maximum-xor-with-an-element-from-array)

**Hints**:
* How can we use a trie to store all the XOR values in the path from a node to the root?
* How can we dynamically add the XOR values with a DFS search?

## Solution 1. DFS + Trie

```cpp
// OJ: https://leetcode.com/problems/maximum-genetic-difference-query/
// Author: github.com/lzl124631x
// Time: O(P + Q)
// Space: O(P + Q)
struct TrieNode {
    TrieNode *next[2] = {};
    int cnt = 0;
};
class Solution {
    void addNumber(TrieNode *node, int n, int d) {
        for (int i = 17; i >= 0; --i) {
            int b = n >> i & 1;
            if (!node->next[b]) node->next[b] = new TrieNode();
            node = node->next[b];
            node->cnt += d;
        }
    }
    int maxDiff(TrieNode *node, int n) {
        int ans = 0;
        for (int i = 17; i >= 0; --i) {
            int b = n >> i & 1, r = 1 - b;
            if (node->next[r] && node->next[r]->cnt) node = node->next[r], ans |= (1 << i);
            else node = node->next[b];
        }
        return ans;
    }
public:
    vector<int> maxGeneticDifference(vector<int>& P, vector<vector<int>>& Q) {
        int N = P.size(), rootIndex;
        vector<vector<pair<int, int>>> Qs(N);
        for (int i = 0; i < Q.size(); ++i) Qs[Q[i][0]].emplace_back(i, Q[i][1]);
        vector<vector<int>> G(N);
        for (int i = 0; i < N; ++i) {
            if (P[i] == -1) rootIndex = i;
            else G[P[i]].push_back(i);
        }
        TrieNode root;
        vector<int> ans(Q.size());
        function<void(int, int)> dfs = [&](int u, int prev) {
            addNumber(&root, u, 1);
            for (auto &[idx, val] : Qs[u]) ans[idx] = maxDiff(&root, val);
            for (int v : G[u]) {
                if (v == prev) continue;
                dfs(v, u);
            }
            addNumber(&root, u, -1);
        };
        dfs(rootIndex, -1);
        return ans;
    }
};
```