# [712. Minimum ASCII Delete Sum for Two Strings (Medium)](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings)

<p>Given two strings <code>s1</code> and&nbsp;<code>s2</code>, return <em>the lowest <strong>ASCII</strong> sum of deleted characters to make two strings equal</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s1 = "sea", s2 = "eat"
<strong>Output:</strong> 231
<strong>Explanation:</strong> Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s1 = "delete", s2 = "leet"
<strong>Output:</strong> 403
<strong>Explanation:</strong> Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 1000</code></li>
	<li><code>s1</code> and <code>s2</code> consist of lowercase English letters.</li>
</ul>

**Companies**:
[TripleByte](https://leetcode.com/company/triplebyte)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Edit Distance (Medium)](https://leetcode.com/problems/edit-distance/)
* [Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)
* [Delete Operation for Two Strings (Medium)](https://leetcode.com/problems/delete-operation-for-two-strings/)

## Solution 1. DP

This question is very similar to [72. Edit Distance (Hard)](https://leetcode.com/problems/edit-distance).

Let `dp[i+1][j+1]` be the result for `S[0..i)]` and `T[0..j)]`.

* If `S[i] == T[j]`, `dp[i+1][j+1] = dp[i][j]`, meaning we simply reuse the result `dp[i][j]`.
* If `S[i] != T[j]`, we pick the minimum from the following two options:
  * `S[i] + dp[i][j+1]`, meaning delete `S[i]` and reuse the result `dp[i][j+1]`.
  * `T[j] + dp[i+1][j]`, meaning delete `T[j]` and reuse the result `dp[i+1][j]`.

```
dp[i+1][j+1] = dp[i][j]                                           if S[i] == T[j]
             = min(S[i] + dp[i][j+1], T[j] + dp[i+1][j])          if S[i] != T[j]

dp[0][0] = 0
dp[i+1][0] = S[0] + ... + S[i]         (0 <= i < M)
dp[0][j+1] = T[0] + ... + T[j]         (0 <= j < N)
```

```cpp
// OJ: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) dp[i + 1][0] = dp[i][0] + s[i];
        for (int j = 0; j < N; ++j) dp[0][j + 1] = dp[0][j] + t[j];
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j];
                else dp[i + 1][j + 1] = min(s[i] + dp[i][j + 1], t[j] + dp[i + 1][j]);
            }
        }
        return dp[M][N];
    }
};
```

Or in another form:

```cpp
// OJ: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 1e9));
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (!i && !j) dp[i][j] = 0;
                else if (i && j && s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(i ? dp[i - 1][j] + s[i - 1] : 1e9, j ? dp[i][j - 1] + t[j - 1] : 1e9);
            }
        }
        return dp[M][N];
    }
};
```

## Solution 2. DP with Space Optimization

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

## Solution 3. DP with Further Space Optimization

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

Or:

```cpp
// OJ: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int M = s.size(), N = t.size();
        if (M < N) swap(M, N), swap(s, t);
        vector<int> dp(N + 1, 1e9);
        for (int i = 0; i <= M; ++i) {
            int prev;
            for (int j = 0; j <= N; ++j) {
                int cur = dp[j];
                if (!i && !j) dp[j] = 0;
                else if (i && j && s[i - 1] == t[j - 1]) dp[j] = prev;
                else dp[j] = min(i ? dp[j] + s[i - 1] : 1e9, j ? dp[j - 1] + t[j - 1] : 1e9);
                prev = cur;
            }
        }
        return dp[N];
    }
};
```