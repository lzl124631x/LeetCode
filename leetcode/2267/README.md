# [2267.  Check if There Is a Valid Parentheses String Path (Hard)](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path)

<p>A parentheses string is a <strong>non-empty</strong> string consisting only of <code>&#39;(&#39;</code> and <code>&#39;)&#39;</code>. It is <strong>valid</strong> if <strong>any</strong> of the following conditions is <strong>true</strong>:</p>

<ul>
	<li>It is <code>()</code>.</li>
	<li>It can be written as <code>AB</code> (<code>A</code> concatenated with <code>B</code>), where <code>A</code> and <code>B</code> are valid parentheses strings.</li>
	<li>It can be written as <code>(A)</code>, where <code>A</code> is a valid parentheses string.</li>
</ul>

<p>You are given an <code>m x n</code> matrix of parentheses <code>grid</code>. A <strong>valid parentheses string path</strong> in the grid is a path satisfying <strong>all</strong> of the following conditions:</p>

<ul>
	<li>The path starts from the upper left cell <code>(0, 0)</code>.</li>
	<li>The path ends at the bottom-right cell <code>(m - 1, n - 1)</code>.</li>
	<li>The path only ever moves <strong>down</strong> or <strong>right</strong>.</li>
	<li>The resulting parentheses string formed by the path is <strong>valid</strong>.</li>
</ul>

<p>Return <code>true</code> <em>if there exists a <strong>valid parentheses string path</strong> in the grid.</em> Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/15/example1drawio.png" style="width: 521px; height: 300px;" />
<pre>
<strong>Input:</strong> grid = [[&quot;(&quot;,&quot;(&quot;,&quot;(&quot;],[&quot;)&quot;,&quot;(&quot;,&quot;)&quot;],[&quot;(&quot;,&quot;(&quot;,&quot;)&quot;],[&quot;(&quot;,&quot;(&quot;,&quot;)&quot;]]
<strong>Output:</strong> true
<strong>Explanation:</strong> The above diagram shows two possible paths that form valid parentheses strings.
The first path shown results in the valid parentheses string &quot;()(())&quot;.
The second path shown results in the valid parentheses string &quot;((()))&quot;.
Note that there may be other valid parentheses string paths.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/15/example2drawio.png" style="width: 165px; height: 165px;" />
<pre>
<strong>Input:</strong> grid = [[&quot;)&quot;,&quot;)&quot;],[&quot;(&quot;,&quot;(&quot;]]
<strong>Output:</strong> false
<strong>Explanation:</strong> The two possible paths form the parentheses strings &quot;))(&quot; and &quot;)((&quot;. Since neither of them are valid parentheses strings, we return false.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>grid[i][j]</code> is either <code>&#39;(&#39;</code> or <code>&#39;)&#39;</code>.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Matrix](https://leetcode.com/tag/matrix)

**Similar Questions**:
* [Check if There is a Valid Path in a Grid (Medium)](https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid)
* [Check if a Parentheses String Can Be Valid (Medium)](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid)

**Hints**:
* What observations can you make about the number of open brackets and close brackets for any prefix of a valid bracket sequence?
* The number of open brackets must always be greater than or equal to the number of close brackets.
* Could you use dynamic programming?

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path
// Author: github.com/lzl124631x
// Time: O(MN * (M + N))
// Space: O(MN * (M + N))
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& A) {
        if (A[0][0] == ')') return false;
        int M = A.size(), N = A[0].size();
        vector<vector<bitset<100>>> dp(M, vector<bitset<100>>(N));
        dp[0][0].set(1);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == 0 && j == 0) continue;
                int d = A[i][j] == '(' ? 1 : -1;
                if (i - 1 >= 0) {
                    dp[i][j] |= A[i][j] == '(' ? (dp[i - 1][j] << 1) : (dp[i - 1][j] >> 1);
                }
                if (j - 1 >= 0) {
                    dp[i][j] |= A[i][j] == '(' ? (dp[i][j - 1] << 1) : (dp[i][j - 1] >> 1);
                }
            }
        }
        return dp[M - 1][N - 1].test(0);
    }
};
```

Since `dp[i][j]` only depends on `dp[i-1][j]` and `dp[i][j-1]`, we can reduce the space complexity to `O(N * (M+N))`

```cpp
// OJ: https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path
// Author: github.com/lzl124631x
// Time: O(MN * (M + N))
// Space: O(N * (M + N))
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& A) {
        if (A[0][0] == ')') return false;
        int M = A.size(), N = A[0].size();
        vector<bitset<100>> dp(N);
        for (int i = 0; i < M; ++i) {
            vector<bitset<100>> next(N);
            for (int j = 0; j < N; ++j) {
                if (i == 0 && j == 0) {
                    next[0].set(1);
                    continue;
                }
                int d = A[i][j] == '(' ? 1 : -1;
                if (i - 1 >= 0) {
                    next[j] |= A[i][j] == '(' ? (dp[j] << 1) : (dp[j] >> 1);
                }
                if (j - 1 >= 0) {
                    next[j] |= A[i][j] == '(' ? (next[j - 1] << 1) : (next[j - 1] >> 1);
                }
            }
            swap(dp, next);
        }
        return dp[N - 1].test(0);
    }
};
```