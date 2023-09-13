# [1235. Maximum Profit in Job Scheduling (Hard)](https://leetcode.com/problems/maximum-profit-in-job-scheduling/)

<p>We have <code>n</code> jobs, where every job is scheduled to be done from <code>startTime[i]</code> to <code>endTime[i]</code>, obtaining a profit of <code>profit[i]</code>.</p>

<p>You're given the <code>startTime</code>, <code>endTime</code> and <code>profit</code> arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.</p>

<p>If you choose a job that ends at time <code>X</code> you will be able to start another job that starts at time <code>X</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/10/sample1_1584.png" style="width: 380px; height: 154px;"></strong></p>

<pre><strong>Input:</strong> startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
<strong>Output:</strong> 120
<strong>Explanation:</strong> The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/10/sample22_1584.png" style="width: 600px; height: 112px;"> </strong></p>

<pre><strong>Input:</strong> startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
<strong>Output:</strong> 150
<strong>Explanation:</strong> The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
</pre>

<p><strong>Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/10/sample3_1584.png" style="width: 400px; height: 112px;"></strong></p>

<pre><strong>Input:</strong> startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
<strong>Output:</strong> 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= startTime.length == endTime.length == profit.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= startTime[i] &lt; endTime[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= profit[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[DoorDash](https://leetcode.com/company/doordash), [Amazon](https://leetcode.com/company/amazon), [Swiggy](https://leetcode.com/company/swiggy), [Databricks](https://leetcode.com/company/databricks), [Airbnb](https://leetcode.com/company/airbnb), [Microsoft](https://leetcode.com/company/microsoft), [LinkedIn](https://leetcode.com/company/linkedin), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Sorting](https://leetcode.com/tag/sorting/)


## Solution 1. DP + Binary Search (Sort by Start Time)

Let `dp[time]` be the maximum profit we can get within time `[time, Infinity)`. We need to get the `dp` values in descending order of start time.

```
dp[startTime[i]] = max( maxProfit, profit[i] + dp[endTime[i]] )
                    where `maxProfit` is the maximumProfit we've seen thus far
```

```cpp
// OJ: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<array<int, 3>> jobs;
        for (int i = 0; i < startTime.size(); ++i) jobs.push_back({ startTime[i], endTime[i], profit[i] });
        sort(begin(jobs), end(jobs), greater<>()); // sort jobs in descending order of start time
        map<int, int> dp{{INT_MAX, 0}}; // startTime to max profit
        int ans = 0;
        for (auto &[s, e, p] : jobs) {
            dp[s] = max(ans, p + dp.lower_bound(e)->second);
            ans = max(ans, dp[s]);
        }
        return ans;
    }
};
```

## Solution 2. DP + Binary Search (Sort by End Time)

The other way around. Let `dp[time]` be the maximum profit we can get within time `[0, time]`. We need to get the `dp` values in ascending order of end time.

```
dp[endTime[i]] = max( maxProfit, profit[i] + dp[startTime[i]] )
                    where `maxProfit` is the maximumProfit we've seen thus far
```

```cpp
// OJ: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<array<int, 3>> jobs;
        for (int i = 0; i < startTime.size(); ++i) jobs.push_back({ endTime[i], startTime[i], profit[i] });
        sort(begin(jobs), end(jobs));
        map<int, int> dp{{0, 0}}; // endTime to max profit
        int ans = 0;
        for (auto &[e, s, p] : jobs) {
            dp[e] = max(ans, p + prev(dp.upper_bound(s))->second);
            ans = max(ans, dp[e]);
        }
        return ans;
    }
};
```


## Note

We can use an auxiliary index array `id` to do the sorting which saves some space.

```cpp
// OJ: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int N = startTime.size(), ans = 0;
        vector<int> id(N);
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](int a, int b) { return startTime[a] > startTime[b]; }); // sort jobs in descending order of start time
        map<int, int> m{{INT_MAX,0}}; // time -> maxProfit
        for (int i : id) {
            m[startTime[i]] = max(ans, profit[i] + m.lower_bound(endTime[i])->second);
            ans = m[startTime[i]];
        }
        return ans;
    }
};
```