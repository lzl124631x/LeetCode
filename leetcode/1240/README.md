# [1240. Tiling a Rectangle with the Fewest Squares (Hard)](https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/)

<p>Given a rectangle of size <code>n</code> x <code>m</code>, return <em>the minimum number of integer-sided squares that tile the rectangle</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/10/17/sample_11_1592.png" style="width: 154px; height: 106px;"></p>

<pre><strong>Input:</strong> n = 2, m = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> <code>3</code> squares are necessary to cover the rectangle.
<code>2</code> (squares of <code>1x1</code>)
<code>1</code> (square of <code>2x2</code>)</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/10/17/sample_22_1592.png" style="width: 224px; height: 126px;"></p>

<pre><strong>Input:</strong> n = 5, m = 8
<strong>Output:</strong> 5
</pre>

<p><strong>Example 3:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/10/17/sample_33_1592.png" style="width: 224px; height: 189px;"></p>

<pre><strong>Input:</strong> n = 11, m = 13
<strong>Output:</strong> 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 13</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
public:
    int tilingRectangle(int n, int m) {
        int ans = INT_MAX;
        vector<vector<bool>> A(n, vector<bool>(m));
        function<void(int)> dfs = [&](int cnt) {
            if (cnt >= ans) return;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (!A[i][j]) {
                        int len = 1;
                        for (; i + len <= n && j + len <= m && cnt + 1 < ans; ++len) {
                            int x = 0, y = 0;
                            for (; y < len && !A[i + len - 1][j + y]; ++y);
                            if (y < len) break;
                            for (; x < len && !A[i + x][j + len - 1]; ++x);
                            if (x < len) break;
                            for (int y = 0; y < len; ++y) A[i + len - 1][j + y] = true;
                            for (int x = 0; x < len; ++x) A[i + x][j + len - 1] = true;
                            dfs(cnt + 1);
                        }
                        for (int x = 0; x < len - 1; ++x) {
                            for (int y = 0; y < len - 1; ++y) {
                                A[i + x][j + y] = false;
                            }
                        }
                        return;
                    }
                }
            }
            ans = min(ans, cnt);
        };
        dfs(0);
        return ans;
    }
};
```