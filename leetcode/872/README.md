# [766. Toeplitz Matrix (Easy)](https://leetcode.com/problems/toeplitz-matrix/)

<p>A matrix is <em>Toeplitz</em> if every diagonal from top-left to bottom-right has the same element.</p>

<p>Now given an <code>M x N</code> matrix, return&nbsp;<code>True</code>&nbsp;if and only if the matrix is <em>Toeplitz</em>.<br>
&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:
</strong>matrix = [
&nbsp; [1,2,3,4],
&nbsp; [5,1,2,3],
&nbsp; [9,5,1,2]
]
<strong>Output:</strong> True
<strong>Explanation:</strong>
In the above grid, the&nbsp;diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:
</strong>matrix = [
&nbsp; [1,2],
&nbsp; [2,2]
]
<strong>Output:</strong> False
<strong>Explanation:</strong>
The diagonal "[1, 2]" has different elements.
</pre>

<p><br>
<strong>Note:</strong></p>

<ol>
	<li><code>matrix</code> will be a 2D array of integers.</li>
	<li><code>matrix</code> will have a number of rows and columns in range <code>[1, 20]</code>.</li>
	<li><code>matrix[i][j]</code> will be integers in range <code>[0, 99]</code>.</li>
</ol>

<p><br>
<strong>Follow up:</strong></p>

<ol>
	<li>What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?</li>
	<li>What if the matrix is so large that you can only load up a partial row into the memory at once?</li>
</ol>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/toeplitz-matrix
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        for (int i = 0; i < M; ++i) {
            for (int x = i + 1, y = 1; x < M && y < N; ++x, ++y) {
                if (matrix[x][y] != matrix[x - 1][y - 1]) return false;
            }
        }
        for (int i = 1; i < N; ++i) {
            for (int x = 1, y = i + 1; x < M && y < N; ++x, ++y) {
                if (matrix[x][y] != matrix[x - 1][y - 1]) return false;
            }
        }
        return true;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/toeplitz-matrix
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) return false;
            }
        }
        return true;
    }
};
```