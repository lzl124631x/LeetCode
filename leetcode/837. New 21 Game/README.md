# [837. New 21 Game (Medium)](https://leetcode.com/problems/new-21-game/)

<p>Alice plays the following game, loosely based on the card game "21".</p>

<p>Alice starts with <code>0</code> points, and draws numbers while she has less than <code>K</code> points.&nbsp; During each draw, she gains an integer number of points randomly from the range <code>[1, W]</code>, where <code>W</code> is an integer.&nbsp; Each draw is independent and the outcomes have equal probabilities.</p>

<p>Alice stops drawing numbers when she gets <code>K</code> or more points.&nbsp; What is the probability&nbsp;that she has <code>N</code> or less points?</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>N = 10, K = 1, W = 10
<strong>Output: </strong>1.00000
<strong>Explanation: </strong> Alice gets a single card, then stops.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>N = 6, K = 1, W = 10
<strong>Output: </strong>0.60000
<strong>Explanation: </strong> Alice gets a single card, then stops.
In 6 out of W = 10 possibilities, she is at or below N = 6 points.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>N = 21, K = 17, W = 10
<strong>Output: </strong>0.73278</pre>

<p><strong>Note:</strong></p>

<ol>
	<li><code>0 &lt;= K &lt;= N &lt;= 10000</code></li>
	<li><code>1 &lt;= W &lt;= 10000</code></li>
	<li>Answers will be accepted as correct if they are within <code>10^-5</code> of the correct answer.</li>
	<li>The judging time limit has been reduced for this question.</li>
</ol>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Brute Force (TLE)

Let `dp[i]` be the possibility to land on node `i`.

For each node `i` in `[0, K)`, try jump `j` steps to node `i + j` where `j` is in `[1, W]`. When landing on node `i + j` from node `i`, `p[i + j]` should increase by `dp[i] / W`.

```cpp
// OJ: https://leetcode.com/problems/new-21-game/
// Author: github.com/lzl124631x
// Time: O(KW)
// Space: O(1)
// NOTE: This solution will get TLE
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (N >= K + W - 1) return 1;
        vector<double> dp(K + W);
        dp[0] = 1;
        for (int i = 0; i < K; ++i) {
            for (int j = 1; j <= W && i + j <= N; ++j) dp[i + j] += dp[i] / W;
        }
        return accumulate(begin(dp) + K, begin(dp) + N + 1, 0.0);
    }
};
```

## Solution 2. DP

Let `dp[i]` be the probability of getting `i` points.

Assume `K = 5, W = 3`.
```
dp[1] = 1/W
dp[2] = 1/W + dp[1]/W
dp[3] = 1/W + dp[1]/W + dp[2]/W

dp[4] = dp[1]/W + dp[2]/W + dp[3]/W
dp[5] = dp[2]/W + dp[3]/W + dp[4]/W

dp[6] = dp[3]/W + dp[4]/W
dp[7] = dp[4]/W
```

```
dp[0] = 1
dp[1] =         dp[0]/W
dp[2] = dp[1] + dp[1]/W
dp[3] = dp[2] + dp[2]/W

dp[4] = dp[3] + dp[3]/W - dp[0]/W
dp[5] = dp[4] + dp[4]/W - dp[1]/W

dp[6] = dp[5]           - dp[2]/W
dp[7] = dp[6]           - dp[3]/W
```

So we have the formula:

```
dp[0] = 1
dp[i] = (i > 1 ? dp[i-1] : 0)
         + (i <= K ? dp[i-1]/W : 0)
         - (i-W-1 >= 0 ? dp[i-W-1]/W : 0)
```

The answer is `sum( dp[i] | K <= i <= N )`.

```cpp
// OJ: https://leetcode.com/problems/new-21-game/
// Author: github.com/lzl124631x
// Time: O(min(N, K + W))
// Space: O(min(N, K + W))
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (!K || N >= K + W - 1) return 1;
        vector<double> dp(N + 1);
        dp[0] = 1;
        double ans = 0;
        for (int i = 1; i <= N; ++i) {
            if (i > 1) dp[i] += dp[i - 1];
            if (i <= K) dp[i] += dp[i - 1] / W;
            if (i > W) dp[i] -= dp[i - W - 1]/W;
            if (i >= K) ans += dp[i];
        }
        return ans;
    }
};
```

## Solution 3. DP

```cpp
// OJ: https://leetcode.com/problems/new-21-game/
// Author: github.com/lzl124631x
// Time: O(K + W)
// Space: O(K + W)
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (!K || N >= K + W - 1) return 1;
        vector<double> dp(K + W);
        for (int i = K; i < K + W && i <= N; ++i) dp[i] = 1;
        double sum = min(N - K + 1, W);
        for (int i = K - 1; i >= 0; --i) {
            dp[i] = sum / W;
            sum += dp[i] - dp[i + W];
        }
        return dp[0];
    }
}
```