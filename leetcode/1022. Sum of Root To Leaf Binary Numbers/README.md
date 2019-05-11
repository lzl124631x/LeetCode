# [1022. Sum of Root To Leaf Binary Numbers (Easy)](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/)

<p>Given a binary tree, each node has value <code>0</code>&nbsp;or <code>1</code>.&nbsp; Each root-to-leaf path represents a binary number starting with the most significant bit.&nbsp; For example, if the path is <code>0 -&gt; 1 -&gt; 1 -&gt; 0 -&gt; 1</code>, then this could represent <code>01101</code> in binary, which is <code>13</code>.</p>

<p>For all leaves in the tree, consider the numbers represented by the path&nbsp;from the root to that leaf.</p>

<p>Return the sum of these numbers.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<p><span id="example-output-1"><img alt="" src="https://assets.leetcode.com/uploads/2019/04/04/sum-of-root-to-leaf-binary-numbers.png" style="width: 304px; height: 200px;"></span></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,0,1,0,1,0,1]</span>
<strong>Output: </strong><span id="example-output-1">22</span>
<strong>Explanation: </strong>(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li>The number of nodes in the tree is between <code>1</code> and <code>1000</code>.</li>
	<li>node.val is <code>0</code> or <code>1</code>.</li>
	<li>The answer will not exceed <code>2^31 - 1</code>.</li>
</ol>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    int sum = 0, num = 0;
public:
    int sumRootToLeaf(TreeNode* root) {
        if (!root) return 0;
        num = num * 2 + root->val;
        if (!root->left && !root->right) sum += num;
        else {
            sumRootToLeaf(root->left);
            sumRootToLeaf(root->right);
        }
        num /= 2;
        return sum;
    }
};
```