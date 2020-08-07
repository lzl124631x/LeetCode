# [987. Vertical Order Traversal of a Binary Tree (Medium)](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)

<p>Given a binary tree, return the <em>vertical order</em> traversal of its nodes&nbsp;values.</p>

<p>For each node at position <code>(X, Y)</code>, its left and right children respectively&nbsp;will be at positions <code>(X-1, Y-1)</code> and <code>(X+1, Y-1)</code>.</p>

<p>Running a vertical line from <code>X = -infinity</code> to <code>X = +infinity</code>, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing <code>Y</code> coordinates).</p>

<p>If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.</p>

<p>Return an list&nbsp;of non-empty reports in order of <code>X</code> coordinate.&nbsp; Every report will have a list of values of nodes.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/01/31/1236_example_1.PNG" style="width: 201px; height: 186px;"></p>

<div>
<pre><strong>Input: </strong><span id="example-input-1-1">[3,9,20,null,null,15,7]</span>
<strong>Output: </strong><span id="example-output-1">[[9],[3,15],[20],[7]]</span>
<strong>Explanation: </strong>
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).
</pre>

<div>
<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/01/31/tree2.png" style="width: 236px; height: 150px;"></strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[1,2,3,4,5,6,7]</span>
<strong>Output: </strong><span id="example-output-2">[[4],[2],[1,5,6],[3],[7]]</span>
<strong>Explanation: </strong>
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.
</pre>

<p>&nbsp;</p>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li>The tree will have between <font face="monospace">1</font>&nbsp;and <code>1000</code> nodes.</li>
	<li>Each node's value will be between <code>0</code> and <code>1000</code>.</li>
</ol>
</div>

<div>
<div>&nbsp;</div>
</div>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Tree](https://leetcode.com/tag/tree/)

## Solution 1.

Use a `map<int, map<int, multiset<int>>> m` to store the values -- `m[node->x][node->y].insert(node->val)`. (Using `set` instead of `multiset` can also pass this problem. I guess LeetCode uses the node values as IDs and assumes the uniqueness of the values. I used `multiset` here to be safe.)

In this way, the values are sorted first in asending order of the `x` values, then in asending order of `y` values, then in asending order of node values.

Note that we shouldn't sort the values with the same X values all together, we should only sort them if they **have the same position**, i.e. when **both their `x` and `y` values are equal**.

```cpp
// OJ: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
    map<int, map<int, multiset<int>>> m;
    void dfs(TreeNode *root, int x, int y) {
        if (!root) return;
        m[x][y].insert(root->val);
        dfs(root->left, x - 1, y + 1);
        dfs(root->right, x + 1, y + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for (auto &[x, mm] : m) {
            ans.emplace_back();
            for (auto &[y, vals] : mm) {
                for (int n : vals) ans.back().push_back(n);
            }
        }
        return ans;
    }
};
```