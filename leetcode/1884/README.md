# [1884. Egg Drop With 2 Eggs and N Floors (Medium)](https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/)

<p>You are given <strong>two identical</strong> eggs and you have access to a building with <code>n</code> floors labeled from <code>1</code> to <code>n</code>.</p>

<p>You know that there exists a floor <code>f</code> where <code>0 &lt;= f &lt;= n</code> such that any egg dropped at a floor <strong>higher</strong> than <code>f</code> will <strong>break</strong>, and any egg dropped <strong>at or below</strong> floor <code>f</code> will <strong>not break</strong>.</p>

<p>In each move, you may take an <strong>unbroken</strong> egg and drop it from any floor <code>x</code> (where <code>1 &lt;= x &lt;= n</code>). If the egg breaks, you can no longer use it. However, if the egg does not break, you may <strong>reuse</strong> it in future moves.</p>

<p>Return <em>the <strong>minimum number of moves</strong> that you need to determine <strong>with certainty</strong> what the value of </em><code>f</code> is.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can drop the first egg from floor 1 and the second egg from floor 2.
If the first egg breaks, we know that f = 0.
If the second egg breaks but the first egg didn't, we know that f = 1.
Otherwise, if both eggs survive, we know that f = 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 100
<strong>Output:</strong> 14
<strong>Explanation:</strong> One optimal strategy is:
- Drop the 1st egg at floor 9. If it breaks, we know f is between 0 and 8. Drop the 2nd egg starting
  from floor 1 and going up one at a time to find f within 7 more drops. Total drops is 1 + 7 = 8.
- If the 1st egg does not break, drop the 1st egg again at floor 22. If it breaks, we know f is between 9
  and 21. Drop the 2nd egg starting from floor 10 and going up one at a time to find f within 12 more
  drops. Total drops is 2 + 12 = 14.
- If the 1st egg does not break again, follow a similar process dropping the 1st egg from floors 34, 45,
  55, 64, 72, 79, 85, 90, 94, 97, 99, and 100.
Regardless of the outcome, it takes at most 14 drops to determine f.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Super Egg Drop (Hard)](https://leetcode.com/problems/super-egg-drop/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] = min(dp[i], 1 + max(j - 1, dp[i - j]));
            }
        }
        return dp[n];
    }
};
```

## Solution 2. Find Pattern

```
// n => answer
1: 1
2: 2
3: 2
4: 3
5: 3
6: 3
7: 4
8: 4
9: 4
10: 4
11: 5
12: 5
...
```

The pattern is that, for `k` drops, we can test up to `1 + 2 + ... + k` floors.

Now we know we have `n` floors, we need to find the minimum `k` that `1 + 2 + ... + k >= n`.

```cpp
// OJ: https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    int twoEggDrop(int n) {
        int ans = 0;
        while (n > 0) n -= ++ans;
        return ans;
    }
};
```

## Solution 3. Math

We are looking for the minimum `k` that `1 + 2 + ... + k = k * (k + 1) / 2 >= n`, so `k^2 + k - 2n >= 0`.

Based on the solution of quadratic equation

$$
x={\frac {-b\pm {\sqrt {b^{2}-4ac}}}{2a}}
$$

We know `k >= (-1 + sqrt(1 + 8 * n)) / 2`.

```cpp
// OJ: https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int twoEggDrop(int n) {
        return ceil((-1 + sqrt(1 + 8 * n)) / 2); 
    }
};
```