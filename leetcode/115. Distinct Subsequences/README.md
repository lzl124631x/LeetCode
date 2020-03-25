# [115. Distinct Subsequences (Hard)](https://leetcode.com/problems/distinct-subsequences/)

Given a string **S** and a string **T**, count the number of distinct subsequences of **S** which equals **T**.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, `"ACE"` is a subsequence of `"ABCDE"` while `"AEC"` is not).

**Example 1:**

**Input:** S = `"rabbbit"`, T = "rabbit"  
**Output:** 3  
**Explanation:**   
As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

```
`rabbbit`
^^^^ ^^
`rabbbit`
^^ ^^^^
`rabbbit`
^^^ ^^^
```

**Example 2:**

**Input:** S = `"babgbag"`, T = "bag"  
**Output:** 5  
**Explanation:**   
As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

```
`babgbag`
^^ ^
`babgbag`
^^    ^
`babgbag`
^    ^^
`babgbag`
  ^  ^^
`babgbag`
    ^^^
```

## Solution 1. DP Top-down (DFS + memo)

```cpp
// OJ: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/lzl124631x
// Time: O(2^S), since there are O(2^S) subsequences. But the memo helped reduce lots of duplicate computation.
// Space: O(ST)
class Solution {
private:
    string S;
    string T;
    vector<vector<int>> v;
    int dfs(int start, int index) {
        if (index == T.size()) {
            return 1;
        }
        if (start >= S.size()) return 0;
        if (v[start][index] != -1) return v[start][index];
        int cnt = 0;
        for (int i = start; i < S.size(); ++i) {
            if (S[i] != T[index]) continue;
            int c = dfs(i + 1, index + 1);
            cnt += c;
        }
        v[start][index] = cnt;
        return cnt;
    }
public:
    int numDistinct(string s, string t) {
        S = s;
        T = t;
        v = vector<vector<int>>(s.size(), vector<int>(t.size(), -1));
        return dfs(0, 0);
    }
};
```

## Solution 2. 2-d DP

Why we can use DP for this question? Because there are lots of duplicate sub-problems.

For example, if `s = ddoooo` and `t = do`, assume we solved the sub-problem `s' = dd` and `t' = d` whose result is 2. Now I have four `o` in `s` to match the `o` in `t`. So the result of sub-problem can be used four times.

Assume `s(i)` is `s[0..(i-1)]`, i.e. the first `i` characters of `s`.

Define `dp(i, j)` as the count of distinct subsequence of `s(i)`  which equals `t(j)`, where `0 <= i <= S` and `0 <= j <= T`.

For `i == 0`, we can't match any `t(j)` if `j > 0`. So `dp(0, j) = 0 (0 < j <= T)`.

For `j == 0`, we can always use empty subsequence to match the empty `t(0)`. So `dp(i, 0) = 1 (0 <= i <= S)`.

For `1 <= i <= S` and `1 <= j <= T`:  
If `s[i - 1] == t[j - 1]` then we have two choices: either use `s[i - 1]` to or not to match `t[j - 1]`.
* If use it, the sub-problem is `dp(i - 1, j - 1)`.
* If not, the sub-problem is `dp(i - 1, j)`

If `s[i - 1] != t[j - 1]` then we have only one choice -- using `s(i-1)` to match `t(j)`, i.e. sub-problem `dp(i - 1, j)`.

In sum:

```
dp(i, j) = => dp(i-1, j) + dp(i-1, j-1)     if s[i] == t[j]
           => dp(i-1, j)                    if s[i] != t[j]
           (0 < j <= T, 0 < i <= S)

dp(0, j) = 0  (0 < j <= T)

dp(i, 0) = 1  (0 <= i <= S)
```

```cpp
// OJ: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/lzl124631x
// Time: O(ST)
// Space: O(ST)
class Solution {
    typedef long long LL;
public:
    int numDistinct(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<LL>> dp(M + 1, vector<LL>(N + 1, 0));
        for (int i = 0; i <= M; ++i) dp[i][0] = 1;
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1]) dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[M][N];
    }
};
```

Or in another form:

```cpp
// OJ: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/lzl124631x
// Time: O(ST)
// Space: O(ST)
class Solution {
    typedef long long LL;
public:
    int numDistinct(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<LL>> dp(M + 1, vector<LL>(N + 1));
        for (int i = M; i >= 0; --i) {
            for (int j = N; j >= 0; --j) {
                if (i == M || j == N) dp[i][j] = j == N;
                else dp[i][j] = dp[i + 1][j] + (s[i] == t[j] ? dp[i + 1][j + 1] : 0);
            }
        }
        return dp[0][0];
    }
};
```

## Solution 3. 1-d DP

From this equation
```
dp(i, j) = => dp(i-1, j) + dp(i-1, j-1)     if s[i] == t[j]
           => dp(i-1, j)                    if s[i] != t[j]
           (0 < j <= T, 0 < i <= S)

dp(0, j) = 0  (0 < j <= T)

dp(i, 0) = 1  (0 <= i <= S)
```

we realized that `dp(i, j)` is only dependent on `dp(i-1, j)` and `dp(i-1, j-1)`.

So if we loop from `i = 1` to `i = S` while `j = T` to `j = 1`, using just one dimensional array is enough since we can reuse the result in the array.

```cpp
// OJ: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/lzl124631x
// Time: O(ST)
// Space: O(T)
class Solution {
    typedef long long LL;
public:
    int numDistinct(string s, string t) {
        vector<LL> dp(t.size() + 1);
        dp[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = t.size(); j > 0; --j) {
                if (s[i] == t[j - 1]) dp[j] += dp[j - 1];
            }
        }
        return dp[t.size()];
    }
};
```

Or in another form:

```cpp
// OJ: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/lzl124631x
// Time: O(ST)
// Space: O(T)
class Solution {
    typedef long long LL;
public:
    int numDistinct(string s, string t) {
        int M = s.size(), N = t.size();
        vector<LL> dp(N + 1);
        for (int i = M; i >= 0; --i) {
            int prev;
            for (int j = N; j >= 0; --j) {
                int cur = dp[j];
                if (i == M || j == N) dp[j] = j == N;
                else if (s[i] == t[j]) dp[j] += prev;
                prev = cur;
            }
        }
        return dp[0];
    }
};
```

Or:

```cpp
// OJ: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/lzl124631x
// Time: O(ST)
// Space: O(T)
class Solution {
    typedef long long LL;
public:
    int numDistinct(string s, string t) {
        int M = s.size(), N = t.size();
        vector<LL> dp(N + 1);
        for (int i = M; i >= 0; --i) {
            for (int j = 0; j <= N; ++j) {
                if (i == M || j == N) dp[j] = j == N;
                else if (s[i] == t[j]) dp[j] += dp[j + 1];
            }
        }
        return dp[0];
    }
};
```