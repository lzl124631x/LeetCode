# [662. Maximum Width of Binary Tree (Medium)](https://leetcode.com/problems/maximum-width-of-binary-tree/)

<p>Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a <b>full binary tree</b>, but some nodes are null. </p>

<p>The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the <code>null</code> nodes between the end-nodes are also counted into the length calculation.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

<b>Output:</b> 4
<b>Explanation:</b> The maximum width existing in the third level with the length 4 (5,3,null,9).
</pre>


<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> 

          1
         /  
        3    
       / \       
      5   3     

<b>Output:</b> 2
<b>Explanation:</b> The maximum width existing in the third level with the length 2 (5,3).
</pre>


<p><b>Example 3:</b><br>
</p><pre><b>Input:</b> 

          1
         / \
        3   2 
       /        
      5      

<b>Output:</b> 2
<b>Explanation:</b> The maximum width existing in the second level with the length 2 (3,2).
</pre>

<p><b>Example 4:</b><br>
</p><pre><b>Input:</b> 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
<b>Output:</b> 8
<b>Explanation:</b>The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


</pre>

<p><b>Note:</b>
Answer will in the range of 32-bit signed integer.
</p>

**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1. Level-order Traversal

```cpp
// OJ: https://leetcode.com/problems/maximum-width-of-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int ans = INT_MIN;
        while (q.size()) {
            int cnt = q.size(), left, right;
            for (int i = 0; i < cnt; ++i) {
                auto &p = q.front();
                q.pop();
                root = p.first;
                if (i == 0) left = p.second;
                if (i == cnt - 1) right = p.second;
                if (root->left) q.push(make_pair(root->left, p.second * 2));
                if (root->right) q.push(make_pair(root->right, p.second * 2 + 1));
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
```