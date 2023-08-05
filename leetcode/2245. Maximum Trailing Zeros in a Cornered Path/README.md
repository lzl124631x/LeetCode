# [2245. Maximum Trailing Zeros in a Cornered Path (Medium)](https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path)

<p>You are given a 2D integer array <code>grid</code> of size <code>m x n</code>, where each cell contains a positive integer.</p>
<p>A <strong>cornered path</strong> is defined as a set of adjacent cells with <strong>at most</strong> one turn. More specifically, the path should exclusively move either <strong>horizontally</strong> or <strong>vertically</strong> up to the turn (if there is one), without returning to a previously visited cell. After the turn, the path will then move exclusively in the <strong>alternate</strong> direction: move vertically if it moved horizontally, and vice versa, also without returning to a previously visited cell.</p>
<p>The <strong>product</strong> of a path is defined as the product of all the values in the path.</p>
<p>Return <em>the <strong>maximum</strong> number of <strong>trailing zeros</strong> in the product of a cornered path found in </em><code>grid</code>.</p>
<p>Note:</p>
<ul>
	<li><strong>Horizontal</strong> movement means moving in either the left or right direction.</li>
	<li><strong>Vertical</strong> movement means moving in either the up or down direction.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/23/ex1new2.jpg" style="width: 577px; height: 190px;">
<pre><strong>Input:</strong> grid = [[23,17,15,3,20],[8,1,20,27,11],[9,4,6,2,21],[40,9,1,10,6],[22,7,4,5,3]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The grid on the left shows a valid cornered path.
It has a product of 15 * 20 * 6 * 1 * 10 = 18000 which has 3 trailing zeros.
It can be shown that this is the maximum trailing zeros in the product of a cornered path.

The grid in the middle is not a cornered path as it has more than one turn.
The grid on the right is not a cornered path as it requires a return to a previously visited cell.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/25/ex2.jpg" style="width: 150px; height: 157px;">
<pre><strong>Input:</strong> grid = [[4,3,2],[7,6,1],[8,8,8]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The grid is shown in the figure above.
There are no cornered paths in the grid that result in a product with a trailing zero.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 1000</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Matrix](https://leetcode.com/tag/matrix/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Factorial Trailing Zeroes (Medium)](https://leetcode.com/problems/factorial-trailing-zeroes/)
* [Bomb Enemy (Medium)](https://leetcode.com/problems/bomb-enemy/)
* [Abbreviating the Product of a Range (Hard)](https://leetcode.com/problems/abbreviating-the-product-of-a-range/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
typedef array<int, 2> AII;
AII operator+(const AII &l, const AII &r) { return { l[0] + r[0], l[1] + r[1] }; }
AII operator-(const AII &l, const AII &r) { return { l[0] - r[0], l[1] - r[1] }; }
int count(const AII &p) { return min(p[0], p[1]); }
int factors(int n, int f) { return n % f ? 0 : 1 + factors(n / f, f); }
class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<vector<AII>> up(M + 1, vector<AII>(N)), left(M, vector<AII>(N + 1));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                AII f25 = {factors(A[i][j], 2), factors(A[i][j], 5)};
                up[i + 1][j] = up[i][j] + f25;
                left[i][j + 1] = left[i][j] + f25;
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                AII U = up[i + 1][j], L = left[i][j], D = up[M][j] - up[i][j], R = left[i][N] - left[i][j + 1];
                ans = max({ ans, count(U + L), count(U + R), count(D + L), count(D + R) });
            }
        }
        return ans;
    }
};
```