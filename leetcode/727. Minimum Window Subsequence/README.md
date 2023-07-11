# [727. Minimum Window Subsequence (Hard)](https://leetcode.com/problems/minimum-window-subsequence)

<p>Given strings <code>s1</code> and <code>s2</code>, return <em>the minimum contiguous&nbsp;substring part of </em><code>s1</code><em>, so that </em><code>s2</code><em> is a subsequence of the part</em>.</p>
<p>If there is no such window in <code>s1</code> that covers all characters in <code>s2</code>, return the empty string <code>""</code>. If there are multiple such minimum-length windows, return the one with the <strong>left-most starting index</strong>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s1 = "abcdebdde", s2 = "bde"
<strong>Output:</strong> "bcde"
<strong>Explanation:</strong> 
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of s2 in the window must occur in order.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s1 = "jmeqksfrsdcmsiwvaovztaqenprpvnbstl", s2 = "u"
<strong>Output:</strong> ""
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s1.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= s2.length &lt;= 100</code></li>
	<li><code>s1</code> and <code>s2</code> consist of lowercase English letters.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google), [Snapchat](https://leetcode.com/company/snapchat), [eBay](https://leetcode.com/company/ebay)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Minimum Window Substring (Hard)](https://leetcode.com/problems/minimum-window-substring/)
* [Longest Continuous Increasing Subsequence (Easy)](https://leetcode.com/problems/longest-continuous-increasing-subsequence/)

## Solution 1. DP

Let `dp[i+1][j+1]` be the number of matched letters between `s[0..i]` and `t[0..j]`, `start[i+1][j+1]` be the starting index of the minimum window corresponding to `dp[i+1][j+1]`.

Initially `dp[i+1][j+1] = 0`, `start[i+1][j+1] = -1`.

If `s[i] == t[j]`, `dp[i+1][j+1] = 1 + dp[i][j]`. `start[i+1][j+1] = j == 0 ? i : start[i][j]`.

If `s[i] != t[j]`, `dp[i+1][j+1] = max(dp[i][j+1], dp[i][j])`. If `dp[i+1][j+1] == dp[i][j+1]`, `start[i+1][j+1] = start[i][j + 1]`. Additionally, if `dp[i+1][j+1] = dp[i][j]`, `start[i+1][j+1] = max(start[i+1][j+1], start[i][j])`

```cpp
// OJ: https://leetcode.com/problems/minimum-window-subsequence
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    string minWindow(string s, string t) {
         int M = s.size(), N = t.size();
         vector<vector<int>> dp(M + 1, vector<int>(N + 1)), start(M + 1, vector<int>(N + 1, -1));
         for (int i = 0; i < M; ++i) {
             for (int j = 0; j < N; ++j) {
                 if (s[i] == t[j]) {
                     dp[i + 1][j + 1] = 1 + dp[i][j];
                     if (j == 0) {
                         start[i + 1][j + 1] = i;
                     } else {
                         start[i + 1][j + 1] = start[i][j];
                     }
                 } else {
                     dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i][j]);
                     if (dp[i + 1][j + 1] == dp[i][j + 1]) {
                         start[i + 1][j + 1] = start[i][j + 1];
                     }
                     if (dp[i + 1][j + 1] == dp[i][j]) {
                         start[i + 1][j + 1] = max(start[i + 1][j + 1], start[i][j]);
                     }
                 }
             }
         }
         int minLen = INT_MAX, st = -1;
         for (int i = 0; i < M; ++i) {
             if (dp[i + 1][N] == N && i - start[i + 1][N] + 1 < minLen) {
                st = start[i + 1][N];
                minLen = i - start[i + 1][N] + 1;
             }
         }
         return minLen == INT_MAX ? "" : s.substr(st, minLen);
    }
};
```

Since `dp[i + 1][j + 1]` only depends on `dp[i][j]` and `dp[i + 1][j]`, we can reduce the space complexity from `O(MN)` to `O(N)`.

```cpp
// OJ: https://leetcode.com/problems/minimum-window-subsequence
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    string minWindow(string s, string t) {
         int M = s.size(), N = t.size(), minLen = INT_MAX, st = -1;
         vector<int> dp(N + 1), start(N + 1, -1);
         for (int i = 0; i < M; ++i) {
             for (int j = N - 1; j >= 0; --j) {
                 if (s[i] == t[j]) {
                     dp[j + 1] = 1 + dp[j];
                     start[j + 1] = j == 0 ? i : start[j];
                 } else {
                     dp[j + 1] = max(dp[j + 1], dp[j]);
                     if (dp[j + 1] == dp[j]) start[j + 1] = max(start[j + 1], start[j]);
                 }
             }
             if (dp[N] == N && i - start[N] + 1 < minLen) {
                 st = start[N];
                 minLen = i - start[N] + 1;
             }
         }
         return minLen == INT_MAX ? "" : s.substr(st, minLen);
    }
};
```