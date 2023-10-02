# [1547. Minimum Cost to Cut a Stick (Hard)](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/)

<p>Given a wooden stick of length <code>n</code> units. The stick is labelled from <code>0</code> to <code>n</code>. For example, a stick of length <strong>6</strong> is labelled as follows:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/21/statement.jpg" style="width: 521px; height: 111px;">
<p>Given an integer array <code>cuts</code>&nbsp;where <code>cuts[i]</code>&nbsp;denotes a position you should perform a cut at.</p>

<p>You should perform the cuts in order, you can change the order of the cuts as you wish.</p>

<p>The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.</p>

<p>Return <em>the minimum total cost</em> of the&nbsp;cuts.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/23/e1.jpg" style="width: 350px; height: 284px;">
<pre><strong>Input:</strong> n = 7, cuts = [1,3,4,5]
<strong>Output:</strong> 16
<strong>Explanation:</strong> Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/21/e11.jpg" style="width: 350px; height: 284px;">
The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 9, cuts = [5,6,1,4,2]
<strong>Output:</strong> 22
<strong>Explanation:</strong> If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost &lt;= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10^6</code></li>
	<li><code>1 &lt;= cuts.length &lt;= min(n - 1, 100)</code></li>
	<li><code>1 &lt;= cuts[i] &lt;= n - 1</code></li>
	<li>All the integers in <code>cuts</code>&nbsp;array are <strong>distinct</strong>.</li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

To simplify the code, we insert `0` and `n` into the `A`.

Let `dp[i][j]` be the minimum cost if we cut on the stick from `A[i]` to `A[j]`.

* If `j == i + 1` (`len == 2`), we can't cut on this stick, so `dp[i][j] = 0`.
* If `j == i + 2` (`len == 3`), the only choice you have is to cut in the middle, and the cost is the length of this stick, so `dp[i][j] = A[i + 2] - A[i]`.
* If `j > i + 2` (`len >= 4`), we can try to cut at `k` where `i < k < j` and use the minimum cost we can get which is the cost of cutting the left part `dp[i][k]` plus the cost of cutting the right part `dp[k][j]` and the cost of the current cut `A[j] - A[i]`, so `dp[i][j] = min( dp[i][k] + dp[k][j] + A[j] - A[i] | i < k < j)`

The answer is `dp[0][N-1]`.

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int minCost(int n, vector<int>& A) {
        A.push_back(0);
        A.push_back(n);
        sort(begin(A), end(A));
        int N = A.size(), inf = INT_MAX;
        vector<vector<int>> dp(N, vector<int>(N, inf));
        for (int i = 0; i + 1 < N; ++i) dp[i][i + 1] = 0;
        for (int i = 0; i + 2 < N; ++i) dp[i][i + 2] = A[i + 2] - A[i];
        for (int i = N - 4; i >= 0; --i) {
            for (int j = i + 3; j < N; ++j) {
                int val = inf;
                for (int k = i + 1; k < j; ++k) val = min(val, dp[i][k] + dp[k][j]);
                dp[i][j] = val + A[j] - A[i];
            }
        }
        return dp[0][N - 1];
    }
};
```

## Solution 2. Knuth's Optimization

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
// Ref: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/discuss/804270/O(N2)-DP-(Knuth's-Optimization)
class Solution {
public:
    int minCost(int n, vector<int>& A) {
        A.push_back(0);
        A.push_back(n);
        sort(begin(A), end(A));
        int N = A.size();
        vector<vector<int>> dp(N, vector<int>(N)), mid(N, vector<int>(N));
        for (int len = 0; len < N; ++len) {
            for (int i = 0; i + len < N; ++i) {
                int j = i + len;
                if (len < 2) {
                    mid[i][j] = i;
                    continue;
                }
                dp[i][j] = A[j] - A[i];
                int val = INT_MAX;
                for (int k = mid[i][j - 1]; k <= mid[i + 1][j]; ++k) {
                    int next = dp[i][k] + dp[k][j];
                    if (next < val) {
                        val = next;
                        mid[i][j] = k;
                    }
                }
                dp[i][j] += val;
            }
        }
        return dp[0][N - 1];
    }
};
```