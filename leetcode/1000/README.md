# [1000. Minimum Cost to Merge Stones (Hard)](https://leetcode.com/problems/minimum-cost-to-merge-stones/)

<p>There are <code>N</code> piles of stones arranged in a row.&nbsp; The <code>i</code>-th pile has <code>stones[i]</code> stones.</p>

<p>A <em>move</em> consists of merging <strong>exactly&nbsp;<code>K</code>&nbsp;consecutive</strong> piles into one pile, and the cost of this move is equal to the total number of stones in these <code>K</code> piles.</p>

<p>Find the minimum cost to merge all piles of stones into one pile.&nbsp; If it is impossible, return <code>-1</code>.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>stones = <span id="example-input-1-1">[3,2,4,1]</span>, K = <span id="example-input-1-2">2</span>
<strong>Output: </strong><span id="example-output-1">20</span>
<strong>Explanation: </strong>
We start with [3, 2, 4, 1].
We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
We merge [4, 1] for a cost of 5, and we are left with [5, 5].
We merge [5, 5] for a cost of 10, and we are left with [10].
The total cost was 20, and this is the minimum possible.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>stones = <span id="example-input-2-1">[3,2,4,1]</span>, K = <span id="example-input-2-2">3</span>
<strong>Output: </strong><span id="example-output-2">-1</span>
<strong>Explanation: </strong>After any merge operation, there are 2 piles left, and we can't merge anymore.  So the task is impossible.
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>stones = <span id="example-input-3-1">[3,5,1,2,6]</span>, K = <span id="example-input-3-2">3</span>
<strong>Output: </strong><span id="example-output-3">25</span>
<strong>Explanation: </strong>
We start with [3, 5, 1, 2, 6].
We merge [5, 1, 2] for a cost of 8, and we are left with [3, 8, 6].
We merge [3, 8, 6] for a cost of 17, and we are left with [17].
The total cost was 25, and this is the minimum possible.
</pre>

<p>&nbsp;</p>

<p><strong><span>Note:</span></strong></p>

<ul>
	<li><code><span>1 &lt;= stones.length &lt;= 30</span></code></li>
	<li><code><span>2 &lt;= K &lt;= 30</span></code></li>
	<li><code><span>1 &lt;= stones[i] &lt;= 100</span></code></li>
</ul>
</div>
</div>
</div>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Burst Balloons (Hard)](https://leetcode.com/problems/burst-balloons/)
* [Minimum Cost to Connect Sticks (Medium)](https://leetcode.com/problems/minimum-cost-to-connect-sticks/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-to-merge-stones/
// Author: github.com/lzl124631x
// Time: O(N^3 / K)
// Space: O(N^2)
// Ref: https://leetcode.com/problems/minimum-cost-to-merge-stones/discuss/247567/JavaC%2B%2BPython-DP
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int N = stones.size();
        if ((N - 1) % (K - 1)) return -1;
        vector<int> prefix(N + 1);
        partial_sum(stones.begin(), stones.end(), prefix.begin() + 1);
        vector<vector<int>> dp(N, vector<int>(N));
        for (int m = K; m <= N; ++m) {
            for (int i = 0; i + m <= N; ++i) {
                int j = i + m - 1;
                dp[i][j] = INT_MAX;
                for (int mid = i; mid < j; mid += K - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                }
                if ((j - i) % (K - 1) == 0) dp[i][j] += prefix[j + 1] - prefix[i];
            }
        }
        return dp[0][N - 1];
    }
};
```