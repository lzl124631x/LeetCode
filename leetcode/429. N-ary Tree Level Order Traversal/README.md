# [429. N-ary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/n-ary-tree-level-order-traversal)

<p>Given an n-ary tree, return the <em>level order</em> traversal of its nodes' values.</p>
<p><em>Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<p><img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="width: 100%; max-width: 300px;"></p>
<pre><strong>Input:</strong> root = [1,null,3,2,4,null,5,6]
<strong>Output:</strong> [[1],[3,2,4],[5,6]]
</pre>
<p><strong class="example">Example 2:</strong></p>
<p><img alt="" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" style="width: 296px; height: 241px;"></p>
<pre><strong>Input:</strong> root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>Output:</strong> [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li>The height of the n-ary tree is less than or equal to <code>1000</code></li>
	<li>The total number of nodes is between <code>[0, 10<sup>4</sup>]</code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Binary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-level-order-traversal/)
* [N-ary Tree Preorder Traversal (Easy)](https://leetcode.com/problems/n-ary-tree-preorder-traversal/)
* [N-ary Tree Postorder Traversal (Easy)](https://leetcode.com/problems/n-ary-tree-postorder-traversal/)
* [The Time When the Network Becomes Idle (Medium)](https://leetcode.com/problems/the-time-when-the-network-becomes-idle/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<Node*> q{{root}};
        while (q.size()) {
            int cnt = q.size();
            vector<int> level;
            while (cnt--) {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);
                for (auto &child : node->children) q.push(child);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    vector<vector<int>> ans;
    void dfs(Node *root, int level) {
        if (!root) return;
        if (level >= ans.size()) ans.emplace_back();
        ans[level].push_back(root->val);
        for (auto &child : root->children) dfs(child, level + 1);
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        dfs(root, 0);
        return ans;
    }
};
```