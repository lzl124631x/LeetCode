# [1973. Count Nodes Equal to Sum of Descendants (Medium)](https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/)

<p>Given the <code>root</code> of a binary tree, return <em>the number of nodes where the value of the node is equal to the <strong>sum</strong> of the values of its descendants</em>.</p>

<p>A <strong>descendant</strong> of a node <code>x</code> is any node that is on the path from node <code>x</code> to some leaf node. The sum is considered to be <code>0</code> if the node has no descendants.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/17/screenshot-2021-08-17-at-17-16-50-diagram-drawio-diagrams-net.png" style="width: 250px; height: 207px;">
<pre><strong>Input:</strong> root = [10,3,4,2,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
For the node with value 10: The sum of its descendants is 3+4+2+1 = 10.
For the node with value 3: The sum of its descendants is 2+1 = 3.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/17/screenshot-2021-08-17-at-17-25-21-diagram-drawio-diagrams-net.png" style="height: 196px; width: 200px;">
<pre><strong>Input:</strong> root = [2,3,null,2,null]
<strong>Output:</strong> 0
<strong>Explanation:</strong>
No node has a value that is equal to the sum of its descendants.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/17/screenshot-2021-08-17-at-17-23-53-diagram-drawio-diagrams-net.png" style="width: 50px; height: 50px;">
<pre><strong>Input:</strong> root = [0]
<strong>Output:</strong> 1
For the node with value 0: The sum of its descendants is 0 since it has no descendants.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Most Frequent Subtree Sum (Medium)](https://leetcode.com/problems/most-frequent-subtree-sum/)
* [Maximum Average Subtree (Medium)](https://leetcode.com/problems/maximum-average-subtree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int ans = 0;
    long dfs(TreeNode *root) {
        if (!root) return 0; 
        long sum = dfs(root->left) + dfs(root->right);
        if (root->val == sum) ++ans;
        return sum + root->val;
    }
public:
    int equalToDescendants(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```