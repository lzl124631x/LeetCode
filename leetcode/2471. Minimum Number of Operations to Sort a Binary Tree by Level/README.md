# [2471. Minimum Number of Operations to Sort a Binary Tree by Level (Medium)](https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level)

<p>You are given the <code>root</code> of a binary tree with <strong>unique values</strong>.</p>
<p>In one operation, you can choose any two nodes <strong>at the same level</strong> and swap their values.</p>
<p>Return <em>the minimum number of operations needed to make the values at each level sorted in a <strong>strictly increasing order</strong></em>.</p>
<p>The <strong>level</strong> of a node is the number of edges along the path between it and the root node<em>.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/09/18/image-20220918174006-2.png" style="width: 500px; height: 324px;">
<pre><strong>Input:</strong> root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
- Swap 4 and 3. The 2<sup>nd</sup> level becomes [3,4].
- Swap 7 and 5. The 3<sup>rd</sup> level becomes [5,6,8,7].
- Swap 8 and 7. The 3<sup>rd</sup> level becomes [5,6,7,8].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/09/18/image-20220918174026-3.png" style="width: 400px; height: 303px;">
<pre><strong>Input:</strong> root = [1,3,2,7,6,5,4]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
- Swap 3 and 2. The 2<sup>nd</sup> level becomes [2,3].
- Swap 7 and 4. The 3<sup>rd</sup> level becomes [4,6,5,7].
- Swap 6 and 5. The 3<sup>rd</sup> level becomes [4,5,6,7].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.
</pre>
<p><strong class="example">Example 3:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/09/18/image-20220918174052-4.png" style="width: 400px; height: 274px;">
<pre><strong>Input:</strong> root = [1,2,3,4,5,6]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Each level is already sorted in increasing order so return 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li>All the values of the tree are <strong>unique</strong>.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Binary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-level-order-traversal/)
* [Longest Cycle in a Graph (Hard)](https://leetcode.com/problems/longest-cycle-in-a-graph/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        int ans = 0;
        while (q.size()) {
            int cnt = q.size();
            vector<int> v, id(cnt);
            iota(begin(id), end(id), 0);
            while (cnt--) {
                auto n = q.front();
                q.pop();
                v.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            sort(begin(id), end(id), [&](int a, int b) { return v[a] < v[b]; });
            for (int i = 0; i < id.size(); ++i) {
                while (id[i] != i) {
                    swap(id[i], id[id[i]]);
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```