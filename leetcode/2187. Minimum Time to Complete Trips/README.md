# [2187. Minimum Time to Complete Trips (Medium)](https://leetcode.com/problems/minimum-time-to-complete-trips/)

<p>You are given an array <code>time</code> where <code>time[i]</code> denotes the time taken by the <code>i<sup>th</sup></code> bus to complete <strong>one trip</strong>.</p>

<p>Each bus can make multiple trips <strong>successively</strong>; that is, the next trip can start <strong>immediately after</strong> completing the current trip. Also, each bus operates <strong>independently</strong>; that is, the trips of one bus do not influence the trips of any other bus.</p>

<p>You are also given an integer <code>totalTrips</code>, which denotes the number of trips all buses should make <strong>in total</strong>. Return <em>the <strong>minimum time</strong> required for all buses to complete <strong>at least</strong> </em><code>totalTrips</code><em> trips</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> time = [1,2,3], totalTrips = 5
<strong>Output:</strong> 3
<strong>Explanation:</strong>
- At time t = 1, the number of trips completed by each bus are [1,0,0]. 
  The total number of trips completed is 1 + 0 + 0 = 1.
- At time t = 2, the number of trips completed by each bus are [2,1,0]. 
  The total number of trips completed is 2 + 1 + 0 = 3.
- At time t = 3, the number of trips completed by each bus are [3,1,1]. 
  The total number of trips completed is 3 + 1 + 1 = 5.
So the minimum time needed for all buses to complete at least 5 trips is 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> time = [2], totalTrips = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong>
There is only one bus, and it will complete its first trip at t = 2.
So the minimum time needed to complete 1 trip is 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= time.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= time[i], totalTrips &lt;= 10<sup>7</sup></code></li>
</ul>


**Similar Questions**:
* [Minimum Speed to Arrive on Time (Medium)](https://leetcode.com/problems/minimum-speed-to-arrive-on-time/)
* [Minimized Maximum of Products Distributed to Any Store (Medium)](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/)
* [Maximum Running Time of N Computers (Hard)](https://leetcode.com/problems/maximum-running-time-of-n-computers/)

## Solution 1. Binary Search

This problem is a classic binary search setup -- there is a breakpoint `m` where all `time < m` are invalid and all `time >= m` are valid. Here `valid` means that we can finish at least `totalTrips` trips given `time`.

We can check whether a `time` is valid in `O(N)` time by traversing `A`.

```cpp
// OJ: https://leetcode.com/problems/minimum-time-to-complete-trips/
// Author: github.com/lzl124631x
// Time: O(NlogM) where M is the maximum possible answer
// Space: O(1)
class Solution {
public:
    long long minimumTime(vector<int>& A, int totalTrips) {
        long long L = 1, R = LONG_MAX;
        auto valid = [&](long long time) { // returns true if we can finish `totalTrips` trips given `time`
            long long sum = 0;
            for (long long n : A) {
                sum += time / n;
                if (sum >= totalTrips) return true; 
            }
            return false;
        };
        while (L <= R) {
            long long M = L + (R - L) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
```

## Discuss

https://leetcode.com/problems/minimum-time-to-complete-trips/discuss/1802417/