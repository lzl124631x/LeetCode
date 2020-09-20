# [1591. Strange Printer II (Hard)](https://leetcode.com/problems/strange-printer-ii/)

<p>There is a strange printer with the following two special requirements:</p>

<ul>
	<li>On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.</li>
	<li>Once the printer has used a color for the above operation, <strong>the same color cannot be used again</strong>.</li>
</ul>

<p>You are given a <code>m x n</code> matrix <code>targetGrid</code>, where <code>targetGrid[row][col]</code> is the color in the position <code>(row, col)</code> of the grid.</p>

<p>Return <code>true</code><em> if it is possible to print the matrix </em><code>targetGrid</code><em>,</em><em> otherwise, return </em><code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/08/15/sample_1_1929.png" style="width: 483px; height: 138px;"></p>

<pre><strong>Input:</strong> targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/08/15/sample_2_1929.png" style="width: 483px; height: 290px;"></p>

<pre><strong>Input:</strong> targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
<strong>Output:</strong> true
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible to form targetGrid because it is not allowed to print the same color in different turns.</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> targetGrid = [[1,1,1],[3,1,3]]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == targetGrid.length</code></li>
	<li><code>n == targetGrid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 60</code></li>
	<li><code>1 &lt;= targetGrid[row][col] &lt;= 60</code></li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Strange Printer (Hard)](https://leetcode.com/problems/strange-printer/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/strange-printer-ii/
// Author: github.com/lzl124631x
// Time: O((MN)^3)
// Space: O(MN)
class Solution {
    unordered_map<int, int> mnx, mxx, mny, mxy;
    bool valid(vector<vector<int>>& A, int c) {
        for (int i = mnx[c]; i <= mxx[c]; ++i) {
            for (int j = mny[c]; j <= mxy[c]; ++j) {
                if (A[i][j] != c && A[i][j] != 0) return false;
            }
        }
        for (int i = mnx[c]; i <= mxx[c]; ++i) {
            for (int j = mny[c]; j <= mxy[c]; ++j) {
                A[i][j] = 0;
            }
        }
        return true;
    }
public:
    bool isPrintable(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        unordered_set<int> color;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int n = A[i][j];
                if (color.count(n)) {
                    mnx[n] = min(mnx[n], i);
                    mxx[n] = max(mxx[n], i);
                    mny[n] = min(mny[n], j);
                    mxy[n] = max(mxy[n], j);
                } else {
                    mnx[n] = mxx[n] = i;
                    mny[n] = mxy[n] = j;
                    color.insert(n);
                }
            }
        }
        unordered_set<int> rm;
        while (true) {
            rm.clear();
            for (int c : color) {
                if (valid(A, c)) rm.insert(c);
            }
            if (rm.size() == 0) return false;
            for (int n : rm) color.erase(n);
            int done = true;
            for (int i = 0; i < M && done; ++i) {
                for (int j = 0; j < N && done; ++j) done = A[i][j] == 0; 
            }
            if (done) break;
        }
        return true;
    }
};
```