# [2201. Count Artifacts That Can Be Extracted (Medium)](https://leetcode.com/problems/count-artifacts-that-can-be-extracted/)

<p>There is an <code>n x n</code> <strong>0-indexed</strong> grid with some artifacts buried in it. You are given the integer <code>n</code> and a <strong>0-indexed </strong>2D integer array <code>artifacts</code> describing the positions of the rectangular artifacts where <code>artifacts[i] = [r1<sub>i</sub>, c1<sub>i</sub>, r2<sub>i</sub>, c2<sub>i</sub>]</code> denotes that the <code>i<sup>th</sup></code> artifact is buried in the subgrid where:</p>

<ul>
	<li><code>(r1<sub>i</sub>, c1<sub>i</sub>)</code> is the coordinate of the <strong>top-left</strong> cell of the <code>i<sup>th</sup></code> artifact and</li>
	<li><code>(r2<sub>i</sub>, c2<sub>i</sub>)</code> is the coordinate of the <strong>bottom-right</strong> cell of the <code>i<sup>th</sup></code> artifact.</li>
</ul>

<p>You will excavate some cells of the grid and remove all the mud from them. If the cell has a part of an artifact buried underneath, it will be uncovered. If all the parts of an artifact are uncovered, you can extract it.</p>

<p>Given a <strong>0-indexed</strong> 2D integer array <code>dig</code> where <code>dig[i] = [r<sub>i</sub>, c<sub>i</sub>]</code> indicates that you will excavate the cell <code>(r<sub>i</sub>, c<sub>i</sub>)</code>, return <em>the number of artifacts that you can extract</em>.</p>

<p>The test cases are generated such that:</p>

<ul>
	<li>No two artifacts overlap.</li>
	<li>Each artifact only covers at most <code>4</code> cells.</li>
	<li>The entries of <code>dig</code> are unique.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/09/16/untitled-diagram.jpg" style="width: 216px; height: 216px;">
<pre><strong>Input:</strong> n = 2, artifacts = [[0,0,0,0],[0,1,1,1]], dig = [[0,0],[0,1]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
The different colors represent different artifacts. Excavated cells are labeled with a 'D' in the grid.
There is 1 artifact that can be extracted, namely the red artifact.
The blue artifact has one part in cell (1,1) which remains uncovered, so we cannot extract it.
Thus, we return 1.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/09/16/untitled-diagram-1.jpg" style="width: 216px; height: 216px;">
<pre><strong>Input:</strong> n = 2, artifacts = [[0,0,0,0],[0,1,1,1]], dig = [[0,0],[0,1],[1,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Both the red and blue artifacts have all parts uncovered (labeled with a 'D') and can be extracted, so we return 2. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= artifacts.length, dig.length &lt;= min(n<sup>2</sup>, 10<sup>5</sup>)</code></li>
	<li><code>artifacts[i].length == 4</code></li>
	<li><code>dig[i].length == 2</code></li>
	<li><code>0 &lt;= r1<sub>i</sub>, c1<sub>i</sub>, r2<sub>i</sub>, c2<sub>i</sub>, r<sub>i</sub>, c<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>r1<sub>i</sub> &lt;= r2<sub>i</sub></code></li>
	<li><code>c1<sub>i</sub> &lt;= c2<sub>i</sub></code></li>
	<li>No two artifacts will overlap.</li>
	<li>The number of cells covered by an artifact is <strong>at most</strong> <code>4</code>.</li>
	<li>The entries of <code>dig</code> are unique.</li>
</ul>


**Companies**:  
[IMC](https://leetcode.com/company/imc)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Maximal Square (Medium)](https://leetcode.com/problems/maximal-square/)

## Solution 1.

Create an `NxN` array `M`. `M[i][j] = true` if the cell `(i, j)` is digged.

For each artifact, traverse all its cells. If all the cells are digged, increment the answer.

```cpp
// OJ: https://leetcode.com/problems/count-artifacts-that-can-be-extracted/
// Author: github.com/lzl124631x
// Time: O(DIG + N^2)
// Space: O(N^2)
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& A, vector<vector<int>>& dig) {
        vector<vector<bool>> M(n, vector<bool>(n)); // M[i][j] = true if it's digged.
        for (auto &d : dig) M[d[0]][d[1]] = true;
        int ans = 0;
        for (auto &v : A) {
            bool good = true;
            for (int x = v[0]; x <= v[2] && good; ++x) {
                for (int y = v[1]; y <= v[3] && good; ++y) {
                    if (!M[x][y]) good = false;
                }
            }
            if (good) ++ans;
        }
        return ans;
    }
};
```

## Discussion

https://leetcode.com/problems/count-artifacts-that-can-be-extracted/discuss/1844106