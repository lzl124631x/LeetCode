# [285. Inorder Successor in BST (Medium)](https://leetcode.com/problems/inorder-successor-in-bst/)

<p>Given a binary search tree and a node in it, find the in-order successor of that node in the BST.</p>

<p><b>Note</b>: If the given node has no in-order successor in the tree, return <code>null</code>.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> root = <code>[2,1,3], p = 1

  2
 / \
1   3
</code>
<b>Output:</b> 2</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> root = <code>[5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /   
1
</code>
<b>Output:</b> null</pre>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft), [Palantir Technologies](https://leetcode.com/company/palantir-technologies), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Binary Tree Inorder Traversal (Medium)](https://leetcode.com/problems/binary-tree-inorder-traversal/)
* [Binary Search Tree Iterator (Medium)](https://leetcode.com/problems/binary-search-tree-iterator/)

## Solution 1. Recursive

```cpp
// OJ: https://leetcode.com/problems/inorder-successor-in-bst/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
    TreeNode *target, *ans = NULL;
    bool seen = false;
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        if (seen && !ans) ans = root;
        if (seen && ans) return;
        if (root == target) seen = true;
        inorder(root->right);
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        target = p;
        inorder(root);
        return ans;
    }
};
```

## Solution 2.

Solution 1 doesn't take advantage of BST. Try to find the smallest number greater than `p->val`.

```cpp
// OJ: https://leetcode.com/problems/inorder-successor-in-bst/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
// Ref: https://leetcode.com/problems/inorder-successor-in-bst/discuss/72721/10-(and-4)-lines-O(h)-JavaC%2B%2B
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *best = NULL;
        while (root) {
            root = root->val > p->val ? (best = root)->left : root->right;
        }
        return best;
    }
};
```