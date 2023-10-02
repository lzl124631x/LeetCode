# [516. Longest Palindromic Subsequence (Medium)](https://leetcode.com/problems/longest-palindromic-subsequence/)

<p>Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.</p>

<p><b>Example 1:</b><br>
Input:</p>

<pre>"bbbab"
</pre>
Output:

<pre>4
</pre>
One possible longest palindromic subsequence is "bbbb".

<p>&nbsp;</p>

<p><b>Example 2:</b><br>
Input:</p>

<pre>"cbbd"
</pre>
Output:

<pre>2
</pre>
One possible longest palindromic subsequence is "bb".
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Longest Palindromic Substring (Medium)](https://leetcode.com/problems/longest-palindromic-substring/)
* [Palindromic Substrings (Medium)](https://leetcode.com/problems/palindromic-substrings/)
* [Count Different Palindromic Subsequences (Hard)](https://leetcode.com/problems/count-different-palindromic-subsequences/)
* [Longest Common Subsequence (Medium)](https://leetcode.com/problems/longest-common-subsequence/)
* [Longest Palindromic Subsequence II (Medium)](https://leetcode.com/problems/longest-palindromic-subsequence-ii/)
* [Maximize Palindrome Length From Subsequences (Hard)](https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/)

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [LinkedIn](https://leetcode.com/company/linkedin), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook)

## Solution 1. DP

Let `dp[i][j]` be the length of the longest palindrome subsequence of `s[i..j]`.

```
dp[i][j] = 2 + dp[i+1][j-1]              If s[i] == s[j]
         = max(dp[i+1][j], dp[i][j-1])   If s[i] != s[j]
dp[i][i] = 1
```

The answer is `dp[0][N-1]`.

Note: when `s[i] == s[j]`, when don't we need to consider `dp[i + 1][j]` and `dp[i][j - 1]`? Because `2 + dp[i + 1][j - 1]` must be greater than or equal to them.

```cpp
// i ~ j
s[i] (s[i+1] ... s[j-1]) s[j]
// i ~ j - 1
s[i] (s[i+1] ... s[j-1])
```

We can see that `dp[i][j-1]` is at most `2 + dp[i+1][j-1]`. Similarly, `dp[i+1][j] <= 2 + dp[i+1][j-1]`.


```cpp
// OJ: https://leetcode.com/problems/longest-palindromic-subsequence
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
  int longestPalindromeSubseq(string s) {
      int N = s.size();
      vector<vector<int>> dp(N, vector<int>(N));
      for (int i = 0; i < N; ++i) dp[i][i] = 1;
      for (int len = 2; len <= N; ++len) {
          for (int i = 0; i <= N - len; ++i) {
              int j = i + len - 1;
              if (s[i] == s[j]) dp[i][j] = 2 + dp[i + 1][j - 1];
              else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
          }
      }
      return dp[0][N - 1];
  }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/longest-palindromic-subsequence
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<vector<int>> dp(N + 1, vector<int>(N + 1));
        for (int i = N - 1; i >= 0; --i) {
            for (int j = i; j <= N - 1; ++j) {
                if (i == j) dp[i][j] = 1;
                else if (s[i] == s[j]) dp[i][j] = 2 + dp[i + 1][j - 1];
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][N - 1];
    }
};
```

## Solution 2. DP + Space Optimization

```cpp
// OJ: https://leetcode.com/problems/longest-palindromic-subsequence
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<int> dp(N + 1);
        for (int i = N - 1; i >= 0; --i) {
            int prev = 0;
            for (int j = i; j <= N - 1; ++j) {
                int cur = dp[j];
                if (i == j) dp[j] = 1;
                else if (s[i] == s[j]) dp[j] = 2 + prev;
                else dp[j] = max(dp[j], dp[j - 1]);
                prev = cur;
            }
        }
        return dp[N - 1];
    }
};
```

## Solution 3. LCS

Let `dp[i][j]` be the length of the longest palindrome subsequence of `s[0..(i-1)]` and `t[0..(j-1)]` where `t` is the reverse of `s`.

```
dp[i][j] = 1 + dp[i-1][j-1]                 If s[i-1] == t[j-1]
           max(dp[i-1][j], dp[i][j-1])      If s[i-1] != t[j-1]
dp[0][i] = dp[i][0] = 0
```

```cpp
// OJ: https://leetcode.com/problems/longest-palindromic-subsequence
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<vector<int>> dp(N + 1, vector<int>(N + 1));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (s[i - 1] == s[N - j]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[N][N];
    }
};
```

## Solution 4. LCS + Space Optimization

Since `dp[i][j]` is only dependent on `dp[i-1][j-1]`, `dp[i-1][j]` and `dp[i][j-1]`, we can reduce the space of `dp` array from `N * N` to `1 * N` with a temporary variable storing `dp[i-1][j-1]`.

```cpp
// OJ: https://leetcode.com/problems/longest-palindromic-subsequence
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
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
};
```

```cpp
// OJ: https://leetcode.com/problems/longest-palindromic-subsequence
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    int lcs(string &s, string &t) {
        int M = s.size(), N = t.size();
        if (M < N) swap(M, N), swap(s, t);
        vector<int> dp(N + 1);
        for (int i = 1; i <= M; ++i) {
            int prev = 0;
            for (int j = 1; j <= N; ++j) {
                int cur = dp[j];
                if (s[i - 1] == t[j - 1]) dp[j] = 1 + prev;
                else dp[j] = max(dp[j], dp[j - 1]);
                prev = cur;
            }
        }
        return dp[N];
    }
public:
    int longestPalindromeSubseq(string s) {
        string t(s.rbegin(), s.rend());
        return lcs(s, t);
    }
};
```