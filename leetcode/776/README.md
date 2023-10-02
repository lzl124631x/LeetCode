# [776. Split BST (Medium)](https://leetcode.com/problems/split-bst)

<p>Given the <code>root</code> of a binary search tree (BST) and an integer <code>target</code>, split the tree into two subtrees where one subtree has nodes that are all smaller or equal to the target value, while the other subtree has all nodes that are greater than the target value. It Is not necessarily the case that the tree contains a node with the value <code>target</code>.</p>
<p>Additionally, most of the structure of the original tree should remain. Formally, for any child <code>c</code> with parent <code>p</code> in the original tree, if they are both in the same subtree after the split, then node <code>c</code> should still have the parent <code>p</code>.</p>
<p>Return <em>an array of the two roots of the two subtrees</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/split-tree.jpg" style="width: 600px; height: 193px;">
<pre><strong>Input:</strong> root = [4,2,6,1,3,5,7], target = 2
<strong>Output:</strong> [[2,1],[4,3,6,null,null,5,7]]
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> root = [1], target = 1
<strong>Output:</strong> [[1],[]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 50]</code>.</li>
	<li><code>0 &lt;= Node.val, target &lt;= 1000</code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Coupang](https://leetcode.com/company/coupang)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Recursion](https://leetcode.com/tag/recursion/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Delete Node in a BST (Medium)](https://leetcode.com/problems/delete-node-in-a-bst/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/split-bst
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        TreeNode *left = nullptr, *right = nullptr;
        function<void(TreeNode*, TreeNode*)> add = [&](TreeNode *root, TreeNode *n) {
            if (n->val > root->val) {
                if (root->right) add(root->right, n);
                else root->right = n;
            } else {
                if (root->left) add(root->left, n);
                else root->left = n;
            }
        };
        function<void(TreeNode*)> dfs = [&](TreeNode *root) {
            if (!root) return;
            auto L = root->left, R = root->right;
            root->left = root->right = nullptr;
            if (root->val <= target) {
                if (!left) left = root;
                else add(left, root);
            } else {
                if (!right) right = root;
                else add(right, root);
            }
            dfs(L);
            dfs(R);
        };
        dfs(root);
        return {left, right};
    }
};
```

## Solution 2. Recursion

```cpp
// OJ: https://leetcode.com/problems/split-bst
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        if (!root) return {nullptr, nullptr};
        if (root->val == target) {
            auto r = root->right;
            root->right = nullptr;
            return {root, r};
        }
        if (root->val < target) {
            auto v = splitBST(root->right, target);
            root->right = v[0];
            return {root, v[1]};
        } else {
            auto v = splitBST(root->left, target);
            root->left = v[1];
            return {v[0], root};
        }
    }
};
```