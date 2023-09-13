# [2673. Make Costs of Paths Equal in a Binary Tree (Medium)](https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree)

<p>You are given an integer <code>n</code> representing the number of nodes in a <strong>perfect binary tree</strong> consisting of nodes numbered from <code>1</code> to <code>n</code>. The root of the tree is node <code>1</code> and each node <code>i</code> in the tree has two children where the left child is the node <code>2 * i</code> and the right child is <code>2 * i + 1</code>.</p>
<p>Each node in the tree also has a <strong>cost</strong> represented by a given <strong>0-indexed</strong> integer array <code>cost</code> of size <code>n</code> where <code>cost[i]</code> is the cost of node <code>i + 1</code>. You are allowed to <strong>increment</strong> the cost of <strong>any</strong> node by <code>1</code> <strong>any</strong> number of times.</p>
<p>Return <em>the <strong>minimum</strong> number of increments you need to make the cost of paths from the root to each <strong>leaf</strong> node equal</em>.</p>
<p><strong>Note</strong>:</p>
<ul>
	<li>A <strong>perfect binary tree </strong>is a tree where each node, except the leaf nodes, has exactly 2 children.</li>
	<li>The <strong>cost of a path</strong> is the sum of costs of nodes in the path.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/04/04/binaryytreeedrawio-4.png">
<pre><strong>Input:</strong> n = 7, cost = [1,5,2,2,3,3,1]
<strong>Output:</strong> 6
<strong>Explanation:</strong> We can do the following increments:
- Increase the cost of node 4 one time.
- Increase the cost of node 3 three times.
- Increase the cost of node 7 two times.
Each path from the root to a leaf will have a total cost of 9.
The total increments we did is 1 + 3 + 2 = 6.
It can be shown that this is the minimum answer we can achieve.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/04/04/binaryytreee2drawio.png" style="width: 205px; height: 151px;">
<pre><strong>Input:</strong> n = 3, cost = [5,3,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The two paths already have equal total costs, so no increments are needed.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n + 1</code> is a power of <code>2</code></li>
	<li><code>cost.length == n</code></li>
	<li><code>1 &lt;= cost[i] &lt;= 10<sup>4</sup></code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/), [Tree](https://leetcode.com/tag/tree/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minIncrements(int n, vector<int>& A) {
        vector<int> maxSum(n);
        for (int i = n - 1; i > 0; --i) {
            int p = (i - 1) / 2;
            maxSum[p] = max(maxSum[p], maxSum[i] + A[i]); // maxSum[p] is the maximum path sum from node[p] (excluded) to leaf nodes.
        }
        int maxPathSum = A[0] + maxSum[0], ans = 0;
        for (int i = 0; 2 * i + 1 < n; ++i) {
            int left = 2 * i + 1, right = left + 1, addLeft = maxPathSum - A[i] - maxSum[left] - A[left], addRight = maxPathSum - A[i] - maxSum[right] - A[right];
            ans += addLeft + addRight;
            A[left] += A[i] + addLeft;
            A[right] += A[i] + addRight;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N) considering the space overwritten in `A`
class Solution {
public:
    int minIncrements(int n, vector<int>& A) {
        int ans = 0;
        for (int i = n / 2 - 1; i >= 0; --i) {
            int L = i * 2 + 1, R = i * 2 + 2;
            ans += abs(A[L] - A[R]);
            A[i] += max(A[L], A[R]);
        }
        return ans;
    }
};
```