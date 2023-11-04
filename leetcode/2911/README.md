# [2911. Minimum Changes to Make K Semi-palindromes (Hard)](https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes)

<p>Given a string <code>s</code> and an integer <code>k</code>, partition <code>s</code> into <code>k</code> <strong>substrings</strong> such that the sum of the number of letter changes required to turn each <strong>substring</strong> into a <strong>semi-palindrome</strong> is minimized.</p>

<p>Return <em>an integer denoting the <strong>minimum</strong> number of letter changes required.</em></p>

<p><strong>Notes</strong></p>

<ul>
	<li>A string is a <strong>palindrome</strong> if it can be read the same way from left to right and right to left.</li>
	<li>A string with a length of <code>len</code> is considered a <strong>semi-palindrome</strong> if there exists a positive integer <code>d</code> such that <code>1 &lt;= d &lt; len</code> and <code>len % d == 0</code>, and if we take indices that have the same modulo by <code>d</code>, they form a <strong>palindrome</strong>. For example, <code>&quot;aa&quot;</code>, <code>&quot;aba&quot;</code>, <code>&quot;adbgad&quot;</code>, and, <code>&quot;abab&quot;</code> are <strong>semi-palindrome</strong> and <code>&quot;a&quot;</code>, <code>&quot;ab&quot;</code>, and, <code>&quot;abca&quot;</code> are not.</li>
	<li>A <strong>substring</strong> is a contiguous sequence of characters within a string.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abcac&quot;, k = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can divide s into substrings &quot;ab&quot; and &quot;cac&quot;. The string &quot;cac&quot; is already a semi-palindrome. If we change &quot;ab&quot; to &quot;aa&quot;, it becomes a semi-palindrome with d = 1.
It can be shown that there is no way to divide the string &quot;abcac&quot; into two semi-palindrome substrings. Therefore, the answer would be at least 1.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abcdef&quot;, k = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can divide it into substrings &quot;abc&quot; and &quot;def&quot;. Each of the substrings &quot;abc&quot; and &quot;def&quot; requires one change to become a semi-palindrome, so we need 2 changes in total to make all substrings semi-palindrome.
It can be shown that we cannot divide the given string into two substrings in a way that it would require less than 2 changes.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aabbaa&quot;, k = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> We can divide it into substrings &quot;aa&quot;, &quot;bb&quot; and &quot;aa&quot;.
The strings &quot;aa&quot; and &quot;bb&quot; are already semi-palindromes. Thus, the answer is zero.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 200</code></li>
	<li><code>1 &lt;= k &lt;= s.length / 2</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>


**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers), [String](https://leetcode.com/tag/string), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Similar Questions**:
* [Palindrome Partitioning III (Hard)](https://leetcode.com/problems/palindrome-partitioning-iii)

**Hints**:
* Define <code>dp[i][j]</code> as the minimum count of letter changes needed to split the suffix of string <code>s</code> starting from <code>s[i]</code> into <code>j</code> valid parts.
* We have <code>dp[i][j] = min(dp[x + 1][j - 1] + v[i][x])</code>. Here <code>v[i][x]</code> is the minimum number of letter changes to change substring <code>s[i..x]</code> into semi-palindrome.
* <code>v[i][j]</code> can be calculated separately by <b>brute-force</b>. We can create a table of <code>v[i][j]</code> independently to improve the complexity. Also note that semi-palindrome’s length is at least <code>2</code>.

## Solution 1.

Let `dp[k][i+1]` be the min changes needed to change `A[0..i]` to `k` substrings that are semi-palindromes (`1 <= k <= i+1`). The answer is `dp[K][N]`.

```
dp[0][0] = 0
dp[k][i+1] = min(dp[k-1][j] + c[j][i] | k-1 <= j <= i)
```

Where `c[i][j]` is the min changes needed to make `A[i..j]` semi-palindrome.

We precompute all `c[i][j]` values. Each `c[i][j]` computation takes `O(N^2)` time. So computing all `c[i][j]` values takes `O(N^4)`.

The DP computation part takes `O(N^2 * K)` time.

```cpp
// OJ: https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes
// Author: github.com/lzl124631x
// Time: O(N^4 + N^2 * K)
// Space: O(N^2 + NK)
class Solution {
public:
    int minimumChanges(string s, int K) {
        int N = s.size();
        vector<vector<int>> c(N, vector<int>(N, INT_MAX)), dp(K + 1, vector<int>(N + 1, INT_MAX));
        auto minChanges = [&](int from, int to) {
            int ans = INT_MAX, len = to - from + 1;
            for (int d = 1; d < len; ++d) {
                if (len % d) continue;
                int cnt = 0;
                for (int offset = 0; offset < d; ++offset) {
                    string tmp;
                    for (int i = from + offset; i <= to; i += d) tmp += s[i];
                    int i = 0, j = tmp.size() - 1;
                    while (i < j) {
                        cnt += tmp[i++] != tmp[j--];
                    }
                }
                ans = min(ans, cnt);
            }
            return ans;
        };
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                c[i][j] = minChanges(i, j);
            }
        }
        dp[0][0] = 0;
        for (int k = 1; k <= K; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = k - 1; j < i; ++j) {
                    if (dp[k - 1][j] != INT_MAX) dp[k][i + 1] = min(dp[k][i + 1], dp[k - 1][j] + c[j][i]);
                }
            }
        }
        return dp[K][N];
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes
// Author: github.com/lzl124631x
// Time: O(N^4 + N^2 * K)
// Space: O(N^2 + NK)
class Solution {
public:
    int minimumChanges(string s, int K) {
        int N = s.size();
        vector<vector<int>> memo(N, vector<int>(K + 1, -1)), ops(N, vector<int>(N, -1));
        auto minStringChanges = [&](int start, int end) {
            if (ops[start][end] != -1) return ops[start][end];
            int len = end - start + 1, ans = len;
            for (int d = len - 1; d >= 1; d--) {
                if (len % d != 0) continue;
                int cnt = 0;
                for (int i = 0; i < d; i++) {
                    int left = start + i, right = (start + i) + (end - start - i) / d * d;
                    while (left < right) {
                        if (s[left] != s[right]) cnt++;
                        left += d;
                        right -= d;
                    }
                }
                ans = min(ans, cnt);
            }
            return ops[start][end] = ans;
        };
        function<int(int, int)> minChanges = [&](int idx, int residual) {
            if (memo[idx][residual] != -1) return memo[idx][residual];
            if (residual == 1) return minStringChanges(idx, N - 1);
            int ans = INT_MAX;
            for (int i = idx + 1; i + (residual - 1) * 2 < N; i++) {
                ans = min(ans, minStringChanges(idx, i) + minChanges(i + 1, residual - 1));
            }
            return memo[idx][residual] = ans;
        };
        return minChanges(0, K);
    }
};
```