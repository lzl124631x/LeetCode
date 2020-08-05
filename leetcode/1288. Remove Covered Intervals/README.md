# [1288. Remove Covered Intervals (Medium)](https://leetcode.com/problems/remove-covered-intervals/)

<p>Given a list of intervals, remove all intervals that are covered by another interval in the list.&nbsp;Interval <code>[a,b)</code> is covered by&nbsp;interval <code>[c,d)</code> if and only if <code>c &lt;= a</code> and <code>b &lt;= d</code>.</p>

<p>After doing so, return the number of remaining intervals.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> intervals = [[1,4],[3,6],[2,8]]
<strong>Output:</strong> 2
<b>Explanation: </b>Interval [3,6] is covered by [2,8], therefore it is removed.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 1000</code></li>
	<li><code>0 &lt;= intervals[i][0] &lt;&nbsp;intervals[i][1] &lt;= 10^5</code></li>
	<li><code>intervals[i] != intervals[j]</code>&nbsp;for all&nbsp;<code>i != j</code></li>
</ul>


**Related Topics**:  
[Line Sweep](https://leetcode.com/tag/line-sweep/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/remove-covered-intervals/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](vector<int> &a, vector<int> &b) { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });
        int ans = A.size(), end = INT_MIN;
        for (auto &r : A) {
            if (r[1] <= end) --ans;
            else end = r[1];
        }
        return ans;
    }
};
```