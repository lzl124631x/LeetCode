# [871. Minimum Number of Refueling Stops (Hard)](https://leetcode.com/problems/minimum-number-of-refueling-stops/)

<p>A car travels from a starting position to a destination which is <code>target</code> miles east of the starting position.</p>

<p>Along the way, there are gas stations.&nbsp; Each <code>station[i]</code>&nbsp;represents a gas station that is <code>station[i][0]</code> miles east of the starting position, and has <code>station[i][1]</code> liters of gas.</p>

<p>The car starts with an infinite tank of gas, which initially has&nbsp;<code>startFuel</code>&nbsp;liters of fuel in it.&nbsp; It uses 1 liter of gas per 1 mile that it drives.</p>

<p>When the car&nbsp;reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.</p>

<p>What is the least number of refueling stops the car must make in order to reach its destination?&nbsp; If it cannot reach the destination, return <code>-1</code>.</p>

<p>Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there.&nbsp; If the car reaches the destination with 0 fuel left, it is still considered to have arrived.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>target = <span id="example-input-1-1">1</span>, startFuel = <span id="example-input-1-2">1</span>, stations = <span id="example-input-1-3">[]</span>
<strong>Output: </strong><span id="example-output-1">0</span>
<strong>Explanation: </strong>We can reach the target without refueling.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>target = <span id="example-input-2-1">100</span>, startFuel = <span id="example-input-2-2">1</span>, stations = <span id="example-input-2-3">[[10,100]]</span>
<strong>Output: </strong><span id="example-output-2">-1</span>
<strong>Explanation: </strong>We can't reach the target (or even the first gas station).
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>target = <span id="example-input-3-1">100</span>, startFuel = <span id="example-input-3-2">10</span>, stations = <span id="example-input-3-3">[[10,60],[20,30],[30,30],[60,40]]</span>
<strong>Output: </strong><span id="example-output-3">2</span>
<strong>Explanation: </strong>
We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= target, startFuel, stations[i][1] &lt;= 10^9</code></li>
	<li><code>0 &lt;= stations.length &lt;= 500</code></li>
	<li><code>0 &lt; stations[0][0] &lt; stations[1][0] &lt; ... &lt; stations[stations.length-1][0] &lt; target</code></li>
</ol>
</div>
</div>
</div>


**Companies**:  
[Flipkart](https://leetcode.com/company/flipkart), [Google](https://leetcode.com/company/google), [Uber](https://leetcode.com/company/uber), [Snapchat](https://leetcode.com/company/snapchat)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Heap](https://leetcode.com/tag/heap/)

## Solution 1.

Let `dp[i + 1][j]` be the maximum distance we can get with `0~i` stations and `j` times of fueling.

The result is the minimal `0 <= j <= N` that `dp[N][j] >= target`

```
dp[i + 1][j] = max(
                                            // if dp[i][j - 1] >= A[i][0],
                    dp[i][j - 1] + A[i][1], // we can fuel in the `i`th station

                    dp[i][j]                // don't fuel in the `i`th station
                   )
dp[i][0] = startFuel      where 0 <= i <= N
```

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-refueling-stops/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& A) {
        int N = A.size();
        vector<vector<long>> dp(N + 1, vector<long>(N + 1));
        for (int i = 0; i <= N; ++i) dp[i][0] = startFuel;
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= i + 1; ++j) {
                dp[i + 1][j] = max(dp[i][j - 1] >= A[i][0] ? dp[i][j - 1] + A[i][1] : 0,
                                   dp[i][j]);
            }
        }
        for (int i = 0; i <= N; ++i) {
            if (dp[N][i] >= target) return i;
        }
        return -1;
    }
};
```

## Solution 2. DP with Space Optimization

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-refueling-stops/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& A) {
        int N = A.size();
        vector<long> dp(N + 1);
        dp[0] = startFuel;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j >= 1; --j) {
                if (dp[j - 1] >= A[i][0]) dp[j] = max(dp[j], dp[j - 1] + A[i][1]);
            }
        }
        for (int i = 0; i <= N; ++i) {
            if (dp[i] >= target) return i;
        }
        return -1;
    }
};
```