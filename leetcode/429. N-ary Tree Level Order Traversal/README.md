# [429. N-ary Tree Level Order Traversal (Easy)](https://leetcode.com/problems/n-ary-tree-level-order-traversal/)

<p>Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).</p>

<p>For example, given a <code>3-ary</code> tree:</p>

<p>&nbsp;</p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="width: 100%; max-width: 300px;"></p>

<p>&nbsp;</p>

<p>We should return its level order traversal:</p>

<pre>[
     [1],
     [3,2,4],
     [5,6]
]
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>The depth of the tree is at most <code>1000</code>.</li>
	<li>The total number of nodes is at most <code>5000</code>.</li>
</ol>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while (q.size()) {
            int cnt = q.size();
            vector<int> level;
            while (cnt--) {
                root = q.front();
                q.pop();
                level.push_back(root->val);
                for (Node *node : root->children) q.push(node);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
```