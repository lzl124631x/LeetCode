# [1235. Maximum Profit in Job Scheduling (Hard)](https://leetcode.com/problems/maximum-profit-in-job-scheduling/)

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
        sort(v.begin(), v.end()); // sort in asending order of start time.
        vector<int> dp(N + 1);
        for (int i = N - 1; i >= 0; --i) {
            dp[i] = dp[i + 1]; // roll the max profit over
            int e = v[i][1];
            vector<int> c{ e, e, 0 }; // find the first job whose startTime is greater than or equal to the end time of the current job
            int j = lower_bound(v.begin(), v.end(), c) - v.begin(); // `upper_bound` also works because it's impossible to be equal to the job `e, e, 0`.
            dp[i] = max(dp[i], dp[j] + v[i][2]);
        }
        return dp[0];
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409188/C%2B%2B-with-picture
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int, int> maxProfit; // start time to max profit
        unordered_map<int, vector<pair<int, int>>> jobs; // start time to <endTime, profit>
        for (int i = 0; i < startTime.size(); ++i) {
            maxProfit[startTime[i]] = 0;
            jobs[startTime[i]].emplace_back(endTime[i], profit[i]);
        }
        int ans = 0;
        for (auto it = rbegin(maxProfit); it != rend(maxProfit); ++it) {
            for (auto &job : jobs[it->first]) {
                auto j = maxProfit.lower_bound(job.first); // find the first job whose start time is greater than or equal to the end time of this current job.
                ans = max(ans, (j == end(maxProfit) ? 0 : j->second) + job.second);
            }
            it->second = ans;
        }
        return ans;
    }
};
```

Using the ID array `idx` saves space compared to saving `endTime` and `profit` in another `map` as shown in the above solutions.

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
        sort(begin(idx), end(idx), [&](int i, int j) { return startTime[i] > startTime[j]; }); // sort the job ids in descending order of start time.
        map<int, int> maxProfit; // start time to max profit
        int ans = 0;
        for (int i = 0; i < idx.size(); ++i) {
            auto j = maxProfit.lower_bound(endTime[idx[i]]); // find the first job whose start time is greater than or equal to the end time of the current job.
            ans = max(ans, (j == end(maxProfit) ? 0 : j->second) + profit[idx[i]]);
            maxProfit[startTime[idx[i]]] = ans;
        }
        return ans;
    }
};
```

## Solution 1. DP + Binary Search

For a job with startTime `s`, endTime `e`, and profit `p`, we need look at all the jobs ends at and before `s`.

Let `dp[s]` be the maximum profit we can get from the beginning to time `s`, then we can try to update `dp[e]` with `dp[s] + p`.

But `dp[s]` is not necessarily set because there might be no jobs ending at `s`, so we need to find the maximum time `t <= s`, and use `dp[t]`.

To achieve this, we can keep the `dp` values sorted in ascending order of the key, i.e. time.

To ensure we've visited all the jobs ends before startTime `s`, we sort the jobs in ascending order of `endTime`.

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

Or

```cpp
// OJ: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int ans = 0, N = startTime.size();
        vector<array<int, 3>> jobs(N + 1);
        for (int i = 0; i < N; ++i) jobs[i + 1] = { endTime[i], startTime[i], profit[i] };
        sort(begin(jobs), end(jobs));
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; ++i) {
            auto [e, s, p] = jobs[i];
            int j = prev(upper_bound(begin(jobs), end(jobs), array<int, 3>{s, s, 0})) - begin(jobs);
            dp[i] = max(ans, p + dp[j]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

Another way to get the `upper_bound` is as follows

```cpp
upper_bound(begin(jobs), end(jobs), s, [](int a, auto &b) { return a < b[0]; })
```

## Solution 2. DP + Binary Search

The other way around also works, i.e. sorting the jobs based on the start times and get the `dp` values in descending order of time.

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
        sort(begin(jobs), end(jobs), greater<>());
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

Or

```cpp
// OJ: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int ans = 0, N = startTime.size();
        vector<array<int, 3>> jobs(N + 1);
        jobs[N] = { INT_MAX, INT_MAX, 0 };
        for (int i = 0; i < N; ++i) jobs[i] = { startTime[i], endTime[i], profit[i] };
        sort(begin(jobs), end(jobs));
        vector<int> dp(N + 1);
        for (int i = N - 1; i >= 0; --i) {
            auto [s, e, p] = jobs[i];
            int j = lower_bound(begin(jobs), end(jobs), array<int, 3>{e, e, 0}) - begin(jobs);
            dp[i] = max(ans, p + dp[j]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```