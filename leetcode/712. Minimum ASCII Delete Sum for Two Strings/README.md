# [712. Minimum ASCII Delete Sum for Two Strings (Medium)](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)

<p>Given two strings <code>s1, s2</code>, find the lowest ASCII sum of deleted characters to make two strings equal.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> s1 = "sea", s2 = "eat"
<b>Output:</b> 231
<b>Explanation:</b> Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> s1 = "delete", s2 = "leet"
<b>Output:</b> 403
<b>Explanation:</b> Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
</pre>
<p></p>

<p><b>Note:</b>
</p><li><code>0 &lt; s1.length, s2.length &lt;= 1000</code>.</li>
<li>All elements of each string will have an ASCII value in <code>[97, 122]</code>.</li> 
<p></p>

**Companies**:  
[TripleByte](https://leetcode.com/company/triplebyte)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Edit Distance (Hard)](https://leetcode.com/problems/edit-distance/)
* [Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)
* [Delete Operation for Two Strings (Medium)](https://leetcode.com/problems/delete-operation-for-two-strings/)

## Solution 1. DP

This question is very similar to [72. Edit Distance (Hard)](https://leetcode.com/problems/edit-distance).

Let `dp[i][j]` be the result for `S[0..(i-1)]` and `T[0..(j-1)]`.

* If `S[i - 1] == T[j - 1]`, `dp[i][j] = dp[i - 1][j - 1]`, meaning we simply reuse the result `dp[i - 1][j - 1]`.
* If `S[i - 1] != T[j - 1]`, we pick the minimum from the following two options:
  * `S[i - 1] + dp[i - 1][j]`, meaning delete `S[i - 1]` and reuse the result `dp[i - 1][j]`.
  * `T[j - 1] + dp[i][j - 1]`, meaning delete `T[j - 1]` and reuse the result `dp[i][j - 1]`.

```
dp[i][j] = dp[i - 1][j - 1]                                           if S[i - 1] == T[j - 1]
         = min(S[i - 1] + dp[i - 1][j], T[j - 1] + dp[i][j - 1])      if S[i - 1] != T[j - 1]

dp[i][0] = S[0] + ... + S[i - 1]         (0 < i <= M)
dp[0][j] = T[0] + ... + T[j - 1]         (0 < j <= N)
```

```cpp
// OJ: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int M = s1.size(), N = s2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 1; i <= M; ++i) dp[i][0] = dp[i - 1][0] + s1[i - 1];
        for (int i = 1; i <= N; ++i) dp[0][i] = dp[0][i - 1] + s2[i - 1];
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(s1[i - 1] + dp[i - 1][j], s2[j - 1] + dp[i][j - 1]);
            }
        }
        return dp[M][N];
    }
};
```

## Solution 2.

Use rolling array to optimize the space to `2 * min(M, N)`.

```cpp
// OJ: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        if (s1.size() > s2.size()) swap(s1, s2);
        int M = s1.size(), N = s2.size();
        vector<vector<int>> dp(2, vector<int>(N + 1));
        for (int i = 1; i <= N; ++i) dp[0][i] = dp[0][i - 1] + s2[i - 1];
        for (int i = 1; i <= M; ++i) {
            dp[i % 2][0] = dp[(i - 1) % 2][0] + s1[i - 1];
            for (int j = 1; j <= N; ++j) {
                if (s1[i - 1] == s2[j - 1]) dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                else dp[i % 2][j] = min(s1[i - 1] + dp[(i - 1) % 2][j], s2[j - 1] + dp[i % 2][j - 1]);
            }
        }
        return dp[M % 2][N];
    }
};
```

## Solution 3.

One thing that prevents us from using one dimensional array is the dependency between `dp[i + 1][j + 1]` and `dp[i][j]` since when we visit `dp[i + 1][j + 1]`, `dp[i][j]` is overwritten by `dp[i + 1][j]`. We can store `dp[i][j]` in a temporary variable.

```cpp
// OJ: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        if (s1.size() > s2.size()) swap(s1, s2);
        int M = s1.size(), N = s2.size();
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; ++i) dp[i] = dp[i - 1] + s2[i - 1];
        for (int i = 1; i <= M; ++i) {
            int prev = dp[0];
            dp[0] += s1[i - 1];
            for (int j = 1; j <= N; ++j) {
                int next = dp[j];
                if (s1[i - 1] == s2[j - 1]) dp[j] = prev;
                else dp[j] = min(s1[i - 1] + dp[j], s2[j - 1] + dp[j - 1]);
                prev = next;
            }
        }
        return dp[N];
    }
};
```