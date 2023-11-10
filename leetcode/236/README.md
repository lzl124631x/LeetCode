# [236. Lowest Common Ancestor of a Binary Tree (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

<p>Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.</p>

<p>According to the <a href="https://en.wikipedia.org/wiki/Lowest_common_ancestor" target="_blank">definition of LCA on Wikipedia</a>: “The lowest common ancestor is defined between two nodes <code>p</code> and <code>q</code> as the lowest node in <code>T</code> that has both <code>p</code> and <code>q</code> as descendants (where we allow <b>a node to be a descendant of itself</b>).”</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png" style="width: 200px; height: 190px;">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong> The LCA of nodes 5 and 1 is 3.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png" style="width: 200px; height: 190px;">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
<strong>Output:</strong> 5
<strong>Explanation:</strong> The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [1,2], p = 1, q = 2
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[2, 10<sup>5</sup>]</code>.</li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li>All <code>Node.val</code> are <strong>unique</strong>.</li>
	<li><code>p != q</code></li>
	<li><code>p</code> and <code>q</code> will exist in the tree.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [LinkedIn](https://leetcode.com/company/linkedin), [Adobe](https://leetcode.com/company/adobe), [Apple](https://leetcode.com/company/apple), [Uber](https://leetcode.com/company/uber), [Zillow](https://leetcode.com/company/zillow), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Reddit](https://leetcode.com/company/reddit), [Atlassian](https://leetcode.com/company/atlassian), [Riot Games](https://leetcode.com/company/riot-games)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Lowest Common Ancestor of a Binary Search Tree (Easy)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
* [Smallest Common Region (Medium)](https://leetcode.com/problems/smallest-common-region/)
* [Lowest Common Ancestor of a Binary Tree II (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/)
* [Lowest Common Ancestor of a Binary Tree III (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/)
* [Lowest Common Ancestor of a Binary Tree IV (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/)

## Solution 1.

Get the two paths from root to target nodes, and return the last node that appears in both paths. Also, this solution works even when `p` or `q` is not found (i.e. [1644. Lowest Common Ancestor of a Binary Tree II (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/))

```cpp
// OJ: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
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

This solution can skip nodes after finding two matched nodes. Also, this solution works even when `p` or `q` is not found (i.e. [1644. Lowest Common Ancestor of a Binary Tree II (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/))

```cpp
// OJ: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    TreeNode *ans = nullptr;
    int dfs(TreeNode *root, TreeNode *p, TreeNode *q) { // returns the number of matched nodes in this subtree
        if (!root || ans) return 0; // if we've already found the LCA, we can skip all subsequent DFS.
        int left = dfs(root->left, p, q), right = dfs(root->right, p, q), cnt = left + right + (root == p || root == q);
        if (cnt == 2 && !ans) ans = root; // The first node that has both nodes as chlid or self is the LCA.
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

This solution will visit all the nodes, but it's short and the logic is easier to understand and less error-prone.

```cpp
// OJ: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        auto left = lowestCommonAncestor(root->left, p, q), right = lowestCommonAncestor(root->right, p, q);
        return left && right ? root : (left ? left : right);
    }
};
```