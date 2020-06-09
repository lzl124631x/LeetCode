# [145. Binary Tree Postorder Traversal (Hard)](https://leetcode.com/problems/binary-tree-postorder-traversal/)

<p>Given a binary tree, return the <em>postorder</em> traversal of its nodes' values.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong>&nbsp;<code>[1,null,2,3]</code>
   1
    \
     2
    /
   3

<strong>Output:</strong>&nbsp;<code>[3,2,1]</code>
</pre>

<p><strong>Follow up:</strong> Recursive solution is trivial, could you do it iteratively?</p>


**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Binary Tree Inorder Traversal (Medium)](https://leetcode.com/problems/binary-tree-inorder-traversal/)
* [N-ary Tree Postorder Traversal (Easy)](https://leetcode.com/problems/n-ary-tree-postorder-traversal/)

## Solution 1. Recursive

```cpp
// OJ: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    vector<int> ans;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        dfs(root->right);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```

## Solution 2. Iterative

```cpp
// OJ: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode *prev = NULL;
        while (root || s.size()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            if (!root->right || root->right == prev) {
                ans.push_back(root->val);
                s.pop();
                prev = root;
                root = NULL;
            } else root = root->right;
        }
        return ans;
    }
};
```