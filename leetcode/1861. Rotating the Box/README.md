# [1861. Rotating the Box (Medium)](https://leetcode.com/problems/rotating-the-box/)

<p>You are given an <code>m x n</code> matrix of characters <code>box</code> representing a side-view of a box. Each cell of the box is one of the following:</p>

<ul>
	<li>A stone <code>'#'</code></li>
	<li>A stationary obstacle <code>'*'</code></li>
	<li>Empty <code>'.'</code></li>
</ul>

<p>The box is rotated <strong>90 degrees clockwise</strong>, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity <strong>does not</strong> affect the obstacles' positions, and the inertia from the box's rotation <strong>does not </strong>affect the stones' horizontal positions.</p>

<p>It is <strong>guaranteed</strong> that each stone in <code>box</code> rests on an obstacle, another stone, or the bottom of the box.</p>

<p>Return <em>an </em><code>n x m</code><em> matrix representing the box after the rotation described above</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcodewithstones.png" style="width: 300px; height: 150px;"></p>

<pre><strong>Input:</strong> box = [["#",".","#"]]
<strong>Output:</strong> [["."],
&nbsp;        ["#"],
&nbsp;        ["#"]]
</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode2withstones.png" style="width: 375px; height: 195px;"></p>

<pre><strong>Input:</strong> box = [["#",".","*","."],
&nbsp;             ["#","#","*","."]]
<strong>Output:</strong> [["#","."],
&nbsp;        ["#","#"],
&nbsp;        ["*","*"],
&nbsp;        [".","."]]
</pre>

<p><strong>Example 3:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode3withstone.png" style="width: 400px; height: 218px;"></p>

<pre><strong>Input:</strong> box = [["#","#","*",".","*","."],
&nbsp;             ["#","#","#","*",".","."],
&nbsp;             ["#","#","#",".","#","."]]
<strong>Output:</strong> [[".","#","#"],
&nbsp;        [".","#","#"],
&nbsp;        ["#","#","*"],
&nbsp;        ["#","*","."],
&nbsp;        ["#",".","*"],
&nbsp;        ["#",".","."]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == box.length</code></li>
	<li><code>n == box[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>box[i][j]</code> is either <code>'#'</code>, <code>'*'</code>, or <code>'.'</code>.</li>
</ul>

**Companies**:  
[Square](https://leetcode.com/company/square)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution 1.

**Intuition**: Treat each column separately. Use a write pointer `w = N - 1`. When reading a stone, write the stone to `w`-th row and `--w`. When reading a obstacle at row `row`, set `w = row - 1`.

```cpp
// OJ: https://leetcode.com/problems/rotating-the-box/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& A) {
        int M = A.size(), N = A[0].size();
        vector<vector<char>> ans(N, vector<char>(M, '.'));
        for (int i = 0; i < M; ++i) {
            int w = N - 1; // `w` is the write pointer
            for (int j = N - 1; j >= 0; --j) {
                if (A[i][j] == '.') continue;
                if (A[i][j] == '#') {
                    ans[w--][M - i - 1] = '#'; // write stone to position `(w, M - i - 1)` and move write pointer
                } else {
                    ans[j][M - i - 1] = '*';
                    w = j - 1; // move the writer pointer to the position after the obstacle
                }
            }
        }
        return ans;
    }
};
```