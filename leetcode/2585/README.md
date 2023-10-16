# [2585. Number of Ways to Earn Points (Hard)](https://leetcode.com/problems/number-of-ways-to-earn-points)

<p>There is a test that has <code>n</code> types of questions. You are given an integer <code>target</code> and a <strong>0-indexed</strong> 2D integer array <code>types</code> where <code>types[i] = [count<sub>i</sub>, marks<sub>i</sub>]</code> indicates that there are <code>count<sub>i</sub></code> questions of the <code>i<sup>th</sup></code> type, and each one of them is worth <code>marks<sub>i</sub></code> points.</p>

<ul>
</ul>

<p>Return <em>the number of ways you can earn <strong>exactly</strong> </em><code>target</code><em> points in the exam</em>. Since the answer may be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p><strong>Note</strong> that questions of the same type are indistinguishable.</p>

<ul>
	<li>For example, if there are <code>3</code> questions of the same type, then solving the <code>1<sup>st</sup></code> and <code>2<sup>nd</sup></code> questions is the same as solving the <code>1<sup>st</sup></code> and <code>3<sup>rd</sup></code> questions, or the <code>2<sup>nd</sup></code> and <code>3<sup>rd</sup></code> questions.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> target = 6, types = [[6,1],[3,2],[2,3]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> You can earn 6 points in one of the seven ways:
- Solve 6 questions of the 0<sup>th</sup> type: 1 + 1 + 1 + 1 + 1 + 1 = 6
- Solve 4 questions of the 0<sup>th</sup> type and 1 question of the 1<sup>st</sup> type: 1 + 1 + 1 + 1 + 2 = 6
- Solve 2 questions of the 0<sup>th</sup> type and 2 questions of the 1<sup>st</sup> type: 1 + 1 + 2 + 2 = 6
- Solve 3 questions of the 0<sup>th</sup> type and 1 question of the 2<sup>nd</sup> type: 1 + 1 + 1 + 3 = 6
- Solve 1 question of the 0<sup>th</sup> type, 1 question of the 1<sup>st</sup> type and 1 question of the 2<sup>nd</sup> type: 1 + 2 + 3 = 6
- Solve 3 questions of the 1<sup>st</sup> type: 2 + 2 + 2 = 6
- Solve 2 questions of the 2<sup>nd</sup> type: 3 + 3 = 6
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> target = 5, types = [[50,1],[50,2],[50,5]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> You can earn 5 points in one of the four ways:
- Solve 5 questions of the 0<sup>th</sup> type: 1 + 1 + 1 + 1 + 1 = 5
- Solve 3 questions of the 0<sup>th</sup> type and 1 question of the 1<sup>st</sup> type: 1 + 1 + 1 + 2 = 5
- Solve 1 questions of the 0<sup>th</sup> type and 2 questions of the 1<sup>st</sup> type: 1 + 2 + 2 = 5
- Solve 1 question of the 2<sup>nd</sup> type: 5
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> target = 18, types = [[6,1],[3,2],[2,3]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> You can only earn 18 points by answering all questions.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= target &lt;= 1000</code></li>
	<li><code>n == types.length</code></li>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>types[i].length == 2</code></li>
	<li><code>1 &lt;= count<sub>i</sub>, marks<sub>i</sub> &lt;= 50</code></li>
</ul>


**Companies**:
[TuSimple](https://leetcode.com/company/tusimple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Similar Questions**:
* [Coin Change II (Medium)](https://leetcode.com/problems/coin-change-ii)
* [Minimum Total Distance Traveled (Hard)](https://leetcode.com/problems/minimum-total-distance-traveled)

**Hints**:
* Use Dynamic Programming
* Let ways[i][points] be the number of ways to score a given number of points after solving some questions of the first i types.
* ways[i][points] is equal to the sum of ways[i-1][points - solved * marks[i] over 0 <= solved <= count_i

## Solution 1. Bounded Knapsack

Let `dp[i+1][k]` be the number of way to get `k` points with `A[0..i]`. The answer is `dp[N][K]`.

```
dp[i+1][0] = 1

dp[i+1][k] = dp[i][k]  // don't use i-th question
             dp[i][k - A[i][1]] // use 1 i-th question
             dp[i][k - 2 * A[i][1]] // use 2 i-th questions
             ...
dp[i+1][k] = sum( dp[i][k - t * A[i][1]] | 0 <= t <= A[i][0] AND k - t * A[i][1] >= 0 )
```

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-earn-points
// Author: github.com/lzl124631x
// Time: O(NK^2)
// Space: O(NK)
class Solution {
public:
    int waysToReachTarget(int K, vector<vector<int>>& A) {
        int N = A.size(), dp[51][1001] = {}, mod = 1e9 + 7;
        dp[0][0] = 1;
        for (int i = 0; i < N; ++i) {
            for (int k = 0; k <= K; ++k) {
                for (int t = 0; t <= A[i][0] && k - t * A[i][1] >= 0; ++t) {
                    dp[i + 1][k] = (dp[i + 1][k] + dp[i][k - t * A[i][1]]) % mod;
                }
            }
        }
        return dp[N][K];
    }
};
```

## Solution 2. DP with Space Optimization

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-earn-points
// Author: github.com/lzl124631x
// Time: O(NK^2)
// Space: O(K)
class Solution {
public:
    int waysToReachTarget(int K, vector<vector<int>>& A) {
        int N = A.size(), dp[1001] = {}, mod = 1e9 + 7;
        dp[0] = 1;
        for (int i = 0; i < N; ++i) {
            int next[1001] = {};
            for (int k = 0; k <= K; ++k) {
                for (int t = 0; t <= A[i][0] && k - t * A[i][1] >= 0; ++t) {
                    next[k] = (next[k] + dp[k - t * A[i][1]]) % mod;
                }
            }
            swap(dp, next);
        }
        return dp[K];
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-earn-points
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(K)
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& A) {
        int dp[1001] = {[0] = 1}, mod = 1e9 + 7;
        for (auto &v : A) {
            int cnt = v[0], mark = v[1], next[1001] = {}, sum[51] = {};
            for (int t = 0; t <= target; ++t) {
                int i = t % mark;
                sum[i] = (sum[i] + dp[t]) % mod;
                if (t - (cnt + 1) * mark >= 0) sum[i] = (sum[i] - dp[t - (cnt + 1) * mark] + mod) % mod;
                next[t] = sum[i];
            }
            swap(next, dp);
        }
        return dp[target];
    }
};
```