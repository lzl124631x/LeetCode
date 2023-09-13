# [114. Flatten Binary Tree to Linked List (Medium)](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

<p>Given the <code>root</code> of a binary tree, flatten the tree into a "linked list":</p>

<ul>
	<li>The "linked list" should use the same <code>TreeNode</code> class where the <code>right</code> child pointer points to the next node in the list and the <code>left</code> child pointer is always <code>null</code>.</li>
	<li>The "linked list" should be in the same order as a <a href="https://en.wikipedia.org/wiki/Tree_traversal#Pre-order,_NLR" target="_blank"><strong>pre-order</strong><strong> traversal</strong></a> of the binary tree.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg" style="width: 500px; height: 226px;">
<pre><strong>Input:</strong> root = [1,2,5,3,4,null,6]
<strong>Output:</strong> [1,null,2,null,3,null,4,null,5,null,6]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [0]
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 2000]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Can you flatten the tree in-place (with <code>O(1)</code> extra space)?

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Bloomberg](https://leetcode.com/company/bloomberg), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Flatten a Multilevel Doubly Linked List (Medium)](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)
* [Correct a Binary Tree (Medium)](https://leetcode.com/problems/correct-a-binary-tree/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    TreeNode* dfs(TreeNode* root) { // returns a pointer to the last node after flattening
        if (!root || (!root->left && !root->right)) return root;
        auto leftLast = dfs(root->left), rightLast = dfs(root->right), left = root->left, right = root->right;
        root->left = nullptr;
        root->right = left ? left : right;
        if (left) leftLast->right = right;
        return right ? rightLast : leftLast;
    }
public:
    void flatten(TreeNode* root) {
        dfs(root);
    }
};
```

## Solution 2. Stack

```cpp
// OJ: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> s{{root}};
        TreeNode *prev = nullptr;
        while (s.size()) {
            auto node = s.top();
            s.pop();
            if (prev) prev->right = node;
            prev = node;
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
            node->left = node->right = nullptr;
        }
    }
};
```

## Solution 3. Left-to-right Pre-order Traversal

```cpp
// OJ: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    TreeNode *prev = nullptr;
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        auto right = root->right;
        if (prev) prev->right = root;
        prev = root;
        flatten(root->left);
        root->left = nullptr;
        flatten(right);
    }
};
```

## Solution 4. Right-to-left Post-order Traversal

Note: Left-to-right pre-order traversal has the reverse result of right-to-left post-order traversal.

```cpp
// OJ: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    TreeNode *prev = nullptr;
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};
```