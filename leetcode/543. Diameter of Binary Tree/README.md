# [543. Diameter of Binary Tree (Easy)](https://leetcode.com/problems/diameter-of-binary-tree/)

<p>
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the <b>longest</b> path between any two nodes in a tree. This path may or may not pass through the root.
</p>

<p>
<b>Example:</b><br>
Given a binary tree <br>
</p><pre>          1
         / \
        2   3
       / \     
      4   5    
</pre>
<p></p>
<p>
Return <b>3</b>, which is the length of the path [4,2,1,3] or [5,2,1,3].
</p>

<p><b>Note:</b>
The length of path between two nodes is represented by the number of edges between them.
</p>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1. Post-order traversal

```cpp
// OJ: https://leetcode.com/problems/diameter-of-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int ans = 0;
    int postorder(TreeNode *root) {
        if (!root) return 0;
        int left = postorder(root->left), right = postorder(root->right);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        postorder(root);
        return ans;
    }
};
```