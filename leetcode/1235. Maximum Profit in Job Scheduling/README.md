# [1235. Maximum Profit in Job Scheduling (Hard)](https://leetcode.com/problems/maximum-profit-in-job-scheduling/submissions/)

<p>We have <code>n</code> jobs, where every job&nbsp;is scheduled to be done from <code>startTime[i]</code> to <code>endTime[i]</code>, obtaining a profit&nbsp;of <code>profit[i]</code>.</p>

<p>You're given the&nbsp;<code>startTime</code>&nbsp;,&nbsp;<code>endTime</code>&nbsp;and <code>profit</code>&nbsp;arrays,&nbsp;you need to output the maximum profit you can take such that there are no 2 jobs in the subset&nbsp;with overlapping time range.</p>

<p>If you choose a job that ends at time <code>X</code>&nbsp;you&nbsp;will be able to start another job that starts at time <code>X</code>.</p>

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

<pre><strong>
Input:</strong> startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
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
	<li><code>1 &lt;= startTime.length == endTime.length ==&nbsp;profit.length&nbsp;&lt;= 5 * 10^4</code></li>
	<li><code>1 &lt;=&nbsp;startTime[i] &lt;&nbsp;endTime[i] &lt;= 10^9</code></li>
	<li><code>1 &lt;=&nbsp;profit[i] &lt;= 10^4</code></li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1. DP + Binary Search

```cpp
// OJ: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int N = startTime.size();
        vector<vector<int>> v(N, vector<int>(3));
        for (int i = 0; i < N; ++i) {
            v[i][0] = startTime[i];
            v[i][1] = endTime[i];
            v[i][2] = profit[i];
        }
        sort(v.begin(), v.end());
        vector<int> dp(N + 1);
        for (int i = N - 1; i >= 0; --i) {
            dp[i] = dp[i + 1];
            int e = v[i][1];
            vector<int> c{ e, e, 0 };
            int j = upper_bound(v.begin(), v.end(), c) - v.begin();
            dp[i] = max(dp[i], dp[j] + v[i][2]);
        }
        return dp[0];
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409188/C%2B%2B-with-picture
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int, int> times; // start time to max profit
        unordered_map<int, vector<pair<int, int>>> jobs; // start time to <endTime, profit>
        for (int i = 0; i < startTime.size(); ++i) {
            times[startTime[i]] = 0;
            jobs[startTime[i]].emplace_back(endTime[i], profit[i]);
        }
        int maxProfit = 0;
        for (auto it = rbegin(times); it != rend(times); ++it) {
            for (auto &job : jobs[it->first]) {
                auto j = times.lower_bound(job.first);
                maxProfit = max(maxProfit, (j == end(times) ? 0 : j->second) + job.second);
            }
            it->second = maxProfit;
        }
        return maxProfit;
    }
};
```

## Solution 3. DP

```cpp
// OJ: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409188/C%2B%2B-with-picture
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> idx(startTime.size());
        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), [&](int i, int j) { return startTime[i] > startTime[j]; });
        map<int, int> memo; // start time to max profit
        int maxProfit = 0;
        for (int i = 0; i < idx.size(); ++i) {
            auto j = memo.lower_bound(endTime[idx[i]]);
            maxProfit = max(maxProfit, (j == end(memo) ? 0 : j->second) + profit[idx[i]]);
            memo[startTime[idx[i]]] = maxProfit;
        }
        return maxProfit;
    }
};
```