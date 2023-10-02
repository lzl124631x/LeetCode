# [1214. Two Sum BSTs (Medium)](https://leetcode.com/problems/two-sum-bsts/)

<p>Given the roots of two binary search trees, <code>root1</code> and <code>root2</code>, return <code>true</code> if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer <code>target</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/10/ex1.png" style="width: 369px; height: 169px;">
<pre><strong>Input:</strong> root1 = [2,1,4], root2 = [1,0,3], target = 5
<strong>Output:</strong> true
<strong>Explanation: </strong>2 and 3 sum up to 5.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/10/ex2.png" style="width: 453px; height: 290px;">
<pre><strong>Input:</strong> root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in each tree is in the range <code>[1, 5000]</code>.</li>
	<li><code>-10<sup>9</sup> &lt;= Node.val, target &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/), [Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Two Sum IV - Input is a BST (Easy)](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/two-sum-bsts/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(HA + HB)
class Solution {
    void pushNodes(stack<TreeNode*> &s, TreeNode *n, bool right = false) {
        for (; n; n = right ? n->right : n->left) s.push(n);
    }
public:
    bool twoSumBSTs(TreeNode* a, TreeNode* b, int target) {
        stack<TreeNode*> sa, sb;
        pushNodes(sa, a);
        pushNodes(sb, b, true);
        while (sa.size() && sb.size()) {
            int sum = sa.top()->val + sb.top()->val;
            if (sum == target) return true;
            if (sum < target) {
                auto n = sa.top();
                sa.pop();
                pushNodes(sa, n->right);
            } else {
                auto n = sb.top();
                sb.pop();
                pushNodes(sb, n->left, true);
            }
        }
        return false;
    }
};
```