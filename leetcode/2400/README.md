# [2400. Number of Ways to Reach a Position After Exactly k Steps (Medium)](https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps)

<p>You are given two <strong>positive</strong> integers <code>startPos</code> and <code>endPos</code>. Initially, you are standing at position <code>startPos</code> on an <strong>infinite</strong> number line. With one step, you can move either one position to the left, or one position to the right.</p>

<p>Given a positive integer <code>k</code>, return <em>the number of <strong>different</strong> ways to reach the position </em><code>endPos</code><em> starting from </em><code>startPos</code><em>, such that you perform <strong>exactly</strong> </em><code>k</code><em> steps</em>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>Two ways are considered different if the order of the steps made is not exactly the same.</p>

<p><strong>Note</strong> that the number line includes negative integers.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> startPos = 1, endPos = 2, k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can reach position 2 from 1 in exactly 3 steps in three ways:
- 1 -&gt; 2 -&gt; 3 -&gt; 2.
- 1 -&gt; 2 -&gt; 1 -&gt; 2.
- 1 -&gt; 0 -&gt; 1 -&gt; 2.
It can be proven that no other way is possible, so we return 3.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> startPos = 2, endPos = 5, k = 10
<strong>Output:</strong> 0
<strong>Explanation:</strong> It is impossible to reach position 5 from position 2 in exactly 10 steps.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= startPos, endPos, k &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Combinatorics](https://leetcode.com/tag/combinatorics/)

**Similar Questions**:
* [Unique Paths (Medium)](https://leetcode.com/problems/unique-paths/)
* [Climbing Stairs (Medium)](https://leetcode.com/problems/climbing-stairs/)
* [Reach a Number (Medium)](https://leetcode.com/problems/reach-a-number/)
* [Reaching Points (Medium)](https://leetcode.com/problems/reaching-points/)
* [Number of Ways to Stay in the Same Place After Some Steps (Medium)](https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/)

## Solution 1. Combination

We need at least `abs(endPos - startPos)` steps. `k` must `>= steps`. When `k > steps`, `(k - steps)` must be a even number.

With `k` available moves, we select `steps + (k - steps) / 2` moves in the `startPos`-to-`endPos` direction, and `(k - steps) / 2` moves in the opposite direction. Thus, the answer is $C_k^{(k-steps)/2}$

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps
// Author: github.com/lzl124631x
// Time: O(K * (K - abs(startPos - endPos)))
// Space: O(K - abs(startPos - endPos))
class Solution {
    int combination(int n, int k, int mod) {
        k = min(k, n - k);
        vector<int> dp(k + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = min(i, k); j > 0; --j) {
                dp[j] = (dp[j] + dp[j - 1]) % mod;
            }
        }
        return dp[k];
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int steps = abs(endPos - startPos);
        if (k < steps || (k - steps) % 2) return 0;
        return combination(k, (k - steps) / 2, 1e9 + 7);
    }
};
```