# [250. Count Univalue Subtrees (Medium)](https://leetcode.com/problems/count-univalue-subtrees/)

<p>Given a binary tree, count the number of uni-value subtrees.</p>

<p>A Uni-value subtree means all nodes of the subtree have the same value.</p>

<p><b>Example :</b></p>

<pre><b>Input:</b>  root = [5,1,5,5,5,null,5]

              5
             / \
            1   5
           / \   \
          5   5   5

<b>Output:</b> 4
</pre>


**Companies**:  
[Box](https://leetcode.com/company/box), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Subtree of Another Tree (Easy)](https://leetcode.com/problems/subtree-of-another-tree/)
* [Longest Univalue Path (Easy)](https://leetcode.com/problems/longest-univalue-path/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-univalue-subtrees/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H) where H is the height of the tree
class Solution {
private:
    int cnt = 0;
    bool postorder(TreeNode *root) {
        if (!root) return true;
        bool left = postorder(root->left), right = postorder(root->right);
        if (left && right
            && (!root->left || root->val == root->left->val)
            && (!root->right || root->val == root->right->val)) {
            ++cnt;
            return true;
        }
        return false;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        postorder(root);
        return cnt;
    }
};
```