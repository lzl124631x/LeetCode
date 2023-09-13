# [1563. Stone Game V (Hard)](https://leetcode.com/problems/stone-game-v/)

<p>There are several stones&nbsp;<strong>arranged in a row</strong>, and each stone has an associated&nbsp;value which is an integer given in the array&nbsp;<code>stoneValue</code>.</p>

<p>In each round of the game, Alice divides the row into <strong>two non-empty rows</strong> (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and&nbsp;Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.</p>

<p>The game ends when there is only <strong>one stone remaining</strong>. Alice's is initially <strong>zero</strong>.</p>

<p>Return <i>the maximum score that Alice can obtain</i>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> stoneValue = [6,2,3,4,5,5]
<strong>Output:</strong> 18
<strong>Explanation:</strong> In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> stoneValue = [7,7,7,7,7,7,7]
<strong>Output:</strong> 28
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> stoneValue = [4]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= stoneValue.length &lt;= 500</code></li>
	<li><code>1 &lt;=&nbsp;stoneValue[i] &lt;= 10^6</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Stone Game (Medium)](https://leetcode.com/problems/stone-game/)
* [Stone Game II (Medium)](https://leetcode.com/problems/stone-game-ii/)
* [Stone Game III (Hard)](https://leetcode.com/problems/stone-game-iii/)
* [Stone Game IV (Hard)](https://leetcode.com/problems/stone-game-iv/)

## TLE version: Bottom-up DP

The bottom-up version DP will get TLE because it go through every cases, while the top-down DP skip some cases.

```cpp
// OJ: https://leetcode.com/problems/stone-game-v/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int stoneGameV(vector<int>& A) {
        int N = A.size();
        vector<vector<int>> dp(N + 1, vector<int>(N + 1));
        vector<int> sum(N + 1);
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + A[i];
        for (int len = 2; len <= N; ++len)  {
            for (int i = 0; i <= N - len; ++i) {
                int j = i + len - 1, val = 0;
                for (int k = i; k < j; ++k) {
                    int left = sum[k + 1] - sum[i], right = sum[j + 1] - sum[k + 1];
                    int L = dp[i][k] + left, R = dp[k + 1][j] + right;
                    if (left < right) val = max(val, L);
                    else if (right < left) val = max(val, R);
                    else val = max(val, max(L, R));
                }
                dp[i][j] = val;
            }
        }
        return dp[0][N - 1];
    }
};
```

## Solution 1. Top-down DP

```cpp
// OJ: https://leetcode.com/problems/stone-game-v/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
    int dp[501][501] = {}, N;
    vector<int> sum;
    int dfs(vector<int> &A, int i, int j){
        if (i == j) return 0;
        if (dp[i][j]) return dp[i][j];
        int val = 0;
        for (int k = i; k < j; ++k) {
            int left = sum[k + 1] - sum[i], right = sum[j + 1] - sum[k + 1];
            if (left < right) val = max(val, dfs(A, i, k) + left);
            else if (right < left) val = max(val, dfs(A, k + 1, j) + right);
            else val = max({ val, dfs(A, i, k) + left, dfs(A, k + 1, j) + right });
        }
        return dp[i][j] = val;
    }
public:
    int stoneGameV(vector<int>& A) {
        N = A.size();
        sum.assign(N + 1, 0);
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + A[i];
        return dfs(A, 0, N - 1);
    }
};
```