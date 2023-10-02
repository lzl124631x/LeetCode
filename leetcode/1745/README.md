# [1745. Palindrome Partitioning IV (Hard)](https://leetcode.com/problems/palindrome-partitioning-iv/)

<p>Given a string <code>s</code>, return <code>true</code> <em>if it is possible to split the string</em> <code>s</code> <em>into three <strong>non-empty</strong> palindromic substrings. Otherwise, return </em><code>false</code>.​​​​​</p>

<p>A string is said to be palindrome if it the same string when reversed.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcbdd"
<strong>Output:</strong> true
<strong>Explanation: </strong>"abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "bcbddxy"
<strong>Output:</strong> false
<strong>Explanation: </strong>s cannot be split into 3 palindromes.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code>​​​​​​ consists only of lowercase English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Palindrome Partitioning (Medium)](https://leetcode.com/problems/palindrome-partitioning/)
* [Palindrome Partitioning II (Hard)](https://leetcode.com/problems/palindrome-partitioning-ii/)
* [Palindrome Partitioning III (Hard)](https://leetcode.com/problems/palindrome-partitioning-iii/)

## Solution 1. Rolling Hash

```cpp
// OJ: https://leetcode.com/problems/palindrome-partitioning-iv/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    bool checkPartitioning(string s) {
        unsigned N = s.size(), h[2001][2001] = {}, rh[2001][2001] = {}, d = 16777619;
        for (int i = 0; i < N; ++i) {
            int hash = 0;
            for (int j = i; j < N; ++j) {
                hash = hash * d + s[j] - 'a';
                h[i][j] = hash;
            }
        }
        reverse(begin(s), end(s));
        for (int i = 0; i < N; ++i) {
            int hash = 0;
            for (int j = i; j < N; ++j) {
                hash = hash * d + s[j] - 'a';
                rh[N - j - 1][N - i - 1] = hash;
            }
        }
        for (int i = 0; i < N; ++i) { // first part [0,i]
            if (h[0][i] != rh[0][i]) continue;
            for (int j = i + 1; j < N - 1; ++j) { // second part [i+1,j], last part [j+1,N-1]
                if (h[i + 1][j] == rh[i + 1][j] && h[j + 1][N - 1] == rh[j + 1][N - 1]) return true;
            }
        }
        return false;
    }
};
```

## Solution 2. DP

Let `dp[i][j]` be whether substring `s[i..j]` is a palindrome.

```
dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1]
dp[i][i] = true 
```

```cpp
// OJ: https://leetcode.com/problems/palindrome-partitioning-iv/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    bool checkPartitioning(string s) {
        int N = s.size(), dp[2001][2001] = {};
        for (int i = N - 1; i >= 0; --i) { // substring [i,j]
            for (int j = i; j < N; ++j) {
                if (i == j) dp[i][j] = true;
                else if (i + 1 == j) dp[i][j] = s[i] == s[j];
                else dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
            }
        }
        for (int i = 0; i < N; ++i) { // first part [0,i]
            for (int j = i + 1; j < N - 1; ++j) { // second part [i+1,j], last part [j+1,N-1]
                if (dp[0][i] && dp[i + 1][j] && dp[j + 1][N - 1]) return true;
            }
        }
        return false;
    }
};
```