# [2415. Reverse Odd Levels of Binary Tree (Medium)](https://leetcode.com/problems/reverse-odd-levels-of-binary-tree)

<p>Given the <code>root</code> of a <strong>perfect</strong> binary tree, reverse the node values at each <strong>odd</strong> level of the tree.</p>

<ul>
	<li>For example, suppose the node values at level 3 are <code>[2,1,3,4,7,11,29,18]</code>, then it should become <code>[18,29,11,7,4,3,1,2]</code>.</li>
</ul>

<p>Return <em>the root of the reversed tree</em>.</p>

<p>A binary tree is <strong>perfect</strong> if all parent nodes have two children and all leaves are on the same level.</p>

<p>The <strong>level</strong> of a node is the number of edges along the path between it and the root node.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/07/28/first_case1.png" style="width: 626px; height: 191px;">
<pre><strong>Input:</strong> root = [2,3,5,8,13,21,34]
<strong>Output:</strong> [2,5,3,8,13,21,34]
<strong>Explanation:</strong> 
The tree has only one odd level.
The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/07/28/second_case3.png" style="width: 591px; height: 111px;">
<pre><strong>Input:</strong> root = [7,13,11]
<strong>Output:</strong> [7,11,13]
<strong>Explanation:</strong> 
The nodes at level 1 are 13, 11, which are reversed and become 11, 13.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
<strong>Output:</strong> [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
<strong>Explanation:</strong> 
The odd levels have non-zero values.
The nodes at level 1 were 1, 2, and are 2, 1 after the reversal.
The nodes at level 3 were 1, 1, 1, 1, 2, 2, 2, 2, and are 2, 2, 2, 2, 1, 1, 1, 1 after the reversal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 2<sup>14</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>root</code> is a <strong>perfect</strong> binary tree.</li>
</ul>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Invert Binary Tree (Easy)](https://leetcode.com/problems/invert-binary-tree/)

## Solution 1. Level-order Traversal

```cpp
// OJ: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root || !root->left) return root;
        queue<TreeNode*> q{{root}};
        int lv = 0;
        while (q.size()) {
            int cnt = q.size();
            vector<TreeNode*> v;
            while (cnt--) {
                auto n = q.front(); q.pop();
                if (lv % 2) v.push_back(n);
                if (n->left) {
                    q.push(n->left);
                    q.push(n->right);
                }
            }
            if (lv % 2) {
                for (int i = 0, j = v.size() - 1; i < j; ) {
                    swap(v[i++]->val, v[j--]->val);
                }
            }
            ++lv;
        }
        return root;
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    void dfs(TreeNode* a, TreeNode *b, int lv) {
        if (!a) return;
        if (lv % 2) swap(a->val, b->val);
        dfs(a->left, b->right, lv + 1);
        dfs(a->right, b->left, lv + 1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 1);
        return root;
    }
};
```