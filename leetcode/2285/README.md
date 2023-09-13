# [2285. Maximum Total Importance of Roads (Medium)](https://leetcode.com/problems/maximum-total-importance-of-roads)

<p>You are given an integer <code>n</code> denoting the number of cities in a country. The cities are numbered from <code>0</code> to <code>n - 1</code>.</p>
<p>You are also given a 2D integer array <code>roads</code> where <code>roads[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> denotes that there exists a <strong>bidirectional</strong> road connecting cities <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code>.</p>
<p>You need to assign each city with an integer value from <code>1</code> to <code>n</code>, where each value can only be used <strong>once</strong>. The <strong>importance</strong> of a road is then defined as the <strong>sum</strong> of the values of the two cities it connects.</p>
<p>Return <em>the <strong>maximum total importance</strong> of all roads possible after assigning the values optimally.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/04/07/ex1drawio.png" style="width: 290px; height: 215px;">
<pre><strong>Input:</strong> n = 5, roads = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
<strong>Output:</strong> 43
<strong>Explanation:</strong> The figure above shows the country and the assigned values of [2,4,5,3,1].
- The road (0,1) has an importance of 2 + 4 = 6.
- The road (1,2) has an importance of 4 + 5 = 9.
- The road (2,3) has an importance of 5 + 3 = 8.
- The road (0,2) has an importance of 2 + 5 = 7.
- The road (1,3) has an importance of 4 + 3 = 7.
- The road (2,4) has an importance of 5 + 1 = 6.
The total importance of all roads is 6 + 9 + 8 + 7 + 7 + 6 = 43.
It can be shown that we cannot obtain a greater total importance than 43.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/04/07/ex2drawio.png" style="width: 281px; height: 151px;">
<pre><strong>Input:</strong> n = 5, roads = [[0,3],[2,4],[1,3]]
<strong>Output:</strong> 20
<strong>Explanation:</strong> The figure above shows the country and the assigned values of [4,3,2,5,1].
- The road (0,3) has an importance of 4 + 5 = 9.
- The road (2,4) has an importance of 2 + 1 = 3.
- The road (1,3) has an importance of 3 + 5 = 8.
The total importance of all roads is 9 + 3 + 8 = 20.
It can be shown that we cannot obtain a greater total importance than 20.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= roads.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>roads[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>There are no duplicate roads.</li>
</ul>

**Companies**:
[HRT](https://leetcode.com/company/hrt)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/), [Graph](https://leetcode.com/tag/graph/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-total-importance-of-roads
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& E) {
        vector<int> degree(n);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            degree[u]++;
            degree[v]++;
        }
        sort(begin(degree), end(degree), greater<>());
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long long)degree[i] * (n - i);
        }
        return ans;
    }
};
```