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
        bool l2r = true;
        vector<vector<int>> ans;
        while (q.size()) {
            int cnt = q.size();
            vector<int> lv;
            while (cnt--) {
                root = q.front();
                q.pop();
                lv.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            if (!l2r) reverse(begin(lv), end(lv));
            ans.push_back(lv);
            l2r = !l2r;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        deque<TreeNode*> q;
        q.push_front(root);
        bool l2r = true;
        while (q.size()) {
            int cnt = q.size();
            ans.emplace_back();
            while (cnt--) {
                if (l2r) {
                    root = q.front();
                    q.pop_front();
                } else {
                    root = q.back();
                    q.pop_back();
                }
                ans.back().push_back(root->val);
                if (l2r) {
                    if (root->left) q.push_back(root->left);
                    if (root->right) q.push_back(root->right);
                } else {
                    if (root->right) q.push_front(root->right);
                    if (root->left) q.push_front(root->left);
                }
            }
            l2r = !l2r;
        }
        return ans;
    }
};
```