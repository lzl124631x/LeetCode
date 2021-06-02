# [1120. Maximum Average Subtree (Medium)](https://leetcode.com/problems/maximum-average-subtree/)

<p>Given the <code>root</code> of a binary tree, find the maximum average value of any subtree of that tree.</p>

<p>(A subtree of a tree is any node of that tree plus all its descendants. The average value of a tree is the sum of its values, divided by the number of nodes.)</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/04/09/1308_example_1.png" style="width: 132px; height: 123px;"></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[5,6,1]</span>
<strong>Output: </strong><span id="example-output-1">6.00000</span>
<strong>Explanation: </strong>
For the node with value = 5 we have an average of (5 + 6 + 1) / 3 = 4.
For the node with value = 6 we have an average of 6 / 1 = 6.
For the node with value = 1 we have an average of 1 / 1 = 1.
So the answer is 6 which is the maximum.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li>The number of nodes in the tree is between <code>1</code> and <code>5000</code>.</li>
	<li>Each node will have a value between <code>0</code> and <code>100000</code>.</li>
	<li>Answers will be accepted as correct if they are within <code>10^-5</code> of the correct answer.</li>
</ol>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-average-subtree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    double ans = 0;
    pair<int, int> dfs(TreeNode *root) {
        if (!root) return {0,0};
        auto left = dfs(root->left), right = dfs(root->right);
        int sum = left.first + right.first + root->val, cnt = left.second + right.second + 1;
        ans = max(ans, (double)sum / cnt);
        return {sum, cnt};
    }
public:
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```