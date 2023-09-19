# [2326. Spiral Matrix IV (Medium)](https://leetcode.com/problems/spiral-matrix-iv)

<p>You are given two integers <code>m</code> and <code>n</code>, which represent the dimensions of a matrix.</p>

<p>You are also given the <code>head</code> of a linked list of integers.</p>

<p>Generate an <code>m x n</code> matrix that contains the integers in the linked list presented in <strong>spiral</strong> order <strong>(clockwise)</strong>, starting from the <strong>top-left</strong> of the matrix. If there are remaining empty spaces, fill them with <code>-1</code>.</p>

<p>Return <em>the generated matrix</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/05/09/ex1new.jpg" style="width: 240px; height: 150px;" />
<pre>
<strong>Input:</strong> m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
<strong>Output:</strong> [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
<strong>Explanation:</strong> The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/05/11/ex2.jpg" style="width: 221px; height: 60px;" />
<pre>
<strong>Input:</strong> m = 1, n = 4, head = [0,1,2]
<strong>Output:</strong> [[0,1,2,-1]]
<strong>Explanation:</strong> The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li>The number of nodes in the list is in the range <code>[1, m * n]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Linked List](https://leetcode.com/tag/linked-list), [Matrix](https://leetcode.com/tag/matrix), [Simulation](https://leetcode.com/tag/simulation)

**Similar Questions**:
* [Spiral Matrix (Medium)](https://leetcode.com/problems/spiral-matrix)
* [Spiral Matrix II (Medium)](https://leetcode.com/problems/spiral-matrix-ii)
* [Spiral Matrix III (Medium)](https://leetcode.com/problems/spiral-matrix-iii)

**Hints**:
* First, generate an m x n matrix filled with -1s.
* Navigate within the matrix at (i, j) with the help of a direction vector ⟨di, dj⟩. At (i, j), you need to decide if you can keep going in the current direction.
* If you cannot keep going, rotate the direction vector clockwise by 90 degrees.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/spiral-matrix-iv
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int x = 0, y = 0, dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}, dir = 0;
        while (head) {
            ans[x][y] = head->val;
            head = head->next;
            int a = x + dirs[dir][0], b = y + dirs[dir][1];
            if (a < 0 || a >= m || b < 0 || b >= n || ans[a][b] != -1) dir = (dir + 1) % 4;
            x += dirs[dir][0], y += dirs[dir][1];
        }
        return ans;
    }
};
```