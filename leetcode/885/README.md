# [885. Spiral Matrix III (Medium)](https://leetcode.com/problems/spiral-matrix-iii/)

<p>On a 2 dimensional grid with <code>R</code> rows and <code>C</code> columns, we start at <code>(r0, c0)</code> facing east.</p>

<p>Here, the north-west corner of the grid is at the&nbsp;first row and column, and the south-east corner of the grid is at the last row and column.</p>

<p>Now, we walk in a clockwise spiral shape to visit every position in this grid.&nbsp;</p>

<p>Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.)&nbsp;</p>

<p>Eventually, we reach all <code>R * C</code> spaces of the grid.</p>

<p>Return a list of coordinates representing the positions of the grid in the order they were visited.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>R = <span id="example-input-1-1">1</span>, C = <span id="example-input-1-2">4</span>, r0 = <span id="example-input-1-3">0</span>, c0 = <span id="example-input-1-4">0</span>
<strong>Output: </strong><span id="example-output-1">[[0,0],[0,1],[0,2],[0,3]]</span>

<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/24/example_1.png" style="width: 174px; height: 99px;">
</pre>

<p>&nbsp;</p>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>R = <span id="example-input-2-1">5</span>, C = <span id="example-input-2-2">6</span>, r0 = <span id="example-input-2-3">1</span>, c0 = <span id="example-input-2-4">4</span>
<strong>Output: </strong><span id="example-output-2">[[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]</span>

<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/24/example_2.png" style="width: 202px; height: 142px;">
</pre>

<div>
<div>
<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= R &lt;= 100</code></li>
	<li><code>1 &lt;= C &lt;= 100</code></li>
	<li><code>0 &lt;= r0 &lt; R</code></li>
	<li><code>0 &lt;= c0 &lt; C</code></li>
</ol>
</div>
</div>


**Companies**:  
[Dataminr](https://leetcode.com/company/dataminr)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/spiral-matrix-iii/
// Author: github.com/lzl124631x
// Time: O(max(R, C)^2)
// Space: O(1)
class Solution {
private:
    vector<vector<int>> ans;
    int r, c;
    void add(int x, int y) {
        if (x < 0 || x >= r || y < 0 || y >= c) return;
        ans.push_back({ x, y });
    }
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        r = R;
        c = C;
        int x = r0, y = c0, cnt = R * C, d = 2;
        ans.push_back({ x, y });
        while (ans.size() < cnt) {
            add(x, ++y);
            for (int i = 1; i < d; ++i) add(++x, y);
            for (int i = 0; i < d; ++i) add(x, --y);
            for (int i = 0; i < d; ++i) add(--x, y);
            for (int i = 0; i < d; ++i) add(x, ++y);
            d += 2;
        }
        return ans;
    }
};
```