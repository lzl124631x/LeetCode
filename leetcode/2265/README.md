# [2265. Count Nodes Equal to Average of Subtree (Medium)](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree)

<p>Given the <code>root</code> of a binary tree, return <em>the number of nodes where the value of the node is equal to the <strong>average</strong> of the values in its <strong>subtree</strong></em>.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>The <strong>average</strong> of <code>n</code> elements is the <strong>sum</strong> of the <code>n</code> elements divided by <code>n</code> and <strong>rounded down</strong> to the nearest integer.</li>
	<li>A <strong>subtree</strong> of <code>root</code> is a tree consisting of <code>root</code> and all of its descendants.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/03/15/image-20220315203925-1.png" style="width: 300px; height: 212px;" />
<pre>
<strong>Input:</strong> root = [4,8,5,0,1,null,6]
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/03/26/image-20220326133920-1.png" style="width: 80px; height: 76px;" />
<pre>
<strong>Input:</strong> root = [1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> For the node with value 1: The average of its subtree is 1 / 1 = 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 1000]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree), [Depth-First Search](https://leetcode.com/tag/depth-first-search), [Binary Tree](https://leetcode.com/tag/binary-tree)

**Similar Questions**:
* [Maximum Average Subtree (Medium)](https://leetcode.com/problems/maximum-average-subtree)
* [Insufficient Nodes in Root to Leaf Paths (Medium)](https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths)
* [Count Nodes Equal to Sum of Descendants (Medium)](https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants)

**Hints**:
* What information do we need to calculate the average? We need the sum of the values and the number of values.
* Create a recursive function that returns the size of a node’s subtree, and the sum of the values of its subtree.

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int ans = 0;
    pair<int, int> dfs(TreeNode *root) {
        if (!root) return {0,0};
        auto [lc, ls] = dfs(root->left);
        auto [rc, rs] = dfs(root->right);
        ans += root->val == (root->val + ls + rs) / (1 + lc + rc);
        return {lc + rc + 1, ls + rs + root->val};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```