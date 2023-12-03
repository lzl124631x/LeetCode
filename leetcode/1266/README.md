# [1266. Minimum Time Visiting All Points (Easy)](https://leetcode.com/problems/minimum-time-visiting-all-points)

<p>On a 2D plane, there are <code>n</code> points with integer coordinates <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>. Return <em>the <strong>minimum time</strong> in seconds to visit all the points in the order given by </em><code>points</code>.</p>

<p>You can move according to these rules:</p>

<ul>
	<li>In <code>1</code> second, you can either:

	<ul>
		<li>move vertically by one&nbsp;unit,</li>
		<li>move horizontally by one unit, or</li>
		<li>move diagonally <code>sqrt(2)</code> units (in other words, move one unit vertically then one unit horizontally in <code>1</code> second).</li>
	</ul>
	</li>
	<li>You have to visit the points in the same order as they appear in the array.</li>
	<li>You are allowed to pass through points that appear later in the order, but these do not count as visits.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/11/14/1626_example_1.PNG" style="width: 500px; height: 428px;" />
<pre>
<strong>Input:</strong> points = [[1,1],[3,4],[-1,0]]
<strong>Output:</strong> 7
<strong>Explanation: </strong>One optimal path is <strong>[1,1]</strong> -&gt; [2,2] -&gt; [3,3] -&gt; <strong>[3,4] </strong>-&gt; [2,3] -&gt; [1,2] -&gt; [0,1] -&gt; <strong>[-1,0]</strong>   
Time from [1,1] to [3,4] = 3 seconds 
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> points = [[3,2],[-2,2]]
<strong>Output:</strong> 5
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>points.length == n</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 100</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-1000&nbsp;&lt;= points[i][0], points[i][1]&nbsp;&lt;= 1000</code></li>
</ul>


**Companies**:
[Apple](https://leetcode.com/company/apple), [Media.net](https://leetcode.com/company/medianet)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Math](https://leetcode.com/tag/math), [Geometry](https://leetcode.com/tag/geometry)

**Hints**:
* To walk from point A to point B there will be an optimal strategy to walk ?
* Advance in diagonal as possible then after that go in straight line.
* Repeat the process until visiting all the points.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-time-visiting-all-points/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int getDist(vector<int> &a, vector<int> &b) {
        return max(abs(a[0] - b[0]), abs(a[1] - b[1]));
    }
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 1; i < points.size(); ++i) {
            ans += getDist(points[i - 1], points[i]);
        }
        return ans;
    }
};
```