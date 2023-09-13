# [968. Binary Tree Cameras (Hard)](https://leetcode.com/problems/binary-tree-cameras/)

<p>Given a binary tree, we install cameras on the nodes of the tree.&nbsp;</p>

<p>Each camera at&nbsp;a node can monitor <strong>its parent, itself, and its immediate children</strong>.</p>

<p>Calculate the minimum number of cameras needed to monitor all nodes of the tree.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_01.png" style="width: 138px; height: 163px;">
<div>
<pre><strong>Input: </strong><span id="example-input-1-1">[0,0,null,0,0]</span>
<strong>Output: </strong><span id="example-output-1">1</span>
<strong>Explanation: </strong>One camera is enough to monitor all nodes if placed as shown.
</pre>

<div>
<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_02.png" style="width: 139px; height: 312px;">
<pre><strong>Input: </strong><span id="example-input-2-1">[0,0,null,0,null,0,null,null,0]</span>
<strong>Output: </strong><span id="example-output-2">2
<strong>Explanation:</strong> At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.</span>
</pre>

<p><br>
<strong>Note:</strong></p>

<ol>
	<li>The number of nodes in the given tree will be in the range&nbsp;<code>[1, 1000]</code>.</li>
	<li><strong>Every</strong> node has value 0.</li>
</ol>
</div>
</div>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1.

Assumption: we can alter the value of the tree node.

Use postorder traversal. Let `val` convey the state of the node:
* 0 means uncovered.
* 1 means covered
* 2 means having camera

If `node` is `NULL`, we regard it as `1`.

* If either of my left/right child is uncovered, I have to put a camera.
* Otherwise, if either of my left/right child has camera, I'm covered and skip me.
* Otherwise (both children are covered), if I'm root, I have to put a camera.
* Otherwise, skip me.

```cpp
// OJ: https://leetcode.com/problems/binary-tree-cameras/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
    TreeNode *R;
    int postorder(TreeNode* root) {
        if (!root) return 0;
        int ans = postorder(root->left) + postorder(root->right);
        int left = root->left ? root->left->val : 1;
        int right = root->right ? root->right->val : 1;
        if (left == 0 || right == 0) {
            root->val = 2;
            return ans + 1;
        } else if (left == 2 || right == 2) {
            root->val = 1;
            return ans;
        } else return root == R ? ans + 1 : ans;
    }
public:
    int minCameraCover(TreeNode* root) {
        R = root;
        return postorder(root);
    }
};
```

## Solution 2.

If we can't have the assumption in Solution 1, we can use the return value to return my state to my parent.

```cpp
// OJ: https://leetcode.com/problems/binary-tree-cameras/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
    int ans = 0;
    int postorder(TreeNode *root) {
        if (!root) return 1;
        int left = postorder(root->left);
        int right = postorder(root->right);
        if (left == 0 || right == 0) {
            ++ans;
            return 2;
        } else return left == 2 || right == 2 ? 1 : 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        return postorder(root) == 0 ? ans + 1 : ans;
    }
};
```