# [1029. Two City Scheduling (Easy)](https://leetcode.com/problems/two-city-scheduling/)

<p>There are <code>2N</code> people a company is planning to interview. The cost of flying the <code>i</code>-th person to city <code>A</code> is <code>costs[i][0]</code>, and the cost of flying the <code>i</code>-th person to city <code>B</code> is <code>costs[i][1]</code>.</p>

<p>Return the minimum cost to fly every person to a city such that exactly <code>N</code> people arrive in each city.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[10,20],[30,200],[400,50],[30,20]]</span>
<strong>Output: </strong><span id="example-output-1">110</span>
<strong>Explanation: </strong>
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= costs.length &lt;= 100</code></li>
	<li>It is guaranteed that <code>costs.length</code> is even.</li>
	<li><code>1 &lt;= costs[i][0], costs[i][1] &lt;= 1000</code></li>
</ol>

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. DP

Let `dp[i + 1][j]` be the min cost arranging the first `i + 1` people and when `j` people go to city A, `0 <= i < N, 0 <= j <= i + 1`.

For `dp[i + 1][j]`, we have two options:
* The `i`-th person goes to city A. We get `dp[i][j - 1] + A[i][0]`.
* The `i`-th person goes to city B. We get `dp[i][j] + A[i][1]`. Note that `i + 1 > j` because otherwise we don't have the spot for the `i`-th person to go to city B.

```
dp[i + 1][j] = min(
                    dp[i][j - 1] + A[i][0],                     // the i-th person goes to city A
                    i + 1> j  ? dp[i][j] + A[i][1] : INF        // the i-th person goes to city B
                  )
dp[i + 1][0] = sum( A[k][1] | 0 <= k <= i )
```

```cpp
// OJ: https://leetcode.com/problems/two-city-scheduling/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& A) {
        int N = A.size();
        vector<vector<int>> dp(N + 1, vector<int>(N / 2 + 1));
        for (int i = 0; i < N; ++i) {
            dp[i + 1][0] = dp[i][0] + A[i][1];
            for (int j = 1; j <= min(i + 1, N / 2); ++j) {
                dp[i + 1][j] = min((i + 1 > j ? dp[i][j] + A[i][1] : INT_MAX), dp[i][j - 1] + A[i][0]);
            }
        }
        return dp[N][N / 2];
    }
};
```

## Solution 2. DP with Space Optimization

```cpp
// OJ: https://leetcode.com/problems/two-city-scheduling/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& A) {
        int N = A.size();
        vector<int> dp(N / 2 + 1);
        for (int i = 0; i < N; ++i) {
            for (int j = min(i + 1, N / 2); j >= 1; --j) {
                dp[j] = min((i + 1 > j ? dp[j] + A[i][1] : INT_MAX), dp[j - 1] + A[i][0]);
            }
            dp[0] += A[i][1];
        }
        return dp[N / 2];
    }
};
```