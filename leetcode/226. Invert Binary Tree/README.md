# [226. Invert Binary Tree (Easy)](https://leetcode.com/problems/invert-binary-tree/)

<p>Invert a binary tree.</p>

<p><strong>Example:</strong></p>

<p>Input:</p>

<pre>     4
   /   \
  2     7
 / \   / \
1   3 6   9</pre>

<p>Output:</p>

<pre>     4
   /   \
  7     2
 / \   / \
9   6 3   1</pre>

<p><strong>Trivia:</strong><br>
This problem was inspired by <a href="https://twitter.com/mxcl/status/608682016205344768" target="_blank">this original tweet</a> by <a href="https://twitter.com/mxcl" target="_blank">Max Howell</a>:</p>

<blockquote>Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.</blockquote>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/invert-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```