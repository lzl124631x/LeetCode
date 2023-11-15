# [2458. Height of Binary Tree After Subtree Removal Queries (Hard)](https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries)

<p>You are given the <code>root</code> of a <strong>binary tree</strong> with <code>n</code> nodes. Each node is assigned a unique value from <code>1</code> to <code>n</code>. You are also given an array <code>queries</code> of size <code>m</code>.</p>

<p>You have to perform <code>m</code> <strong>independent</strong> queries on the tree where in the <code>i<sup>th</sup></code> query you do the following:</p>

<ul>
	<li><strong>Remove</strong> the subtree rooted at the node with the value <code>queries[i]</code> from the tree. It is <strong>guaranteed</strong> that <code>queries[i]</code> will <strong>not</strong> be equal to the value of the root.</li>
</ul>

<p>Return <em>an array </em><code>answer</code><em> of size </em><code>m</code><em> where </em><code>answer[i]</code><em> is the height of the tree after performing the </em><code>i<sup>th</sup></code><em> query</em>.</p>

<p><strong>Note</strong>:</p>

<ul>
	<li>The queries are independent, so the tree returns to its <strong>initial</strong> state after each query.</li>
	<li>The height of a tree is the <strong>number of edges in the longest simple path</strong> from the root to some node in the tree.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/09/07/binaryytreeedrawio-1.png" style="width: 495px; height: 281px;" />
<pre>
<strong>Input:</strong> root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
<strong>Output:</strong> [2]
<strong>Explanation:</strong> The diagram above shows the tree after removing the subtree rooted at node with value 4.
The height of the tree is 2 (The path 1 -&gt; 3 -&gt; 2).
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/09/07/binaryytreeedrawio-2.png" style="width: 301px; height: 284px;" />
<pre>
<strong>Input:</strong> root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
<strong>Output:</strong> [3,2,3,2]
<strong>Explanation:</strong> We have the following queries:
- Removing the subtree rooted at node with value 3. The height of the tree becomes 3 (The path 5 -&gt; 8 -&gt; 2 -&gt; 4).
- Removing the subtree rooted at node with value 2. The height of the tree becomes 2 (The path 5 -&gt; 8 -&gt; 1).
- Removing the subtree rooted at node with value 4. The height of the tree becomes 3 (The path 5 -&gt; 8 -&gt; 2 -&gt; 6).
- Removing the subtree rooted at node with value 8. The height of the tree becomes 2 (The path 5 -&gt; 9 -&gt; 3).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is <code>n</code>.</li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= Node.val &lt;= n</code></li>
	<li>All the values in the tree are <strong>unique</strong>.</li>
	<li><code>m == queries.length</code></li>
	<li><code>1 &lt;= m &lt;= min(n, 10<sup>4</sup>)</code></li>
	<li><code>1 &lt;= queries[i] &lt;= n</code></li>
	<li><code>queries[i] != root.val</code></li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Tree](https://leetcode.com/tag/tree), [Depth-First Search](https://leetcode.com/tag/depth-first-search), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search), [Binary Tree](https://leetcode.com/tag/binary-tree)

**Similar Questions**:
* [Maximum Depth of Binary Tree (Easy)](https://leetcode.com/problems/maximum-depth-of-binary-tree)

**Hints**:
* Try pre-computing the answer for each node from 1 to n, and answer each query in O(1).
* The answers can be precomputed in a single tree traversal after computing the height of each subtree.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries
// Author: github.com/lzl124631x
// Time: O(N + Q)
// Space: O(N)
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& Q) {
        vector<vector<int>> nodes;
        unordered_map<int, int> height, subTreeHeight, result;
        function<void(TreeNode*, int)> fillHeights = [&](TreeNode *n, int h) {
            height[n->val] = h;
            if (n->left) fillHeights(n->left, h + 1);
            if (n->right) fillHeights(n->right, h + 1);
        };
        fillHeights(root, 0); // height[nodeValue] is the depth of the node from root. Root's depth is 0.
        function<int(TreeNode*)> fillSubTreeHeights = [&](TreeNode *n) {
            if (!n) return 0;
            return subTreeHeight[n->val] = max({height[n->val], fillSubTreeHeights(n->left), fillSubTreeHeights(n->right) });
        };
        fillSubTreeHeights(root); // subTreeHeight[nodeValue] is the maximum height value of the subtree rooted at the node with nodeValue.
        function<void(TreeNode *)> fillNodes = [&](TreeNode *r) {
            int lv = 0;
            queue<TreeNode*> q{{r}};
            while (q.size()) {
                int cnt = q.size();
                nodes.emplace_back();
                while (cnt--) {
                    auto n = q.front();
                    q.pop();
                    nodes.back().push_back(n->val);
                    if (n->left) q.push(n->left);
                    if (n->right) q.push(n->right);
                }
            }
        };
        fillNodes(root); // Level-order traversal to store the node values layer by layer.
        for (int i = nodes.size() - 1; i >= 0; --i) { // for each layer
            stack<int> s; // we use monostack to track the maximum subTreeHeight of the nodes to the right
            int leftMax = 0; // leftMax tracks the maximum subTreeHeight of the nodes to the left
            for (int j = nodes[i].size() - 1; j >= 0; --j) {
                if (s.empty() || subTreeHeight[nodes[i][j]] >= subTreeHeight[s.top()]) s.push(nodes[i][j]);
            }
            for (int j = 0; j < nodes[i].size(); ++j) {
                if (s.size() && s.top() == nodes[i][j]) s.pop();
                result[nodes[i][j]] = max({leftMax, height[nodes[i][j]] - 1, s.size() ? subTreeHeight[s.top()] : 0}); // the result corresponding to the current node value is max of leftMax, height[nodeValue] - 1 and rightMax, where rightMax = subTreeHeight[s.top()]
                leftMax = max(leftMax, subTreeHeight[nodes[i][j]]);
            }
        }
        vector<int> ans(Q.size());
        for (int i = 0; i < Q.size(); ++i) ans[i] = result[Q[i]];
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries
// Author: github.com/lzl124631x
// Time: O(N + Q)
// Space: O(N)
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& Q) {
        unordered_map<TreeNode*, int> depth, height;
        unordered_map<int, int> m;
        function<int(TreeNode*, int)> dfs = [&](TreeNode *root, int d) {
            if (!root) return d - 1;
            depth[root] = d;
            return height[root] = max(dfs(root->left, d + 1), dfs(root->right, d + 1));
        };
        dfs(root, 0);
        deque<TreeNode*> q{root};
        while (q.size()) {
            int cnt = q.size(), maxLeft = -1;
            stack<TreeNode*> s;
            while (cnt--) {
                auto n = q.back();
                q.pop_back();
                q.push_front(n);
                if (s.empty() || height[s.top()] < height[n]) s.push(n);
            }
            cnt = q.size();
            while (cnt--) {
                auto n = q.front();
                q.pop_front();
                if (s.size() && s.top() == n) s.pop();
                int maxRight = s.size() ? height[s.top()] : -1;
                m[n->val] = max(maxLeft, maxRight);
                if (m[n->val] == -1) m[n->val] = depth[n] - 1;
                maxLeft = max(maxLeft, height[n]);
                if (n->left) q.push_back(n->left);
                if (n->right) q.push_back(n->right);
            }
        }
        vector<int> ans;
        for (int q : Q) ans.push_back(m[q]);
        return ans;
    }
};
```