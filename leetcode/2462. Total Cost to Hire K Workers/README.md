# [2462. Total Cost to Hire K Workers (Medium)](https://leetcode.com/problems/total-cost-to-hire-k-workers)

<p>You are given a <strong>0-indexed</strong> integer array <code>costs</code> where <code>costs[i]</code> is the cost of hiring the <code>i<sup>th</sup></code> worker.</p>
<p>You are also given two integers <code>k</code> and <code>candidates</code>. We want to hire exactly <code>k</code> workers according to the following rules:</p>
<ul>
	<li>You will run <code>k</code> sessions and hire exactly one worker in each session.</li>
	<li>In each hiring session, choose the worker with the lowest cost from either the first <code>candidates</code> workers or the last <code>candidates</code> workers. Break the tie by the smallest index.
	<ul>
		<li>For example, if <code>costs = [3,2,7,7,1,2]</code> and <code>candidates = 2</code>, then in the first hiring session, we will choose the <code>4<sup>th</sup></code> worker because they have the lowest cost <code>[<u>3,2</u>,7,7,<u><strong>1</strong>,2</u>]</code>.</li>
		<li>In the second hiring session, we will choose <code>1<sup>st</sup></code> worker because they have the same lowest cost as <code>4<sup>th</sup></code> worker but they have the smallest index <code>[<u>3,<strong>2</strong></u>,7,<u>7,2</u>]</code>. Please note that the indexing may be changed in the process.</li>
	</ul>
	</li>
	<li>If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.</li>
	<li>A worker can only be chosen once.</li>
</ul>
<p>Return <em>the total cost to hire exactly </em><code>k</code><em> workers.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
<strong>Output:</strong> 11
<strong>Explanation:</strong> We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [<u>17,12,10,2</u>,7,<u>2,11,20,8</u>]. The lowest cost is 2, and we break the tie by the smallest index, which is 3. The total cost = 0 + 2 = 2.
- In the second hiring round we choose the worker from [<u>17,12,10,7</u>,<u>2,11,20,8</u>]. The lowest cost is 2 (index 4). The total cost = 2 + 2 = 4.
- In the third hiring round we choose the worker from [<u>17,12,10,7,11,20,8</u>]. The lowest cost is 7 (index 3). The total cost = 4 + 7 = 11. Notice that the worker with index 3 was common in the first and last four workers.
The total hiring cost is 11.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> costs = [1,2,4,1], k = 3, candidates = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [<u>1,2,4,1</u>]. The lowest cost is 1, and we break the tie by the smallest index, which is 0. The total cost = 0 + 1 = 1. Notice that workers with index 1 and 2 are common in the first and last 3 workers.
- In the second hiring round we choose the worker from [<u>2,4,1</u>]. The lowest cost is 1 (index 2). The total cost = 1 + 1 = 2.
- In the third hiring round there are less than three candidates. We choose the worker from the remaining workers [<u>2,4</u>]. The lowest cost is 2 (index 0). The total cost = 2 + 2 = 4.
The total hiring cost is 4.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= costs.length &lt;= 10<sup>5 </sup></code></li>
	<li><code>1 &lt;= costs[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k, candidates &lt;= costs.length</code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [MathWorks](https://leetcode.com/company/mathworks)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Meeting Rooms II (Medium)](https://leetcode.com/problems/meeting-rooms-ii/)
* [Time to Cross a Bridge (Hard)](https://leetcode.com/problems/time-to-cross-a-bridge/)

## Solution 1. Heap + Two Pointers

```cpp
// OJ: https://leetcode.com/problems/total-cost-to-hire-k-workers
// Author: github.com/lzl124631x
// Time: O((K + C) * logC)
// Space: O(C)
class Solution {
public:
    long long totalCost(vector<int>& A, int K, int C) {
        long long N = A.size(), i = 0, j = N - 1, ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int k = 0; k < C && i <= j; ++k, ++i) pq.emplace(A[i], i);
        for (int k = 0; k < C && i <= j; ++k, --j) pq.emplace(A[j], j);
        while (K--) {
            auto [c, index] = pq.top();
            pq.pop();
            ans += c;
            if (i <= j) {
                if (index < i) pq.emplace(A[i], i), ++i;
                else pq.emplace(A[j], j), --j;
            }
        }
        return ans;
    }
};
```