# [103. Binary Tree Zigzag Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

<p>Given a binary tree, return the <i>zigzag level order</i> traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).</p>

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
return its zigzag level order traversal as:<br>
</p><pre>[
  [3],
  [20,9],
  [15,7]
]
</pre>
<p></p>

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Binary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-level-order-traversal/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};
    queue<TreeNode*> q;
    q.push(root);
    bool ltr = true;
    vector<vector<int>> ans;
    while (q.size()) {
      int N = q.size();
      vector<int> lv;
      stack<TreeNode*> s;
      while (N--) {
        root = q.front();
        q.pop();
        lv.push_back(root->val);
        if (ltr) {
          if (root->left) s.push(root->left);
          if (root->right) s.push(root->right);
        } else {
          if (root->right) s.push(root->right);
          if (root->left) s.push(root->left);
        }
      }
      while (s.size()) { q.push(s.top()); s.pop(); }
      ltr = !ltr;
      ans.push_back(lv);
    }
    return ans;
  }
};
```