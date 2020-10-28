# [1632. Rank Transform of a Matrix (Hard)](https://leetcode.com/problems/rank-transform-of-a-matrix/)

<p>Given an <code>m x n</code> <code>matrix</code>, return <em>a new matrix </em><code>answer</code><em> where </em><code>answer[row][col]</code><em> is the </em><em><strong>rank</strong> of </em><code>matrix[row][col]</code>.</p>

<p>The <strong>rank</strong> is an <strong>integer</strong> that represents how large an element is compared to other elements. It is calculated using the following rules:</p>

<ul>
	<li>The rank is an integer starting from <code>1</code>.</li>
	<li>If two elements <code>p</code> and <code>q</code> are in the <strong>same row or column</strong>, then:
	<ul>
		<li>If <code>p &lt; q</code> then <code>rank(p) &lt; rank(q)</code></li>
		<li>If <code>p == q</code> then <code>rank(p) == rank(q)</code></li>
		<li>If <code>p &gt; q</code> then <code>rank(p) &gt; rank(q)</code></li>
	</ul>
	</li>
	<li>The <strong>rank</strong> should be as <strong>small</strong> as possible.</li>
</ul>

<p>It is guaranteed that <code>answer</code> is unique under the given rules.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/18/rank1.jpg" style="width: 442px; height: 162px;">
<pre><strong>Input:</strong> matrix = [[1,2],[3,4]]
<strong>Output:</strong> [[1,2],[2,3]]
<strong>Explanation:</strong>
The rank of matrix[0][0] is 1 because it is the smallest integer in its row and column.
The rank of matrix[0][1] is 2 because matrix[0][1] &gt; matrix[0][0] and matrix[0][0] is rank 1.
The rank of matrix[1][0] is 2 because matrix[1][0] &gt; matrix[0][0] and matrix[0][0] is rank 1.
The rank of matrix[1][1] is 3 because matrix[1][1] &gt; matrix[0][1], matrix[1][1] &gt; matrix[1][0], and both matrix[0][1] and matrix[1][0] are rank 2.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/18/rank2.jpg" style="width: 442px; height: 162px;">
<pre><strong>Input:</strong> matrix = [[7,7],[7,7]]
<strong>Output:</strong> [[1,1],[1,1]]
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/18/rank3.jpg" style="width: 601px; height: 322px;">
<pre><strong>Input:</strong> matrix = [[20,-21,14],[-19,4,19],[22,-47,24],[-19,4,19]]
<strong>Output:</strong> [[4,2,3],[1,3,4],[5,1,6],[1,3,4]]
</pre>

<p><strong>Example 4:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/18/rank4.jpg" style="width: 601px; height: 242px;">
<pre><strong>Input:</strong> matrix = [[7,3,6],[1,4,5],[9,8,2]]
<strong>Output:</strong> [[5,1,4],[1,2,3],[6,3,1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>-10<sup>9</sup> &lt;= matrix[row][col] &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/), [Union Find](https://leetcode.com/tag/union-find/)

**Similar Questions**:
* [Rank Transform of an Array (Easy)](https://leetcode.com/problems/rank-transform-of-an-array/)

## Solution 1. Union Find

Intuition: Sort the numbers in ascending order. Visit them one by one. Each number should have a rank that is greater than those smaller numbers in the same row/column that are already assigned ranks.

The tricky part is how to handle those numbers of the same value. The numbers that have the same value and are in the same row/column should use the same rank, and the rank is the greatest one of those ranks if we check them individually.

To group those numbers, we can use Union Find.

If two numbers in the same row share the same value, we should connect the two column indexes.

If two numbers in the same column share the same value, we should connect the two row indexes.

Basically we are regarding the row and column indexes as vertices in a graph, and the numbers in the matrix as edge.

Time complexity: 

For pushing into the map, in the worst case where all the numbers are different, the map will have `MN` distinct values, so it's `O(MNlog(MN))`.

For each of the loops with Union Find, the time complexity is `O(K)` where `K` is the count of the `pos` array. So the overall time complexity of the Union Find loop is `O(MN)`.

In sum, the time complexity is `O(MNlog(MN))`.

```cpp
// OJ: https://leetcode.com/problems/rank-transform-of-a-matrix/
// Author: github.com/lzl124631x
// Time: O(MNlog(MN))
// Space: O(MN)
// Ref: https://leetcode.com/problems/rank-transform-of-a-matrix/discuss/909142/Python-Union-Find
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
};
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        map<int, vector<vector<int>>> m;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) m[A[i][j]].push_back({ i, j });
        }
        vector<int> rank(M + N, 0); // rank[0..(M-1)] stores the highest ranks of the rows, rank[M..(M+N-1)] stores the highest ranks of the columns.
        vector<vector<int>> ans(M, vector<int>(N));
        for (auto &[val, pos] : m) {
            UnionFind uf(M + N);
            for (auto &p : pos) {
                int x = uf.find(p[0]), y = uf.find(p[1] + M);
                uf.connect(x, y); // for each number, connect its (representative) row and column
                rank[uf.find(x)] = max(rank[x], rank[y]);
            }
            auto next = rank;
            for (auto &p : pos) {
                int x = p[0], y = p[1], r = uf.find(x);
                ans[x][y] = next[x] = next[y + M] = rank[r] + 1;
            }
            rank = move(next);
        }
        return ans;
    }
};
```