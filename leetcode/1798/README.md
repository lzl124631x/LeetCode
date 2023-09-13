# [1798. Maximum Number of Consecutive Values You Can Make (Medium)](https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/)

<p>You are given an integer array <code>coins</code> of length <code>n</code> which represents the <code>n</code> coins that you own. The value of the <code>i<sup>th</sup></code> coin is <code>coins[i]</code>. You can <strong>make</strong> some value <code>x</code> if you can choose some of your <code>n</code> coins such that their values sum up to <code>x</code>.</p>

<p>Return the <em>maximum number of consecutive integer values that you <strong>can</strong> <strong>make</strong> with your coins <strong>starting</strong> from and <strong>including</strong> </em><code>0</code>.</p>

<p>Note that you may have multiple coins of the same value.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> coins = [1,3]
<strong>Output:</strong> 2
<strong>Explanation: </strong>You can make the following values:
- 0: take []
- 1: take [1]
You can make 2 consecutive integer values starting from 0.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> coins = [1,1,1,4]
<strong>Output:</strong> 8
<strong>Explanation: </strong>You can make the following values:
- 0: take []
- 1: take [1]
- 2: take [1,1]
- 3: take [1,1,1]
- 4: take [4]
- 5: take [4,1]
- 6: take [4,1,1]
- 7: take [4,1,1,1]
You can make 8 consecutive integer values starting from 0.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,4,10,3,1]
<strong>Output:</strong> 20</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>coins.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= coins[i] &lt;= 4 * 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Patching Array (Hard)](https://leetcode.com/problems/patching-array/)

## Solution 1. Greedy

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int getMaximumConsecutive(vector<int>& A) {
        int cnt = 1;
        sort(begin(A), end(A));
        for (int n : A) {
            if (n > cnt) break;
            cnt += n;
        }
        return cnt;
    }
};
```

## Note

At first I thought this is a 0-1 knapsack problem which will take `O(N * SUM(A))` time. But this will get TLE given the constraints.

```cpp
// 0-1 knapsack. TLE
class Solution {
public:
    int getMaximumConsecutive(vector<int>& A) {
        long sum = accumulate(begin(A), end(A), 0L), N = A.size();
        vector<bool> dp(sum + 1);
        dp[0] = true;
        for (int i = 0; i < N; ++i) {
            for (long j = sum; j >= A[i]; --j) {
                dp[j] = dp[j] | dp[j - A[i]];
            }
        }
        for (long i = 0; i <= sum; ++i) {
            if (!dp[i]) return i;
        }
        return sum + 1;
    }
};
```

Then I started to think how to reduce computation. Apparently iterating all the `sum` is very expensive.

Assume we know what we can get `1, 2, 3`, the we get a new number `5`, then what are all the numbers we can get? They are `1, 2, 3, 6, 7, 8`.

If we represent the numbers using binary mask, then `1, 2, 3` is `111`, and `1, 2, 3, 6, 7, 8` is `11100111`. It's shifting the previous mask leftwards by `5` and merge with the previous mask. Since the sum could be very large we can't use binary mask here.

Since we only care about the first number that we can't form, we only need to keep track of the maximum number we can form.

Assume we can form `[0, cnt)` numbers and now we get a new number `k`, then we can form `[k, cnt + k)` numbers. As long as `k <= cnt`, we can extend the range to `[0, cnt + k)`.

When `k > cnt`, we can't form value `cnt`, and thus we can only get `cnt` consecutive numbers