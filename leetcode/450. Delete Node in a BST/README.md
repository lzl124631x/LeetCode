# [450. Delete Node in a BST (Medium)](https://leetcode.com/problems/delete-node-in-a-bst/)

<p>Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.</p>

<p>Basically, the deletion can be divided into two stages:</p>

<ol>
	<li>Search for a node to remove.</li>
	<li>If the node is found, delete the node.</li>
</ol>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/04/del_node_1.jpg" style="width: 800px; height: 214px;">
<pre><strong>Input:</strong> root = [5,3,6,2,4,null,7], key = 3
<strong>Output:</strong> [5,4,6,2,null,null,7]
<strong>Explanation:</strong> Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/04/del_node_supp.jpg" style="width: 350px; height: 255px;">
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [5,3,6,2,4,null,7], key = 0
<strong>Output:</strong> [5,3,6,2,4,null,7]
<strong>Explanation:</strong> The tree does not contain a node with value = 0.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [], key = 0
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li>Each node has a <strong>unique</strong> value.</li>
	<li><code>root</code> is a valid binary search tree.</li>
	<li><code>-10<sup>5</sup> &lt;= key &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you solve it with time complexity <code>O(height of tree)</code>?</p>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [LinkedIn](https://leetcode.com/company/linkedin), [Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google), [Oracle](https://leetcode.com/company/oracle), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Split BST (Medium)](https://leetcode.com/problems/split-bst/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/delete-node-in-a-bst/
// Author: github.com/lzl124631x
// Time: O(H)
// Space: O(H)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val > key) root->left = deleteNode(root->left, key);
        else if (root->val < key) root->right = deleteNode(root->right, key);
        else if (root->left) {
            auto p = root->left;
            while (p->right) p = p->right;
            root->val = p->val;
            root->left = deleteNode(root->left, root->val);
        } else if (root->right) {
            auto p = root->right;
            while (p->left) p = p->left;
            root->val = p->val;
            root->right = deleteNode(root->right, root->val);
        } else {
            delete root;
            root = NULL;
        }
        return root;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/delete-node-in-a-bst/
// Author: github.com/lzl124631x
// Time: O(H)
// Space: O(H)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val > key) root->left = deleteNode(root->left, key);
        else if (root->val < key) root->right = deleteNode(root->right, key);
        else if (!root->left) {
            auto right = root->right;
            delete root;
            return right;
        } else if (!root->right) {
            auto left = root->left;
            delete root;
            return left;
        } else {
            auto node = root->right;
            while (node->left) node = node->left;
            root->val = node->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/delete-node-in-a-bst/
// Author: github.com/lzl124631x
// Time: O(H)
// Space: O(H)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (!root->left || !root->right) return root->left ? root->left : root->right;
        auto newRoot = root->right, left = newRoot->left, node = root->left; // Use `root->right` as the new root. Put `root->right->left` as the right child of the rightmost child of `root->left`.
        newRoot->left = root->left;
        while (node->right) node = node->right;
        node->right = left;
        return newRoot;
    }
};
```