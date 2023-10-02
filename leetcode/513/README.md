# [513. Find Bottom Left Tree Value (Medium)](https://leetcode.com/problems/find-bottom-left-tree-value/)

<p>
Given a binary tree, find the leftmost value in the last row of the tree. 
</p>

<p><b>Example 1:</b><br>
</p><pre>Input:

    2
   / \
  1   3

Output:
1
</pre>
<p></p>

<p> <b> Example 2: </b><br>
</p><pre>Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
</pre>
<p></p>

<p><b>Note:</b>
You may assume the tree (i.e., the given root node) is not <b>NULL</b>.
</p>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. Level-order Traversal

```cpp
// OJ: https://leetcode.com/problems/find-bottom-left-tree-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int cnt = q.size();
            ans = q.front()->val;
            while (cnt--) {
                root = q.front();
                q.pop();
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        return ans;
    }
};
```

## Solution 2. Level-order Traversal (Right-to-left)

```cpp
// OJ: https://leetcode.com/problems/find-bottom-left-tree-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            root = q.front();
            ans = root->val;
            q.pop();
            if (root->right) q.push(root->right);
            if (root->left) q.push(root->left);
        }
        return ans;
    }
};
```

## Solution 3. Pre-order Traversal

```cpp
// OJ: https://leetcode.com/problems/find-bottom-left-tree-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int maxDepth = -1, ans = 0;
    void preorder(TreeNode *root, int depth) {
        if (!root) return;
        if (depth > maxDepth) {
            ans = root->val;
            maxDepth = depth;
        }
        preorder(root->left, depth + 1);
        preorder(root->right, depth + 1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        preorder(root, 0);
        return ans;
    }
};
```