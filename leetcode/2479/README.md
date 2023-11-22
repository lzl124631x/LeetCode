# [2479. Maximum XOR of Two Non-Overlapping Subtrees (Hard)](https://leetcode.com/problems/maximum-xor-of-two-non-overlapping-subtrees)

<p>There is an undirected tree with <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code>. You are given the integer <code>n</code> and a 2D integer array <code>edges</code> of length <code>n - 1</code>, where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree. The root of the tree is the node labeled <code>0</code>.</p>

<p>Each node has an associated <strong>value</strong>. You are given an array <code>values</code> of length <code>n</code>, where <code>values[i]</code> is the <strong>value</strong> of the <code>i<sup>th</sup></code> node.</p>

<p>Select any two <strong>non-overlapping</strong> subtrees. Your <strong>score</strong> is the bitwise XOR of the sum of the values within those subtrees.</p>

<p>Return <em>the</em> <em><strong>maximum</strong></em> <i>possible <strong>score</strong> you can achieve</i>. <em>If it is impossible to find two nonoverlapping subtrees</em>, return <code>0</code>.</p>

<p><strong>Note</strong> that:</p>

<ul>
	<li>The <strong>subtree</strong> of a node is the tree consisting of that node and all of its descendants.</li>
	<li>Two subtrees are <strong>non-overlapping </strong>if they do not share <strong>any common</strong> node.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/11/22/treemaxxor.png" style="width: 346px; height: 249px;" />
<pre>
<strong>Input:</strong> n = 6, edges = [[0,1],[0,2],[1,3],[1,4],[2,5]], values = [2,8,3,6,2,5]
<strong>Output:</strong> 24
<strong>Explanation:</strong> Node 1&#39;s subtree has sum of values 16, while node 2&#39;s subtree has sum of values 8, so choosing these nodes will yield a score of 16 XOR 8 = 24. It can be proved that is the maximum possible score we can obtain.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/11/22/tree3drawio.png" style="width: 240px; height: 261px;" />
<pre>
<strong>Input:</strong> n = 3, edges = [[0,1],[1,2]], values = [4,6,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no possible way to select two non-overlapping subtrees, so we just return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>values.length == n</code></li>
	<li><code>1 &lt;= values[i] &lt;= 10<sup>9</sup></code></li>
	<li>It is guaranteed that <code>edges</code> represents a valid tree.</li>
</ul>


**Companies**:
[Directi](https://leetcode.com/company/directi), [Media.net](https://leetcode.com/company/medianet)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree), [Depth-First Search](https://leetcode.com/tag/depth-first-search), [Graph](https://leetcode.com/tag/graph), [Trie](https://leetcode.com/tag/trie)

**Hints**:
* Try to build the answer bit by bit from the most significant bit to the least significant.
* Use the Trie Data Structure to decide for each bit if it exists in the final answer.

## Solution 1.

Given a subtree sum, Trie can help us quickly find the maxXor.

But how do we exclude the nodes that are ancestors or descendent of the current node? I found that we can use a mix of pre-order and post-order traversal:

* First of all, we precompute the subtree sum of a node `u` as `sum[u]`.
* Then, we do the mixed pre/post-order traversal.
  * When visiting a node `u`, we use Trie to calcuate the maxXor value corresponding to `sum[u]`. (This is the pre-order part)
  * We DFS to node `u`'s decendents.
  * Then, we add `sum[u]` to the Trie. (This is the post-order part)

```cpp
// OJ: https://leetcode.com/problems/maximum-xor-of-two-non-overlapping-subtrees
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
struct TrieNode {
    TrieNode *next[2] = {};
};
class Solution {
    void addNumber(TrieNode *node, long long n) {
        for (int i = 63; i >= 0; --i) {
            long long b = n >> i & 1;
            if (!node->next[b]) node->next[b] = new TrieNode();
            node = node->next[b];
        }
    }
    long long getMaxXor(TrieNode *node, long long n) {
        long long ans = 0;
        for (int i = 63; i >= 0; --i) {
            long long b = n >> i & 1, r = 1 - b;
            if (node->next[r]) node = node->next[r], ans |= (1LL << i);
            else if (node->next[b]) node = node->next[b];
            else return 0;
        }
        return ans;
    }
public:
    long long maxXor(int n, vector<vector<int>>& E, vector<int>& A) {
        vector<vector<int>> G(n);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        TrieNode root;
        unordered_map<int, long long> sum;
        function<long long(int, int)> getSubTreeSum = [&](int u, int prev) -> long long {
            long long ans = A[u];
            for (int v : G[u]) {
                if (v == prev) continue;
                ans += getSubTreeSum(v, u);
            }
            return sum[u] = ans;
        };
        getSubTreeSum(0, -1);
        long long ans = 0;
        function<void(int, int)> dfs = [&](int u, int prev) {
            ans = max(ans, getMaxXor(&root, sum[u]));
            for (int v : G[u]) {
                if (v == prev) continue;
                dfs(v, u);
            }
            addNumber(&root, sum[u]);
        };
        dfs(0, -1);
        return ans;
    }
};
```