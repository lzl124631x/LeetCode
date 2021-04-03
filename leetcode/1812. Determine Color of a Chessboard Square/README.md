# [1812. Determine Color of a Chessboard Square (Easy)](https://leetcode.com/problems/determine-color-of-a-chessboard-square/)

<p>You are given <code>coordinates</code>, a string that represents the coordinates of a square of the chessboard. Below is a chessboard for your reference.</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/screenshot-2021-02-20-at-22159-pm.png" style="width: 400px; height: 396px;"></p>

<p>Return <code>true</code><em> if the square is white, and </em><code>false</code><em> if the square is black</em>.</p>

<p>The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first, and the number second.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> coordinates = "a1"
<strong>Output:</strong> false
<strong>Explanation:</strong> From the chessboard above, the square with coordinates "a1" is black, so return false.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> coordinates = "h3"
<strong>Output:</strong> true
<strong>Explanation:</strong> From the chessboard above, the square with coordinates "h3" is white, so return true.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> coordinates = "c7"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>coordinates.length == 2</code></li>
	<li><code>'a' &lt;= coordinates[0] &lt;= 'h'</code></li>
	<li><code>'1' &lt;= coordinates[1] &lt;= '8'</code></li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/determine-color-of-a-chessboard-square/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool squareIsWhite(string s) {
        return (s[0] - 'a') % 2 == (s[1] - '0') % 2;
    }
};
```