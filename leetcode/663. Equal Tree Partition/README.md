# [663. Equal Tree Partition (Medium)](https://leetcode.com/problems/equal-tree-partition/)

<p>
Given a binary tree with <code>n</code> nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing <b>exactly</b> one edge on the original tree.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b>     
    5
   / \
  10 10
    /  \
   2   3

<b>Output:</b> True
<b>Explanation:</b> 
    5
   / 
  10
      
Sum: 15

   10
  /  \
 2    3

Sum: 15
</pre>
<p></p>


<p><b>Example 2:</b><br>
</p><pre><b>Input:</b>     
    1
   / \
  2  10
    /  \
   2   20

<b>Output:</b> False
<b>Explanation:</b> You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The range of tree node value is in the range of [-100000, 100000].</li>
<li>1 &lt;= n &lt;= 10000</li>
</ol>
<p></p>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/equal-tree-partition/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(logN)
class Solution {
public:
    int getSum(TreeNode *root) {
        if (!root) return 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }
    bool dfs(TreeNode *root, int target) {
        if (!root) return false;
        int sum = getSum(root);
        if (sum == target) return true;
        if (sum - root->val < target) return false;
        return dfs(root->left, target) || dfs(root->right, target);
    }
public:
    bool checkEqualTree(TreeNode* root) {
        int sum = getSum(root);
        if (sum % 2) return false;
        return dfs(root->left, sum / 2) || dfs(root->right, sum / 2);
    }
};
```