# [1771. Maximize Palindrome Length From Subsequences (Hard)](https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/)

<p>You are given two strings, <code>word1</code> and <code>word2</code>. You want to construct a string in the following manner:</p>

<ul>
	<li>Choose some <strong>non-empty</strong> subsequence <code>subsequence1</code> from <code>word1</code>.</li>
	<li>Choose some <strong>non-empty</strong> subsequence <code>subsequence2</code> from <code>word2</code>.</li>
	<li>Concatenate the subsequences: <code>subsequence1 + subsequence2</code>, to make the string.</li>
</ul>

<p>Return <em>the <strong>length</strong> of the longest <strong>palindrome</strong> that can be constructed in the described manner. </em>If no palindromes can be constructed, return <code>0</code>.</p>

<p>A <strong>subsequence</strong> of a string <code>s</code> is a string that can be made by deleting some (possibly none) characters from <code>s</code> without changing the order of the remaining characters.</p>

<p>A <strong>palindrome</strong> is a string that reads the same forward&nbsp;as well as backward.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> word1 = "cacb", word2 = "cbba"
<strong>Output:</strong> 5
<strong>Explanation:</strong> Choose "ab" from word1 and "cba" from word2 to make "abcba", which is a palindrome.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> word1 = "ab", word2 = "ab"
<strong>Output:</strong> 3
<strong>Explanation:</strong> Choose "ab" from word1 and "a" from word2 to make "aba", which is a palindrome.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> word1 = "aa", word2 = "bb"
<strong>Output:</strong> 0
<strong>Explanation:</strong> You cannot construct a palindrome from the described method, so return 0.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word1.length, word2.length &lt;= 1000</code></li>
	<li><code>word1</code> and <code>word2</code> consist of lowercase English letters.</li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Longest Palindromic Subsequence (Medium)](https://leetcode.com/problems/longest-palindromic-subsequence/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/
// Author: github.com/lzl124631x
// Time: O(MM + NN + MN)
// Space: O(MM + NN + MN)
class Solution {
public:
    int longestPalindrome(string A, string B) {
        reverse(begin(A), end(A));
        int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        vector<vector<int>> X(A.size(), vector<int>(A.size(), 1)), Y(N, vector<int>(B.size(), 1));
        for (int len = 2; len <= M; ++len) {
            for (int i = 0; i <= M - len; ++i) {
                if (A[i] == A[i + len - 1]) X[i][i + len - 1] = 2 + (i + 1 <= i + len - 2 ? X[i + 1][i + len - 2] : 0);
                else X[i][i + len - 1] = max(X[i + 1][i + len - 1], X[i][i + len - 2]);
            }
        }
        for (int len = 2; len <= N; ++len) {
            for (int i = 0; i <= N - len; ++i) {
                if (B[i] == B[i + len - 1]) Y[i][i + len - 1] = 2 + (i + 1 <= i + len - 2 ? Y[i + 1][i + len - 2] : 0);
                else Y[i][i + len - 1] = max(Y[i + 1][i + len - 1], Y[i][i + len - 2]);
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i] == B[j]) {
                    dp[i + 1][j + 1] = 2 + max({dp[i][j], i > 0 ? X[0][i - 1] : 0, j > 0 ? Y[0][j - 1] : 0 });
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[M][N];
    }
};
```

## Solution 2. DP


```cpp
// OJ: https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/
// Author: github.com/lzl124631x
// Time: O((M + N)^2)
// Space: O((M + N)^2)
// Ref: https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/discuss/1075453/C%2B%2B-Longest-Palindromic-Subsequence
class Solution {
    vector<vector<int>> longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = N - 1; i >= 0; --i) {
            for (int j = i; j < N; ++j) {
                if (i == j) dp[i][j] = 1;
                else if (s[i] == s[j]) dp[i][j] = 2 + dp[i + 1][j - 1];
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp;
    }
public:
    int longestPalindrome(string A, string B) {
        auto dp = longestPalindromeSubseq(A + B);
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = B.size() - 1; j >= 0; --j) {
                if (A[i] == B[j]) {
                    ans = max(ans, dp[i][A.size() + j]);
                    break; // Once we find a valid palindrome starting with `A[i]`, it must be the longest among all those starting with `A[i]` because we are traversing `j` in the reverse order. So we can break here.
                }
            }
        }
        return ans;
    }
};
```