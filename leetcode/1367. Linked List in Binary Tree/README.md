# [1367. Linked List in Binary Tree (Medium)](https://leetcode.com/problems/linked-list-in-binary-tree/)

<p>Given a binary tree <code>root</code> and a&nbsp;linked list with&nbsp;<code>head</code>&nbsp;as the first node.&nbsp;</p>

<p>Return True if all the elements in the linked list starting from the <code>head</code> correspond to some <em>downward path</em> connected in the binary tree&nbsp;otherwise return False.</p>

<p>In this context downward path means a path that starts at some node and goes downwards.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/02/12/sample_1_1720.png" style="width: 220px; height: 280px;"></strong></p>

<pre><strong>Input:</strong> head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
<strong>Output:</strong> true
<strong>Explanation:</strong> Nodes in blue form a subpath in the binary Tree.  
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/02/12/sample_2_1720.png" style="width: 220px; height: 280px;"></strong></p>

<pre><strong>Input:</strong> head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
<strong>Output:</strong> true
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no path in the binary tree that contains all the elements of the linked list from <code>head</code>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= node.val&nbsp;&lt;= 100</code>&nbsp;for each node in the linked list and binary tree.</li>
	<li>The given linked list will contain between&nbsp;<code>1</code>&nbsp;and <code>100</code>&nbsp;nodes.</li>
	<li>The given binary tree will contain between&nbsp;<code>1</code>&nbsp;and&nbsp;<code>2500</code>&nbsp;nodes.</li>
</ul>

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/linked-list-in-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N * min(L, H))
// Space: O(H)
class Solution {
    bool match(ListNode *head, TreeNode *root) {
        if (!head) return true;
        if (!root) return false;
        if (head->val != root->val) return false;
        return match(head->next, root->left) || match(head->next, root->right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        if (match(head, root)) return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
```