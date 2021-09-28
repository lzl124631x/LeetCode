# [1751. Maximum Number of Events That Can Be Attended II (Hard)](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/)

<p>You are given an array of <code>events</code> where <code>events[i] = [startDay<sub>i</sub>, endDay<sub>i</sub>, value<sub>i</sub>]</code>. The <code>i<sup>th</sup></code> event starts at <code>startDay<sub>i</sub></code><sub> </sub>and ends at <code>endDay<sub>i</sub></code>, and if you attend this event, you will receive a value of <code>value<sub>i</sub></code>. You are also given an integer <code>k</code> which represents the maximum number of events you can attend.</p>

<p>You can only attend one event at a time. If you choose to attend an event, you must attend the <strong>entire</strong> event. Note that the end day is <strong>inclusive</strong>: that is, you cannot attend two events where one of them starts and the other ends on the same day.</p>

<p>Return <em>the <strong>maximum sum</strong> of values that you can receive by attending events.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-60048-pm.png" style="width: 400px; height: 103px;"></p>

<pre><strong>Input:</strong> events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
<strong>Output:</strong> 7
<strong>Explanation: </strong>Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-60150-pm.png" style="width: 400px; height: 103px;"></p>

<pre><strong>Input:</strong> events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
<strong>Output:</strong> 10
<strong>Explanation:</strong> Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do <strong>not</strong> have to attend k events.</pre>

<p><strong>Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-60703-pm.png" style="width: 400px; height: 126px;"></strong></p>

<pre><strong>Input:</strong> events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
<strong>Output:</strong> 9
<strong>Explanation:</strong> Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= events.length</code></li>
	<li><code>1 &lt;= k * events.length &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= startDay<sub>i</sub> &lt;= endDay<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= value<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Maximum Number of Events That Can Be Attended (Medium)](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)
* [Maximum Earnings From Taxi (Medium)](https://leetcode.com/problems/maximum-earnings-from-taxi/)

## Solution 1. Top-down DP + Binary Search

sort `A` in ascending order of start time

Let `dp[k][i]` be the maximum value we can get with at most `k` events selected among the `i`th to the last events.

```
dp[k][i] = max(
                dp[k-1][j] + A[i][2], // pick
                dp[k][i+1]            // skip
              )
where `j` is the smallest index that `A[j][0] > A[i][1]`
and 1 <= k <= K, 0 <= i < N
```

We can get `j` using binary search.

Trivial cases:
```
dp[k][i] = 0 if k == 0 || i >= N
```

The answer is `dp[K][0]`.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
// Author: github.com/lzl124631x
// Time: O(KNlogN)
// Space: O(KN)
class Solution {
public:
    int maxValue(vector<vector<int>>& A, int k) {
        sort(begin(A), end(A));
        vector<vector<int>> dp(k + 1, vector<int>(A.size(), -1));
        function<int(int, int)> dfs = [&](int k, int i) {
            if (k == 0 || i >= A.size()) return 0;
            if (dp[k][i] != -1) return dp[k][i];
            int j = upper_bound(begin(A) + i + 1, end(A), A[i][1], [](int t, auto &a) { return a[0] > t; }) - begin(A);
            return dp[k][i] = max(dfs(k, i + 1), A[i][2] + dfs(k - 1, j));
        };
        return dfs(k, 0);
    }
};
```

## Solution 2. Bottom-up DP + Binary Search + Space Optimization

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
// Author: github.com/lzl124631x
// Time: O(KNlogN)
// Space: O(N)
class Solution {
public:
    int maxValue(vector<vector<int>>& A, int k) {
        sort(begin(A), end(A));
        int N = A.size();
        vector<int> dp(N + 1);
        for (int i = 1; i <= k; ++i) {
            vector<int> next(N + 1);
            for (int j = N - 1; j >= 0; --j) {
                int t = upper_bound(begin(A) + j + 1, end(A), A[j][1], [](int t, auto &v) { return v[0] > t; }) - begin(A);
                next[j] = max(dp[t] + A[j][2], next[j + 1]);
            }
            swap(dp, next);
        }
        return dp[0];
    }
};
```

## Solution 3. DP + Map

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
// Author: github.com/lzl124631x
// Time: O(KNlogU) where `U` is the number of unique start times.
// Space: O(U)
class Solution {
public:
    int maxValue(vector<vector<int>>& A, int k) {
        sort(begin(A), end(A), [&](auto &a, auto &b) { return a[0] > b[0]; });
        map<int, int> m{{INT_MAX, 0}};
        int ans;
        while (k--) {
            map<int, int> next{{INT_MAX, 0}};
            ans = 0;
            for (auto &a : A) {
                int s = a[0], e = a[1], v = a[2];
                next[s] = max(ans, v + m.upper_bound(e)->second);
                ans = max(ans, next[s]);
            }
            swap(m, next);
        }
        return ans;
    }
};
```