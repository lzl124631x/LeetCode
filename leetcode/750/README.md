# [750. Number Of Corner Rectangles (Medium)](https://leetcode.com/problems/number-of-corner-rectangles/)

<p>Given a grid where each entry is only 0 or 1, find the number of corner rectangles.</p>

<p>A <em>corner rectangle</em> is 4 distinct 1s on the grid that form an axis-aligned rectangle. Note that only the corners need to have the value 1. Also, all four 1s used must be distinct.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> grid = 
[[1, 0, 0, 1, 0],
 [0, 0, 1, 0, 1],
 [0, 0, 0, 1, 0],
 [1, 0, 1, 0, 1]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is only one corner rectangle, with corners grid[1][2], grid[1][4], grid[3][2], grid[3][4].
</pre>

<p>&nbsp;</p>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = 
[[1, 1, 1],
 [1, 1, 1],
 [1, 1, 1]]
<strong>Output:</strong> 9
<strong>Explanation:</strong> There are four 2x2 rectangles, four 2x3 and 3x2 rectangles, and one 3x3 rectangle.
</pre>

<p>&nbsp;</p>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = 
[[1, 1, 1, 1]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Rectangles must have four distinct corners.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li>The number of rows and columns of <code>grid</code> will each be in the range <code>[1, 200]</code>.</li>
	<li>Each <code>grid[i][j]</code> will be either <code>0</code> or <code>1</code>.</li>
	<li>The number of <code>1</code>s in the grid will be at most <code>6000</code>.</li>
</ol>

<p>&nbsp;</p>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-corner-rectangles/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(C^2) where C is the count of 1s.
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size(), ans = 0;
        map<int, set<int>> m;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!grid[i][j]) continue;
                m[i].insert(j);
            }
        }
        for (auto i = m.begin(); i != m.end(); ++i) {
            for (auto j = next(i); j != m.end(); ++j) {
                int cnt = 0;
                for (int y : i->second) {
                    if (j->second.find(y) == j->second.end()) continue;
                    ++cnt;
                }
                ans += cnt * (cnt - 1) / 2;
            }
        }
        return ans;
    }
};
```