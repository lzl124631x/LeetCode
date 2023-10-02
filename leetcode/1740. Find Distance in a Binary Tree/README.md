# [1740. Find Distance in a Binary Tree (Medium)](https://leetcode.com/problems/find-distance-in-a-binary-tree/)

<p>Given the root of a binary tree and two integers <code>p</code> and <code>q</code>, return <em>the <strong>distance</strong> between the nodes of value </em><code>p</code><em> and value </em><code>q</code><em> in the tree</em>.</p>

<p>The <strong>distance</strong> between two nodes is the number of edges on the path from one to the other.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 0
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 edges between 5 and 0: 5-3-1-0.</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 7
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are 2 edges between 5 and 7: 5-2-7.</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 5
<strong>Output:</strong> 0
<strong>Explanation:</strong> The distance between a node and itself is 0.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li>All <code>Node.val</code> are <strong>unique</strong>.</li>
	<li><code>p</code> and <code>q</code> are values in the tree.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Step-By-Step Directions From a Binary Tree Node to Another (Medium)](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/)

## Solution 1. Find Path

```cpp
// OJ: https://leetcode.com/problems/find-distance-in-a-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    bool findPath(TreeNode *root, int target, vector<TreeNode*> &path) {
        if (!root) return false;
        path.push_back(root);
        if (root->val == target || findPath(root->left, target, path) || findPath(root->right, target, path)) return true;
        path.pop_back();
        return false;
    }
public:
    int findDistance(TreeNode* root, int p, int q) {
        if (p == q) return 0;
        vector<TreeNode*> a, b;
        findPath(root, p, a);
        findPath(root, q, b);
        int i = 0;
        while (i < a.size() && i < b.size() && a[i] == b[i]) ++i;
        return a.size() + b.size() - 2 * i;
    }
};
```

## Solution 2. Post-order Traversal

```cpp
// OJ: https://leetcode.com/problems/find-distance-in-a-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int lcaDepth = 0;
    vector<int> depth;
    TreeNode* dfs(TreeNode *root, int p, int q, int d = 0) {
        if (!root) return nullptr;
        auto left = dfs(root->left, p, q, d + 1), right = dfs(root->right, p, q, d + 1);
        if (root->val == p || root->val == q) {
            depth.push_back(d);
            lcaDepth = d;
            return root;
        }
        if (left && right) lcaDepth = d;
        return left && right ? root : (left ? left : right);
    }
public:
    int findDistance(TreeNode* root, int p, int q) {
        if (p == q) return 0;
        dfs(root, p, q);
        return depth[0] + depth[1] - 2 * lcaDepth;
    }
};
```