# [473. Matchsticks to Square (Medium)](https://leetcode.com/problems/matchsticks-to-square/)

<p>You are given an integer array <code>matchsticks</code> where <code>matchsticks[i]</code> is the length of the <code>i<sup>th</sup></code> matchstick. You want to use <strong>all the matchsticks</strong> to make one square. You <strong>should not break</strong> any stick, but you can link them up, and each matchstick must be used <strong>exactly one time</strong>.</p>

<p>Return <code>true</code> if you can make this square and <code>false</code> otherwise.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/09/matchsticks1-grid.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> matchsticks = [1,1,2,2,2]
<strong>Output:</strong> true
<strong>Explanation:</strong> You can form a square with length 2, one side of the square came two sticks with length 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> matchsticks = [3,3,3,3,4]
<strong>Output:</strong> false
<strong>Explanation:</strong> You cannot find a way to form a square with all the matchsticks.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= matchsticks.length &lt;= 15</code></li>
	<li><code>1 &lt;= matchsticks[i] &lt;= 10<sup>8</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Bitmask](https://leetcode.com/tag/bitmask/)

## Solution 1. Bitmask DP on Subsets

```cpp
// OJ: https://leetcode.com/problems/matchsticks-to-square/
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(2^N)
class Solution {
public:
    bool makesquare(vector<int>& A) {
        int sum = accumulate(begin(A), end(A), 0), N = A.size();
        if (sum % 4 || *max_element(begin(A), end(A)) > sum / 4) return false;
        sum /= 4;
        sort(begin(A), end(A), greater<>()); // Try rocks before sands
        vector<int> dp(1 << N, -1); // -1 unvisited, 0 invalid, 1 valid
        dp[(1 << N) - 1] = 1;
        function<bool(int, int)> dfs = [&](int mask, int target) {
            if (dp[mask] != -1) return dp[mask];
            dp[mask] = 0;
            if (target == 0) target = sum;
            for (int i = 0; i < N && !dp[mask]; ++i) {
                if ((mask >> i & 1) || A[i] > target) continue;
                dp[mask] = dfs(mask | (1 << i), target - A[i]);
            }
            return dp[mask];
        };
        return dfs(0, sum);
    }
};
```

## Solution 2. Backtrack to Fill Buckets

Let `target = sum(A) / 4`, which is the target length of each edge.

We use DFS to try to fill each `A[i]` into different edges.

Two optimizations here:

1. The `unordered_set<int> seen` is used to prevent handling the same edge value again. For example, assume `edge = [1, 1, 1, 1]`, and now we are trying to add a stick of length `2` to it. Adding `2` to either `1` will yield the same result. So we just need to add to a edge with length `1` once.
1. Sorting the sticks in descending order will make it converge faster because it's easy to fill in sands but hard to fill in peddles; filling peddles first will fail faster.

```cpp
// OJ: https://leetcode.com/problems/matchsticks-to-square/
// Author: github.com/lzl124631x
// Time: O(4^N)
// Space: O(N * SUM(A))
class Solution {
public:
    bool makesquare(vector<int>& A) {
        long v[4] = {}, sum = accumulate(begin(A), end(A), 0L);
        if (sum % 4 || *max_element(begin(A), end(A)) > sum / 4) return false;
        sum /= 4;
        sort(begin(A), end(A), greater<>()); // Try rocks before sands
        function<bool(int)> dfs = [&](int i) {
            if (i == A.size()) return true;
            unordered_set<long> seen;
            for (int j = 0; j < 4; ++j) {
                if (A[i] + v[j] > sum || seen.count(v[j])) continue;
                seen.insert(v[j]);
                v[j] += A[i];
                if (dfs(i + 1)) return true;
                v[j] -= A[i];
            }
            return false;
        };
        return dfs(0);
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/matchsticks-to-square/
// Author: github.com/lzl124631x
// Time: O(4^N)
// Space: O(N * SUM(A))
class Solution {
public:
    bool makesquare(vector<int>& A) {
        long v[4] = {}, sum = accumulate(begin(A), end(A), 0L), N = A.size();
        if (sum % 4) return false;
        sum /= 4;
        sort(begin(A), end(A), greater<>()); // Try rocks before sands
        function<bool(int)> dfs = [&](int i) {
            if (i == N) return true;
            for (int j = 0; j < 4; ++j) {
                if (A[i] + v[j] > sum) continue;
                v[j] += A[i];
                if (dfs(i + 1)) return true;
                v[j] -= A[i];
                if (v[j] == 0) break; // Simply don't visit empty bucket again. This takes less space but longer time.
            }
            return false;
        };
        return dfs(0);
    }
};
```