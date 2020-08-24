# [404. Sum of Left Leaves (Easy)](https://leetcode.com/problems/sum-of-left-leaves/)

<p>Find the sum of all left leaves in a given binary tree.</p>

<p><b>Example:</b>
</p><pre>    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values <b>9</b> and <b>15</b> respectively. Return <b>24</b>.
</pre>
<p></p>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/sum-of-left-leaves
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    int dfs(TreeNode *root, bool isLeftChild) {
        if (!root) return 0;
        if (!root->left && !root->right && isLeftChild) return root->val;
        return dfs(root->left, true) + dfs(root->right, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};
```