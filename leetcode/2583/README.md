# [2583. Kth Largest Sum in a Binary Tree (Medium)](https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree)

<p>You are given the <code>root</code> of a binary tree and a positive integer <code>k</code>.</p>

<p>The <strong>level sum</strong> in the tree is the sum of the values of the nodes that are on the <strong>same</strong> level.</p>

<p>Return<em> the </em><code>k<sup>th</sup></code><em> <strong>largest</strong> level sum in the tree (not necessarily distinct)</em>. If there are fewer than <code>k</code> levels in the tree, return <code>-1</code>.</p>

<p><strong>Note</strong> that two nodes are on the same level if they have the same distance from the root.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/12/14/binaryytreeedrawio-2.png" style="width: 301px; height: 284px;" />
<pre>
<strong>Input:</strong> root = [5,8,9,2,1,3,7,4,6], k = 2
<strong>Output:</strong> 13
<strong>Explanation:</strong> The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2<sup>nd</sup> largest level sum is 13.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/12/14/treedrawio-3.png" style="width: 181px; height: 181px;" />
<pre>
<strong>Input:</strong> root = [1,2,null,3], k = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong> The largest level sum is 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is <code>n</code>.</li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>


**Companies**:
[Bloomberg](https://leetcode.com/company/bloomberg), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search), [Tree](https://leetcode.com/tag/tree), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search)

**Similar Questions**:
* [Binary Tree Preorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-preorder-traversal)
* [Maximum Level Sum of a Binary Tree (Medium)](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree)

**Hints**:
* Find the sum of values of nodes on each level and return the kth largest one.
* To find the sum of the values of nodes on each level, you can use a DFS or BFS algorithm to traverse the tree and keep track of the level of each node.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree
// Author: github.com/lzl124631x
// Time: O(NlogK)
// Space: O(N + K)
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq;
        queue<TreeNode*> q{{root}};
        while (q.size()) {
            long long cnt = q.size(), sum = 0;
            while (cnt--) {
                auto n = q.front();
                q.pop();
                sum += n->val;
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            pq.push(sum);
            if (pq.size() > k) pq.pop();
        }
        return pq.size() == k ? pq.top() : -1;
    }
};
```