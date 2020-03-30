# [1312. Minimum Insertion Steps to Make a String Palindrome (Hard)](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)

<p>Given a string <code>s</code>. In one step you can insert any character at any index of the string.</p>

<p>Return <em>the minimum number of steps</em> to make <code>s</code>&nbsp;palindrome.</p>

<p>A&nbsp;<b>Palindrome String</b>&nbsp;is one that reads the same backward as well as forward.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "zzazz"
<strong>Output:</strong> 0
<strong>Explanation:</strong> The string "zzazz" is already palindrome we don't need any insertions.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "mbadm"
<strong>Output:</strong> 2
<strong>Explanation:</strong> String can be "mbdadbm" or "mdbabdm".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "leetcode"
<strong>Output:</strong> 5
<strong>Explanation:</strong> Inserting 5 characters the string becomes "leetcodocteel".
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "g"
<strong>Output:</strong> 0
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> s = "no"
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li>All characters of <code>s</code>&nbsp;are lower case English letters.</li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

This problem is similar to "given two strings `s` and `t`, count how many insertions are needed to make them the same".

In this problem, `t` is the reversed `s`.

Let `dp[i][j]` be the minimum insertions needed to make `s[0..(i-1)]` and `t[0..(j-1)]` the same.

```
dp[i][j] = dp[i-1][j-1]                     If s[i-1] == t[j-1]
         = 1 + min(dp[i-1][j], dp[i][j-1])  If s[i-1] != t[j-1]
dp[0][i] = dp[i][0] = i
```

The answer of this problem is `dp[N][N] / 2`.

```cpp
// OJ: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int minInsertions(string s) {
        int N = s.size();
        string t(s.rbegin(), s.rend());
        vector<vector<int>> dp(N + 1, vector<int>(N + 1));
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (i == 0 || j == 0) dp[i][j] = i + j;
                else if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[N][N] / 2;
    }
};
```

## Solution 2. DP + Space Optimization

Since `dp[i][j]` is only dependent on `dp[i-1][j-1]`, `dp[i-1][j]` and `dp[i][j-1]`, we can reduce the space of `dp` array from `N * N` to `1 * N` with a temporary variable storing `dp[i-1][j-1]`.

```cpp
// OJ: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int minInsertions(string s) {
        int N = s.size();
        vector<int> dp(N + 1);
        for (int i = 0; i <= N; ++i) {
            int prev;
            for (int j = 0; j <= N; ++j) {
                int cur = dp[j];
                if (i == 0 || j == 0) dp[j] = i + j;
                else if (s[i - 1] == s[N - j]) dp[j] = prev;
                else dp[j] = 1 + min(dp[j], dp[j - 1]);
                prev = cur;
            }
        }
        return dp[N] / 2;
    }
};;
```

## Solution 3. Longest Palindrome Subsequence

If we know the length of the longest palindrome subsequence of `s` is `M`, then the answer to this problem would be `s.size() - M`.

So we can reuse the solution to [516. Longest Palindromic Subsequence (Medium)](https://leetcode.com/problems/longest-palindromic-subsequence/).

```cpp
// OJ: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    int longestPalindromeSubseq(string &s) {
        int N = s.size();
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; ++i) {
            int prev = 0;
            for (int j = 1; j <= N; ++j) {
                int cur = dp[j];
                if (s[i - 1] == s[N - j]) dp[j] = 1 + prev;
                else dp[j] = max(dp[j], dp[j - 1]);
                prev = cur;
            }
        }
        return dp[N];
    }
public:
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};
```