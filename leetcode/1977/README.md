# [1977. Number of Ways to Separate Numbers (Hard)](https://leetcode.com/problems/number-of-ways-to-separate-numbers/)

<p>You wrote down many <strong>positive</strong> integers in a string called <code>num</code>. However, you realized that you forgot to add commas to seperate the different numbers. You remember that the list of integers was <strong>non-decreasing</strong> and that <strong>no</strong> integer had leading zeros.</p>

<p>Return <em>the <strong>number of possible lists of integers</strong> that you could have written down to get the string </em><code>num</code>. Since the answer may be large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = "327"
<strong>Output:</strong> 2
<strong>Explanation:</strong>&nbsp;You could have written down the numbers:
3, 27
327
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = "094"
<strong>Output:</strong> 0
<strong>Explanation:</strong>&nbsp;No numbers can have leading zeros and all numbers must be positive.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> num = "0"
<strong>Output:</strong> 0
<strong>Explanation:</strong>&nbsp;No numbers can have leading zeros and all numbers must be positive.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> num = "9999999999999"
<strong>Output:</strong> 101
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 3500</code></li>
	<li><code>num</code> consists of digits <code>'0'</code> through <code>'9'</code>.</li>
</ul>


**Similar Questions**:
* [Decode Ways (Medium)](https://leetcode.com/problems/decode-ways/)
* [Decode Ways II (Hard)](https://leetcode.com/problems/decode-ways-ii/)
* [Restore The Array (Hard)](https://leetcode.com/problems/restore-the-array/)

## Solution 1. DP

Let `dp[i][j]` be the number of ways to split `num[0..j]` with the last number starting at index `i` (`0 <= i <= j < N`). 

The answer is $\sum\limits_{i=0}^{N-1}{dp[i][N-1]}$

For the second to last number `num[k..(i-1)]` of length `i - k` and the last number `num[i..j]` of length `j + 1 - i`:

1. If `i - k < j + 1 - i`, we add `dp[k][i-1]` to `dp[i][j]`. So `dp[i][j] += sum( dp[k][i-1] | max(0, 2*i-j) <= k < i )`
2. If `i - k == j + 1 - i`, i.e. `k == 2*i-j-1`, we need to compare `num[k..(i-1)]` and `num[i..j]`, and add `dp[k][i-1]` to `dp[i][j]` if `num[k..(i-1)] <= num[i..j]`.
3. If `i - k > j + 1 - i`, skip.

```
// 0 <= i <= j < N
dp[i][j] = sum( dp[k][i-1] | max(0, 2*i-j) <= k < i )                        // Case 1
           + (k == 2*i-j-1 && num[k..(i-1)] <= num[i..j] ? dp[k][i-1] : 0)   // Case 2

dp[0][i] = 1 
```

For case 1 and case 2, they will take `O(N)` time without optimization, resulting in a overall time complexity of `O(N^3)`.

**Case 1 Optimization**:

Let `SUM[i][j] = sum( dp[k][i-1] | max(0, 2*i-j) <= k < i )`. 

We can see that for a specific `i`, when `j` increases, the left bound of `k`'s range decreases while right bound stays the same. So we optimize it using suffix sum.

```
SUM[i][j-1] =                  dp[2*i-j+1][i-1] + dp[2*i-j+2][i-1] + ... + dp[i-1][i-1]

SUM[i][j]   = dp[2*i-j][i-1] + dp[2*i-j+1][i-1] + dp[2*i-j+2][i-1] + ... + dp[i-1][i-1]
```

So:

```
// For j >= i+1
SUM[i][j] = SUM[i][j-1] + dp[2*i-j][i-1]
// For j == i
SUM[i][i] = 0
```

**Case 2 Optimization**:

Let `lcp[i][j]` be the length of the longest common prefix of `num[i..(N-1)]` and `num[j..(N-1)]`. We can pre-compute `lcp` with `O(N^2)` time and `O(N^2)` space.

Now we just need to compare next character after the longest common prefixes of these two numbers.

**After Optimization**:

```
// 0 <= i <= j < N
dp[i][j] = SUM[i][j]   // Case 1
          + (k == 2*i-j-1 && (len>=j+1-i || num[k+len] <= num[i+len]) ? dp[k][i] : 0) // Case 2
        where SUM[i][j] is defined above and len = lcp[k][i]

dp[0][i] = 1 
```

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-separate-numbers/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
// Ref: https://leetcode-cn.com/problems/number-of-ways-to-separate-numbers/solution/yu-chu-li-dong-tai-gui-hua-by-endlessche-7am2/
class Solution {
public:
    int numberOfCombinations(string s) {
        if (s[0] == '0') return 0;
        long N = s.size(), mod = 1e9 + 7, ans = 0;
        vector<vector<long>> lcp(N + 1, vector<long>(N + 1)), dp(N, vector<long>(N));
        for (int i = N - 2; i >= 0; --i) {
            for (int j = N - 1; j > i; --j) {
                if (s[i] == s[j]) lcp[i][j] = 1 + lcp[i + 1][j + 1];
            }
        }
        auto ge = [&](int k, int i, int j) { // ge(k, i, j) is true if `s[i..j] >= s[k..(i-1)]`
            int len = lcp[k][i];
            return len >= j + 1 - i || s[k + len] < s[i + len];
        };
        for (int j = 0; j < N; ++j) dp[0][j] = 1;
        for (int i = 1; i < N; ++i) {
            if (s[i] == '0') continue; // case 1
            for (int j = i, k = i - 1, sum = 0; j < N; ++j) {
                dp[i][j] = sum;
                if (k < 0) continue; // if k < 0, case 2 (equal length) is invalid but we still need to continue to handle case 1, so we should use `continue` here.
                if (s[k] > '0' && ge(k, i, j)) dp[i][j] = (dp[i][j] + dp[k][i - 1]) % mod; // case 2
                sum = (sum + dp[k][i - 1]) % mod; // update the sum used in case 1
                --k;
            }
        }
        for (int i = 0; i < N; ++i) ans = (ans + dp[i][N - 1]) % mod;
        return ans;
    }
};
```


## TODO

Summarize the following solution.

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-separate-numbers/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    long mod = 1e9 + 7, N;
    vector<vector<long>> lcp, m, msum;
    long sum(string &s, int i, int prevLen) {
        if (i >= N || prevLen > N - i - 1) return 0;
        if (msum[i][prevLen] != -1) return msum[i][prevLen];
        long ans = (dp(s, i + prevLen + 1, prevLen + 1) + sum(s, i, prevLen + 1)) % mod;
        return msum[i][prevLen] = ans;
    }
    long dp(string &s, int i, int prevLen = 0) {
        if (i >= N) return i == N;
        if (s[i] == '0') return 0;
        if (m[i][prevLen] != -1) return m[i][prevLen];
        long ans = 0;
        if (prevLen && i + prevLen <= N) {
            int len = lcp[i - prevLen][i];
            if (len >= prevLen || s[i - prevLen + len] < s[i + len]) ans = dp(s, i + prevLen, prevLen);
        }
        ans = (ans + sum(s, i, prevLen)) % mod;
        return m[i][prevLen] = ans;
    }
public:
    int numberOfCombinations(string s) {
        if (s[0] == '0') return 0;
        N = s.size();
        lcp.assign(N + 1, vector<long>(N + 1, 0));
        m.assign(N + 1, vector<long>(N + 1, -1));
        msum.assign(N + 1, vector<long>(N + 1, -1));
        for (int i = N - 2; i >= 0; --i) {
            for (int j = N - 1; j > i; --j) {
                if (s[i] == s[j]) lcp[i][j] = 1 + lcp[i + 1][j + 1];
            }
        }
        return dp(s, 0);
    }
};
```