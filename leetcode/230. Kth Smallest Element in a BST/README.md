# [230. Kth Smallest Element in a BST (Medium)](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

<p>Given a binary search tree, write a function <code>kthSmallest</code> to find the <b>k</b>th smallest element in it.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
&nbsp;  2
<strong>Output:</strong> 1</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
<strong>Output:</strong> 3
</pre>

<p><b>Follow up:</b><br>
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?</p>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of elements of the BST is between <code>1</code> to <code>10^4</code>.</li>
	<li>You may assume <code>k</code> is always valid, <code>1 ≤ k ≤ BST's total elements</code>.</li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Binary Tree Inorder Traversal (Medium)](https://leetcode.com/problems/binary-tree-inorder-traversal/)
* [Second Minimum Node In a Binary Tree (Easy)](https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/)

## Solution 1. In-order traversal (Recursive)

```cpp
// OJ: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int i = 0;
    int inorder(TreeNode *root, int k) {
        if (!root) return 0;
        int val = inorder(root->left, k);
        if (val) return val;
        if (++i == k) return root->val;
        return inorder(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};
```

## Solution 1. In-order traversal (Iterative)

```cpp
// OJ: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while (root || s.size()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (--k == 0) return root->val;
            root = root->right;
        }
        return -1;
    }
};
```