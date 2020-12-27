# [1288. Remove Covered Intervals (Medium)](https://leetcode.com/problems/remove-covered-intervals/)

<p>Given a list of <code>intervals</code>, remove all intervals that are covered by another interval in the list.</p>

<p>Interval <code>[a,b)</code> is covered by&nbsp;interval <code>[c,d)</code> if and only if <code>c &lt;= a</code> and <code>b &lt;= d</code>.</p>

<p>After doing so, return <em>the number of remaining intervals</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> intervals = [[1,4],[3,6],[2,8]]
<strong>Output:</strong> 2
<b>Explanation: </b>Interval [3,6] is covered by [2,8], therefore it is removed.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> intervals = [[1,4],[2,3]]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> intervals = [[0,10],[5,12]]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> intervals = [[3,10],[4,10],[5,11]]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> intervals = [[1,2],[1,4],[3,4]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 1000</code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>0 &lt;= intervals[i][0] &lt;&nbsp;intervals[i][1] &lt;= 10^5</code></li>
	<li>All the intervals are <strong>unique</strong>.</li>
</ul>

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/), [Sort](https://leetcode.com/tag/sort/), [Line Sweep](https://leetcode.com/tag/line-sweep/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/remove-covered-intervals/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; });
        int ans = A.size(), e = INT_MIN;
        for (auto &r : A) {
            if (r[1] <= e) --ans;
            else e = r[1];
        }
        return ans;
    }
};
```