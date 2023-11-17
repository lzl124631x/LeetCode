# [660. Remove 9 (Hard)](https://leetcode.com/problems/remove-9)

<p>Start from integer <code>1</code>, remove any integer that contains <code>9</code> such as <code>9</code>, <code>19</code>, <code>29</code>...</p>

<p>Now, you will have a new integer sequence <code>[1, 2, 3, 4, 5, 6, 7, 8, 10, 11, ...]</code>.</p>

<p>Given an integer <code>n</code>, return <em>the</em> <code>n<sup>th</sup></code> (<strong>1-indexed</strong>) integer in the new sequence.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 9
<strong>Output:</strong> 10
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 10
<strong>Output:</strong> 11
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 8 * 10<sup>8</sup></code></li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google), [Houzz](https://leetcode.com/company/houzz)

**Related Topics**:  
[Math](https://leetcode.com/tag/math)

## Solution 1.

**Intuition**:

* Let `count(x)` be the count of positive numbers that are `<= x`. This `count(x)` is monotonically non-decreasing for `x`.
* We can binary search in range `[1, INT_MAX]`, and find the first number `x` that satisfies `count(x) >= n`


**Algorithm**:

Let `cnt[i]` be the count of positive numbers that have exactly `i` digits without any `9`s.

```
cnt[1] = 8            // 1-8
cnt[2] = 8 * 9        // 1-8 for the first digit, 0-8 for others
cnt[3] = 8 * 9 * 9
...
```

So, `cnt[i] = 8 * 9^(i-1)`. 

Let `sum[i]` be the count of positive numbers that have `<= i` digits without any `9`s.

So, `sum[i] = SUM( cnt[j] | 1 <= j <= i )`.

For a given `n` that has `len` digits, we can use DFS to count the numbers that are `<= n`. For `dfs(i, len)`, we choose the digit to fill at the `i`-th digit, say `c`:

* If we fill a digit `d < c`, we have `mul = c - (i == 0)` such options, then we can fill any **non-negative** numbers that have `len-i-1` digits without `9`s. So this part contributes `mul * (sum[len-i-1] + 1)` numbers. The `+1` is for `0`.
* If `c != 9` and we fill `c`, then we can fill any **non-negative** numbers that are `<=` the last `len-i-1` digits of `n`, and doesn't have `9`s. So this part contributes `c == 9 ? 0 : dfs(i + 1, len)` numbers.

```cpp
// OJ: https://leetcode.com/problems/remove-9
// Author: github.com/lzl124631x
// Time: O(log(INT_MAX) * lg(INT_MAX))
// Space: O(lg(INT_MAX))
class Solution {
public:
    int newInteger(int n) {
        long long L = 1, R = INT_MAX;
        auto count = [&](long long n) {
            auto s = to_string(n);
            int len = s.size();
            vector<long long> sum(len + 1);
            function<long long(int, int)> dfs = [&](int i, int len) {
                if (i == len) return 1LL;
                int c = s[i] - '0', mul = c - (i == 0);
                return mul * (sum[len - i - 1] + 1) + (c == 9 ? 0 : dfs(i + 1, len));
            };
            long long cnt = 1;
            for (int L = 1; L < len; ++L) {
                cnt *= L == 1 ? 8 : 9; // 1-8 for the first digit, 0-8 for the other digits.
                sum[L] = sum[L - 1] + cnt;
            }
            return sum[len - 1] + dfs(0, len);
        };
        while (L <= R) {
            long long M = (L + R) / 2, cnt = count(M);
            if (cnt < n) L = M + 1;
            else R = M - 1;
        }
        return L;
    }
};
```

## Solution 2. Math

Let's write the first numbers and try to notice a pattern. Those numbers are:

```
1, 2, 3, 4, 5, 6, 7, 8,
10, 11, 12, 13, 14, 15, 16, 17, 18,
20, 21, 22, 23, 24, 25, 26, 27, 28,
...
80, 81, 82, 83, 84, 85, 86, 87, 88,
100, 101, 102, ...
```

These numbers look exactly like all base-9 numbers!

Indeed, every base-9 number is a number in this sequence, and every number in this sequence is a base-9 number. Both this sequence and the sequence of all base-9 numbers are in increasing order. The answer is therefore just the n-th base-9 number.

```cpp
// OJ: https://leetcode.com/problems/remove-9
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
    string base9(int n) {
        string ans;
        while (n) {
            ans += '0' + n % 9;
            n /= 9;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
public:
    int newInteger(int n) {
        return stoi(base9(n));
    }
};
```