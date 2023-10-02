# [2719. Count of Integers (Hard)](https://leetcode.com/problems/count-of-integers)

<p>You are given two numeric strings <code>num1</code> and <code>num2</code> and two integers <code>max_sum</code> and <code>min_sum</code>. We denote an integer <code>x</code> to be <em>good</em> if:</p>

<ul>
	<li><code>num1 &lt;= x &lt;= num2</code></li>
	<li><code>min_sum &lt;= digit_sum(x) &lt;= max_sum</code>.</li>
</ul>

<p>Return <em>the number of good integers</em>. Since the answer may be large, return it modulo <code>10<sup>9</sup> + 7</code>.</p>

<p>Note that <code>digit_sum(x)</code> denotes the sum of the digits of <code>x</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num1 = &quot;1&quot;, num2 = &quot;12&quot;, <code>min_sum</code> = 1, max_sum = 8
<strong>Output:</strong> 11
<strong>Explanation:</strong> There are 11 integers whose sum of digits lies between 1 and 8 are 1,2,3,4,5,6,7,8,10,11, and 12. Thus, we return 11.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num1 = &quot;1&quot;, num2 = &quot;5&quot;, <code>min_sum</code> = 1, max_sum = 5
<strong>Output:</strong> 5
<strong>Explanation:</strong> The 5 integers whose sum of digits lies between 1 and 5 are 1,2,3,4, and 5. Thus, we return 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num1 &lt;= num2 &lt;= 10<sup>22</sup></code></li>
	<li><code>1 &lt;= min_sum &lt;= max_sum &lt;= 400</code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [DE Shaw](https://leetcode.com/company/de-shaw)

**Related Topics**:  
[Math](https://leetcode.com/tag/math), [String](https://leetcode.com/tag/string), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Hints**:
* Let f(n, l, r) denotes the number of integers from 1 to n with the sum of digits between l and r.
* The answer is f(num2, min_sum, max_sum) - f(num-1, min_sum, max_sum).
* You can calculate f(n, l, r) using digit dp.

## Solution 1.

Let `dp[s][mx]` be the count of numbers `<= s` (`s` is a number expressed as a string) whose digit sum `<= mx`.

The answer can be expressed as follows

```
(dp[t][mx] - dp[t][mn - 1]) - (dp[s1][mx] - dp[s1][mn - 1])
```

where `s1` is the string expression of `s - 1`.

For `dp[s][mx]`, there are two cases:

1. Let the first digit be `s[0]`, we need to count `dp[s[1:]][mx - s[0]]`
2. Let the first digit be `c < s[0]`, we need to count `dp2[s.size() - 1][mx - c]`

Here `dp2[len][mx]` is the count of numbers of length `len` whose digit sum `<= mx`.

```
dp2[len][mx] = SUM( dp2[len - 1][mx - i] | 0 <= i <= 9 )
```

```cpp
// OJ: https://leetcode.com/problems/count-of-integers
// Author: github.com/lzl124631x
// Time: O((M + N) * (Mx + Mn)) where M/N is the length of `s` and `t`.
// Space: O((M + N) * (Mx + Mn))
class Solution {
public:
    int count(string s, string t, int mn, int mx) {
        long mod = 1e9 + 7;
        unordered_map<string, unordered_map<int, long>> m;
        unordered_map<int, unordered_map<int, long>> m2;
        function<long(int, int)> dp2 = [&](int len, int mx) -> long {
            if (len == 1) return max(0, min(mx, 9) + 1);
            if (mx < 0) return 0L;
            if (m2.count(len) && m2[len].count(mx)) return m2[len][mx];
            long ans = 0;
            for (int i = 0; i <= 9; ++i) {
                ans = (ans + dp2(len - 1, mx - i)) % mod;
            }
            return m2[len][mx] = ans;
        };
        function<long(string, int)> dp = [&](string s, int mx) -> long {
            if (s.size() == 1) return max(0, min(s[0] - '0', mx) + 1);
            if (mx < 0) return 0L;
            if (m.count(s) && m[s].count(mx)) return m[s][mx];
            long ans = 0;
            ans = (ans + dp(s.substr(1), mx - s[0] + '0')); // Let the first digit be `s[0]`, count `dp[s[1:]][mx - s[0]]`
            for (char c = s[0] - 1; c >= '0'; --c) {
                ans = (ans + dp2(s.size() - 1, mx - c + '0')) % mod; // Let the first digit be `c < s[0]`, count `dp2[s.size() - 1][mx - c]`
            }
            return m[s][mx] = ans;
        };
        long a = (dp(t, mx) - dp(t, mn - 1) + mod) % mod;
        auto s1 = s;
        int carry = -1;
        for (int i = s1.size() - 1; i >= 0 && carry; --i) {
            if (s1[i] == '0') {
                s1[i] = '9';
            } else {
                s1[i]--;
                carry = 0;
            }
        }
        if (s1[0] == '0' && s1.size() > 1) s1 = s1.substr(1);
        return ((a - dp(s1, mx) + mod) % mod + dp(s1, mn - 1)) % mod;
    }
};
```