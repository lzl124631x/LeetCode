# [51. N-Queens (Hard)](https://leetcode.com/problems/n-queens/)

<p>The <strong>n-queens</strong> puzzle is the problem of placing <code>n</code> queens on an <code>n x n</code> chessboard such that no two queens attack each other.</p>

<p>Given an integer <code>n</code>, return <em>all distinct solutions to the <strong>n-queens puzzle</strong></em>.</p>

<p>Each solution contains a distinct board configuration of the n-queens' placement, where <code>'Q'</code> and <code>'.'</code> both indicate a queen and an empty space, respectively.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/queens.jpg" style="width: 600px; height: 268px;">
<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
<strong>Explanation:</strong> There exist two distinct solutions to the 4-queens puzzle as shown above
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> [["Q"]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 9</code></li>
</ul>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [N-Queens II (Hard)](https://leetcode.com/problems/n-queens-ii/)
* [Grid Illumination (Hard)](https://leetcode.com/problems/grid-illumination/)

## Solution 1. Backtracking

```cpp
// OJ: https://leetcode.com/problems/n-queens/
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N^2)
class Solution {
    vector<vector<string>> ans;
    vector<string> B;
    vector<bool> col, hill, dale;
    int n;
    void dfs(int i) {
        if (i == n) {
            ans.push_back(B);
            return;
        }
        for (int j = 0; j < n; ++j) {
            int h = i + j, d = i + n - 1 - j;
            if (col[j] || hill[h] || dale[d]) continue;
            col[j] = hill[h] = dale[d] = true;
            B[i][j] = 'Q';
            dfs(i + 1);
            B[i][j] = '.';
            col[j] = hill[h] = dale[d] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        B.assign(n, string(n, '.'));
        col.assign(n, false);
        hill.assign(2 * n - 1, false);
        dale.assign(2 * n - 1, false);
        dfs(0);
        return ans;
    }
};
```