# [889. Construct Binary Tree from Preorder and Postorder Traversal (Medium)](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)

<p>Return any binary tree that matches the given preorder and postorder traversals.</p>

<p>Values in the traversals&nbsp;<code>pre</code> and <code>post</code>&nbsp;are distinct&nbsp;positive integers.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>pre = <span id="example-input-1-1">[1,2,4,5,3,6,7]</span>, post = <span id="example-input-1-2">[4,5,2,6,7,3,1]</span>
<strong>Output: </strong><span id="example-output-1">[1,2,3,4,5,6,7]</span>
</pre>

<p>&nbsp;</p>

<p><strong><span>Note:</span></strong></p>

<ul>
	<li><code>1 &lt;= pre.length == post.length &lt;= 30</code></li>
	<li><code>pre[]</code> and <code>post[]</code>&nbsp;are both permutations of <code>1, 2, ..., pre.length</code>.</li>
	<li>It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.</li>
</ul>
</div>


**Companies**:  
[Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
    TreeNode *construct(vector<int> &pre, int preBegin, int preEnd,
                       vector<int> &post, int postBegin, int postEnd) {
        if (preBegin >= preEnd) return NULL;
        auto node = new TreeNode(pre[preBegin]);
        if (preBegin + 1 < preEnd) {
            int leftVal = pre[preBegin + 1];
            int postMid = find(post.begin() + postBegin, post.begin() + postEnd - 1, leftVal) - post.begin();
            int postLeftLength = postMid - postBegin + 1;
            node->left = construct(pre, preBegin + 1, preBegin + 1 + postLeftLength,
                                   post, postBegin, postMid + 1);
            node->right = construct(pre, preBegin + 1 + postLeftLength, preEnd,
                                   post, postMid + 1, postEnd - 1);
        }
        return node;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return construct(pre, 0, pre.size(), post, 0, post.size());
    }
};
```