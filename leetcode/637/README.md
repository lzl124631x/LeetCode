# [637. Average of Levels in Binary Tree (Easy)](https://leetcode.com/problems/average-of-levels-in-binary-tree/)

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b>
    3
   / \
  9  20
    /  \
   15   7
<b>Output:</b> [3, 14.5, 11]
<b>Explanation:</b>
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The range of node's value is in the range of 32-bit signed integer.</li>
</ol>
<p></p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Binary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-level-order-traversal/)
* [Binary Tree Level Order Traversal II (Easy)](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

## Solution 1. Level-order Traversal

```cpp
// OJ: https://leetcode.com/problems/average-of-levels-in-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            double cnt = q.size(), sum = 0;
            for (int i = 0; i < cnt; ++i) {
                root = q.front();
                q.pop();
                sum += root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            ans.push_back(sum / cnt);
        }
        return ans;
    }
};
```