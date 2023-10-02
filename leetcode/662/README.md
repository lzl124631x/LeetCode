# [662. Maximum Width of Binary Tree (Medium)](https://leetcode.com/problems/maximum-width-of-binary-tree/)

<p>Given the <code>root</code> of a binary tree, return <em>the <strong>maximum width</strong> of the given tree</em>.</p>

<p>The <strong>maximum width</strong> of a tree is the maximum <strong>width</strong> among all levels.</p>

<p>The <strong>width</strong> of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.</p>

<p>It is <strong>guaranteed</strong> that the answer will in the range of <strong>32-bit</strong> signed integer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/03/width1-tree.jpg" style="width: 359px; height: 302px;">
<pre><strong>Input:</strong> root = [1,3,2,5,3,null,9]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The maximum width existing in the third level with the length 4 (5,3,null,9).
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/03/width2-tree.jpg" style="width: 224px; height: 302px;">
<pre><strong>Input:</strong> root = [1,3,null,5,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The maximum width existing in the third level with the length 2 (5,3).
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/03/width3-tree.jpg" style="width: 289px; height: 299px;">
<pre><strong>Input:</strong> root = [1,3,2,5]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The maximum width existing in the second level with the length 2 (3,2).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 3000]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

## Solution 1. Pre-order Traversal

```cpp
// OJ: https://leetcode.com/problems/maximum-width-of-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    typedef unsigned long long ULL;
    vector<vector<ULL>> v;
    ULL ans = 0;
    void dfs(TreeNode *node, int lv, ULL nodeId) {
        if (!node) return;
        if (v.size() <= lv) v.push_back({ULLONG_MAX, 0});
        v[lv][0] = min(v[lv][0], nodeId);
        v[lv][1] = max(v[lv][1], nodeId);
        ans = max(ans, v[lv][1] - v[lv][0] + 1);
        dfs(node->left, lv + 1, 2 * nodeId);
        dfs(node->right, lv + 1, 2 * nodeId + 1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 0, 0);
        return ans;
    }
};
```

## Solution 2. Level-order Traversal

```cpp
// OJ: https://leetcode.com/problems/maximum-width-of-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    typedef unsigned long long ULL;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, ULL>> q{{{root, 0}}};
        ULL ans = 0;
        while (q.size()) {
            ULL cnt = q.size(), minId, maxId; 
            for (int i = 0; i < cnt; ++i) {
                auto [node, nodeId] = q.front();
                q.pop();
                if (node->left) q.emplace(node->left, nodeId * 2);
                if (node->right) q.emplace(node->right, nodeId * 2 + 1);
                if (i == 0) minId = nodeId;
                if (i == cnt - 1) maxId = nodeId;
            }
            ans = max(ans, maxId - minId + 1);
        }
        return ans;
    }
};
```

## Solution 3. Level-order Traversal

```cpp
// OJ: https://leetcode.com/problems/maximum-width-of-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, long>> q{{{root, 0}}};
        long ans = 0;
        while (q.size()) {
            long cnt = q.size(), offset = -1, last;
            while (cnt--) {
                auto [n, i] = q.front();
                if (offset == -1) offset = i;
                i -= offset;
                last = i;
                q.pop();
                if (n->left) q.emplace(n->left, 2 * i);
                if (n->right) q.emplace(n->right, 2 * i + 1);
            }
            ans = max(ans, last + 1);
        }
        return ans;
    }
};
```