# [1008. Construct Binary Search Tree from Preorder Traversal (Medium)](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)

<p>Return the root node of a binary <strong>search</strong> tree that matches the given <code>preorder</code> traversal.</p>

<p><em>(Recall that a binary search tree&nbsp;is a binary tree where for every <font face="monospace">node</font>, any descendant of <code>node.left</code> has a value <code>&lt;</code>&nbsp;<code>node.val</code>, and any descendant of <code>node.right</code> has a value <code>&gt;</code>&nbsp;<code>node.val</code>.&nbsp; Also recall that a preorder traversal&nbsp;displays the value of the&nbsp;<code>node</code> first, then traverses <code>node.left</code>, then traverses <code>node.right</code>.)</em></p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[8,5,1,7,10,12]</span>
<strong>Output: </strong><span id="example-output-1">[8,5,10,1,7,null,12]
<img alt="" src="https://assets.leetcode.com/uploads/2019/03/06/1266.png" style="height: 200px; width: 306px;"></span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong>&nbsp;</p>

<ol>
	<li><code>1 &lt;= preorder.length &lt;= 100</code></li>
	<li>The values of <code>preorder</code> are distinct.</li>
</ol>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(H)
class Solution {
private:
    TreeNode* construct(vector<int> &preorder, int begin, int end) {
        if (begin >= end) return NULL;
        auto root = new TreeNode(preorder[begin]);
        int i = begin + 1;
        while (i < end && preorder[i] < preorder[begin]) ++i;
        root->left = construct(preorder, begin + 1, i);
        root->right = construct(preorder, i, end);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, 0, preorder.size());
    }
};
```

Or use `find_if`:

```cpp
// OJ: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(H)
class Solution {
    typedef vector<int>::iterator iter;
    TreeNode* dfs(vector<int>& A, iter begin, iter end) {
        if (begin == end) return NULL;
        auto root = new TreeNode(*begin);
        auto mid = find_if(begin + 1, end, [&](int x) { return x > *begin; });
        root->left = dfs(A, begin + 1, mid);
        root->right = dfs(A, mid, end);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& A) {
        return dfs(A, A.begin(), A.end());
    }
};
```

## Solution 2. Stack

We use a `stack<pair<TreeNode*, int>> s` to keep track of the parent nodes where the first item in the pair is the parent node, and the second item is the right bound of the parent node (i.e. the grandparent's node value).

* If the current node value is smaller than the value of the parent node at the stack top, we should add this new node as the left child of the parent node, and push `node, s.top().first->val` to the stack top.
* Otherwise, we keep popping the stack top until `A[i] < s.top().second`. Then we add the new node as the right child of the parent node at the stack top, and push `node, s.top().second` to the stack top.

```cpp
// OJ: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& A) {
        stack<pair<TreeNode*, int>> s;
        s.emplace(new TreeNode(A[0]), INT_MAX);
        auto root = s.top().first;
        for (int i = 1; i < A.size(); ++i) { 
            auto node = new TreeNode(A[i]);
            if (A[i] < s.top().first->val) {
                s.top().first->left = node;
                s.emplace(node, s.top().first->val);
            } else {
                while (A[i] > s.top().second) s.pop();
                s.top().first->right = node;
                s.emplace(node, s.top().second);
            }
        }
        return root;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
// Ref: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/discuss/252232/JavaC%2B%2BPython-O(N)-Solution
class Solution {
    int i = 0;
public:
    TreeNode* bstFromPreorder(vector<int>& A, int bound = INT_MAX) {
        if (i == A.size() || A[i] > bound) return NULL;
        auto root = new TreeNode(A[i++]);
        root->left = bstFromPreorder(A, root->val);
        root->right = bstFromPreorder(A, bound);
        return root;
    }
};
```