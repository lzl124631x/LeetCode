# [508. Most Frequent Subtree Sum (Medium)](https://leetcode.com/problems/most-frequent-subtree-sum/)

<p>Given the <code>root</code> of a binary tree, return the most frequent <strong>subtree sum</strong>. If there is a tie, return all the values with the highest frequency in any order.</p>

<p>The <strong>subtree sum</strong> of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/freq1-tree.jpg" style="width: 207px; height: 183px;">
<pre><strong>Input:</strong> root = [5,2,-3]
<strong>Output:</strong> [2,-3,4]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/freq2-tree.jpg" style="width: 207px; height: 183px;">
<pre><strong>Input:</strong> root = [5,2,-5]
<strong>Output:</strong> [2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Subtree of Another Tree (Easy)](https://leetcode.com/problems/subtree-of-another-tree/)
* [Count Nodes Equal to Sum of Descendants (Medium)](https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/most-frequent-subtree-sum/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(N)
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        int maxFreq = 0;
        unordered_map<int, int> m;
        function<int(TreeNode*)> dfs = [&](TreeNode *root) {
            if (!root) return 0;
            int left = dfs(root->left), right = dfs(root->right), sum = left + right + root->val, f = ++m[sum];
            if (f > maxFreq) maxFreq = f, ans = {sum};
            else if (f == maxFreq) ans.push_back(sum);
            return sum;
        };
        dfs(root);
        return ans;
    }
};
```