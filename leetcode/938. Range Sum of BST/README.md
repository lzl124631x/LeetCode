# [938. Range Sum of BST (Easy)](https://leetcode.com/problems/transpose-matrix/)

Given the `root` node of a binary search tree, return the sum of values of all nodes with value between `L` and `R` (inclusive).

The binary search tree is guaranteed to have unique values.

**Example 1:**

**Input:** root = \[10,5,15,3,7,null,18\], L = 7, R = 15  
**Output:** 32

**Example 2:**

**Input:** root = \[10,5,15,3,7,13,18,1,null,6\], L = 6, R = 10  
**Output:** 23

**Note:**

1.  The number of nodes in the tree is at most `10000`.
2.  The final answer is guaranteed to be less than `2^31`.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/transpose-matrix/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        return (root->val >= L && root->val <= R ? root->val : 0) + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
};
```