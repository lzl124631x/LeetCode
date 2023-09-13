# [1428. Leftmost Column with at Least a One (Medium)](https://leetcode.com/problems/leftmost-column-with-at-least-a-one/)

<div><p><em>(This problem is an&nbsp;<strong>interactive problem</strong>.)</em></p>

<p>A binary matrix means that all elements are&nbsp;<code>0</code>&nbsp;or&nbsp;<code>1</code>. For each&nbsp;<strong>individual</strong> row of the matrix, this row&nbsp;is sorted in non-decreasing order.</p>

<p>Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a&nbsp;<code>1</code>&nbsp;in it. If such&nbsp;index&nbsp;doesn't exist, return <code>-1</code>.</p>

<p><strong>You can't access the Binary Matrix directly.</strong>&nbsp; You may only access the matrix using a&nbsp;<code>BinaryMatrix</code>&nbsp;interface:</p>

<ul>
	<li><code>BinaryMatrix.get(x, y)</code> returns the element of the matrix&nbsp;at index <code>(x, y)</code>&nbsp;(0-indexed).</li>
	<li><code>BinaryMatrix.dimensions()</code>&nbsp;returns a list of 2 elements&nbsp;<code>[m, n]</code>, which means the matrix is <code>m * n</code>.</li>
</ul>

<p>Submissions making more than <code>1000</code>&nbsp;calls to&nbsp;<code>BinaryMatrix.get</code>&nbsp;will be judged <em>Wrong Answer</em>.&nbsp; Also, any solutions that attempt to circumvent the judge&nbsp;will result in disqualification.</p>

<p>For custom testing purposes you're given the binary matrix <code>mat</code>&nbsp;as input&nbsp;in the following four examples. You will not have&nbsp;access the binary matrix directly.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/25/untitled-diagram-5.jpg" style="width: 81px; height: 81px;"></strong></p>

<pre><strong>Input:</strong> mat = [[0,0],[1,1]]
<strong>Output:</strong> 0
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/25/untitled-diagram-4.jpg" style="width: 81px; height: 81px;"></strong></p>

<pre><strong>Input:</strong> mat = [[0,0],[0,1]]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/25/untitled-diagram-3.jpg" style="width: 81px; height: 81px;"></strong></p>

<pre><strong>Input:</strong> mat = [[0,0],[0,0]]
<strong>Output:</strong> -1</pre>

<p><strong>Example 4:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/25/untitled-diagram-6.jpg" style="width: 161px; height: 121px;"></strong></p>

<pre><strong>Input:</strong> mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>mat[i][j]</code> is either <code>0</code>&nbsp;or&nbsp;<code>1</code>.</li>
	<li><code>mat[i]</code>&nbsp;is sorted in a&nbsp;non-decreasing way.</li>
</ul></div>

## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/leftmost-column-with-at-least-a-one/
// Author: github.com/lzl124631x
// Time: O(M * logN)
// Space: O(1)
class Solution {
    int search(BinaryMatrix &A, int i, int end) {
        int L = 0, R = end - 1;
        while (L <= R) {
            int M = (L + R) / 2, val = A.get(i, M);
            if (val == 0) L = M + 1;
            else if (val == 1) {
                if (M - 1 < 0 || A.get(i, M - 1) == 0) return M;
                R = M - 1;
            }
        }
        return -1;
    }
public:
    int leftMostColumnWithOne(BinaryMatrix &A) {
        auto dim = A.dimensions();
        int M = dim[0], N = dim[1], ans = N;
        for (int i = 0; i < M; ++i) {
            int j = search(A, i, ans);
            if (j != -1) ans = j;
        }
        return ans == N ? -1 : ans;
    }
};
```