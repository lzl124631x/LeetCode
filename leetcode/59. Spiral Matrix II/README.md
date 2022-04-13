# [59. Spiral Matrix II (Medium)](https://leetcode.com/problems/spiral-matrix-ii/)

<p>Given a positive integer <code>n</code>, generate an <code>n x n</code> <code>matrix</code> filled with elements from <code>1</code> to <code>n<sup>2</sup></code> in spiral order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> [[1,2,3],[8,9,4],[7,6,5]]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> [[1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
</ul>


**Companies**:  
[tiktok](https://leetcode.com/company/tiktok), [Apple](https://leetcode.com/company/apple), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Matrix](https://leetcode.com/tag/matrix/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Spiral Matrix (Medium)](https://leetcode.com/problems/spiral-matrix/)
* [Spiral Matrix III (Medium)](https://leetcode.com/problems/spiral-matrix-iii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/spiral-matrix-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1) extra space
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0, d = 1; i < n / 2; ++i) {
            int len = n - 2 * i - 1;
            for (int j = 0; j < len; ++j) ans[i][i + j] = d++;
            for (int j = 0; j < len; ++j) ans[i + j][n - i - 1] = d++;
            for (int j = 0; j < len; ++j) ans[n - i - 1][n - i - j - 1] = d++;
            for (int j = 0; j < len; ++j) ans[n - i - j - 1][i] = d++;
        }
        if (n % 2) ans[n / 2][n / 2] = n * n;
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/spiral-matrix-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1) extra space
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int i = 0, j = 0, d = 0, dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        for (int val = 1; val <= n * n; ++val) {
            ans[i][j] = val;
            int x = i + dirs[d][0], y = j + dirs[d][1];
            if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y]) d = (d + 1) % 4;
            i += dirs[d][0];
            j += dirs[d][1];
        }
        return ans;
    }
};
```