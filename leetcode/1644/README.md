# [1644. Lowest Common Ancestor of a Binary Tree II (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/)

<p>Given the <code>root</code> of a binary tree, return <em>the lowest common ancestor (LCA) of two given nodes, </em><code>p</code><em> and </em><code>q</code>. If either node <code>p</code> or <code>q</code> <strong>does not exist</strong> in the tree, return <code>null</code>. All values of the nodes in the tree are <strong>unique</strong>.</p>

<p>According to the <strong><a href="https://en.wikipedia.org/wiki/Lowest_common_ancestor" target="_blank">definition of LCA on Wikipedia</a></strong>: "The lowest common ancestor of two nodes <code>p</code> and <code>q</code> in a binary tree <code>T</code> is the lowest node that has both <code>p</code> and <code>q</code> as <strong>descendants</strong> (where we allow <b>a node to be a descendant of itself</b>)". A <strong>descendant</strong> of a node <code>x</code> is a node <code>y</code> that is on the path from node <code>x</code> to some leaf node.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong> The LCA of nodes 5 and 1 is 3.</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png"></p>

<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
<strong>Output:</strong> 5
<strong>Explanation:</strong> The LCA of nodes 5 and 4 is 5. A node can be a descendant of itself according to the definition of LCA.</pre>

<p><strong>Example 3:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png"></p>

<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 10
<strong>Output:</strong> null
<strong>Explanation:</strong> Node 10 does not exist in the tree, so return null.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li>All <code>Node.val</code> are <strong>unique</strong>.</li>
	<li><code>p != q</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong>&nbsp;Can you find the LCA traversing the tree, without checking nodes existence?

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Lowest Common Ancestor of a Binary Search Tree (Easy)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
* [Lowest Common Ancestor of a Binary Tree (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
* [Lowest Common Ancestor of a Binary Tree III (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/)
* [Lowest Common Ancestor of a Binary Tree IV (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    bool findPath(TreeNode *node, TreeNode *target, vector<TreeNode*> &path) {
        if (!node) return false;
        path.push_back(node);
        if (node == target) return true;
        if (findPath(node->left, target, path) || findPath(node->right, target, path)) return true;
        path.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a, b;
        findPath(root, p, a);
        findPath(root, q, b);
        TreeNode *ans = nullptr;
        for (int i = 0; i < a.size() && i < b.size() && a[i] == b[i]; ++i) ans = a[i];
        return ans;
    }
};
```

## Solution 2. Post-order Traversal

```cpp
// OJ: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    TreeNode *ans = nullptr;
    int dfs(TreeNode *root, TreeNode *p, TreeNode *q) { // returns the number of matched nodes in this subtree
        if (!root || ans) return 0; // if we've already found the LCA, we can skip all subsequent DFS.
        int left = dfs(root->left, p, q), right = dfs(root->right, p, q), cnt = left + right + (root == p || root == q);
        if (cnt == 2 && (left == 1 || right == 1)) ans = root; // If this subtree has two matched nodes and either the left or right subtree only has exactly one matched node, this is the LCA.
        return cnt;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};
```

## Solution 3. Post-order Traversal

```cpp
// OJ: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int cnt = 0;
    TreeNode* dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return nullptr;
        auto left = dfs(root->left, p, q), right = dfs(root->right, p, q);
        if (root == p || root == q) {
            ++cnt;
            return root;
        }
        return left && right ? root : (left ? left : right);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto ans = dfs(root, p, q);
        return cnt == 2 ? ans : nullptr;
    }
};
```