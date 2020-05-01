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

## Solution 1. DP

Let `dp[d][i]` be the answer for the subproblem with `d` days at `i`th job.

Let `mx[i][j]` be the maximum value in `A[i..j]`.

```
dp[d][i] = min( dp[d-1][j-1] + mx[j][i] | d-1 <= j <= i )
```

```cpp
// OJ: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
// Author: github.com/lzl124631x
// Time: O(N^2 * D)
// Space: O(N^2 + ND)
class Solution {
    typedef long long LL;
    inline void setMin(LL &a, LL b) { a = min(a, b); }
public:
    int minDifficulty(vector<int>& A, int D) {
        int N = A.size();
        if (D > N) return -1;
        vector<vector<LL>> mx(N, vector<LL>(N)), dp(D + 1, vector<LL>(N, 1e9));
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) mx[i][j] = *max_element(A.begin() + i, A.begin() + j + 1);
        }
        for (int i = 0; i < N; ++i) dp[1][i] = mx[0][i];
        for (int d = 2; d <= D; ++d) {
            for (int i = d - 1; i < N; ++i) {
                for (int j = d - 1; j <= i; ++j) {
                    setMin(dp[d][i], dp[d - 1][j - 1] + mx[j][i]);
                }
            }
        }
        return dp[D][N - 1];
    }
};
```

## Solution 2. DP

We can compute the `mx` while computing `dp` instead of computing `mx` array beforehand.

```cpp
// OJ: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
// Author: github.com/lzl124631x
// Time: O(N^2 * D)
// Space: O(ND) 
class Solution {
    typedef long long LL;
    inline void setMin(LL &a, LL b) { a = min(a, b); }
public:
    int minDifficulty(vector<int>& A, int D) {
        int N = A.size(), inf = 1e9;
        if (D > N) return -1;
        vector<vector<LL>> dp(D + 1, vector<LL>(N, inf));
        for (int i = 0; i < N; ++i) dp[1][i] = i == 0 ? A[0] : max(dp[1][i - 1], (LL)A[i]);
        for (int d = 2; d <= D; ++d) {
            for (int i = d - 1; i < N; ++i) {
                int mx = 0;
                for (int j = i; j >= d - 1; --j) {
                    mx = max(mx, A[j]);
                    setMin(dp[d][i], dp[d - 1][j - 1] + mx);
                }
            }
        }
        return dp[D][N - 1];
    }
};
```

## Solution 3. DP

Since `dp[d][i]` is dependent on `dp[d-1][j-1]` and `j <= i`, we can flip the loop direction and just need 1D `dp` array.

```cpp
// OJ: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
// Author: github.com/lzl124631x
// Time: O(NND)
// Space: O(N)
class Solution {
    typedef long long LL;
    inline void setMin(LL &a, LL b) { a = min(a, b); }
public:
    int minDifficulty(vector<int>& A, int D) {
        int N = A.size(), inf = 1e9;
        if (D > N) return -1;
        vector<LL> dp(N);
        for (int i = 0; i < N; ++i) dp[i] = i == 0 ? A[0] : max(dp[i - 1], (LL)A[i]);
        for (int d = 2; d <= D; ++d) {
            for (int i = N - 1; i >= d - 1; --i) {
                int mx = 0;
                dp[i] = inf;
                for (int j = i; j >= d - 1; --j) {
                    mx = max(mx, A[j]);
                    setMin(dp[i], dp[j - 1] + mx);
                }
            }
        }
        return dp[N - 1];
    }
};
```

## Solution 4. DP + Monotonic Min Stack

TODO
https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/discuss/490316/JavaC%2B%2BPython3-DP-O(nd)-Solution

https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/discuss/495000/C%2B%2B-0ms!-O(d*n)-time-O(n)-space.-DP-%2B-MonotonicMinimum-Stack