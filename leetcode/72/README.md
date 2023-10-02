# [72. Edit Distance (Hard)](https://leetcode.com/problems/edit-distance)

<p>Given two words <em>word1</em> and <em>word2</em>, find the minimum number of operations required to convert <em>word1</em> to <em>word2</em>.</p>

<p>You have the following 3 operations permitted on a word:</p>

<ol>
	<li>Insert a character</li>
	<li>Delete a character</li>
	<li>Replace a character</li>
</ol>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> word1 = "horse", word2 = "ros"
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
horse -&gt; rorse (replace 'h' with 'r')
rorse -&gt; rose (remove 'r')
rose -&gt; ros (remove 'e')
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> word1 = "intention", word2 = "execution"
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
intention -&gt; inention (remove 't')
inention -&gt; enention (replace 'i' with 'e')
enention -&gt; exention (replace 'n' with 'x')
exention -&gt; exection (replace 'n' with 'c')
exection -&gt; execution (insert 'u')
</pre>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [LinkedIn](https://leetcode.com/company/linkedin), [Bloomberg](https://leetcode.com/company/bloomberg), [Microsoft](https://leetcode.com/company/microsoft), [Baidu](https://leetcode.com/company/baidu), [Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [One Edit Distance (Medium)](https://leetcode.com/problems/one-edit-distance/)
* [Delete Operation for Two Strings (Medium)](https://leetcode.com/problems/delete-operation-for-two-strings/)
* [Minimum ASCII Delete Sum for Two Strings (Medium)](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)

## Solution 1. DP

Considering the typical "longest common sequence (LCS)" problem, we can use the same DP strategy for this problem, that is, branching based on the equality of `A[i]` and `B[j]`.

Let `dp[i + 1][j + 1]` as the result for `A[0..i]` and `B[0..j]`.

* If `A[i]` equals `B[j]`, `dp[i + 1][j + 1] = dp[i][j]`.
* If `A[i]` doesn't equal `B[j]`, the best result comes from the `min` of the following 3 cases:
	* `1 + dp[i][j]`, where `dp[i][j]` is the result for `A[0..(i - 1)]` and `B[0..(j - 1)]`, and `1` means we do a replacement between `A[i]` and `B[j]` at the end of `A[0..i]` and `B[0..j]`.
	* `1 + dp[i + 1][j]`, where `dp[i + 1][j]` is the result for `A[0..i]` and `B[0..(j - 1)]`, and `1` means we add `B[j]` to the end of `B[0..(j - 1)]`.
	* `1 + dp[i][j + 1]`, where `dp[i][j + 1]` is the result for `A[0..(i - 1)]` and `B[0..j]`, and `1` means we add `A[i]` to the end of `A[0..(i - 1)]`.

In sum:

```
dp[i + 1][j + 1] = dp[i][j]                                            if A[i] == B[j]
                 = 1 + min{ dp[i][j], dp[i + 1][j], dp[i][j + 1] }     if A[i] != B[j]

where 0 <= i < M, 0 <= j < N
```

Trivial cases:
```
dp[i + 1][0] = i + 1
dp[0][j + 1] = j + 1

where 0 <= i < M, 0 <= j < N
```

```cpp
// OJ: https://leetcode.com/problems/edit-distance
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minDistance(string A, string B) {
        if (A.empty() || B.empty()) return max(A.size(), B.size());
        int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) dp[i + 1][0] = i + 1;
        for (int j = 0; j < N; ++j) dp[0][j + 1] = j + 1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i] == B[j]) dp[i + 1][j + 1] = dp[i][j];
                else dp[i + 1][j + 1] = 1 + min({ dp[i][j], dp[i][j + 1], dp[i + 1][j] });
            }
        }
        return dp[M][N];
    }
};
```

Or in another form.

```cpp
// OJ: https://leetcode.com/problems/edit-distance
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minDistance(string A, string B) {
        int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, INT_MAX));
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (i == 0 || j == 0) dp[i][j] = i + j;
                else if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
            }
        }
        return dp[M][N];
    }
};
```

## Solution 2. Space Optimization

Since `dp[i + 1][j + 1]` only relies on `dp[i][j], dp[i + 1][j], dp[i][j + 1]`, we can reduce space from `O(MN)` to `O(min(M, N))` by using rolling arrays.

```cpp
// OJ: https://leetcode.com/problems/edit-distance
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        if (M < N) {
            swap(word1, word2);
            swap(M, N);
        }
        vector<vector<int>> dp(2, vector<int>(N + 1));
        for (int i = 1; i <= N; ++i) dp[0][i] = i;
        for (int i = 1; i <= M; ++i) {
            dp[i % 2][0] = i;
            for (int j = 1; j <= N; ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                else dp[i % 2][j] = 1 + min(min(dp[(i - 1) % 2][j], dp[i % 2][j - 1]), dp[(i - 1) % 2][j - 1]);
            }
        }
        return dp[M % 2][N];
    }
};
```

Or in another form

```cpp
// OJ: https://leetcode.com/problems/edit-distance
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int minDistance(string A, string B) {
        int M = A.size(), N = B.size();
        if (M < N) swap(A, B), swap(M, N); 
        vector<vector<int>> dp(2, vector<int>(N + 1, INT_MAX));
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (i == 0 || j == 0) dp[i % 2][j] = i + j;
                else if (A[i - 1] == B[j - 1]) dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                else dp[i % 2][j] = 1 + min({ dp[(i - 1) % 2][j], dp[i % 2][j - 1], dp[(i - 1) % 2][j - 1] });
            }
        }
        return dp[M % 2][N];
    }
};
```

## Solution 3. Further Space Optimization

The Solution 2 actually requires `2 * min(M, N)` space, we can further reduce it to `min(M, N)`.

One thing that prevents us from using one dimensional array is the dependency between `dp[i + 1][j + 1]` and `dp[i][j]` since when we visit `dp[i + 1][j + 1]`, `dp[i][j]` is overwritten by `dp[i + 1][j]`. We can store `dp[i][j]` in a temporary variable.

```cpp
// OJ: https://leetcode.com/problems/edit-distance
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        if (M < N) {
            swap(word1, word2);
            swap(M, N);
        }
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; ++i) dp[i] = i;
        for (int i = 1; i <= M; ++i) {
            int pre = dp[0];
            dp[0] = i;
            for (int j = 1; j <= N; ++j) {
                int tmp = dp[j];
                if (word1[i - 1] == word2[j - 1]) dp[j] = pre;
                else dp[j] = min(pre, min(dp[j - 1], dp[j])) + 1;
                pre = tmp;
            }
        }
        return dp[N];
    }
};
```

Or in another form

```cpp
// OJ: https://leetcode.com/problems/edit-distance
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int minDistance(string A, string B) {
        int M = A.size(), N = B.size();
        if (M < N) swap(A, B), swap(M, N); 
        vector<int> dp(N + 1, INT_MAX);
        for (int i = 0; i <= M; ++i) {
            int prev;
            for (int j = 0; j <= N; ++j) {
                int cur = dp[j];
                if (i == 0 || j == 0) dp[j] = i + j;
                else if (A[i - 1] == B[j - 1]) dp[j] = prev;
                else dp[j] = 1 + min({ dp[j], dp[j - 1], prev });
                prev = cur;
            }
        }
        return dp[N];
    }
};
```