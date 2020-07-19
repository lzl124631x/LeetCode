# [1478. Allocate Mailboxes (Hard)](https://leetcode.com/problems/allocate-mailboxes/)

<p>Given the array <code>houses</code> and an integer <code>k</code>. where <code>houses[i]</code> is the location of the ith house along a street, your task is to allocate <code>k</code> mailboxes in&nbsp;the street.</p>

<p>Return the <strong>minimum</strong> total distance between each house and its nearest mailbox.</p>

<p>The answer is guaranteed to fit in a 32-bit signed integer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/05/07/sample_11_1816.png" style="width: 454px; height: 154px;"></p>

<pre><strong>Input:</strong> houses = [1,4,8,10,20], k = 3
<strong>Output:</strong> 5
<strong>Explanation: </strong>Allocate mailboxes in position 3, 9 and 20.
Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/05/07/sample_2_1816.png" style="width: 433px; height: 154px;"></strong></p>

<pre><strong>Input:</strong> houses = [2,3,5,12,18], k = 2
<strong>Output:</strong> 9
<strong>Explanation: </strong>Allocate mailboxes in position 3 and 14.
Minimum total distance from each houses to nearest mailboxes is |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> houses = [7,4,6,1], k = 1
<strong>Output:</strong> 8
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> houses = [3,6,14,10], k = 4
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == houses.length</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 100</code></li>
	<li><code>1 &lt;= houses[i] &lt;= 10^4</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
	<li>Array <code>houses</code> contain unique integers.</li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Given `i` and `j` which are the indexes of two houses, what's the optimal mailbox position?

Consider input `[1, 4, 10]`, we should put the mailbox at `4`.

Consider input `[1, 2, 4, 10]`, we should put the mailbox at a position in range `[2, 4]`. Assume we pick `2`.

So in both cases we can pick `A[(i + j) / 2]`.

Let `dist(i, j)` be this optimal total distance. `dist(i, j) = sum( abs(A[k] - A[(i + j) / 2] | i <= k <= j )`.

Let `dp[k][i + 1]` be the answer to the subproblem with `k` mailboxes and houses `[0 .. i]`.

For `dp[k][i + 1]`, we can try spliting with length `j` such that houses `[0 .. j-1]` use `k - 1` mailboxes and houses `[j .. i]` use one mailbox.

```
dp[k][i + 1] = min( dp[k - 1][j] + dist[j][i] | k - 1 <= j <= i ) where k <= i + 1

dp[1][i + 1] = dist[0][i]
```

```cpp
// OJ: https://leetcode.com/problems/allocate-mailboxes/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int minDistance(vector<int>& A, int K) {
        if (A.size() == K) return 0;
        sort(begin(A), end(A));
        int N = A.size(); 
        vector<vector<int>> dist(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int m = A[(i + j) / 2];
                for (int k = i; k <= j; ++k) dist[i][j] += abs(A[k] - m);
            }
        }
        vector<vector<int>> dp(K + 1, vector<int> (N + 1, 1e6));
        for (int i = 0; i < N; ++i) dp[1][i + 1] = dist[0][i];
        for (int k = 2; k <= K; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = i; j >= k - 1; --j) {
                    dp[k][i + 1] = min(dp[k][i + 1], dp[k - 1][j] + dist[j][i]);
                }
            }
        }
        return dp[K][N];
    }
};
```

## Solution 2. DP

Consider input `[1, 4, 10]`, we should put the mailbox at `4` so that the total distance is `10 - 1`.

Consider input `[1, 2, 4, 10]`, we should put the mailbox at a position in range `[2, 4]`, so that the total distance is `(4 + 10) - (1 + 2)`.

Let `dist(i, j)` be this optimal total distance. `dist(i, j) = sum((i + j + 1) / 2, j) - sum(i, (i + j) / 2)`, where `sum(a, b) = sum( A[i] | a <= i <= b )`.

Let `presum[i + 1] = sum( A[k] | 0 <= k <= i )`. Then `sum(a, b) = presum(b + 1) - presum(a)`, so:

```
dist(i, j) = (presum(j + 1) - presum((i + j + 1) / 2)) - (presum((i + j) / 2 + 1) - presum(i))
```

Another optimization is that we can use 1D array for `dp`.

```cpp
// OJ: https://leetcode.com/problems/allocate-mailboxes/
// Author: github.com/lzl124631x
// Time: O(N^2 * K)
// Space: O(N)
// Ref: https://leetcode.com/problems/allocate-mailboxes/discuss/685403/JavaC%2B%2BPython-DP-Solution
class Solution {
    int dist(vector<int> &presum, int i, int j) {
        return (presum[j + 1] - presum[(i + j + 1) / 2]) - (presum[(i + j) / 2 + 1] - presum[i]);
    }
public:
    int minDistance(vector<int>& A, int K) {
        if (A.size() == K) return 0;
        sort(begin(A), end(A));
        int N = A.size(); 
        vector<int> presum(N + 1);
        for (int i = 0; i < N; ++i) presum[i + 1] = presum[i] + A[i];
        vector<int> dp(N + 1, 1e6);
        for (int i = 0; i < N; ++i) dp[i + 1] = dist(presum, 0, i);
        for (int k = 2; k <= K; ++k) {
            for (int i = N - 1; i >= 0; --i) {
                for (int j = i; j >= k - 1; --j) {
                    dp[i + 1] = min(dp[i + 1], dp[j] + dist(presum, j, i));
                }
            }
        }
        return dp[N];
    }
};
```