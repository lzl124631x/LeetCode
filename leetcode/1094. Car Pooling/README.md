# [1094. Car Pooling (Medium)](https://leetcode.com/problems/car-pooling/)

<p>You are driving a vehicle that&nbsp;has <code>capacity</code> empty seats initially available for passengers.&nbsp; The vehicle <strong>only</strong> drives east (ie. it <strong>cannot</strong> turn around and drive west.)</p>

<p>Given a list of <code>trips</code>, <code>trip[i] = [num_passengers, start_location, end_location]</code>&nbsp;contains information about the <code>i</code>-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.&nbsp; The locations are given as the number of kilometers&nbsp;due east from your vehicle's initial location.</p>

<p>Return <code>true</code> if and only if&nbsp;it is possible to pick up and drop off all passengers for all the given trips.&nbsp;</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>trips = <span id="example-input-1-1">[[2,1,5],[3,3,7]]</span>, capacity = <span id="example-input-1-2">4</span>
<strong>Output: </strong><span id="example-output-1">false</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>trips = <span id="example-input-2-1">[[2,1,5],[3,3,7]]</span>, capacity = <span id="example-input-2-2">5</span>
<strong>Output: </strong><span id="example-output-2">true</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>trips = <span id="example-input-3-1">[[2,1,5],[3,5,7]]</span>, capacity = <span id="example-input-3-2">3</span>
<strong>Output: </strong><span id="example-output-3">true</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong>trips = <span id="example-input-4-1">[[3,2,7],[3,7,9],[8,3,9]]</span>, capacity = <span id="example-input-4-2">11</span>
<strong>Output: </strong><span id="example-output-4">true</span>
</pre>
</div>
</div>
</div>

<div>
<div>
<div>
<div>&nbsp;</div>
</div>
</div>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ol>
	<li><code>trips.length &lt;= 1000</code></li>
	<li><code>trips[i].length == 3</code></li>
	<li><code>1 &lt;= trips[i][0] &lt;= 100</code></li>
	<li><code>0 &lt;= trips[i][1] &lt; trips[i][2] &lt;= 1000</code></li>
	<li><code>1 &lt;=&nbsp;capacity &lt;= 100000</code></li>
</ol>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Meeting Rooms II (Medium)](https://leetcode.com/problems/meeting-rooms-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/car-pooling/
// Author: github.com/lzl124631x
// Time: O(T + P) where T is the size of `trips` and P is the count of distinct stops
// Space: O(P)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> m;
        for (auto &t : trips) {
            m[t[1]] += t[0];
            m[t[2]] -= t[0];
        }
        int cnt = 0;
        for (auto &[p, n] : m) {
            cnt += n;
            if (cnt > capacity) return false;
        }
        return true;
    }
};
```