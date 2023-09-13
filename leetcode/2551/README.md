# [2551. Put Marbles in Bags (Hard)](https://leetcode.com/problems/put-marbles-in-bags)

<p>You have <code>k</code> bags. You are given a <strong>0-indexed</strong> integer array <code>weights</code> where <code>weights[i]</code> is the weight of the <code>i<sup>th</sup></code> marble. You are also given the integer <code>k.</code></p>
<p>Divide the marbles into the <code>k</code> bags according to the following rules:</p>
<ul>
	<li>No bag is empty.</li>
	<li>If the <code>i<sup>th</sup></code> marble and <code>j<sup>th</sup></code> marble are in a bag, then all marbles with an index between the <code>i<sup>th</sup></code> and <code>j<sup>th</sup></code> indices should also be in that same bag.</li>
	<li>If a bag consists of all the marbles with an index from <code>i</code> to <code>j</code> inclusively, then the cost of the bag is <code>weights[i] + weights[j]</code>.</li>
</ul>
<p>The <strong>score</strong> after distributing the marbles is the sum of the costs of all the <code>k</code> bags.</p>
<p>Return <em>the <strong>difference</strong> between the <strong>maximum</strong> and <strong>minimum</strong> scores among marble distributions</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> weights = [1,3,5,1], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
The distribution [1],[3,5,1] results in the minimal score of (1+1) + (3+1) = 6. 
The distribution [1,3],[5,1], results in the maximal score of (1+3) + (5+1) = 10. 
Thus, we return their difference 10 - 6 = 4.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> weights = [1, 3], k = 2
<strong>Output:</strong> 0
<strong>Explanation:</strong> The only distribution possible is [1],[3]. 
Since both the maximal and minimal score are the same, we return 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= k &lt;= weights.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= weights[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/)

## Solution 1. Greedy
 0 1 2 3
[1,3,5,1]
  v v 
For `N` weights, we have `N-1` possible split points, out of which we need to pick `K-1` split points.

If we split between `A[i]` and `A[i+1]`, we have `cost[i] = A[i] + A[i+1]`

If we need to find `K-1` split points resulting in the maximum score, we should greedily pick the `K-1` points with the highest costs.

Vice versa for minimum score.

So, we can compute `cost` array where `cost[i] = A[i] + A[i+1]`, sort `cost` array, then `maxScore` is the sum of the greatest `K-1` costs, and `minScore` is the sum of the smallest `K-1` costs.

```cpp
// OJ: https://leetcode.com/problems/put-marbles-in-bags
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    long long putMarbles(vector<int>& A, int K) {
        int N = A.size();
        if (N == K) return 0;
        vector<long long> cost(N - 1);
        for (int i = 0; i < N - 1; ++i) cost[i] = (long long)A[i] + A[i + 1];
        sort(begin(cost), end(cost));
        return accumulate(begin(cost) + N - K, end(cost), 0LL) - accumulate(begin(cost), begin(cost) + K - 1, 0LL);
    }
};
```