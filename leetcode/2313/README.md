# [2313. Minimum Flips in Binary Tree to Get Result (Hard)](https://leetcode.com/problems/minimum-flips-in-binary-tree-to-get-result)

<p>You are given the <code>root</code> of a <strong>binary tree</strong> with the following properties:</p>

<ul>
	<li><strong>Leaf nodes</strong> have either the value <code>0</code> or <code>1</code>, representing <code>false</code> and <code>true</code> respectively.</li>
	<li><strong>Non-leaf nodes</strong> have either the value <code>2</code>, <code>3</code>, <code>4</code>, or <code>5</code>, representing the boolean operations <code>OR</code>, <code>AND</code>, <code>XOR</code>, and <code>NOT</code>, respectively.</li>
</ul>

<p>You are also given a boolean <code>result</code>, which is the desired result of the <strong>evaluation</strong> of the <code>root</code> node.</p>

<p>The evaluation of a node is as follows:</p>

<ul>
	<li>If the node is a leaf node, the evaluation is the <strong>value</strong> of the node, i.e. <code>true</code> or <code>false</code>.</li>
	<li>Otherwise, <strong>evaluate</strong> the node&#39;s children and <strong>apply</strong> the boolean operation of its value with the children&#39;s evaluations.</li>
</ul>

<p>In one operation, you can <strong>flip</strong> a leaf node, which causes a <code>false</code> node to become <code>true</code>, and a <code>true</code> node to become <code>false</code>.</p>

<p>Return<em> the minimum number of operations that need to be performed such that the evaluation of </em><code>root</code><em> yields </em><code>result</code>. It can be shown that there is always a way to achieve <code>result</code>.</p>

<p>A <strong>leaf node</strong> is a node that has zero children.</p>

<p>Note: <code>NOT</code> nodes have either a left child or a right child, but other non-leaf nodes have both a left child and a right child.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/20/operationstree.png" style="width: 500px; height: 179px;" />
<pre>
<strong>Input:</strong> root = [3,5,4,2,null,1,1,1,0], result = true
<strong>Output:</strong> 2
<strong>Explanation:</strong>
It can be shown that a minimum of 2 nodes have to be flipped to make the root of the tree
evaluate to true. One way to achieve this is shown in the diagram above.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [0], result = false
<strong>Output:</strong> 0
<strong>Explanation:</strong>
The root of the tree already evaluates to false, so 0 nodes have to be flipped.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 5</code></li>
	<li><code>OR</code>, <code>AND</code>, and <code>XOR</code> nodes have <code>2</code> children.</li>
	<li><code>NOT</code> nodes have <code>1</code> child.</li>
	<li>Leaf nodes have a value of <code>0</code> or <code>1</code>.</li>
	<li>Non-leaf nodes have a value of <code>2</code>, <code>3</code>, <code>4</code>, or <code>5</code>.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Tree](https://leetcode.com/tag/tree), [Depth-First Search](https://leetcode.com/tag/depth-first-search), [Binary Tree](https://leetcode.com/tag/binary-tree)

**Similar Questions**:
* [Check If Two Expression Trees are Equivalent (Medium)](https://leetcode.com/problems/check-if-two-expression-trees-are-equivalent)
* [Design an Expression Tree With Evaluate Function (Medium)](https://leetcode.com/problems/design-an-expression-tree-with-evaluate-function)
* [Evaluate Boolean Binary Tree (Easy)](https://leetcode.com/problems/evaluate-boolean-binary-tree)

**Hints**:
* Try using tree DP to solve this problem.
* Find the minimum operations to change each subtree to true and to false separately.
* For nodes representing boolean operations, find the minimum operations by trying all combinations of values to which the child nodes can evaluate.

## Solution 1. DP (Top-down)

```cpp
// OJ: https://leetcode.com/problems/minimum-flips-in-binary-tree-to-get-result
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    unordered_map<TreeNode*, int> m[2];
public:
    int minimumFlips(TreeNode* root, bool result) {
        if (!root->left && !root->right) return result != root->val;
        if (m[result].count(root)) return m[result][root];
        int ans;
        if (root->val == 2) { // OR
            if (result) ans = min(minimumFlips(root->left, true), minimumFlips(root->right, true));
            else ans = minimumFlips(root->left, false) + minimumFlips(root->right, false);
        } else if (root->val == 3) { // AND
            if (result) ans = minimumFlips(root->left, true) + minimumFlips(root->right, true);
            else ans = min(minimumFlips(root->left, false), minimumFlips(root->right, false));
        } else if (root->val == 4) { // XOR
            if (result) ans = min(minimumFlips(root->left, true) + minimumFlips(root->right, false), minimumFlips(root->left, false) + minimumFlips(root->right, true));
            else ans = min(minimumFlips(root->left, true) + minimumFlips(root->right, true), minimumFlips(root->left, false) + minimumFlips(root->right, false));
        } else { // NOT
            auto node = root->left ? root->left : root->right;
            ans = minimumFlips(node, !result);
        }
        return m[result][root] = ans;
    }
};
```

## Solution 2. Post-order Traversal

```cpp
// OJ: https://leetcode.com/problems/minimum-flips-in-binary-tree-to-get-result
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    array<int, 2> dfs(TreeNode *root) { // minimum operations to get result `false` / `true`.
        if (!root) return {INT_MAX, INT_MAX};
        if (root->val <= 1) return {root->val, !root->val};
        auto [a, b] = dfs(root->left);
        auto [c, d] = dfs(root->right);
        if (root->val == 2) { // OR
            return {a + c, min(b, d)};
        } else if (root->val == 3) { // AND
            return {min(a, c), b + d};
        } else if (root->val == 4) { // XOR
            return {min(a + c, b + d), min(a + d, b + c)};
        } else { // NOT
            return {min(b, d), min(a, c)};
        }
    }
public:
    int minimumFlips(TreeNode* root, bool result) {
        return dfs(root)[result];
    }
};
```