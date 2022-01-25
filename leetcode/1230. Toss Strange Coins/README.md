# [1230. Toss Strange Coins (Medium)](https://leetcode.com/problems/toss-strange-coins/)

<p>You have some coins.&nbsp; The <code>i</code>-th&nbsp;coin has a probability&nbsp;<code>prob[i]</code> of facing heads when tossed.</p>

<p>Return the probability that the number of coins facing heads equals <code>target</code> if you toss every coin exactly once.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> prob = [0.4], target = 1
<strong>Output:</strong> 0.40000
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> prob = [0.5,0.5,0.5,0.5,0.5], target = 0
<strong>Output:</strong> 0.03125
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= prob.length &lt;= 1000</code></li>
	<li><code>0 &lt;= prob[i] &lt;= 1</code></li>
	<li><code>0 &lt;= target&nbsp;</code><code>&lt;= prob.length</code></li>
	<li>Answers will be accepted as correct if they are within <code>10^-5</code> of the correct answer.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Probability and Statistics](https://leetcode.com/tag/probability-and-statistics/)

## Solution 1. DP

The brute force idea is DFS, or better, DFS + Memo -- for each coin, try head or tail. The time complexity is `O(C(N, T))` where `C(N, T)` is the number of combinations picking `T` elements from total `N` elements. Since `N=1000` at most, in the worst case, `C(N, T)` is `C(1000, 500)` which is a very large number.

The second idea is to consider the coins one by one and use Math and DP.

Consider the first 2 coins, assume we have the following distribution

# of Heads | Probability
---|---
2 | a
1 | b
0 | c

Now consider the 3rd coin with head probability `x`. We'll have a new distribution

# of Heads | Probability
---|---
3|ax
2|bx + a(1-x)
1|cx + b(1-x)
0|     c(1-x)

We can see that for each new coin `A[i]`, we just need to go through previous `i+1` distributions. This results in a time complexity of `O(N^2)`.

```cpp
// OJ: https://leetcode.com/problems/toss-strange-coins/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    double probabilityOfHeads(vector<double>& A, int target) {
        double dp[1001] = {[0] = 1}, tmp[1001] = {};
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= i + 1; ++j) tmp[j] = 0;
            for (int j = 0; j <= i; ++j) tmp[j + 1] += dp[j] * A[i];
            for (int j = 0; j <= i; ++j) tmp[j] += dp[j] * (1 - A[i]);
            swap(tmp, dp);
        }
        return dp[target];
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/toss-strange-coins/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    double probabilityOfHeads(vector<double>& A, int target) {
        int N = A.size();
        vector<double> dp(target + 1);
        dp[0] = 1;
        for (int i = 0; i < N; ++i) {
            for (int j = min(i + 1, target); j >= 0; --j) {
                dp[j] = (j ? dp[j - 1] * A[i] : 0) + dp[j] * (1 - A[i]);
            }
        }
        return dp[target];
    }
};
```