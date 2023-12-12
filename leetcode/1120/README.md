# [1120. Maximum Average Subtree (Medium)](https://leetcode.com/problems/maximum-average-subtree)

<p>Given the <code>root</code> of a binary tree, return <em>the maximum <strong>average</strong> value of a <strong>subtree</strong> of that tree</em>. Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</p>

<p>A <strong>subtree</strong> of a tree is any node of that tree plus all its descendants.</p>

<p>The <strong>average</strong> value of a tree is the sum of its values, divided by the number of nodes.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/04/09/1308_example_1.png" style="width: 132px; height: 123px;" />
<pre>
<strong>Input:</strong> root = [5,6,1]
<strong>Output:</strong> 6.00000
<strong>Explanation:</strong> 
For the node with value = 5 we have an average of (5 + 6 + 1) / 3 = 4.
For the node with value = 6 we have an average of 6 / 1 = 6.
For the node with value = 1 we have an average of 1 / 1 = 1.
So the answer is 6 which is the maximum.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [0,null,1]
<strong>Output:</strong> 1.00000
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:
[Rippling](https://leetcode.com/company/rippling), [Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree), [Depth-First Search](https://leetcode.com/tag/depth-first-search), [Binary Tree](https://leetcode.com/tag/binary-tree)

**Similar Questions**:
* [Count Nodes Equal to Sum of Descendants (Medium)](https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants)
* [Count Nodes Equal to Average of Subtree (Medium)](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree)

**Hints**:
* Can you find the sum of values and the number of nodes for every sub-tree ?
* Can you find the sum of values and the number of nodes for a sub-tree given the sum of values and the number of nodes of it's left and right sub-trees ?
* Use depth first search to recursively find the solution for the children of a node then use their solutions to compute the current node's solution.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-average-subtree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    double ans = 0;
    pair<int, int> dfs(TreeNode *root) {
        if (!root) return {0,0};
        auto left = dfs(root->left), right = dfs(root->right);
        int sum = left.first + right.first + root->val, cnt = left.second + right.second + 1;
        ans = max(ans, (double)sum / cnt);
        return {sum, cnt};
    }
public:
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```