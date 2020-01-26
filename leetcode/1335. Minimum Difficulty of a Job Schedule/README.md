# [1335. Minimum Difficulty of a Job Schedule (Hard)](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/)

<p>You want to schedule a list of jobs in <code>d</code> days. Jobs are dependent (i.e To work on the <code>i-th</code> job, you have to finish all the jobs <code>j</code> where <code>0 &lt;= j &lt; i</code>).</p>

<p>You have to finish <strong>at least</strong> one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the <code>d</code> days. The difficulty of a day is the maximum difficulty of a job done in that day.</p>

<p>Given an array of integers <code>jobDifficulty</code> and an integer <code>d</code>. The difficulty of the <code>i-th</code>&nbsp;job is&nbsp;<code>jobDifficulty[i]</code>.</p>

<p>Return <em>the minimum difficulty</em> of a job schedule. If you cannot find a schedule for the jobs return <strong>-1</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/01/16/untitled.png" style="width: 365px; height: 230px;">
<pre><strong>Input:</strong> jobDifficulty = [6,5,4,3,2,1], d = 2
<strong>Output:</strong> 7
<strong>Explanation:</strong> First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> jobDifficulty = [9,9,9], d = 4
<strong>Output:</strong> -1
<strong>Explanation:</strong> If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> jobDifficulty = [1,1,1], d = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> The schedule is one job per day. total difficulty will be 3.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> jobDifficulty = [7,1,7,1,7,1], d = 3
<strong>Output:</strong> 15
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> jobDifficulty = [11,111,22,222,33,333,44,444], d = 6
<strong>Output:</strong> 843
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= jobDifficulty.length &lt;= 300</code></li>
	<li><code>0 &lt;=&nbsp;jobDifficulty[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= d &lt;= 10</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
// Author: github.com/lzl124631x
// Time: O(N^2 * D)
// Space: O(N^2 + ND)
class Solution {
    int get(int from, int to) { return from * 1000 + to; }
public:
    int minDifficulty(vector<int>& A, int d) {
        unordered_map<int, int> m;
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            int maxV = A[i];
            for (int j = i; j < N; ++j) {
                m[get(i, j)] = maxV = max(maxV, A[j]);
            }
        }
        vector<vector<int>> dp(N + 1, vector<int>(d + 1, INT_MAX));
        for (int i = 0; i < N; ++i) dp[i + 1][1] = m[get(0,i)];
        for (int j = 2; j <= d; ++j) {
            for (int i = 0; i < N; ++i) {
                int minV = INT_MAX;
                for (int k = 0; k < i; ++k) {
                    minV = min(minV, dp[k + 1][j - 1] == INT_MAX ? INT_MAX : dp[k + 1][j - 1] + m[get(k + 1, i)]);
                }
                dp[i + 1][j] = minV;
            }
        }
        return dp[N][d] == INT_MAX ? -1 : dp[N][d];
    }
};
```