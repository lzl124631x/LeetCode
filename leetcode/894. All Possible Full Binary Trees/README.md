# [894. All Possible Full Binary Trees (Medium)](https://leetcode.com/problems/all-possible-full-binary-trees/)

<p>A <em>full binary tree</em>&nbsp;is a binary tree where each node has exactly 0 or 2&nbsp;children.</p>

<p>Return a list of all possible full binary trees with <code>N</code> nodes.&nbsp; Each element of the answer is the root node of one possible tree.</p>

<p>Each <code>node</code> of each&nbsp;tree in the answer <strong>must</strong> have <code>node.val = 0</code>.</p>

<p>You may return the final list of trees in any order.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">7</span>
<strong>Output: </strong><span id="example-output-1">[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]</span>
<strong>Explanation:</strong>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/22/fivetrees.png" style="width: 700px; height: 400px;">
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ul>
	<li><code>1 &lt;= N &lt;= 20</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Recursion](https://leetcode.com/tag/recursion/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/all-possible-full-binary-trees/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if (N % 2 == 0) return {};
        if (N == 1) return { new TreeNode(0) };
        vector<TreeNode*> ans;
        for (int i = 1; i <= N - 2; i += 2) {
            auto lefts = allPossibleFBT(i);
            auto rights = allPossibleFBT(N - i - 1);
            for (auto left : lefts) {
                for (auto right : rights) {
                    auto root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
```