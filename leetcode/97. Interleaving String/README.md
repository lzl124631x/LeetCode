# [97. Interleaving String (Hard)](https://leetcode.com/problems/interleaving-string/)

<p>Given <em>s1</em>, <em>s2</em>, <em>s3</em>, find whether <em>s3</em> is formed by the interleaving of <em>s1</em> and <em>s2</em>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s1 = "aabcc", s2 = "dbbca", <em>s3</em> = "aadbbcbcac"
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s1 = "aabcc", s2 = "dbbca", <em>s3</em> = "aadbbbaccc"
<strong>Output:</strong> false
</pre>


**Companies**:  
[Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP Top-down (DFS + Memo)

```cpp
// OJ: https://leetcode.com/problems/interleaving-string/
// Author: github.com/lzl124631x
// Time: O(2^(M+N))
// Space: O(MN)
class Solution {
    int M, N;
    vector<vector<int>> m;
    int dfs(string &a, string &b, string &c, int i, int j) {
        if (i == M && j == N) return 1;
        if (m[i][j] != 0) return m[i][j];
        int val = -1;
        if (i < M && a[i] == c[i + j]) val = dfs(a, b, c, i + 1, j);
        if (val != 1 && j < N && b[j] == c[i + j]) val = dfs(a, b, c, i, j + 1);
        return m[i][j] = val;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        M = s1.size(), N = s2.size();
        if (M + N != s3.size()) return false;
        m.assign(M + 1, vector<int>(N + 1));
        return dfs(s1, s2, s3, 0, 0) == 1;
    }
};
```

## Solution 2. DP Bottom-up

Let `dp[i][j]` be whether `a[0..i]` and `b[0..j]` can form `c[0..(i+j)]`.

```
dp[i][j] =  either dp[i + 1][j] if i < M && a[i] == c[i+j]
            or     dp[i][j + 1] if j < N && b[j] == c[i+j]
            or     false

dp[M][N] = true
```

```cpp
// OJ: https://leetcode.com/problems/interleaving-string/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    bool isInterleave(string a, string b, string c) {
        int M = a.size(), N = b.size();
        if (M + N != c.size()) return false;
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        dp[M][N] = true;
        for (int i = M; i >= 0; --i) {
            for (int j = N; j >= 0; --j) {
                if (i < M && a[i] == c[i + j]) dp[i][j] |= dp[i + 1][j];
                if (j < N && b[j] == c[i + j]) dp[i][j] |= dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};
```

## Solution 3. DP with Space Optimization

Since `dp[i][j]` is only dependent on `dp[i+1][j]` and `dp[i][j+1]`, we can reduce the `dp` array from 2D to 1D.

```cpp
// OJ: https://leetcode.com/problems/interleaving-string/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    bool isInterleave(string a, string b, string c) {
        int M = a.size(), N = b.size();
        if (M + N != c.size()) return false;
        vector<int> dp(N + 1);
        for (int i = M; i >= 0; --i) {
            for (int j = N; j >= 0; --j) {
                if (i == M && j == N) dp[j] = true;
                else dp[j] = (i < M && a[i] == c[i + j] && dp[j])
                    || (j < N && b[j] == c[i + j] && dp[j + 1]);
            }
        }
        return dp[0];
    }
};
```