# [113. Path Sum II (Medium)](https://leetcode.com/problems/path-sum-ii/)

<p>Given the <code>root</code> of a binary tree and an integer <code>targetSum</code>, return all <strong>root-to-leaf</strong> paths where each path's sum equals <code>targetSum</code>.</p>

<p>A <strong>leaf</strong> is a node with no children.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg" style="width: 500px; height: 356px;">
<pre><strong>Input:</strong> root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
<strong>Output:</strong> [[5,4,11,2],[5,8,4,5]]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg" style="width: 212px; height: 181px;">
<pre><strong>Input:</strong> root = [1,2,3], targetSum = 5
<strong>Output:</strong> []
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [1,2], targetSum = 0
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 5000]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
	<li><code>-1000 &lt;= targetSum &lt;= 1000</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Path Sum (Easy)](https://leetcode.com/problems/path-sum/)
* [Binary Tree Paths (Easy)](https://leetcode.com/problems/binary-tree-paths/)
* [Path Sum III (Medium)](https://leetcode.com/problems/path-sum-iii/)
* [Path Sum IV (Medium)](https://leetcode.com/problems/path-sum-iv/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/path-sum-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(TreeNode *root, int target) {
        if (!root) return;
        tmp.push_back(root->val);
        target -= root->val;
        if (target == 0 && !root->left && !root->right) ans.push_back(tmp);
        dfs(root->left, target);
        dfs(root->right, target);
        tmp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return ans;
    }
};
```