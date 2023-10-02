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

See https://liuzhenglaichn.gitbook.io/algorithm/k-subset-partitioning

## Solution 1. Backtrack to Fill Buckets

Using similar solution to [698. Partition to K Equal Sum Subsets (Medium)](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/).

One difference is that, here we should sort the `A` in ascending order because in this way we are more likely the spread the long jobs into different buckets.

```cpp
// OJ: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
// Author: github.com/lzl124631x
// Time: O(K^N) ~150ms as of 1/17/2021
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

Note that with this trick, it's better sorting the `A` in descending order so that the rocks settle at the beginning of the DFS and the sands are shuffled at the tail of the DFS, making it more likely to get evenly distributed.

```cpp
// OJ: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
// Author: github.com/lzl124631x
// Time: O(K^N) ~24ms as of 1/17/2021
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
            if (seen.count(v[t]) || v[t] + A[i] > ans) continue; // Must use set `seen` instead of `if (v[t] == 0) break;`.
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

Another type of optimization is preventing assign a work `A[i]` to totally free workers twice because assigning to either totally free worker will get the same result.

The time complexity of brute force DFS is `O(K^N)`. If a DFS invocation sees `x` zeros, this optimization will skip `x - 1` zeros and thus reduce the time complexity to the `1/x` of the brute force one. In the first layer of DFS, there are `K` zeros. In the second layer, there are at least `K - 1` zeros. In the third layer, there are at least `K - 2` zeros, and so on. So the time complexity will be `1/K * 1/(K - 1) * 1/(K - 2) * ... * 1/1 = 1/K!` of the brute force one, i.e. `O(K^N / K!)`.

```cpp
// OJ: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
// Author: github.com/lzl124631x
// Time: O(K^N / K!) ~16ms as of 1/17/2021
// Space: O(N)
// Ref: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/discuss/1010057/Python-Binary-search-24ms
class Solution {
    int ans = INT_MAX;
    vector<int> v;
    void dfs(vector<int> &A, int i) {
        if (i == A.size()) {
            ans = min(ans, *max_element(begin(v), end(v)));
            return;
        }
        for (int j = 0; j < v.size(); ++j) {
            if (v[j] + A[i] > ans) continue;
            v[j] += A[i];
            dfs(A, i + 1);
            v[j] -= A[i];
            if (v[j] == 0) break; // prevent assigning `A[i]` to other totally free workers `v[j + 1]`, `v[j + 2]`, ...
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

## Solution 2. Binary Answer + Backtrack to Fill Buckets

The range of the answer is `[max(A), sum(A)]`. We can binary search in this range.

Let `dfs(limit)` be whether we can fit the jobs with less than or equal to `k` workers given the maximum working time `limit`.

### Time Complexity

The binary search loop runs `O(log(sum(A)))` times.

Each `dfs` check at most takes `O(K^N)` (a very loose upper bound).

So overall it's `O(log(sum(A)) * K^N)`.

```cpp
// OJ: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
// Author: github.com/lzl124631x
// Time: O(log(sum(A)) * K^N) ~4ms as of 1/17/2021
// Space: O(K + N)
// Ref: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/discuss/1010057/Python-Binary-search-24ms
class Solution {
public:
    int minimumTimeRequired(vector<int>& A, int k) {
        sort(begin(A), end(A), greater<>());
        int N = A.size(), L = *max_element(begin(A), end(A)), R = accumulate(begin(A), end(A), 0);
        vector<int> v;
        function<bool(int, int)> dfs = [&](int i, int limit) {
            if (i == N) return true;
            for (int j = 0; j < k; ++j) {
                if (v[j] + A[i] > limit) continue;
                v[j] += A[i];
                if (dfs(i + 1, limit)) return true;
                v[j] -= A[i];
                if (v[j] == 0) break;
            }
            return false;
        };
        while (L <= R) {
            int M = (L + R) / 2;
            v.assign(k, 0);
            if (dfs(0, M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
```

## Solution 3. DP on Subsets

Let `dp[i+1][mask]` be the minimum maximum working time with `i+1` workers on job subset `mask`.

Let `sum[mask]` be the total working time required for job subset `mask`. `sum[mask] = SUM( A[i] | (mask & (1 << i)) != 0 )`.

For `dp[i+1][mask]`, we can try to assign a job subset `sub` to the `i`-th worker, and reuse `dp[i - 1][mask ^ sub]` for the rest `i - 1` workers and job subset `mask ^ sub`.

```
dp[i][mask] = min( dp[i - 1][mask ^ sub] + sum[sub] | `sub` is a subset of `mask` )
```

### Time Complexity

Initialization takes `O(K + 2^N * N)` time.

DP part takes `O(K * 3^N)` time.

So overall it's `O(K * 3^N)`.

```cpp
// OJ: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
// Author: github.com/lzl124631x
// Time: O(K * 3^N) ~400ms as of 1/21/2021
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
// Time: O(K * 3^N) ~400ms as of 1/17/2021
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

## Solution 4. Binary Search + DP

The range of the answer is `[max(A), sum(A)]`. We can binary search in this range.

Let `valid(limit)` be whether we can fit the jobs with less than or equal to `k` workers given the maximum working time `limit`.

Let `dp[mask]` be the minimum workers needed to handle those jobs given `limit`.

```
dp[mask] = min( 1 + dp[mask ^ sub] | `sub` is a subset of `mask` && sum[sub] <= limit )
```

### Time Complexity

The binary seach `while` loop runs `O(log(sum(A)))` times.

Each `valid` invocation takes `O(3^N)`.

So overall it's `O(log(sum(A)) * 3^N)`.

```cpp
// OJ: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
// Author: github.com/lzl124631x
// Time: O(log(sum(A)) * 3^N) ~400ms as of 1/17/2021
// Space: O(2^N)
int dp[1 << 12], sum[1 << 12];
class Solution {
    inline int lowbit(int x) { return x & -x; };
public:
    int minimumTimeRequired(vector<int>& A, int k) {
        int N = A.size(), L = *max_element(begin(A), end(A)), R = accumulate(begin(A), end(A), 0);
        for (int mask = 1; mask < (1 << N); ++mask) sum[mask] = sum[mask - lowbit(mask)] + A[__builtin_ctz(lowbit(mask))];
        auto valid = [&](int limit) {
            memset(dp, 0x3f, sizeof(dp));
            dp[0] = 0;
            for (int mask = 1; mask < (1 << N); ++mask) {
                for (int sub = mask; sub; sub = (sub - 1) & mask) {
                    if (sum[sub] <= limit) dp[mask] = min(dp[mask], 1 + dp[mask ^ sub]);
                }
            }
            return dp[(1 << N) - 1] <= k;
        };
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
```