# [156. Binary Tree Upside Down (Medium)](https://leetcode.com/problems/binary-tree-upside-down/)

<p>Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input: </strong>[1,2,3,4,5]

    1
   / \
  2   3
 / \
4   5

<strong>Output:</strong> return the root of the binary tree [4,5,2,#,#,3,1]

   4
  / \
 5   2
    / \
   3   1  
</pre>

<p><strong>Clarification:</strong></p>

<p>Confused what <code>[4,5,2,#,#,3,1<font face="monospace">]</font></code>&nbsp;means? Read more below on how binary tree is serialized on OJ.</p>

<p>The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.</p>

<p>Here's an example:</p>

<pre>   1
  / \
 2   3
    /
   4
    \
     5
</pre>

<p>The above binary tree is serialized as <code>[1,2,3,#,#,4,#,#,5]</code>.</p>


**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Reverse Linked List (Easy)](https://leetcode.com/problems/reverse-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/binary-tree-upside-down/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left) return root;
        TreeNode *left = root->left, *right = root->right, *newRoot = NULL;
        while (left) {
            TreeNode *nextLeft = left->left, *nextRight = left->right;
            if (!newRoot) root->left = root->right = NULL;
            newRoot = left;
            newRoot->left = right;
            newRoot->right = root;
            root = left;
            left = nextLeft;
            right = nextRight;
        }
        return newRoot;
    }
};
```