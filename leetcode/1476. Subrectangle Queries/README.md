# [1476. Subrectangle Queries (Medium)](https://leetcode.com/problems/subrectangle-queries/)

<p>Implement the class <code>SubrectangleQueries</code>&nbsp;which receives a <code>rows x cols</code> rectangle as a matrix of integers in the constructor and supports two methods:</p>

<p>1.<code>&nbsp;updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)</code></p>

<ul>
	<li>Updates all values with <code>newValue</code> in the subrectangle whose upper left coordinate is <code>(row1,col1)</code> and bottom right coordinate is <code>(row2,col2)</code>.</li>
</ul>

<p>2.<code>&nbsp;getValue(int row, int col)</code></p>

<ul>
	<li>Returns the current value of the coordinate <code>(row,col)</code> from&nbsp;the rectangle.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["SubrectangleQueries","getValue","updateSubrectangle","getValue","getValue","updateSubrectangle","getValue","getValue"]
[[[[1,2,1],[4,3,4],[3,2,1],[1,1,1]]],[0,2],[0,0,3,2,5],[0,2],[3,1],[3,0,3,2,10],[3,1],[0,2]]
<strong>Output</strong>
[null,1,null,5,5,null,10,5]
<strong>Explanation</strong>
SubrectangleQueries subrectangleQueries = new SubrectangleQueries([[1,2,1],[4,3,4],[3,2,1],[1,1,1]]);  
// The initial rectangle (4x3) looks like:
// 1 2 1
// 4 3 4
// 3 2 1
// 1 1 1
subrectangleQueries.getValue(0, 2); // return 1
subrectangleQueries.updateSubrectangle(0, 0, 3, 2, 5);
// After this update the rectangle looks like:
// 5 5 5
// 5 5 5
// 5 5 5
// 5 5 5 
subrectangleQueries.getValue(0, 2); // return 5
subrectangleQueries.getValue(3, 1); // return 5
subrectangleQueries.updateSubrectangle(3, 0, 3, 2, 10);
// After this update the rectangle looks like:
// 5   5   5
// 5   5   5
// 5   5   5
// 10  10  10 
subrectangleQueries.getValue(3, 1); // return 10
subrectangleQueries.getValue(0, 2); // return 5
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input</strong>
["SubrectangleQueries","getValue","updateSubrectangle","getValue","getValue","updateSubrectangle","getValue"]
[[[[1,1,1],[2,2,2],[3,3,3]]],[0,0],[0,0,2,2,100],[0,0],[2,2],[1,1,2,2,20],[2,2]]
<strong>Output</strong>
[null,1,null,100,100,null,20]
<strong>Explanation</strong>
SubrectangleQueries subrectangleQueries = new SubrectangleQueries([[1,1,1],[2,2,2],[3,3,3]]);
subrectangleQueries.getValue(0, 0); // return 1
subrectangleQueries.updateSubrectangle(0, 0, 2, 2, 100);
subrectangleQueries.getValue(0, 0); // return 100
subrectangleQueries.getValue(2, 2); // return 100
subrectangleQueries.updateSubrectangle(1, 1, 2, 2, 20);
subrectangleQueries.getValue(2, 2); // return 20
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>There will be at most <code><font face="monospace">500</font></code>&nbsp;operations considering both methods:&nbsp;<code>updateSubrectangle</code> and <code>getValue</code>.</li>
	<li><code>1 &lt;= rows, cols &lt;= 100</code></li>
	<li><code>rows ==&nbsp;rectangle.length</code></li>
	<li><code>cols == rectangle[i].length</code></li>
	<li><code>0 &lt;= row1 &lt;= row2 &lt; rows</code></li>
	<li><code>0 &lt;= col1 &lt;= col2 &lt; cols</code></li>
	<li><code>1 &lt;= newValue, rectangle[i][j] &lt;= 10^9</code></li>
	<li><code>0 &lt;= row &lt; rows</code></li>
	<li><code>0 &lt;= col &lt; cols</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. Brute force

```cpp
// OJ: https://leetcode.com/problems/subrectangle-queries/
// Author: github.com/lzl124631x
// Time:
//      O(MN) for SubrectangleQueries and updateSubrectangle
//      O(1) for getValue
// Space: O(MN)
class SubrectangleQueries {
    vector<vector<int>> A;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : A(rectangle) {}
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                A[i][j] = newValue;
            }
        }
    }
    int getValue(int row, int col) {
        return A[row][col];
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/subrectangle-queries/
// Author: github.com/lzl124631x
// Time:
//      O(MN) for SubrectangleQueries
//      O(1) for updateSubrectangle
//      O(Update) for getValue
// Space: O(MN)
class SubrectangleQueries {
    vector<vector<int>> A, sub;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : A(rectangle) {}
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        sub.push_back({ row1, col1, row2, col2, newValue });
    }
    
    int getValue(int row, int col) {
        for (int i = sub.size() - 1; i >= 0; --i) {
            if (row >= sub[i][0] && row <= sub[i][2] && col >= sub[i][1] && col <= sub[i][3]) return sub[i][4];
        }
        return A[row][col];
    }
};
```