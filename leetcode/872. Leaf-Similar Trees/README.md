# [872. Leaf-Similar Trees (Easy)](https://leetcode.com/problems/leaf-similar-trees/)

<p>Consider all the leaves of a binary tree.&nbsp; From&nbsp;left to right order, the values of those&nbsp;leaves form a <em>leaf value sequence.</em></p>

<p><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png" style="width: 300px; height: 240px;"></p>

<p>For example, in the given tree above, the leaf value sequence is <code>(6, 7, 4, 9, 8)</code>.</p>

<p>Two binary trees are considered <em>leaf-similar</em>&nbsp;if their leaf value sequence is the same.</p>

<p>Return <code>true</code> if and only if the two given trees with head nodes <code>root1</code> and <code>root2</code> are leaf-similar.</p>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ul>
	<li>Both of the given trees will have between <code>1</code> and <code>100</code> nodes.</li>
</ul>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/leaf-similar-trees/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    void dfs(TreeNode *root, vector<int> &v) {
        if (!root) return;
        if (!root->left && !root->right) v.push_back(root->val);
        dfs(root->left, v);
        dfs(root->right, v);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        dfs(root1, a);
        dfs(root2, b);
        return a == b;
    }
};
```