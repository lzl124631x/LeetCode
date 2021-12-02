# [1012. Numbers With Repeated Digits (Hard)](https://leetcode.com/problems/numbers-with-repeated-digits/)

<p>Given an integer <code>n</code>, return <em>the number of positive integers in the range </em><code>[1, n]</code><em> that have <strong>at least one</strong> repeated digit</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 20
<strong>Output:</strong> 1
<strong>Explanation:</strong> The only positive number (&lt;= 20) with at least 1 repeated digit is 11.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 100
<strong>Output:</strong> 10
<strong>Explanation:</strong> The positive numbers (&lt;= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 1000
<strong>Output:</strong> 262
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Akuna Capital](https://leetcode.com/company/akuna-capital), [IBM](https://leetcode.com/company/ibm), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Bitmask DP

Let's say a good number is a number without repeated digits.

This problem is the same as counting good numbers in `[1,n]`.

Firstly, express `n` as an digits array. Example: `n = 2345`, `digits = [2,3,4,5]`.

Let `f[mask][i]` be the count of good numbers whose `j >= i`th digit is `<= digits[j]` and is not selected in `mask`. The answer is `n - f[0][0]`.

Example:

Assume `digits = [2,3,4,5]`, if we select `2` as the first digit, then we go from state `f[0][0]` to `f[100][1]` where `f[100][1]` is the count of good numbers whose `j >= 1`th digit is `<= digits[j]` and is not `2` (because `mask = 100`).

For `f[mask][i]`, we can try all digits `d` that are `<= digits[i]` and don't conflict with `mask`.

If we selects a digit `d` that is `< digit[i]`, then the following digits are not confined by `digits` but only by `mask`.

Let `g[mask][len]` be the count of good numbers of length `len` those digits don't conflict with `mask`.

For `g[mask][len]`, we can try all digits `d` that don't conflict with `mask`:

```
g[mask][len] = SUM( g[newMask, len - 1] | 0 <= d <= 9 && d is not conflict with mask )
                where newMask = d == 0 && mask == 0 ? 0 : (1 << d | mask)

f[mask][i] = SUM( g[newMask][digits.size() - 1 - i] | 0 <= d < digits[i] && d is not conflict with mask )
                where newMask = d == 0 && mask == 0 ? 0 : (1 << d | mask)
              + ((mask >> digits[i] & 1) == 0 ? f[1 << digit[i] | mask][i+1] : 0)
```

```cpp
// OJ: https://leetcode.com/problems/numbers-with-repeated-digits/
// Author: github.com/lzl124631x
// Time: O(2^lgN * lgN)
// Space: O(2^lgN * lgN)
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        vector<int> digits;
        for (int m = n; m; m /= 10) digits.push_back(m % 10);
        reverse(begin(digits), end(digits));
        int mg[1024][10] = {};
        memset(mg, -1, sizeof(mg));
        function<int(int, int)> g = [&](int mask, int len) -> int {
            if (len == 0) return mask != 0;
            if (mg[mask][len] != -1) return mg[mask][len];
            int ans = 0;
            for (int d = 0; d <= 9; ++d) {
                if (mask >> d & 1) continue;
                int newMask = d == 0 && mask == 0 ? 0 : (1 << d | mask);
                ans += g(newMask, len - 1);
            }
            return mg[mask][len] = ans;
        };
        function<int(int, int)> f = [&](int mask, int i) {
            if (i == digits.size()) return 1;
            int ans = 0;
            for (int d = 0; d < digits[i]; ++d) {
                if (mask >> d & 1) continue;
                int newMask = d == 0 && mask == 0 ? 0 : (1 << d | mask);
                ans += g(newMask, digits.size() - 1 - i);
            }
            if ((mask >> digits[i] & 1) == 0) ans += f(1 << digits[i] | mask, i + 1);
            return ans;
        };
        return n - f(0, 0);
    }
};
```

## TODO

Read https://leetcode.com/problems/numbers-with-repeated-digits/discuss/?currentPage=1&orderBy=most_votes&query=