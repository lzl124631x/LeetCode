# [10. Regular Expression Matching (Hard)](https://leetcode.com/problems/regular-expression-matching/solution/)

<p>Given an input string (<code>s</code>) and a pattern (<code>p</code>), implement regular expression matching with support for <code>'.'</code> and <code>'*'</code>.</p>

<pre>'.' Matches any single character.
'*' Matches zero or more of the preceding element.
</pre>

<p>The matching should cover the <strong>entire</strong> input string (not partial).</p>

<p><strong>Note:</strong></p>

<ul>
	<li><code>s</code>&nbsp;could be empty and contains only lowercase letters <code>a-z</code>.</li>
	<li><code>p</code> could be empty and contains only lowercase letters <code>a-z</code>, and characters like&nbsp;<code>.</code>&nbsp;or&nbsp;<code>*</code>.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong>
s = "aa"
p = "a"
<strong>Output:</strong> false
<strong>Explanation:</strong> "a" does not match the entire string "aa".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong>
s = "aa"
p = "a*"
<strong>Output:</strong> true
<strong>Explanation:</strong>&nbsp;'*' means zero or more of the preceding&nbsp;element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong>
s = "ab"
p = ".*"
<strong>Output:</strong> true
<strong>Explanation:</strong>&nbsp;".*" means "zero or more (*) of any character (.)".
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong>
s = "aab"
p = "c*a*b"
<strong>Output:</strong> true
<strong>Explanation:</strong>&nbsp;c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong>
s = "mississippi"
p = "mis*is*p*."
<strong>Output:</strong> false
</pre>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Wildcard Matching (Hard)](https://leetcode.com/problems/wildcard-matching/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/regular-expression-matching/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(M)
class Solution {
private:
    inline bool matchChar(string &s, int i, string &p, int j) {
        return p[j] == '.' ? i < s.size() : s[i] == p[j];
    }
    bool isMatch(string s, int i, string p, int j) {
        if (j == p.size()) return i == s.size();
        if (j + 1 < p.size() && p[j + 1] == '*') {
            bool ans = false;
            while (!(ans = isMatch(s, i, p, j + 2))
            && matchChar(s, i, p, j)) ++i;
            return ans;
        } else {
            return matchChar(s, i, p, j) && isMatch(s, i + 1, p, j + 1);
        }
    }
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/regular-expression-matching/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
    int M, N;
    bool dfs(string &s, string &p, int i, int j) {
        while (i < M && j < N) {
            if (j + 1 < N && p[j + 1] == '*') {
                if (dfs(s, p, i, j + 2)) return true;
                while (i < M && (p[j] == '.' || s[i] == p[j])) {
                    if (dfs(s, p, ++i, j + 2)) return true;
                }
                return false;
            } else {
                if (p[j] != '.' && s[i] != p[j]) return false;
                ++i, ++j;
            }
        }
        if (i == M) {
            while (j + 1 < N && p[j + 1] == '*') j += 2;
        }
        return i == M && j == N;
    }
public:
    bool isMatch(string s, string p) {
        M = s.size(), N = p.size();
        return dfs(s, p, 0, 0);
    }
};
```

## Solution 3. DP (DFS + Memo)

```cpp
// OJ: https://leetcode.com/problems/regular-expression-matching/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
    int M, N;
    vector<vector<int>> m;
    int dfs(string &s, string &p, int i, int j) {
        if (m[i][j] != 0) return m[i][j];
        while (i < M && j < N) {
            if (j + 1 < N && p[j + 1] == '*') {
                do {
                    m[i][j] = dfs(s, p, i, j + 2);
                    if (m[i][j] == 1) return 1;
                    if (p[j] == '.' || s[i] == p[j]) ++i;
                    else return m[i][j] = -1;
                } while (i < M);
            } else {
                if (p[j] != '.' && s[i] != p[j]) return m[i][j] = -1;
                ++i, ++j;
            }
        }
        if (i == M) {
            while (j + 1 < N && p[j + 1] == '*') j += 2;
        }
        return i == M && j == N ? 1 : -1;
    }
public:
    bool isMatch(string s, string p) {
        M = s.size(), N = p.size();
        m.assign(M + 1, vector<int>(N + 1));
        return dfs(s, p, 0, 0) == 1;
    }
};
```

## Solution 4. DP Bottom-up

When I was looking at [the DP solution provided by LeetCode](https://leetcode.com/problems/regular-expression-matching/solution/), I thought why not iterating from the beginning?

Let `dp[i][j]` be whether `s[0..(i-1)]` and `p[0..(j-1)]` matches, where `i` is in `[0, M]`, `j` is in `[0, N]`, and `M` and `N` are the lengths of `s` and `p` respectively.

The result would be `dp[M][N]`.

Trivial case `dp[0][0] = true`.

We handle the `*` pattern when visiting `*`, so we skip `p[j-1]` if `p[j] == '*'`.

* If `p[j-1] == '*'`, we can try using this `*` pattern to:
  1. match 0 element, so `dp[i][j] = dp[i][j - 2]`.
  1. match 1 element if `p[j-2]` and `s[i-1]` matches, so `dp[i][j] = dp[i-1][j-2]`
  1. if the above case is true and `p[j-2]` and `s[i-2]` matches, match 2 elements, so `dp[i][j] = dp[i-2][j-2]`.
  1. ...
  1. keep trying until we are unable to match.
* Otherwise, if `p[j-1]` and `s[i-1]` matches, `dp[i][j] = dp[i-1][j-1]`.

```cpp
// OJ: https://leetcode.com/problems/regular-expression-matching/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size();
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1));
        dp[0][0] = true;
        for (int i = 0; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (j < N && p[j] == '*') continue; // the next element is '*', skip the current one
                if (p[j - 1] == '*') {
                    int k = i;
                    do {
                        if (dp[i][j] = dp[k][j - 2]) break;
                        if (k > 0 && (p[j - 2] == '.' || s[k - 1] == p[j - 2])) --k;
                        else break;
                    } while (k >= 0);
                } else if (i - 1 >= 0 && (p[j - 1] == '.' || s[i - 1] == p[j - 1])) dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[M][N];
    }
};
```

## Solution 5. DP Bottom-up

Let `dp[i][j]` be whether `s[i..(M-1)]` and `p[j..(N-1)]` matches, where `M` and `N` are the lengths of `s` and `p` respectively, and `i` is in `[0,M]` and `j` is in `[0,N]`.

The result would be `dp[0][0]`.

Trivial case `dp[M][N] = true`.

* If `p[j + 1] == '*'`, then we have two options:
  1. ignore this `p[j]*` pattern, so `dp[i][j] = dp[i][j + 2]`.
  1. If `s[i]` matches `p[j]`, we can use `dp[j]*` to cover `s[i]`, so `dp[i][j] = dp[i + 1][j]`.
* Otherwise, if `s[i]` matches `p[j]`, `dp[i][j] = dp[i + 1][j + 1]`
* Otherwise, `dp[i][j] = false`.

```cpp
// OJ: https://leetcode.com/problems/regular-expression-matching/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
// Ref: https://leetcode.com/problems/regular-expression-matching/solution/
class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size();
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1));
        dp[M][N] = true;
        for (int i = M; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                bool match = i < M && (p[j] == '.' || p[j] == s[i]);
                if (j + 1 < N && p[j + 1] == '*') dp[i][j] = dp[i][j + 2] || (match && dp[i + 1][j]);
                else dp[i][j] = match && dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};
```