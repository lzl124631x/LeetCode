# [366. Find Leaves of Binary Tree (Medium)](https://leetcode.com/problems/find-leaves-of-binary-tree/)

<p>Given the <code>root</code> of a binary tree, collect a tree's nodes as if you were doing this:</p>

<ul>
	<li>Collect all the leaf nodes.</li>
	<li>Remove all the leaf&nbsp;nodes.</li>
	<li>Repeat until the tree is empty.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/16/remleaves-tree.jpg" style="width: 500px; height: 215px;">
<pre><strong>Input:</strong> root = [1,2,3,4,5]
<strong>Output:</strong> [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not matter the order on which elements are returned.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [1]
<strong>Output:</strong> [[1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 100]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-leaves-of-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    bool dfs(TreeNode *root, vector<int> &v) {
        if (!root) return true;
        if (!root->left && !root->right) {
            v.push_back(root->val);
            return true;
        }
        if (dfs(root->left, v)) root->left = NULL;
        if (dfs(root->right, v)) root->right = NULL;
        return false;
    }
    vector<int> removeLeaves(TreeNode *root) {
        vector<int> v;
        dfs(root, v);
        return v;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        while (root->left || root->right) {
            ans.push_back(removeLeaves(root));
        }
        ans.push_back({ root->val });
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/find-leaves-of-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    vector<vector<int>> ans;
    int dfs(TreeNode *root) {
        if (!root) return -1;
        int left = dfs(root->left), right = dfs(root->right), level = 1 + max(left, right);
        if (ans.size() <= level) ans.emplace_back();
        ans[level].push_back(root->val);
        return level;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```