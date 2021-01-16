# [1723. Find Minimum Time to Finish All Jobs (Hard)](https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/)

<p>You are given an integer array <code>jobs</code>, where <code>jobs[i]</code> is the amount of time it takes to complete the <code>i<sup>th</sup></code> job.</p>

<p>There are <code>k</code> workers that you can assign jobs to. Each job should be assigned to <strong>exactly</strong> one worker. The <strong>working time</strong> of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the <strong>maximum working time</strong> of any worker is <strong>minimized</strong>.</p>

<p><em>Return the <strong>minimum</strong> possible <strong>maximum working time</strong> of any assignment. </em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> jobs = [3,2,3], k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> By assigning each person one job, the maximum time is 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> jobs = [1,2,4,7,8], k = 2
<strong>Output:</strong> 11
<strong>Explanation:</strong> Assign the jobs the following way:
Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
Worker 2: 4, 7 (working time = 4 + 7 = 11)
The maximum working time is 11.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= jobs.length &lt;= 12</code></li>
	<li><code>1 &lt;= jobs[i] &lt;= 10<sup>7</sup></code></li>
</ul>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/), [Recursion](https://leetcode.com/tag/recursion/)

## Note

Similar Problems:

* [698. Partition to K Equal Sum Subsets (Medium)](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)
* [473. Matchsticks to Square (Medium)](https://leetcode.com/problems/matchsticks-to-square/)

K Subset partitioning: partition the original array into `K` subsets and find the optimial result.

Candidate Solutions:
1. DFS + Optimizations
2. DP

### DFS + Optimizations

**Algorithm**

Create a `vector` of length `K` to store the subset values.

DFS to visit elements in the input array `A` one by one. In each DFS call, we traverse the `K` subsets and try to add `A[i]` to a subset.

**Tricks**

A important trick is to prevent visiting the same subset value again using `unordered_set`.

For example, if you get 4 subsets and each with sum `10`, and now you want to add `5` to one of them. Plain DFS will try adding `5` to each of these `10`s, but adding to which `10` actually makes no difference.

So we add the visited values into a `unordered_set` and skip visiting the same subset value when we see them again.

Another trick is sorting the `A`. Pick the order that can get a feasible partition as fast as possible.

### DP

Traverse all the subsets: `for (int mask = 0; mask < (1 << N); ++mask)`

Check if `A[i]` is included in the current subset: `mask & (1 << i)`

Traverse subsets of a set `mask` in descending order of subset size: 

```cpp
for (int sub = mask; sub; sub = (sub - 1) & mask) {
    // visit subset `sub`
}
```

Traverse subsets of a set `mask` in ascending order of subset size:

```cpp
for (int sub = 0; sub <= mask; ++sub) {
    if ((sub & mask) != sub) continue;
    // visit subset `sub`
}
```

Given `N` elements, traverse subsets of size `K`:

```cpp
int sub = (1 << k) - 1;            
while (sub < (1 << N)) {
    // visit subset `sub`
    int c = sub & - sub;
    int r = sub + c;
    sub = (((r ^ sub) >> 2) / c) | r;
}
```
## Solution 1. DFS to Fill Buckets

Using similar solution to [698. Partition to K Equal Sum Subsets (Medium)](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/).

One difference is that, here we should sort the `A` in ascending order because in this way we are more likely the spread the long jobs into different buckets.

```cpp
// OJ: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
// Author: github.com/lzl124631x
// Time: O(K^N)
// Space: O(NK)
// Ref: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/discuss/1009817/One-branch-cutting-trick-to-solve-three-LeetCode-questions
class Solution {
    int ans = INT_MAX;
    vector<int> v;
    void dfs(vector<int> &A, int i) {
        if (i == A.size()) {
            ans = min(ans, *max_element(begin(v), end(v)));
            return;
        }
        unordered_set<int> seen;
        for (int j = 0; j < v.size(); ++j) {
            if (seen.count(v[j]) || v[j] + A[i] > ans) continue;
            seen.insert(v[j]);
            v[j] += A[i];
            dfs(A, i + 1);
            v[j] -= A[i];
        }
    }
public:
    int minimumTimeRequired(vector<int>& A, int k) {
        v.assign(k, 0);
        sort(begin(A), end(A));
        dfs(A, 0);
        return ans;
    }
};
```

Another trick is to spread the works across different workers during DFS using different `start`. In this way, we can distribute the works more evenly instead of piling on the first worker.

Note that with this trick, it's better sorting the `A` in descending order so that the pebbles settle at the beginning of the DFS and the sands are shuffled at the tail of the DFS, making it more likely to get evenly distributed.

```cpp
// OJ: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
// Author: github.com/lzl124631x
// Time: O(K^N)
// Space: O(NK)
// Ref: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/discuss/1009817/One-branch-cutting-trick-to-solve-three-LeetCode-questions/814428
class Solution {
    int ans = INT_MAX, start = 0;
    vector<int> v;
    void dfs(vector<int> &A, int i) {
        ++start;
        if (i == A.size()) {
            ans = min(ans, *max_element(begin(v), end(v)));
            return;
        }
        unordered_set<int> seen;
        for (int s = start, j = 0; j < v.size(); ++j) {
            int t = (s + j) % v.size();
            if (seen.count(v[t]) || v[t] + A[i] > ans) continue;
            seen.insert(v[t]);
            v[t] += A[i];
            dfs(A, i + 1);
            v[t] -= A[i];
        }
    }
public:
    int minimumTimeRequired(vector<int>& A, int k) {
        v.assign(k, 0);
        sort(begin(A), end(A), greater<>());
        dfs(A, 0);
        return ans;
    }
};
```

## Solution 2. DP on Subsets

Let `dp[i+1][mask]` be the minimum maximum working time with `i+1` workers on job subset `mask`.

Let `sum[mask]` be the total working time required for job subset `mask`. `sum[mask] = SUM( A[i] | (mask & (1 << i)) != 0 )`.

For `dp[i+1][mask]`, we can try to assign a job subset `sub` to the `i`-th worker, and reuse `dp[i - 1][mask ^ sub]` for the rest `i - 1` workers and job subset `mask ^ sub`.

```
dp[i][mask] = min( dp[i - 1][mask ^ sub] + sum[sub] | `sub` is a subset of `mask` )
```

### Time Complexity

Initialization takes `O(K + 2^N * N)` time.

DP part takes `O(K * 2^N * 2^N)` time.

So overall it's `O(K * 2^(2N))`.

```cpp
// OJ: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
// Author: github.com/lzl124631x
// Time: O(K * 2^(2N))
// Space: O(K * 2^N)
int dp[13][1 << 12], sum[1 << 12];
class Solution {
public:
    int minimumTimeRequired(vector<int>& A, int k) {
        int N = A.size();
        memset(dp, 0x3f, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i <= k; ++i) dp[i][0] = 0;
        for (int mask = 0; mask < (1 << N); ++mask) {
            for (int i = 0; i < N; ++i) {
                if (mask & (1 << i)) sum[mask] += A[i];
            }
        }
        for (int i = 0; i < k; ++i) {
            for (int mask = 0; mask < (1 << N); ++mask) {
                for (int sub = mask; sub; sub = (sub - 1) & mask) {
                    dp[i + 1][mask] = min(dp[i + 1][mask], max(dp[i][mask ^ sub], sum[sub]));
                }
            }
        }
        return dp[k][(1 << N) - 1];
    }
};
```

Since `dp[i][mask]` only depends on `dp[i - 1][mask ^ sub]` and `mask ^ sub <= mask`, we can reduce the space complexity from `O(K * 2^N)` to `O(2^N)`.

```cpp
// OJ: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
// Author: github.com/lzl124631x
// Time: O(K * 2^(2N))
// Space: O(2^N)
int dp[1 << 12], sum[1 << 12];
class Solution {
public:
    int minimumTimeRequired(vector<int>& A, int k) {
        int N = A.size();
        memset(dp, 0x3f, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        dp[0] = 0;
        for (int mask = 0; mask < (1 << N); ++mask) {
            for (int i = 0; i < N; ++i) {
                if (mask & (1 << i)) sum[mask] += A[i]; // if this subset `mask` contains the ith job, add `A[i]` to the corresponding `sum[mask]`.
            }
        }
        while (k--) {
            for (int mask = (1 << N) - 1; mask >= 0; --mask) { // here we must traverse in descending order to make sure that `dp[mask ^ sub]` are with implicit `i - 1`.
                for (int sub = mask; sub; sub = (sub - 1) & mask) {
                    dp[mask] = min(dp[mask], max(dp[mask ^ sub], sum[sub]));
                }
            }
        }
        return dp[(1 << N) - 1];
    }
};
```