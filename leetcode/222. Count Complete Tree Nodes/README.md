# [222. Count Complete Tree Nodes (Medium)](https://leetcode.com/problems/count-complete-tree-nodes/)

<p>Given a <b>complete</b> binary tree, count the number of nodes.</p>

<p><b>Note: </b></p>

<p><b><u>Definition of a complete binary tree from <a href="http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees" target="_blank">Wikipedia</a>:</u></b><br>
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2<sup>h</sup> nodes inclusive at the last level h.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> 
    1
   / \
  2   3
 / \  /
4  5 6

<strong>Output:</strong> 6</pre>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Closest Binary Search Tree Value (Easy)](https://leetcode.com/problems/closest-binary-search-tree-value/)

## Solution 1.

Given a subtree, we just compute the lengths of the leftmost path and the rightmost path.

* if they are the same, then this subtree is complete and its node count is `2^length - 1`.
* otherwise, we recursively count nodes for the left subtree and the right subtree and return the sum of them plus 1.

```cpp
// OJ: https://leetcode.com/problems/count-complete-tree-nodes/
// Author: github.com/lzl124631x
// Time: O(H^2)
// Space: O(H)
class Solution {
    int countLeft(TreeNode *root) {
        int cnt = 0;
        for (; root; ++cnt, root = root->left);
        return cnt;
    }
    int countRight(TreeNode *root) {
        int cnt = 0;
        for (; root; ++cnt, root = root->right);
        return cnt;
    }
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int left = countLeft(root), right = countRight(root);
        if (left == right) return (1 << left) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
```

## Solution 2.

Minor optimization which prevents us from recomputing the lengths that we've already known.

```cpp
// OJ: https://leetcode.com/problems/count-complete-tree-nodes/
// Author: github.com/lzl124631x
// Time: O(H^2)
// Space: O(H)
class Solution {
    int countLeft(TreeNode *root) {
        int cnt = 0;
        for (; root; ++cnt, root = root->left);
        return cnt;
    }
    int countRight(TreeNode *root) {
        int cnt = 0;
        for (; root; ++cnt, root = root->right);
        return cnt;
    }
    int count(TreeNode* root, int left = INT_MIN, int right = INT_MIN) {
        if (!root) return 0;
        if (left == INT_MIN) left = countLeft(root);
        if (right == INT_MIN) right = countRight(root);
        if (left == right) return (1 << left) - 1;
        return count(root->left, left - 1, INT_MIN) + 1 + count(root->right, INT_MIN, right - 1);
    }
public:
    int countNodes(TreeNode* root) {
        return count(root);
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/count-complete-tree-nodes/
// Author: github.com/lzl124631x
// Time: O(H^2)
// Space: O(H)
// Ref: https://leetcode.com/problems/count-complete-tree-nodes/discuss/61958/Concise-Java-solutions-O(log(n)2)
class Solution {
    int height(TreeNode *root) {
        return root ? 1 + height(root->left) : -1;
    }
public:
    int countNodes(TreeNode* root) {
        int h = height(root);
        return h < 0 ? 0 : (height(root->right) + 1 == h ? (1 << h) + countNodes(root->right) : (1 << (h - 1)) + countNodes(root->left));
    }
};
```