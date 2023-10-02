# [2374. Node With Highest Edge Score (Medium)](https://leetcode.com/problems/node-with-highest-edge-score)

<p>You are given a directed graph with <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code>, where each node has <strong>exactly one</strong> outgoing edge.</p>
<p>The graph is represented by a given <strong>0-indexed</strong> integer array <code>edges</code> of length <code>n</code>, where <code>edges[i]</code> indicates that there is a <strong>directed</strong> edge from node <code>i</code> to node <code>edges[i]</code>.</p>
<p>The <strong>edge score</strong> of a node <code>i</code> is defined as the sum of the <strong>labels</strong> of all the nodes that have an edge pointing to <code>i</code>.</p>
<p>Return <em>the node with the highest <strong>edge score</strong></em>. If multiple nodes have the same <strong>edge score</strong>, return the node with the <strong>smallest</strong> index.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/06/20/image-20220620195403-1.png" style="width: 450px; height: 260px;">
<pre><strong>Input:</strong> edges = [1,0,0,0,0,7,7,5]
<strong>Output:</strong> 7
<strong>Explanation:</strong>
- The nodes 1, 2, 3 and 4 have an edge pointing to node 0. The edge score of node 0 is 1 + 2 + 3 + 4 = 10.
- The node 0 has an edge pointing to node 1. The edge score of node 1 is 0.
- The node 7 has an edge pointing to node 5. The edge score of node 5 is 7.
- The nodes 5 and 6 have an edge pointing to node 7. The edge score of node 7 is 5 + 6 = 11.
Node 7 has the highest edge score so return 7.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/06/20/image-20220620200212-3.png" style="width: 150px; height: 155px;">
<pre><strong>Input:</strong> edges = [2,0,0,2]
<strong>Output:</strong> 0
<strong>Explanation:</strong>
- The nodes 1 and 2 have an edge pointing to node 0. The edge score of node 0 is 1 + 2 = 3.
- The nodes 0 and 3 have an edge pointing to node 2. The edge score of node 2 is 0 + 3 = 3.
Nodes 0 and 2 both have an edge score of 3. Since node 0 has a smaller index, we return 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == edges.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= edges[i] &lt; n</code></li>
	<li><code>edges[i] != i</code></li>
</ul>

**Companies**:
[Juspay](https://leetcode.com/company/juspay)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [Sort Characters By Frequency (Medium)](https://leetcode.com/problems/sort-characters-by-frequency/)
* [Sort Array by Increasing Frequency (Easy)](https://leetcode.com/problems/sort-array-by-increasing-frequency/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/node-with-highest-edge-score
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int edgeScore(vector<int>& A) {
        long long N = A.size(), maxScore = -1, ans = 0;
        vector<long long> score(N);
        for (int i = 0; i < N; ++i) {
            score[A[i]] += i;
        }
        for (int i = 0; i < N; ++i) {
            if (score[i] > maxScore) {
                maxScore = score[i];
                ans = i;
            }
        }
        return ans;
    }
};
```