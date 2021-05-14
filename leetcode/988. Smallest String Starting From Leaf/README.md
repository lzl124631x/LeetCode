# [988. Smallest String Starting From Leaf (Medium)](https://leetcode.com/problems/smallest-string-starting-from-leaf/)

<p>Given the <code>root</code> of a binary tree, each node has a value from <code>0</code> to <code>25</code> representing the letters <code>'a'</code> to <code>'z'</code>: a value of <code>0</code> represents <code>'a'</code>, a value of <code>1</code> represents <code>'b'</code>, and so on.</p>

<p>Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.</p>

<p><em>(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, <code>"ab"</code> is lexicographically smaller than <code>"aba"</code>.&nbsp; A leaf of a node is a node that has no children.)</em></p>

<div>
<div>
<p>&nbsp;</p>

<ol>
</ol>
</div>
</div>

<div>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/01/30/tree1.png" style="width: 160px; height: 107px;"></strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[0,1,2,3,4,3,4]</span>
<strong>Output: </strong><span id="example-output-1">"dba"</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/01/30/tree2.png" style="width: 160px; height: 107px;"></strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[25,1,3,1,3,0,2]</span>
<strong>Output: </strong><span id="example-output-2">"adz"</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/02/01/tree3.png" style="height: 170px; width: 172px;"></strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[2,2,1,null,1,0,null,0]</span>
<strong>Output: </strong><span id="example-output-3">"abc"</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li>The number of nodes in the given tree will be between <code>1</code> and <code>8500</code>.</li>
	<li>Each node in the tree will have a value between <code>0</code> and <code>25</code>.</li>
</ol>
</div>
</div>
</div>

**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Sum Root to Leaf Numbers (Medium)](https://leetcode.com/problems/sum-root-to-leaf-numbers/)
* [Binary Tree Paths (Easy)](https://leetcode.com/problems/binary-tree-paths/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/smallest-string-starting-from-leaf/
// Author: github.com/lzl124631x
// Time: O(N + (logN)^2)
// Space: O(logN)
class Solution {
    string ans, path;
    void dfs(TreeNode *root) {
        if (!root) return;
        path += 'a' + root->val;
        if (!root->left && !root->right) {
            reverse(begin(path), end(path));
            if (ans.empty() || path < ans) ans = path;
            reverse(begin(path), end(path));
        } else {
            dfs(root->left);
            dfs(root->right);
        }
        path.pop_back();
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```