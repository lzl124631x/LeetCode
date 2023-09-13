# [115. Distinct Subsequences (Hard)](https://leetcode.com/problems/distinct-subsequences/)

<p>Given two strings <code>s</code> and <code>t</code>, return <em>the number of distinct subsequences of <code>s</code> which equals <code>t</code></em>.</p>

<p>A string's <strong>subsequence</strong> is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., <code>"ACE"</code> is a subsequence of <code>"ABCDE"</code> while <code>"AEC"</code> is not).</p>

<p>It is guaranteed the answer fits on a 32-bit signed integer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "rabbbit", t = "rabbit"
<strong>Output:</strong> 3
<strong>Explanation:</strong>
As shown below, there are 3 ways you can generate "rabbit" from S.
<code><strong><u>rabb</u></strong>b<strong><u>it</u></strong></code>
<code><strong><u>ra</u></strong>b<strong><u>bbit</u></strong></code>
<code><strong><u>rab</u></strong>b<strong><u>bit</u></strong></code>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "babgbag", t = "bag"
<strong>Output:</strong> 5
<strong>Explanation:</strong>
As shown below, there are 5 ways you can generate "bag" from S.
<code><strong><u>ba</u></strong>b<u><strong>g</strong></u>bag</code>
<code><strong><u>ba</u></strong>bgba<strong><u>g</u></strong></code>
<code><u><strong>b</strong></u>abgb<strong><u>ag</u></strong></code>
<code>ba<u><strong>b</strong></u>gb<u><strong>ag</strong></u></code>
<code>babg<strong><u>bag</u></strong></code></pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 1000</code></li>
	<li><code>s</code> and <code>t</code> consist of English letters.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Mathworks](https://leetcode.com/company/mathworks), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Number of Unique Good Subsequences (Hard)](https://leetcode.com/problems/number-of-unique-good-subsequences/)

## Solution 1. Bottom-up DP

Can use DP for this problem? Yes, because there are lots of duplicate sub-problems.

For example, if `s = ddoooo` and `t = do`, assume we solved the sub-problem `s' = dd` and `t' = d` whose result is 2. Now I have four `o` in `s` to match the `o` in `t`. So the result of sub-problem can be used four times.

Let `dp[i+1][j+1]` the be distinct subsequence of `s[0..i]` and `t[0..j]`. The answer is `dp[M][N]`.

For `dp[i+1][j+1]`, we can:
* add `dp[i][j+1]` to it, which means we simply don't use `s[i]` at all.
* If `s[i] == t[j]`, we can add `dp[i][j]` to it. 

So we have:

```
dp[i+1][j+1] = dp[i][j+1]
                + (s[i] == t[j] ? dp[i][j] : 0) 

dp[0][j] = 0 
dp[i][0] = 1
```

```cpp
// OJ: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int numDistinct(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<long>> dp(M + 1, vector<long>(N + 1));
        for (int i = 0; i <= M; ++i) dp[i][0] = 1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i + 1][j + 1] = dp[i][j + 1];
                if (s[i] == t[j]) dp[i + 1][j + 1] += dp[i][j];
                if (dp[i + 1][j + 1] > INT_MAX) dp[i + 1][j + 1] = 0; // Since the answer is guaranteed to fit on a 32-bit signed integer, once the intermediate value exceeds `INT_MAX`, we can reset it to `0` since it won't be used in the answer.
            }
        }
        return dp[M][N];
    }
};
```

## Solution 2. Space-optimized Bottom-up DP

Since `dp[i+1][j+1]` only depends on `dp[i][j]` and `dp[i][j+1]`, we can reduce the `dp` array from `M * N` to `1 * N`.

```cpp
// OJ: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int numDistinct(string s, string t) {
        int M = s.size(), N = t.size();
        vector<long> dp(N + 1);
        dp[0] = 1;
        for (int i = 0; i < M; ++i) {
            for (int j = N - 1; j >= 0; --j) {
                if (s[i] == t[j]) dp[j + 1] += dp[j];
                if (dp[j + 1] > INT_MAX) dp[j + 1] = 0;
            }
        }
        return dp[N];
    }
};
```
## Solution 3. Top-down DP (DFS + memo)

Using the same DP formula, we can do a top-down DP as well.

```cpp
// OJ: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int numDistinct(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<int>> m(M, vector<int>(N, -1));
        function<int(int, int)> dp = [&](int i, int j) {
            if (i == M || j == N) return int(j == N);
            if (m[i][j] != -1) return m[i][j];
            long ans = dp(i + 1, j);
            if (s[i] == t[j]) ans += dp(i + 1, j + 1);
            if (ans > INT_MAX) ans = 0;
            return m[i][j] = ans;
        };
        return dp(0, 0);
    }
};
```
