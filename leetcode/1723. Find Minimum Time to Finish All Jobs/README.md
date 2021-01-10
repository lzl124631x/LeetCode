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