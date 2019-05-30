# [124. Binary Tree Maximum Path Sum (Hard)](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

<p>Given a <strong>non-empty</strong> binary tree, find the maximum path sum.</p>

<p>For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain <strong>at least one node</strong> and does not need to go through the root.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [1,2,3]

       <strong>1</strong>
      <strong>/ \</strong>
     <strong>2</strong>   <strong>3</strong>

<strong>Output:</strong> 6
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [-10,9,20,null,null,15,7]

&nbsp;  -10
&nbsp; &nbsp;/ \
&nbsp; 9 &nbsp;<strong>20</strong>
&nbsp; &nbsp; <strong>/ &nbsp;\</strong>
&nbsp; &nbsp;<strong>15 &nbsp; 7</strong>

<strong>Output:</strong> 42
</pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1.

For node `n`, let `f(n)` be the maximum path sum that STARTS from node `n` to its children. It means that the path can only go through one of its children, not both of them. We have:

```
f(n) = n->val + max(0, max(f(n->left), f(n->right)))
```

For each node `n`, we also need to try to update the maximum path sum using `max(0, f(n->left)) + max(0, f(n->right)) + n->val`.

In sum, we can use post order traversal to compute `f(n)` and update maximum path sum along the process.

```cpp
// OJ: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    int ans = INT_MIN;
    int postOrder(TreeNode *root) {
        if (!root) return INT_MIN;
        int L = max(0, postOrder(root->left)), R = max(0, postOrder(root->right));
        ans = max(ans, L + R + root->val);
        return root->val + max(L, R);
    }
public:
    int maxPathSum(TreeNode* root) {
        postOrder(root);
        return ans;
    }
};
```