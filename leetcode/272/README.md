# [272. Closest Binary Search Tree Value II (Hard)](https://leetcode.com/problems/closest-binary-search-tree-value-ii)

<p>Given the <code>root</code> of a binary search tree, a <code>target</code> value, and an integer <code>k</code>, return <em>the </em><code>k</code><em> values in the BST that are closest to the</em> <code>target</code>. You may return the answer in <strong>any order</strong>.</p>
<p>You are <strong>guaranteed</strong> to have only one unique set of <code>k</code> values in the BST that are closest to the <code>target</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/12/closest1-1-tree.jpg" style="width: 292px; height: 302px;">
<pre><strong>Input:</strong> root = [4,2,5,1,3], target = 3.714286, k = 2
<strong>Output:</strong> [4,3]
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> root = [1], target = 0.000000, k = 1
<strong>Output:</strong> [1]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li>The number of nodes in the tree is <code>n</code>.</li>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>4</sup></code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>
<p>&nbsp;</p>
<p><strong>Follow up:</strong> Assume that the BST is balanced. Could you solve it in less than <code>O(n)</code> runtime (where <code>n = total nodes</code>)?</p>

**Companies**:
[LinkedIn](https://leetcode.com/company/linkedin), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Binary Tree Inorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-inorder-traversal/)
* [Closest Binary Search Tree Value (Easy)](https://leetcode.com/problems/closest-binary-search-tree-value/)
* [Closest Nodes Queries in a Binary Search Tree (Medium)](https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/)

## Solution 1. DFS + Heap

```cpp
// OJ: https://leetcode.com/problems/closest-binary-search-tree-value-ii
// Author: github.com/lzl124631x
// Time: O(NlogK)
// Space: O(H + K)
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        typedef pair<double, int> Node;
        auto cmp = [&](auto &a, auto &b) { return a.first < b.first; };
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
        function<void(TreeNode*)> dfs = [&](TreeNode *node) {
            if (!node) return;
            double d = abs(target - node->val);
            pq.emplace(d, node->val);
            if (pq.size() > k) pq.pop();
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        vector<int> ans;
        while (pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
```