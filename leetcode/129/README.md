# [129. Sum Root to Leaf Numbers (Medium)](https://leetcode.com/problems/sum-root-to-leaf-numbers/)

<p>Given a binary tree containing digits from <code>0-9</code> only, each root-to-leaf path could represent a number.</p>

<p>An example is the root-to-leaf path <code>1-&gt;2-&gt;3</code> which represents the number <code>123</code>.</p>

<p>Find the total sum of all root-to-leaf numbers.</p>

<p><strong>Note:</strong>&nbsp;A leaf is a node with no children.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> [1,2,3]
    1
   / \
  2   3
<strong>Output:</strong> 25
<strong>Explanation:</strong>
The root-to-leaf path <code>1-&gt;2</code> represents the number <code>12</code>.
The root-to-leaf path <code>1-&gt;3</code> represents the number <code>13</code>.
Therefore, sum = 12 + 13 = <code>25</code>.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [4,9,0,5,1]
    4
   / \
  9   0
&nbsp;/ \
5   1
<strong>Output:</strong> 1026
<strong>Explanation:</strong>
The root-to-leaf path <code>4-&gt;9-&gt;5</code> represents the number 495.
The root-to-leaf path <code>4-&gt;9-&gt;1</code> represents the number 491.
The root-to-leaf path <code>4-&gt;0</code> represents the number 40.
Therefore, sum = 495 + 491 + 40 = <code>1026</code>.</pre>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Path Sum (Easy)](https://leetcode.com/problems/path-sum/)
* [Binary Tree Maximum Path Sum (Hard)](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
* [Smallest String Starting From Leaf (Medium)](https://leetcode.com/problems/smallest-string-starting-from-leaf/)

## Solution 1. Pre-order traversal (Recursive)

```cpp
// OJ: https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int ans = 0;
    void dfs(TreeNode *root, int sum) {
        if (!root) return;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) ans += sum;
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int sumNumbers(TreeNode* root, int sum = 0) {
        if (!root) return 0;
        sum = 10 * sum + root->val;
        if (!root->left && !root->right) return sum;
        return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
    }
};
```

## Solution 2. Pre-order traversal (Iterative)

```cpp
// OJ: https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        stack<pair<TreeNode*, int>> s;
        s.emplace(root, 0);
        int ans = 0;
        while (s.size()) {
            auto p = s.top();
            root = p.first;
            int sum = p.second * 10 + root->val;
            s.pop();
            if (!root->left && !root->right) ans += sum;
            if (root->right) s.emplace(root->right, sum);
            if (root->left) s.emplace(root->left, sum);
        }
        return ans;
    }
};
```