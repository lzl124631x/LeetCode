# [572. Subtree of Another Tree (Easy)](https://leetcode.com/problems/subtree-of-another-tree/)

Given two non-empty binary trees **s** and **t**, check whether tree **t** has exactly the same structure and node values with a subtree of **s**. A subtree of **s** is a tree consists of a node in **s** and all of this node's descendants. The tree **s** could also be considered as a subtree of itself.

**Example 1:**  
Given tree s:

```
     3
    / \
   4   5
  / \
 1   2
```

Given tree t:

```
   4 
  / \
 1   2
```

Return **true**, because t has the same structure and node values with a subtree of s.

**Example 2:**  
Given tree s:

```
     3
    / \
   4   5
  / \
 1   2
    /
   0
```

Given tree t:

```
   4
  / \
 1   2
```

Return **false**.

# Solution 1.

```cpp
// OJ: https://leetcode.com/problems/shortest-unsorted-continuous-subarray
// Author: github.com/lzl124631x
// Time: O(ST) where S and T are the node count of s and t.
// Space: O(H) where H is the height of s.
class Solution {
private:
    bool isSameTree(TreeNode* s, TreeNode* t) {
        return (!s && !t) || (s && t && s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right));
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return isSameTree(s, t) || (s && (isSubtree(s->left, t) || isSubtree(s->right, t)));
    }
};
```