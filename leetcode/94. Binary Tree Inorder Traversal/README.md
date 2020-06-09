# [94. Binary Tree Inorder Traversal (Medium)](https://leetcode.com/problems/binary-tree-inorder-traversal/)

<p>Given a binary tree, return the <em>inorder</em> traversal of its nodes' values.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> [1,null,2,3]
   1
    \
     2
    /
   3

<strong>Output:</strong> [1,3,2]</pre>

<p><strong>Follow up:</strong> Recursive solution is trivial, could you do it iteratively?</p>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Validate Binary Search Tree (Medium)](https://leetcode.com/problems/validate-binary-search-tree/)
* [Binary Tree Preorder Traversal (Medium)](https://leetcode.com/problems/binary-tree-preorder-traversal/)
* [Binary Tree Postorder Traversal (Hard)](https://leetcode.com/problems/binary-tree-postorder-traversal/)
* [Binary Search Tree Iterator (Medium)](https://leetcode.com/problems/binary-search-tree-iterator/)
* [Kth Smallest Element in a BST (Medium)](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
* [Closest Binary Search Tree Value II (Hard)](https://leetcode.com/problems/closest-binary-search-tree-value-ii/)
* [Inorder Successor in BST (Medium)](https://leetcode.com/problems/inorder-successor-in-bst/)
* [Convert Binary Search Tree to Sorted Doubly Linked List (Medium)](https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/)
* [Minimum Distance Between BST Nodes (Easy)](https://leetcode.com/problems/minimum-distance-between-bst-nodes/)

## Solution 1. Recursive

```cpp
// OJ: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    vector<int> ans;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```

## Solution 2. Iterative

```cpp
// OJ: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while (root || s.size()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};
```