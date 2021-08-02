# [652. Find Duplicate Subtrees (Medium)](https://leetcode.com/problems/find-duplicate-subtrees/)

<p>Given the <code>root</code>&nbsp;of a binary tree, return all <strong>duplicate subtrees</strong>.</p>

<p>For each kind of duplicate subtrees, you only need to return the root node of any <b>one</b> of them.</p>

<p>Two trees are <strong>duplicate</strong> if they have the <strong>same structure</strong> with the <strong>same node values</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/16/e1.jpg" style="width: 450px; height: 354px;">
<pre><strong>Input:</strong> root = [1,2,3,4,null,2,4,null,null,4]
<strong>Output:</strong> [[2,4],[4]]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/16/e2.jpg" style="width: 321px; height: 201px;">
<pre><strong>Input:</strong> root = [2,1,1]
<strong>Output:</strong> [[1]]
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/16/e33.jpg" style="width: 450px; height: 303px;">
<pre><strong>Input:</strong> root = [2,2,2,3,null,3,null]
<strong>Output:</strong> [[2,3],[3]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of the nodes in the tree will be in the range <code>[1, 10^4]</code></li>
	<li><code>-200 &lt;= Node.val &lt;= 200</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Serialize and Deserialize Binary Tree (Hard)](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
* [Serialize and Deserialize BST (Medium)](https://leetcode.com/problems/serialize-and-deserialize-bst/)
* [Construct String from Binary Tree (Easy)](https://leetcode.com/problems/construct-string-from-binary-tree/)
* [Delete Duplicate Folders in System (Hard)](https://leetcode.com/problems/delete-duplicate-folders-in-system/)

## Solution 1.

Must not encode `null` as empty string because then we can't tell if it's left child or right child.

```cpp
// OJ: https://leetcode.com/problems/find-duplicate-subtrees/
// Author: github.com/lzl124631x
// Time: O(N^2) since string concatenation takes O(N) time on average
// Space: O(N^2) since string take O(N) space on average
class Solution {
    unordered_map<string, int> cnt;
    vector<TreeNode*> ans;
    string dfs(TreeNode *node) {
        if (!node) return "#";
        auto s = to_string(node->val) + "," + dfs(node->left) + "," + dfs(node->right);
        if (++cnt[s] == 2) ans.push_back(node);
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```

Or this more generalized way. This generalized way also works for n-ary tree. For example, in [1948. Delete Duplicate Folders in System (Hard)](https://leetcode.com/problems/delete-duplicate-folders-in-system/submissions/)

```cpp
// OJ: https://leetcode.com/problems/find-duplicate-subtrees/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    unordered_map<string, int> cnt;
    vector<TreeNode*> ans;
    string dfs(TreeNode *root) {
        if (!root) return "#";
        auto s = "(" + to_string(root->val) + dfs(root->left) + dfs(root->right) + ")";
        if (++cnt[s] == 2) ans.push_back(root);
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```