# [107. Binary Tree Level Order Traversal II (Easy)](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

<p>Given a binary tree, return the <i>bottom-up level order</i> traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).</p>

<p>
For example:<br>
Given binary tree <code>[3,9,20,null,null,15,7]</code>,<br>
</p><pre>    3
   / \
  9  20
    /  \
   15   7
</pre>
<p></p>
<p>
return its bottom-up level order traversal as:<br>
</p><pre>[
  [15,7],
  [9,20],
  [3]
]
</pre>
<p></p>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Binary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-level-order-traversal/)
* [Average of Levels in Binary Tree (Easy)](https://leetcode.com/problems/average-of-levels-in-binary-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/binary-tree-level-order-traversal-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    for (int cnt = 1; cnt; ) {
      int nextCnt = 0;
      vector<int> row;
      while (cnt--) {
        TreeNode *root = q.front();
        q.pop();
        row.push_back(root->val);
        if (root->left) {
          q.push(root->left);
          ++nextCnt;
        }
        if (root->right) {
          q.push(root->right);
          ++nextCnt;
        }
      }
      ans.push_back(row);
      cnt = nextCnt;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
```