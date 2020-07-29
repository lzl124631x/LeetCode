# [1531. String Compression II (Hard)](https://leetcode.com/problems/string-compression-ii/)

<p><a href="http://en.wikipedia.org/wiki/Run-length_encoding">Run-length encoding</a> is a string compression method that works by&nbsp;replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string&nbsp;<code>"aabccc"</code>&nbsp;we replace <font face="monospace"><code>"aa"</code></font>&nbsp;by&nbsp;<font face="monospace"><code>"a2"</code></font>&nbsp;and replace <font face="monospace"><code>"ccc"</code></font>&nbsp;by&nbsp;<font face="monospace"><code>"c3"</code></font>. Thus the compressed string becomes <font face="monospace"><code>"a2bc3"</code>.</font></p>

<p>Notice that in this problem, we are not adding&nbsp;<code>'1'</code>&nbsp;after single characters.</p>

<p>Given a&nbsp;string <code>s</code>&nbsp;and an integer <code>k</code>. You need to delete <strong>at most</strong>&nbsp;<code>k</code> characters from&nbsp;<code>s</code>&nbsp;such that the run-length encoded version of <code>s</code>&nbsp;has minimum length.</p>

<p>Find the <em>minimum length of the run-length encoded&nbsp;version of </em><code>s</code><em> after deleting at most </em><code>k</code><em> characters</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aaabcccd", k = 2
<strong>Output:</strong> 4
<b>Explanation: </b>Compressing s without deleting anything will give us "a3bc3d" of length 6. Deleting any of the characters 'a' or 'c' would at most decrease the length of the compressed string to 5, for instance delete 2 'a' then we will have s = "abcccd" which compressed is abc3d. Therefore, the optimal way is to delete 'b' and 'd', then the compressed version of s will be "a3c3" of length 4.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aabbaa", k = 2
<strong>Output:</strong> 2
<b>Explanation: </b>If we delete both 'b' characters, the resulting compressed string would be "a4" of length 2.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "aaaaaaaaaaa", k = 0
<strong>Output:</strong> 3
<strong>Explanation: </strong>Since k is zero, we cannot delete anything. The compressed string is "a11" of length 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= s.length</code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Let `dp[i][j]` be the answer to the sub-problem with `s[0..(i-1)]` and `j` deletions.

For `dp[i][j]`, we have two options:
1. delete `s[i - 1]`. Then the result is `dp[i - 1][j - 1]`.
2. keep `s[i - 1]`. Then we can try to contruct the optimal solution by scanning backward and delete those letters are different from `s[i - 1]`. Those letters that are same as `s[i - 1]` will be merged using run-length encoding
    1. We scan `t` from `i` to `1`.
    2. If `s[t - 1] == s[i - 1]` then we merge them together; otherwise we delete `s[t - 1]`. We store the merge count using `cnt` and the deleted count using `del`.
    3. We can update `dp[i][j]` using `dp[t - 1][j - del]` and `1 + (cnt >= 100 ? 3 : cnt >= 10 ? 2 : cnt >= 2 ? 1 : 0))` which is the number of characters required to encode the merged `s[i - 1]` section.

```cpp
// OJ: https://leetcode.com/problems/string-compression-ii/
// Author: github.com/lzl124631x
// Time: O(N^2 * K)
// Space: O(N^2)
int dp[101][101];
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int N = s.size();
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                int cnt = 0, del = 0;
                for (int t = i; t > 0; --t) {
                    if (s[t - 1] == s[i - 1]) ++cnt;
                    else ++del;
                    if (j - del < 0) break;
                    dp[i][j] = min(dp[i][j], dp[t - 1][j - del] + 1 + (cnt >= 100 ? 3 : cnt >= 10 ? 2 : cnt >= 2 ? 1 : 0));
                }
            }
        }
        return dp[N][k];
    }
};
```