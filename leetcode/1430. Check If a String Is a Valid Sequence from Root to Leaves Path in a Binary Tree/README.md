# [1430. Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree (Medium)](https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree/)

<div class="question-detail"><div class="question-description__3U1T"><div><p>Given a binary tree where each path going from the root to any leaf form a <strong>valid sequence</strong>, check if a given string&nbsp;is a <strong>valid sequence</strong> in such binary tree.&nbsp;</p>

<p>We get the given string from the concatenation of an array of integers <code>arr</code> and the concatenation of all&nbsp;values of the nodes along a path results in a <strong>sequence</strong> in the given binary tree.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/leetcode_testcase_1.png" style="width: 333px; height: 250px;"></strong></p>

<pre><strong>Input:</strong> root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
<strong>Output:</strong> true
<strong>Explanation: 
</strong>The path 0 -&gt; 1 -&gt; 0 -&gt; 1 is a valid sequence (green color in the figure). 
Other valid sequences are: 
0 -&gt; 1 -&gt; 1 -&gt; 0 
0 -&gt; 0 -&gt; 0
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/leetcode_testcase_2.png" style="width: 333px; height: 250px;"></strong></p>

<pre><strong>Input:</strong> root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
<strong>Output:</strong> false 
<strong>Explanation:</strong> The path 0 -&gt; 0 -&gt; 1 does not exist, therefore it is not even a sequence.
</pre>

<p><strong>Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/leetcode_testcase_3.png" style="width: 333px; height: 250px;"></strong></p>

<pre><strong>Input:</strong> root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
<strong>Output:</strong> false
<strong>Explanation: </strong>The path 0 -&gt; 1 -&gt; 1 is a sequence, but it is not a valid sequence.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 5000</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 9</code></li>
	<li>Each node's value is between [0 - 9].</li>
</ul></div></div></div>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    bool dfs(TreeNode* root, vector<int> &A, int i) {
        if (i >= A.size()) return false;
        if (!root || root->val != A[i]) return false;
        if (i == A.size() - 1) return !root->left && !root->right;
        return dfs(root->left, A, i + 1) || dfs(root->right, A, i + 1);
    }
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if (!root) return arr.size() == 0;
        return dfs(root, arr, 0);
    }
};
```