# [664. Strange Printer (Hard)](https://leetcode.com/problems/strange-printer/)

<p>
There is a strange printer with the following two special requirements:

</p><ol>
<li>The printer can only print a sequence of the same character each time.</li>
<li>At each turn, the printer can print new characters starting from and ending at any places, and will cover the original existing characters.</li>
</ol>

<p></p>

<p>
Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> "aaabbb"
<b>Output:</b> 2
<b>Explanation:</b> Print "aaa" first and then print "bbb".
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> "aba"
<b>Output:</b> 2
<b>Explanation:</b> Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
</pre>
<p></p>

<p><b>Hint</b>: Length of the given string will not exceed 100.</p>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Remove Boxes (Hard)](https://leetcode.com/problems/remove-boxes/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/strange-printer/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
// Ref: https://leetcode.com/problems/strange-printer/discuss/106810/Java-O(n3)-DP-Solution-with-Explanation-and-Simple-Optimization
class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            dp[i][i] = 1;
            if (i > 0) dp[i - 1][i] = s[i - 1] == s[i] ? 1 : 2;
        }
        for (int len = 3; len <= N; ++len) {
            for (int i = 0; i + len <= N; ++i) {
                int val = len;
                for (int j = 0; j < len - 1; ++j) {
                    val = min(val, dp[i][i + j] + dp[i + j + 1][i + len - 1] - (s[i + j] == s[i + len - 1]));
                }
                dp[i][i + len - 1] = val;
            }
        } 
        return dp[0][N - 1];
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/strange-printer/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
// Ref: https://leetcode.com/problems/strange-printer/discuss/106810/Java-O(n3)-DP-Solution-with-Explanation-and-Simple-Optimization/342701
class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int j = 0; j < N; ++j) {
            for (int i = j; i >= 0; --i) {
                dp[i][j] = i == j ? 1 : (1 + dp[i + 1][j]);
                for (int k = i + 1; k <= j; ++k) {
                    if (s[k] != s[i]) continue;
                    dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                }
            }
        }
        return dp[0][N - 1];
    }
};
```