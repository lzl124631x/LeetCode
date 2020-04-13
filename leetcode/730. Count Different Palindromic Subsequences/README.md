# [730. Count Different Palindromic Subsequences (Hard)](https://leetcode.com/problems/count-different-palindromic-subsequences/)

<p>
Given a string S, find the number of different non-empty palindromic subsequences in S, and <b>return that number modulo <code>10^9 + 7</code>.</b>
</p><p>
A subsequence of a string S is obtained by deleting 0 or more characters from S.
</p><p>
A sequence is palindromic if it is equal to the sequence reversed.
</p><p>
Two sequences <code>A_1, A_2, ...</code> and <code>B_1, B_2, ...</code> are different if there is some <code>i</code> for which <code>A_i != B_i</code>.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> 
S = 'bccb'
<b>Output:</b> 6
<b>Explanation:</b> 
The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> 
S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
<b>Output:</b> 104860361
<b>Explanation:</b> 
There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7.
</pre>
<p></p>

<p><b>Note:</b>
</p><li>The length of <code>S</code> will be in the range <code>[1, 1000]</code>.</li>
<li>Each character <code>S[i]</code> will be in the set <code>{'a', 'b', 'c', 'd'}</code>.</li>
<p></p>

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Longest Palindromic Subsequence (Medium)](https://leetcode.com/problems/longest-palindromic-subsequence/)

## Solution 1. DP

First consider the case where we count duplicates as well.

Let `dp[i][j]` be the number of palindromic subsequences in `S[i..j]`.

```
dp[i][j] = 0   if i > j
dp[i][i] = 1
```

If `S[i] != S[j]`:

```
dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]
```
We need to `- dp[i + 1][j - 1]` because the palindromic subsequences are counted twice already in `dp[i + 1][j]` and `dp[i][j - 1]`.

If `S[i] == S[j]`, then there are additional `dp[i + 1][j - 1] + 1` cases where are the palindromic subsequences in `S[(i+1)..(j-1)]` wrapped with `S[i]` and `S[j]`, plus one case `S[i]S[j]`.

```
dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + (dp[i + 1][j - 1] + 1)
         = dp[i + 1][j] + dp[i][j - 1] + 1
```

So in sum, `dp[i][j] = `:
* 0, if `i > j`
* 1, if `i == j`
* `dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]`, if `S[i] != S[j]`
* `dp[i + 1][j] + dp[i][j - 1] + 1`, if `S[i] == S[j]`

Now consider distinct count.

`dp[i][j][k]` is the number of distinct palindromic subsequences in `S[i..j]` bordered by `'a' + k`.

If `S[i] != S[j]`:
```
dp[i][j][k] = dp[i+1][j][k] + dp[i][j-1][k] - dp[i+1][j-1][k]
```

If `S[i] == S[j] && S[i] == 'a' + k`:
```
dp[i][j][k] = 2 + sum( dp[i+1][j-1][t] | 0 <= t < 4 )
```

This is because we can wrap all the cases of `dp[i+1][j-1][t]` with `S[i]` and `S[j]` to form new palindromes (which won't contain `a` and `aa`), and the `+2` means `a` and `aa`.

So in sum, `dp[i][j][k] =`:
* 0, if `i > j` or `i == j && S[i] != 'a' + k`
* 1, if `i == j && S[i] == 'a' + k`
* `dp[i+1][j][k] + dp[i][j-1][k] - dp[i+1][j-1][k]`, if `S[i] != S[j]`
* `2 + sum( dp[i+1][j-1][t] | 0 <= t < 4 )`, if `S[i] == S[j] && S[i] == 'a' + k`

```cpp
// OJ: https://leetcode.com/problems/count-different-palindromic-subsequences/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
// Ref: https://leetcode.com/problems/count-different-palindromic-subsequences/discuss/272297/DP-C%2B%2B-Clear-solution-explained
int memo[1001][1001][4];
class Solution {
    int mod = 1e9 + 7;
    string s;
    int dp(int first, int last, int ch) {
        if (first > last) return 0;
        if (first == last) return s[first] - 'a' == ch;
        if (memo[first][last][ch] != -1) return memo[first][last][ch];
        int ans = 0;
        if (s[first] == s[last] && s[first] - 'a' == ch) {
            ans = 2;
            for (int i = 0; i < 4; ++i) ans = (ans + dp(first + 1, last - 1, i)) % mod;
        } else {
            ans = (ans + dp(first, last - 1, ch)) % mod;
            ans = (ans + dp(first + 1, last, ch)) % mod;
            ans = (ans - dp(first + 1, last - 1, ch)) % mod;
            if (ans < 0) ans += mod;
        }
        return memo[first][last][ch] = ans;
    }
public:
    int countPalindromicSubsequences(string S) {
        s = S;
        memset(memo, -1, sizeof(memo));
        int ans = 0;
        for (int i = 0; i < 4; ++i) ans = (ans + dp(0, S.size() - 1, i)) % mod;
        return ans;
    }
};
```