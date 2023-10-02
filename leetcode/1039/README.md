# [1039. Minimum Score Triangulation of Polygon (Medium)](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/)

<p>Given <code>N</code>, consider a convex <code>N</code>-sided polygon with vertices labelled <code>A[0], A[i], ..., A[N-1]</code>&nbsp;in clockwise order.</p>

<p>Suppose you triangulate the polygon into <code>N-2</code> triangles.&nbsp; For each triangle, the value of that triangle is the <strong>product</strong>&nbsp;of the labels of the vertices, and the <em>total score</em> of the triangulation is the sum of these values over all <code>N-2</code> triangles in the triangulation.</p>

<p>Return the smallest possible total score that you can achieve with some triangulation of the polygon.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,2,3]</span>
<strong>Output: </strong><span id="example-output-1">6</span>
<strong>Explanation: </strong>The polygon is already triangulated, and the score of the only triangle is 6.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/05/01/minimum-score-triangulation-of-polygon-1.png" style="width: 253px; height: 150px;"></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[3,7,4,5]</span>
<strong>Output: </strong><span id="example-output-2">144</span>
<strong>Explanation: </strong>There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.  The minimum score is 144.
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[1,3,1,4,1,5]</span>
<strong>Output: </strong><span id="example-output-3">13</span>
<strong>Explanation: </strong>The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>3 &lt;= A.length &lt;= 50</code></li>
	<li><code>1 &lt;= A[i] &lt;= 100</code></li>
</ol>
</div>
</div>
</div>

**Companies**:  
[Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP Top-down

```cpp
// OJ: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
// Ref: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/discuss/286753/C%2B%2B-with-picture
class Solution {
private:
    int dp[50][50] = {0};
    int minScoreTriangulation(vector<int>& A, int i, int j) {
        if (j - i < 2) return 0;
        if (dp[i][j]) return dp[i][j];
        int ans = INT_MAX;
        for (int k = i + 1; k < j; ++k) {
            ans = min(ans, minScoreTriangulation(A, i, k) + A[i] * A[j] * A[k] + minScoreTriangulation(A, k, j));
        }
        return dp[i][j] = ans;
    }
public:
    int minScoreTriangulation(vector<int>& A) {
        return minScoreTriangulation(A, 0, A.size() - 1);
    }
};
```

## Solution 2. DP Bottom-up

```cpp
// OJ: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int N = A.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int len = 3; len <= N; ++len) {
            for (int i = 0; i <= N - len; ++i) {
                int val = INT_MAX;
                for (int k = i + 1; k < i + len - 1; ++k) {
                    val = min(val, dp[i][k] + dp[k][i + len - 1] + A[i] * A[i + len - 1] * A[k]);
                }
                dp[i][i + len - 1] = val;
            }
        }
        return dp[0][N - 1];
    }
};
```