# [2476. Closest Nodes Queries in a Binary Search Tree (Medium)](https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree)

<p>You are given the <code>root</code> of a <strong>binary search tree </strong>and an array <code>queries</code> of size <code>n</code> consisting of positive integers.</p>
<p>Find a <strong>2D</strong> array <code>answer</code> of size <code>n</code> where <code>answer[i] = [min<sub>i</sub>, max<sub>i</sub>]</code>:</p>
<ul>
	<li><code>min<sub>i</sub></code> is the <strong>largest</strong> value in the tree that is smaller than or equal to <code>queries[i]</code>. If a such value does not exist, add <code>-1</code> instead.</li>
	<li><code>max<sub>i</sub></code> is the <strong>smallest</strong> value in the tree that is greater than or equal to <code>queries[i]</code>. If a such value does not exist, add <code>-1</code> instead.</li>
</ul>
<p>Return <em>the array</em> <code>answer</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/09/28/bstreeedrawioo.png" style="width: 261px; height: 281px;">
<pre><strong>Input:</strong> root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], queries = [2,5,16]
<strong>Output:</strong> [[2,2],[4,6],[15,-1]]
<strong>Explanation:</strong> We answer the queries in the following way:
- The largest number that is smaller or equal than 2 in the tree is 2, and the smallest number that is greater or equal than 2 is still 2. So the answer for the first query is [2,2].
- The largest number that is smaller or equal than 5 in the tree is 4, and the smallest number that is greater or equal than 5 is 6. So the answer for the second query is [4,6].
- The largest number that is smaller or equal than 16 in the tree is 15, and the smallest number that is greater or equal than 16 does not exist. So the answer for the third query is [15,-1].
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/09/28/bstttreee.png" style="width: 101px; height: 121px;">
<pre><strong>Input:</strong> root = [4,null,9], queries = [3]
<strong>Output:</strong> [[-1,4]]
<strong>Explanation:</strong> The largest number that is smaller or equal to 3 in the tree does not exist, and the smallest number that is greater or equal to 3 is 4. So the answer for the query is [-1,4].
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li>The number of nodes in the tree is in the range <code>[2, 10<sup>5</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
	<li><code>n == queries.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries[i] &lt;= 10<sup>6</sup></code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Closest Binary Search Tree Value (Easy)](https://leetcode.com/problems/closest-binary-search-tree-value/)
* [Closest Binary Search Tree Value II (Hard)](https://leetcode.com/problems/closest-binary-search-tree-value-ii/)
* [Search in a Binary Search Tree (Easy)](https://leetcode.com/problems/search-in-a-binary-search-tree/)

## Solution 1. Offline Query

```cpp
// OJ: https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree
// Author: github.com/lzl124631x
// Time: O(QlogQ + N)
// Space: O(Q + H)
class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& Q) {
        int N = Q.size(), i = 0, prev = -1;
        vector<int> id(N);
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](int a, int b) { return Q[a] < Q[b]; });
        vector<vector<int>> ans(N);
        stack<TreeNode*> s;
        while ((root || s.size()) && i < N) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            for (; i < N && Q[id[i]] <= root->val; ++i) {
                ans[id[i]] = {Q[id[i]] == root->val ? root->val : prev, root->val};
            }
            prev = root->val;
            root = root->right;
        }
        for (; i < N; ++i) ans[id[i]] = {prev, -1};
        return ans;
    }
};
```