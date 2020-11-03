# [1639. Number of Ways to Form a Target String Given a Dictionary (Hard)](https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/)

<p>You are given a list of strings of the <strong>same length</strong> <code>words</code> and a string <code>target</code>.</p>

<p>Your task is to form <code>target</code> using the given <code>words</code> under the following rules:</p>

<ul>
	<li><code>target</code> should be formed from left to right.</li>
	<li>To form the <code>i<sup>th</sup></code> character (<strong>0-indexed</strong>) of <code>target</code>, you can choose the <code>k<sup>th</sup></code> character of the <code>j<sup>th</sup></code> string in <code>words</code> if <code>target[i] = words[j][k]</code>.</li>
	<li>Once you use the <code>k<sup>th</sup></code> character of the <code>j<sup>th</sup></code> string of <code>words</code>, you <strong>can no longer</strong> use the <code>x<sup>th</sup></code> character of any string in <code>words</code> where <code>x &lt;= k</code>. In other words, all characters to the left of or at index <code>k</code> become unusuable for every string.</li>
	<li>Repeat the process until you form the string <code>target</code>.</li>
</ul>

<p><strong>Notice</strong>&nbsp;that you can use <strong>multiple characters</strong> from the <strong>same string</strong> in <code>words</code> provided the conditions above are met.</p>

<p>Return <em>the number of ways to form <code>target</code> from <code>words</code></em>. Since the answer may be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["acca","bbbb","caca"], target = "aba"
<strong>Output:</strong> 6
<strong>Explanation:</strong> There are 6 ways to form target.
"aba" -&gt; index 0 ("<u>a</u>cca"), index 1 ("b<u>b</u>bb"), index 3 ("cac<u>a</u>")
"aba" -&gt; index 0 ("<u>a</u>cca"), index 2 ("bb<u>b</u>b"), index 3 ("cac<u>a</u>")
"aba" -&gt; index 0 ("<u>a</u>cca"), index 1 ("b<u>b</u>bb"), index 3 ("acc<u>a</u>")
"aba" -&gt; index 0 ("<u>a</u>cca"), index 2 ("bb<u>b</u>b"), index 3 ("acc<u>a</u>")
"aba" -&gt; index 1 ("c<u>a</u>ca"), index 2 ("bb<u>b</u>b"), index 3 ("acc<u>a</u>")
"aba" -&gt; index 1 ("c<u>a</u>ca"), index 2 ("bb<u>b</u>b"), index 3 ("cac<u>a</u>")
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["abba","baab"], target = "bab"
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 ways to form target.
"bab" -&gt; index 0 ("<u>b</u>aab"), index 1 ("b<u>a</u>ab"), index 2 ("ab<u>b</u>a")
"bab" -&gt; index 0 ("<u>b</u>aab"), index 1 ("b<u>a</u>ab"), index 3 ("baa<u>b</u>")
"bab" -&gt; index 0 ("<u>b</u>aab"), index 2 ("ba<u>a</u>b"), index 3 ("baa<u>b</u>")
"bab" -&gt; index 1 ("a<u>b</u>ba"), index 2 ("ba<u>a</u>b"), index 3 ("baa<u>b</u>")
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> words = ["abcd"], target = "abcd"
<strong>Output:</strong> 1
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> words = ["abab","baba","abba","baab"], target = "abba"
<strong>Output:</strong> 16
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 1000</code></li>
	<li>All strings in <code>words</code> have the same length.</li>
	<li><code>1 &lt;= target.length &lt;= 1000</code></li>
	<li><code>words[i]</code> and <code>target</code> contain only lowercase English letters.</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Intuition: we can think of flattening the `words` array into a string where each place has multiple character options. And we use this spacial string to match `target`.

We first do the flattening using a `cnt` array, where `cnt[i]` stores the frequencies of characters at position `i` in `words`.

Let `dp[i+1][j+1]` be the number of ways to match `target[0..j]` using `cnt[0..i]`.

When `j == 0`, we have only `target[0]` to match, we have two options:
1. Use `cnt[i]` to match. There are `cnt[i][target[j] - 'a']` ways.
2. Reuse `dp[i][j + 1]` which covers the cases where we use `cnt[j], j < i` to match `target[0]`.

So `dp[i + 1][j + 1] = cnt[i][target[j] - 'a'] + dp[i][j + 1]` when `j == 0`.

When `j > 0`, we have two options:
1. Use `cnt[i]` to match `target[j]`. There are `cnt[i][target[j] - 'a']` ways to match the last character, and for the leading part there are `dp[i][j]` ways. So in total there are `cnt[i][target[j] - 'a'] * dp[i][j]` ways.
2. Reuse the `dp[i][j + 1]` which covers the cases where we use `cnt[j], j < i` to match `target[j]`. 

So `dp[i + 1][j + 1] = cnt[i][target[j] - 'a'] * dp[i][j] + dp[i][j + 1]` when `j > 0`.

We can merge these two cases by treating `dp[i][j] = 1` if `j == 0`:

```
dp[i + 1][j + 1] = cnt[i][target[j] - 'a'] * dp[i][j] + dp[i][j + 1] where 0 <= i < L, 0 <= j < N

dp[i][0] = 1

dp[i + 1][j + 1] = 0 if i < j
```

The answer is `dp[L][N]`.

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
// Author: github.com/lzl124631x
// Time: O(LM + LN)
// Space: O(LN)
class Solution {
public:
    int numWays(vector<string>& A, string target) {
        long mod = 1e9+7, M = A.size(), L = A[0].size(), N = target.size();
        if (L < N) return 0;
        vector<array<long, 26>> cnt(L, array<long, 26>());
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < M; ++j) cnt[i][A[j][i] - 'a']++;
        }
        vector<vector<int>> dp(L + 1, vector<int>(N + 1));
        for (int i = 0; i < L; ++i) {
            dp[i][0] = 1;
            for (int j = 0; j <= i && j < N; ++j) {
                dp[i + 1][j + 1] = ((cnt[i][target[j] - 'a'] * dp[i][j]) % mod + dp[i][j + 1]) % mod;
            }
        }
        return dp[L][N];
    }
};
```

## Solution 2. DP with Space Optimization

Since `dp[i + 1][j + 1]` only depends on `dp[i][j]` and `dp[i][j + 1]`, we can flatten the `dp` array from `L * N` to `1 * N`.

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
// Author: github.com/lzl124631x
// Time: O(LM + LN)
// Space: O(L + N)
class Solution {
public:
    int numWays(vector<string>& A, string target) {
        long mod = 1e9+7, M = A.size(), L = A[0].size(), N = target.size();
        if (L < N) return 0;
        vector<array<long, 26>> cnt(L, array<long, 26>());
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < M; ++j) cnt[i][A[j][i] - 'a']++;
        }
        vector<long> dp(N + 1);
        for (int i = 0; i < L; ++i) {
            int prev = 1;
            for (int j = 0; j <= i && j < N; ++j) {
                int cur = dp[j + 1];
                dp[j + 1] = ((cnt[i][target[j] - 'a'] * prev) % mod + dp[j + 1]) % mod;
                prev = cur;
            }
        }
        return dp[N];
    }
};
```