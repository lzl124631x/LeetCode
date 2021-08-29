# [1986. Minimum Number of Work Sessions to Finish the Tasks (Medium)](https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/)

<p>There are <code>n</code> tasks assigned to you. The task times are represented as an integer array <code>tasks</code> of length <code>n</code>, where the <code>i<sup>th</sup></code> task takes <code>tasks[i]</code> hours to finish. A <strong>work session</strong> is when you work for <strong>at most</strong> <code>sessionTime</code> consecutive hours and then take a break.</p>

<p>You should finish the given tasks in a way that satisfies the following conditions:</p>

<ul>
	<li>If you start a task in a work session, you must complete it in the <strong>same</strong> work session.</li>
	<li>You can start a new task <strong>immediately</strong> after finishing the previous one.</li>
	<li>You may complete the tasks in <strong>any order</strong>.</li>
</ul>

<p>Given <code>tasks</code> and <code>sessionTime</code>, return <em>the <strong>minimum</strong> number of <strong>work sessions</strong> needed to finish all the tasks following the conditions above.</em></p>

<p>The tests are generated such that <code>sessionTime</code> is <strong>greater</strong> than or <strong>equal</strong> to the <strong>maximum</strong> element in <code>tasks[i]</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> tasks = [1,2,3], sessionTime = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can finish the tasks in two work sessions.
- First work session: finish the first and the second tasks in 1 + 2 = 3 hours.
- Second work session: finish the third task in 3 hours.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> tasks = [3,1,3,1,1], sessionTime = 8
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can finish the tasks in two work sessions.
- First work session: finish all the tasks except the last one in 3 + 1 + 3 + 1 = 8 hours.
- Second work session: finish the last task in 1 hour.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> tasks = [1,2,3,4,5], sessionTime = 15
<strong>Output:</strong> 1
<strong>Explanation:</strong> You can finish all the tasks in one work session.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == tasks.length</code></li>
	<li><code>1 &lt;= n &lt;= 14</code></li>
	<li><code>1 &lt;= tasks[i] &lt;= 10</code></li>
	<li><code>max(tasks[i]) &lt;= sessionTime &lt;= 15</code></li>
</ul>


**Similar Questions**:
* [Smallest Sufficient Team (Hard)](https://leetcode.com/problems/smallest-sufficient-team/)
* [Find Minimum Time to Finish All Jobs (Hard)](https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/)

## Solution 1. Bitmask DP

Note that, without precomputing the `valid` array, the algorithm takes `O(3^N * N)` time, and since `N` is at most `14`, it's `66,961,566 ~= 7e7` which is around TLE.

If we precompute the `valid` array, `3^14 = 4,782,969 ~= 5e6` which is safe to get passed.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/
// Author: github.com/lzl124631x
// Time: O(3^N)
// Space: O(2^N)
class Solution {
    int m[16385] = {};
    bool valid[16385] = {};
    int dp(vector<int> &A, int mask, int total) {
        if (mask == 0) return 0;
        if (m[mask] != -1) return m[mask];
        int ans = INT_MAX;
        for (int ms = mask; ms; ms = (ms - 1) & mask) {
            if (!valid[ms]) continue;
            ans = min(ans, 1 + dp(A, mask & ~ms, total));
        }
        return m[mask] = ans;
    }
public:
    int minSessions(vector<int>& A, int total) {
        memset(m, -1, sizeof(m));
        for (int mask = 1; mask < (1 << A.size()); ++mask) {
            int sum = 0;
            for (int i = 0; i < A.size(); ++i) {
                if (mask >> i & 1) sum += A[i];
            }
            valid[mask] = sum <= total;
        }
        return dp(A, (1 << A.size()) - 1, total);
    }
};
```

## Solution 2. Binary Answer

The time complexity of `valid` function has a very loose upper bound `O(N^N)` but lots of combinations are skipped so it's way efficient than that.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/
// Author: github.com/lzl124631x
// Time: O(logN * N^N)
// Space: O(N)
class Solution {
    bool dfs(vector<int> &A, vector<int> &s, int i, int total) {
        if (i == A.size()) return true;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] + A[i] <= total) {
                s[j] += A[i];
                if (dfs(A, s, i + 1, total)) return true;
                s[j] -= A[i];
            }
            if (s[j] == 0) break; // Don't try subsequent `0`s since trying them is a waste of time -- trying either `0` session is the same.
        }
        return false;
    }
    bool valid(vector<int> &A, int cnt, int total) {
        vector<int> s(cnt);
        return dfs(A, s, 0, total);
    }
public:
    int minSessions(vector<int>& A, int total) {
        int L = 1, R = A.size();
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(A, M, total)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
```