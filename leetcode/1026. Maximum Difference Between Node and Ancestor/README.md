# [1026. Maximum Difference Between Node and Ancestor (Medium)](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/)

<p>Given the <code>root</code> of a binary tree, find the maximum value <code>V</code> for which there exists <strong>different</strong> nodes <code>A</code> and <code>B</code> where <code>V = |A.val - B.val|</code>&nbsp;and <code>A</code> is an ancestor of <code>B</code>.</p>

<p>(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/09/09/2whqcep.jpg" style="height: 230px; width: 300px;"></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[8,3,10,1,6,null,14,null,null,4,7,13]</span>
<strong>Output: </strong><span id="example-output-1">7</span>
<strong>Explanation: </strong>
We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li>The number of nodes in the tree is between <code>2</code> and <code>5000</code>.</li>
	<li>Each node will have value between <code>0</code> and <code>100000</code>.</li>
</ol>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(H)
class Solution {
    multiset<int> s;
    int ans = 0;
    void preorder(TreeNode *root) {
        if (!root) return;
        if (s.size()) ans = max({ ans, abs(*s.begin() - root->val), abs(*s.rbegin() - root->val) });
        s.insert(root->val);
        preorder(root->left);
        preorder(root->right);
        s.erase(s.find(root->val));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        preorder(root);
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int dfs(TreeNode *root, int mn, int mx) {
        if (!root) return mx - mn;
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        return max(dfs(root->left, mn, mx), dfs(root->right, mn, mx));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};
```