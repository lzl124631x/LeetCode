# [501. Find Mode in Binary Search Tree (Easy)](https://leetcode.com/problems/find-mode-in-binary-search-tree)

<p>Given the <code>root</code> of a binary search tree (BST) with duplicates, return <em>all the <a href="https://en.wikipedia.org/wiki/Mode_(statistics)" target="_blank">mode(s)</a> (i.e., the most frequently occurred element) in it</em>.</p>

<p>If the tree has more than one mode, return them in <strong>any order</strong>.</p>

<p>Assume a BST is defined as follows:</p>

<ul>
	<li>The left subtree of a node contains only nodes with keys <strong>less than or equal to</strong> the node&#39;s key.</li>
	<li>The right subtree of a node contains only nodes with keys <strong>greater than or equal to</strong> the node&#39;s key.</li>
	<li>Both the left and right subtrees must also be binary search trees.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/11/mode-tree.jpg" style="width: 142px; height: 222px;" />
<pre>
<strong>Input:</strong> root = [1,null,2,2]
<strong>Output:</strong> [2]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [0]
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

**Companies**:
[Adobe](https://leetcode.com/company/adobe), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree), [Depth-First Search](https://leetcode.com/tag/depth-first-search), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree), [Binary Tree](https://leetcode.com/tag/binary-tree)

**Similar Questions**:
* [Validate Binary Search Tree (Medium)](https://leetcode.com/problems/validate-binary-search-tree)

## Solution 1. DFS (Preorder Traversal)

```cpp
// OJ: https://leetcode.com/problems/find-mode-in-binary-search-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> m;
        int maxFreq = 0;
        function<void(TreeNode*)> dfs = [&](TreeNode *root) {
            if (!root) return;
            int f = ++m[root->val];
            if (f > maxFreq) maxFreq = f, ans = {root->val};
            else if (f == maxFreq) ans.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        return ans;
    }
};
```

## Solution 2. Inorder Traversal

If we traverse the tree in in-order, we see the numbers in ascending order.

```cpp
// OJ: https://leetcode.com/problems/find-mode-in-binary-search-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) ignoring space taken by callstack
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int maxFreq = 0, curFreq = 0, cur = INT_MIN;
        function<void(TreeNode *)> dfs = [&](TreeNode *node) {
            if (!node) return;
            dfs(node->left);
            if (node->val != cur) {
                cur = node->val;
                curFreq = 0;
            }
            ++curFreq;
            if (curFreq > maxFreq) {
                ans = {cur};
                maxFreq = curFreq;
            } else if (curFreq == maxFreq) {
                ans.push_back(cur);
            }
            dfs(node->right);
        };
        dfs(root);
        return ans;
    }
};
```