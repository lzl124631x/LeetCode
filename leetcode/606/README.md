# [606. Construct String from Binary Tree (Easy)](https://leetcode.com/problems/construct-string-from-binary-tree)

You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

**Example 1:**
```
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)".
```

**Example 2:**
```
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example, 
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
```

## Solution 1. DFS

Plain DFS. Notice when you should add the left/right child part.

```cpp
// OJ: https://leetcode.com/problems/construct-string-from-binary-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  string tree2str(TreeNode* t) {
    if (!t) return "";
    string left = tree2str(t->left), right = tree2str(t->right);
    string ans = to_string(t->val);
    if (left.size() || right.size())  ans += "(" + left + ")";
    if (right.size()) ans += "(" + right + ")";
    return ans;
  }
};
```