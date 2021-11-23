# [106. Construct Binary Tree from Inorder and Postorder Traversal (Medium)](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

<p>Given two integer arrays <code>inorder</code> and <code>postorder</code> where <code>inorder</code> is the inorder traversal of a binary tree and <code>postorder</code> is the postorder traversal of the same tree, construct and return <em>the binary tree</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree.jpg" style="width: 277px; height: 302px;">
<pre><strong>Input:</strong> inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
<strong>Output:</strong> [3,9,20,null,null,15,7]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> inorder = [-1], postorder = [-1]
<strong>Output:</strong> [-1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= inorder.length &lt;= 3000</code></li>
	<li><code>postorder.length == inorder.length</code></li>
	<li><code>-3000 &lt;= inorder[i], postorder[i] &lt;= 3000</code></li>
	<li><code>inorder</code> and <code>postorder</code> consist of <strong>unique</strong> values.</li>
	<li>Each value of <code>postorder</code> also appears in <code>inorder</code>.</li>
	<li><code>inorder</code> is <strong>guaranteed</strong> to be the inorder traversal of the tree.</li>
	<li><code>postorder</code> is <strong>guaranteed</strong> to be the postorder traversal of the tree.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Shopee](https://leetcode.com/company/shopee)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Tree](https://leetcode.com/tag/tree/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Construct Binary Tree from Preorder and Inorder Traversal (Medium)](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(H)
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        function<TreeNode*(int, int, int, int)> build = [&](int is, int ie, int ps, int pe) -> TreeNode* {
            if (is == ie) return NULL;
            auto n = new TreeNode(postorder[pe - 1]);
            int mid = find(begin(inorder) + is, begin(inorder) + ie, n->val) - begin(inorder);
            n->left = build(is, mid, ps, ps + mid - is);
            n->right = build(mid + 1, ie, ps + mid - is, pe - 1);
            return n;
        };
        return build(0, inorder.size(), 0, postorder.size());
    }
};
```

Or use a map to store the `value` to `index` pairs

```cpp
// OJ: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); ++i) m[inorder[i]] = i;
        function<TreeNode*(int, int, int, int)> build = [&](int is, int ie, int ps, int pe) -> TreeNode* {
            if (is == ie) return NULL;
            auto n = new TreeNode(postorder[pe - 1]);
            int mid = m[n->val];
            n->left = build(is, mid, ps, ps + mid - is);
            n->right = build(mid + 1, ie, ps + mid - is, pe - 1);
            return n;
        };
        return build(0, inorder.size(), 0, postorder.size());
    }
};
```

## Solution 2.

We traverse the tree in pre-order from right to left (normal pre-order is from left to right), i.e. from the last to the first elements of `postorder`.

```cpp
if (inorder[inorderIndex] != node->val) node->right = build(node); 
```

If `inorder[inorderIndex] != node->val`, it means that there are some right children of this current `node`. `postorder[postorderIndex]` is the direct right child of `node`, while `inorder[inorderIndex]` is the rightmost child of `node`.

We keep appending right children until `inorder[inorderIndex] == node->val` which means that `node` doesn't have any right `children`.

Now we can decrement `inorderIndex`.

```cpp
if (!end || inorder[inorderIndex] != end->val) node->left = build(end);
```

```
    0
  /
1
  \ 
    2
  / 
3
inorder: [1,3,2,0]
postorder: [3,2,1,0]
```

Node `0`'s `end` is `NULL`.  
Node `2`'s `end` is node `1`.  
Node `3`'s `end` is node `1`.  
Node `1`'s `end` is `NULL`.

`end` points to the closest ancester node that `node` is a right child of `end`.

If `inorder[inorderIndex] == end->val`, it means that we've exhausted the right subtree of node `end` -- no more left children for the current `node`.  
Otherwise, we build tree as the left subtree of the current `node`.

```cpp
// OJ: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
// Ref: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/discuss/34782/My-recursive-Java-code-with-O(n)-time-and-O(n)-space/33107
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inorderIndex = inorder.size() - 1, postorderIndex = postorder.size() - 1;
        function<TreeNode*(TreeNode*)> build = [&](TreeNode *end) -> TreeNode* {
            if (postorderIndex < 0) return NULL;
            auto node = new TreeNode(postorder[postorderIndex--]);
            if (inorder[inorderIndex] != node->val) node->right = build(node); 
            --inorderIndex;
            if (!end || inorder[inorderIndex] != end->val) node->left = build(end);
            return node;
        };
        return build(NULL);
    }
};
```