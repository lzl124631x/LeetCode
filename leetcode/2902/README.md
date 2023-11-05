# [2902. Count of Sub-Multisets With Bounded Sum (Hard)](https://leetcode.com/problems/count-of-sub-multisets-with-bounded-sum)

<p>You are given a <strong>0-indexed</strong> array <code>nums</code> of non-negative integers, and two integers <code>l</code> and <code>r</code>.</p>

<p>Return <em>the <strong>count of sub-multisets</strong> within</em> <code>nums</code> <em>where the sum of elements in each subset falls within the inclusive range of</em> <code>[l, r]</code>.</p>

<p>Since the answer may be large, return it modulo <code>10<sup>9 </sup>+ 7</code>.</p>

<p>A <strong>sub-multiset</strong> is an <strong>unordered</strong> collection of elements of the array in which a given value <code>x</code> can occur <code>0, 1, ..., occ[x]</code> times, where <code>occ[x]</code> is the number of occurrences of <code>x</code> in the array.</p>

<p><strong>Note</strong> that:</p>

<ul>
	<li>Two <strong>sub-multisets</strong> are the same if sorting both sub-multisets results in identical multisets.</li>
	<li>The sum of an <strong>empty</strong> multiset is <code>0</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,2,3], l = 6, r = 6
<strong>Output:</strong> 1
<strong>Explanation:</strong> The only subset of nums that has a sum of 6 is {1, 2, 3}.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,1,4,2,7], l = 1, r = 5
<strong>Output:</strong> 7
<strong>Explanation:</strong> The subsets of nums that have a sum within the range [1, 5] are {1}, {2}, {4}, {2, 2}, {1, 2}, {1, 4}, and {1, 2, 2}.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,1,3,5,2], l = 3, r = 5
<strong>Output:</strong> 9
<strong>Explanation:</strong> The subsets of nums that have a sum within the range [3, 5] are {3}, {5}, {1, 2}, {1, 3}, {2, 2}, {2, 3}, {1, 1, 2}, {1, 1, 3}, and {1, 2, 2}.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 2 * 10<sup>4</sup></code></li>
	<li>Sum of <code>nums</code> does not exceed <code>2 * 10<sup>4</sup></code>.</li>
	<li><code>0 &lt;= l &lt;= r &lt;= 2 * 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Sliding Window](https://leetcode.com/tag/sliding-window)

**Similar Questions**:
* [Coin Change (Medium)](https://leetcode.com/problems/coin-change)
* [Coin Change II (Medium)](https://leetcode.com/problems/coin-change-ii)

**Hints**:
* Since the sum of <code>nums</code>is at most <code>20000</code>, the number of distinct elements of nums is <code>200</code>.
* Let <code>dp[x]</code> be the number of submultisets of <code>nums</code> with sum <code>x</code>.
* The answer to the problem is <code>dp[l] + dp[l+1] + … + dp[r]</code>.
* Use coin change dp to transition between states.

## Solution 1.

What's the max number of distinct elements in `A`? To get the max number of distinct elements, we fill `0,1,2,...` into `A`, and the sum is `(N-1)*N/2`. Since the sum of `A` is at most `20000`, we can get that the max number of `N` is `200`.

Let `dp[x]` be the number of submultisets of `A` with sum `x`. The answer is `SUM( dp[i] | l <= i <= r )`.

We can calculate `dp[x]` using bounded knapsack.

```
dp[i+1][0] = 1
dp[i+1][x] = dp[i][x] // don't use A[i]
				+ dp[i][x-A[i]] // use A[i] once
				+ dp[i][x-2*A[i]] // use A[i] twice
				+ ...
				+ dp[i][x-cnt[i]*A[i]] // use A[i] `cnt[i]` times where cnt[i] is the count of A[i] in the original array
```

Since `dp[i+1][x]` only depends on values in the previous row, we can reduce the space complexity to `O(2*N)`

```
next[x] = dp[x] + dp[x-A[i]] + ... dp[x-cnt[i]*A[i]]
		= dp[x] + next[x-A[i]] - dp[x-(cnt[i]+1)*A[i]]
```

```cpp
// OJ: https://leetcode.com/problems/count-of-sub-multisets-with-bounded-sum
// Author: github.com/lzl124631x
// Time: O(N + UR) where U is the number of unique numbers in `A`
// Space: O(U + R)
class Solution {
public:
    int countSubMultisets(vector<int>& A, int L, int R) {
        long N = A.size(), mod = 1e9 + 7, ans = 0;
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        vector<long> dp(R + 1);
        dp[0] = 1;
        for (auto &[n, c] : cnt) {
            if (n == 0) continue;
            vector<long> next(R + 1);
            next[0] = 1;
            for (int x = 1; x <= R; ++x) {
                next[x] = dp[x];
                if (x - n >= 0) {
                    next[x] = (next[x] + next[x - n]) % mod;
                    if (x - (c + 1) * n >= 0) next[x] = (next[x] - dp[x - (c + 1) * n] + mod) % mod;
                }
            }
            swap(dp, next);
        }
        for (int i = L; i <= R; ++i) ans = (ans + dp[i]) % mod;
        return ans * (cnt[0] + 1) % mod;
    }
};
```