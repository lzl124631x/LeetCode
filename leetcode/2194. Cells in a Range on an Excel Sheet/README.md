# [2194. Cells in a Range on an Excel Sheet (Easy)](https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/)

<p>A cell <code>(r, c)</code> of an excel sheet is represented as a string <code>"&lt;col&gt;&lt;row&gt;"</code> where:</p>

<ul>
	<li><code>&lt;col&gt;</code> denotes the column number <code>c</code> of the cell. It is represented by <strong>alphabetical letters</strong>.

	<ul>
		<li>For example, the <code>1<sup>st</sup></code> column is denoted by <code>'A'</code>, the <code>2<sup>nd</sup></code> by <code>'B'</code>, the <code>3<sup>rd</sup></code> by <code>'C'</code>, and so on.</li>
	</ul>
	</li>
	<li><code>&lt;row&gt;</code> is the row number <code>r</code> of the cell. The <code>r<sup>th</sup></code> row is represented by the <strong>integer</strong> <code>r</code>.</li>
</ul>

<p>You are given a string <code>s</code>&nbsp;in&nbsp;the format <code>"&lt;col1&gt;&lt;row1&gt;:&lt;col2&gt;&lt;row2&gt;"</code>, where <code>&lt;col1&gt;</code> represents the column <code>c1</code>, <code>&lt;row1&gt;</code> represents the row <code>r1</code>, <code>&lt;col2&gt;</code> represents the column <code>c2</code>, and <code>&lt;row2&gt;</code> represents the row <code>r2</code>, such that <code>r1 &lt;= r2</code> and <code>c1 &lt;= c2</code>.</p>

<p>Return <em>the <strong>list of cells</strong></em> <code>(x, y)</code> <em>such that</em> <code>r1 &lt;= x &lt;= r2</code> <em>and</em> <code>c1 &lt;= y &lt;= c2</code>. The cells should be represented as&nbsp;<strong>strings</strong> in the format mentioned above and be sorted in <strong>non-decreasing</strong> order first by columns and then by rows.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/02/08/ex1drawio.png" style="width: 250px; height: 160px;">
<pre><strong>Input:</strong> s = "K1:L2"
<strong>Output:</strong> ["K1","K2","L1","L2"]
<strong>Explanation:</strong>
The above diagram shows the cells which should be present in the list.
The red arrows denote the order in which the cells should be presented.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/02/09/exam2drawio.png" style="width: 500px; height: 50px;">
<pre><strong>Input:</strong> s = "A1:F1"
<strong>Output:</strong> ["A1","B1","C1","D1","E1","F1"]
<strong>Explanation:</strong>
The above diagram shows the cells which should be present in the list.
The red arrow denotes the order in which the cells should be presented.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>s.length == 5</code></li>
	<li><code>'A' &lt;= s[0] &lt;= s[3] &lt;= 'Z'</code></li>
	<li><code>'1' &lt;= s[1] &lt;= s[4] &lt;= '9'</code></li>
	<li><code>s</code> consists of uppercase English letters, digits and <code>':'</code>.</li>
</ul>


**Similar Questions**:
* [Excel Sheet Column Title (Easy)](https://leetcode.com/problems/excel-sheet-column-title/)
* [Excel Sheet Column Number (Easy)](https://leetcode.com/problems/excel-sheet-column-number/)
* [Matrix Cells in Distance Order (Easy)](https://leetcode.com/problems/matrix-cells-in-distance-order/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/
// Author: github.com/lzl124631x
// Time: O(1) since there are at most 26 * 9 cells.
// Space: O(1) extra space
class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        char a = s[0], b = s[3], x = s[1], y = s[4];
        for (; a <= b; ++a) {
            for (char i = x; i <= y; ++i) {
                ans.push_back(string(1, a) + string(1, i));
            }
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/discuss/1823631