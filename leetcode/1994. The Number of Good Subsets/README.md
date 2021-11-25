# [1994. The Number of Good Subsets (Hard)](https://leetcode.com/problems/the-number-of-good-subsets/)

<p>You are given an integer array <code>nums</code>. We call a subset of <code>nums</code> <strong>good</strong> if its product can be represented as a product of one or more <strong>distinct prime</strong> numbers.</p>

<ul>
	<li>For example, if <code>nums = [1, 2, 3, 4]</code>:

	<ul>
		<li><code>[2, 3]</code>, <code>[1, 2, 3]</code>, and <code>[1, 3]</code> are <strong>good</strong> subsets with products <code>6 = 2*3</code>, <code>6 = 2*3</code>, and <code>3 = 3</code> respectively.</li>
		<li><code>[1, 4]</code> and <code>[4]</code> are not <strong>good</strong> subsets with products <code>4 = 2*2</code> and <code>4 = 2*2</code> respectively.</li>
	</ul>
	</li>
</ul>

<p>Return <em>the number of different <strong>good</strong> subsets in </em><code>nums</code><em> <strong>modulo</strong> </em><code>10<sup>9</sup> + 7</code>.</p>

<p>A <strong>subset</strong> of <code>nums</code> is any array that can be obtained by deleting some (possibly none or all) elements from <code>nums</code>. Two subsets are different if and only if the chosen indices to delete are different.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The good subsets are:
- [1,2]: product is 2, which is the product of distinct prime 2.
- [1,2,3]: product is 6, which is the product of distinct primes 2 and 3.
- [1,3]: product is 3, which is the product of distinct prime 3.
- [2]: product is 2, which is the product of distinct prime 2.
- [2,3]: product is 6, which is the product of distinct primes 2 and 3.
- [3]: product is 3, which is the product of distinct prime 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,3,15]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The good subsets are:
- [2]: product is 2, which is the product of distinct prime 2.
- [2,3]: product is 6, which is the product of distinct primes 2 and 3.
- [2,15]: product is 30, which is the product of distinct primes 2, 3, and 5.
- [3]: product is 3, which is the product of distinct prime 3.
- [15]: product is 15, which is the product of distinct primes 3 and 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 30</code></li>
</ul>


**Companies**:  
[Lowe](https://leetcode.com/company/lowe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Bitmask](https://leetcode.com/tag/bitmask/)

**Similar Questions**:
* [Smallest Sufficient Team (Hard)](https://leetcode.com/problems/smallest-sufficient-team/)
* [Number of Ways to Wear Different Hats to Each Other (Hard)](https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/)

## Solution 1. Bitmask DP

```cpp
// OJ: https://leetcode.com/problems/the-number-of-good-subsets/
// Author: github.com/lzl124631x
// Time: O(30 * 2^10)
// Space: O(2^10)
constexpr long mod = 1000000007;
int mask[31] = { -1, 0, 1, 2, -1, 4, 3, 8, -1, -1, 5, 16, -1, 32, 9, 6, -1, 64, -1, 128, -1, 10, 17, 256, -1, -1, 33, -1, -1, 512, 7 };
class Solution {
public:
    int numberOfGoodSubsets(vector<int>& A) {
        long dp[1025] = { 1 }, cnt[31] = {};
        for (int n : A) ++cnt[n];
        for (int i = 2; i <= 30; ++i) {
            if (mask[i] == -1 || cnt[i] == 0) continue;
            for (int mi = mask[i], mj = 0; mj < 1024; ++mj) {
                dp[mi | mj] = (dp[mi | mj] + cnt[i] * dp[mj] * ((mi & mj) == 0)) % mod;
            }
        }
        int ans = accumulate(begin(dp) + 1, end(dp), 0, [](int s, int n) { return (s + n) % mod; });
        while (cnt[1]--) ans = (ans << 1) % mod;
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/the-number-of-good-subsets/
// Author: github.com/lzl124631x
// Time: O(30 * 2^10)
// Space: O(30 * 2^10)
long mod = 1e9 + 7, dp[1024][31] = {};
class Solution {
public:
    int numberOfGoodSubsets(vector<int>& A) {
        int primes[10] = {2,3,5,7,11,13,17,19,23,29}, cnt[31] = {}, bitmasks[31] = {}, bad[31] = {};
        for (int n : A) cnt[n]++;
        for (int i = 2; i <= 30; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (i % primes[j] == 0) bitmasks[i] |= 1 << j;
            }
        }
        for (int n : {4,8,9,12,16,18,20,24,25,27,28}) bad[n] = 1;
        memset(dp, -1, sizeof(dp));
        function<long(int, int)> dfs = [&](int mask, int num) -> long {
            if (num == 1) return 1;
            if (dp[mask][num] != -1) return dp[mask][num];
            long ans = dfs(mask, num - 1); // If we skip this number
            if (bad[num] == 0 && (mask & bitmasks[num]) == 0) { // If this number is not bad and it doesn't conflict with the selected numbers
                ans = (ans + dfs(mask | bitmasks[num], num - 1) * cnt[num] % mod) % mod; // then we take this number
            }
            return dp[mask][num] = ans;
        };
        long ans = (dfs(0, 30) - 1 + mod) % mod;
        while (cnt[1]--) ans = (ans << 1) % mod;
        return ans;
    }
};
```