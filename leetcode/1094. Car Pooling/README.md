# [1094. Car Pooling (Medium)](https://leetcode.com/problems/car-pooling/)

<p>There is a car with <code>capacity</code> empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).</p>

<p>You are given the integer <code>capacity</code> and an array <code>trips</code> where <code>trips[i] = [numPassengers<sub>i</sub>, from<sub>i</sub>, to<sub>i</sub>]</code> indicates that the <code>i<sup>th</sup></code> trip has <code>numPassengers<sub>i</sub></code> passengers and the locations to pick them up and drop them off are <code>from<sub>i</sub></code> and <code>to<sub>i</sub></code> respectively. The locations are given as the number of kilometers due east from the car's initial location.</p>

<p>Return <code>true</code><em> if it is possible to pick up and drop off all passengers for all the given trips, or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> trips = [[2,1,5],[3,3,7]], capacity = 4
<strong>Output:</strong> false
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> trips = [[2,1,5],[3,3,7]], capacity = 5
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= trips.length &lt;= 1000</code></li>
	<li><code>trips[i].length == 3</code></li>
	<li><code>1 &lt;= numPassengers<sub>i</sub> &lt;= 100</code></li>
	<li><code>0 &lt;= from<sub>i</sub> &lt; to<sub>i</sub> &lt;= 1000</code></li>
	<li><code>1 &lt;= capacity &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Flipkart](https://leetcode.com/company/flipkart), [Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Bloomberg](https://leetcode.com/company/bloomberg), [DoorDash](https://leetcode.com/company/doordash)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Simulation](https://leetcode.com/tag/simulation/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Meeting Rooms II (Medium)](https://leetcode.com/problems/meeting-rooms-ii/)

## Solution 1. Difference Array

```cpp
// OJ: https://leetcode.com/problems/car-pooling/
// Author: github.com/lzl124631x
// Time: O(TlogP + P) where T is the size of `trips` and P is the count of distinct stops
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

Or

```cpp
// OJ: https://leetcode.com/problems/car-pooling/
// Author: github.com/lzl124631x
// Time: O(T + P)
// Space: O(P)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff[1001] = {};
        for (auto &v : trips) {
            diff[v[1]] += v[0];
            diff[v[2]] -= v[0];
        }
        int cnt = 0;
        for (int d : diff) {
            if ((cnt += d) > capacity) return false;
        }
        return true;
    }
};
```