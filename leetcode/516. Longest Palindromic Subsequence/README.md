# [516. Longest Palindromic Subsequence (Medium)](https://leetcode.com/problems/longest-palindromic-subsequence/)

<p>
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
</p>

<p><b>Example 1:</b><br>
Input: 
</p><pre>"bbbab"
</pre>
Output: 
<pre>4
</pre>
One possible longest palindromic subsequence is "bbbb".
<p></p>

<p><b>Example 2:</b><br>
Input:
</p><pre>"cbbd"
</pre>
Output:
<pre>2
</pre>
One possible longest palindromic subsequence is "bb".
<p></p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [LinkedIn](https://leetcode.com/company/linkedin), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-palindromic-subsequence
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    if (s.empty()) return 0;
    vector<vector<int>> m(s.size(), vector<int>(s.size(), 0));
    for (int i = 0; i < s.size(); ++i) m[i][i] = 1;
    for (int len = 2; len <= s.size(); ++len) {
      for (int i = 0; i <= s.size() - len; ++i) {
        int j = i + len - 1;
        if (s[i] == s[j]) m[i][j] = max(2 + m[i + 1][j - 1], max(m[i + 1][j], m[i][j - 1]));
        else m[i][j] = max(m[i + 1][j], m[i][j - 1]);
      }
    }
    return m[0][s.size() - 1];
  }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/longest-palindromic-subsequence
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int N = s.size();
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (s[i] == s[N - 1 - j]) dp[i + 1][j + 1] = dp[i][j] + 1;
        else dp[i + 1][j + 1] = maax(dp[i][j + 1], dp[i + 1][j]);
      }
    }
    return dp[N][N];
  }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/longest-palindromic-subsequence
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int N = s.size();
    vector<vector<int>> dp(2, vector<int>(N + 1, 0));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (s[i] == s[N - 1 - j]) dp[(i + 1) % 2][j + 1] = dp[i % 2][j] + 1;
        else dp[(i + 1) % 2][j + 1] = max(dp[i % 2][j + 1], dp[(i + 1) % 2][j]);
      }
    }
    return dp[N % 2][N];
  }
};
```