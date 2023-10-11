# [2251. Number of Flowers in Full Bloom (Hard)](https://leetcode.com/problems/number-of-flowers-in-full-bloom)

<p>You are given a <strong>0-indexed</strong> 2D integer array <code>flowers</code>, where <code>flowers[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> means the <code>i<sup>th</sup></code> flower will be in <strong>full bloom</strong> from <code>start<sub>i</sub></code> to <code>end<sub>i</sub></code> (<strong>inclusive</strong>). You are also given a <strong>0-indexed</strong> integer array <code>people</code> of size <code>n</code>, where <code>people[i]</code> is the time that the <code>i<sup>th</sup></code> person will arrive to see the flowers.</p>

<p>Return <em>an integer array </em><code>answer</code><em> of size </em><code>n</code><em>, where </em><code>answer[i]</code><em> is the <strong>number</strong> of flowers that are in full bloom when the </em><code>i<sup>th</sup></code><em> person arrives.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/02/ex1new.jpg" style="width: 550px; height: 216px;" />
<pre>
<strong>Input:</strong> flowers = [[1,6],[3,7],[9,12],[4,13]], poeple = [2,3,7,11]
<strong>Output:</strong> [1,2,2,2]
<strong>Explanation: </strong>The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/02/ex2new.jpg" style="width: 450px; height: 195px;" />
<pre>
<strong>Input:</strong> flowers = [[1,10],[3,3]], poeple = [3,3,2]
<strong>Output:</strong> [2,2,1]
<strong>Explanation:</strong> The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= flowers.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>flowers[i].length == 2</code></li>
	<li><code>1 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= people.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= people[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Binary Search](https://leetcode.com/tag/binary-search), [Sorting](https://leetcode.com/tag/sorting), [Prefix Sum](https://leetcode.com/tag/prefix-sum), [Ordered Set](https://leetcode.com/tag/ordered-set)

**Similar Questions**:
* [Meeting Rooms II (Medium)](https://leetcode.com/problems/meeting-rooms-ii)
* [Minimum Interval to Include Each Query (Hard)](https://leetcode.com/problems/minimum-interval-to-include-each-query)

**Hints**:
* Notice that for any given time t, the number of flowers blooming at time t is equal to the number of flowers that have started blooming minus the number of flowers that have already stopped blooming.
* We can obtain these values efficiently using binary search.
* We can store the starting times in sorted order, which then allows us to binary search to find how many flowers have started blooming for a given time t.
* We do the same for the ending times to find how many flowers have stopped blooming at time t.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-flowers-in-full-bloom
// Author: github.com/lzl124631x
// Time: O(FlogF + PlogP + PlogF)
// Space: O(F + P)
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& F, vector<int>& P) {
        int M = F.size(), N = P.size();
        vector<int> ans(N), id(N);
        iota(begin(id), end(id), 0); // people ids
        sort(begin(id), end(id), [&](int a, int b) { return P[a] < P[b]; }); // Sort people
        sort(begin(F), end(F)); // sort flowers in ascending order of start time
        priority_queue<int, vector<int>, greater<>> pq; // a min heap of blooming flowers' end times
        for (int i = 0, j = 0; i < N; ++i) {
            int p = P[id[i]];
            while (j < M && F[j][0] <= p) pq.push(F[j++][1]); // push end time of flowers that `<=` people[i]'s arrival time into the min heap
            while (pq.size() && pq.top() < p) pq.pop(); // remove flowers that ended blooming before people[i]'s arrival time from the min heap
            ans[id[i]] = pq.size();
        }
        return ans;
    }
};
```