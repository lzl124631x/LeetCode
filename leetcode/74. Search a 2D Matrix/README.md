# [74. Search a 2D Matrix (Medium)](https://leetcode.com/problems/search-a-2d-matrix/)

<p>Write an efficient algorithm that searches for a value in an <code>m x n</code> matrix. This matrix has the following properties:</p>

<ul>
	<li>Integers in each row are sorted from left to right.</li>
	<li>The first integer of each row is greater than the last integer of the previous row.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/mat.jpg" style="width: 322px; height: 242px;">
<pre><strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg" style="width: 322px; height: 242px;">
<pre><strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
<strong>Output:</strong> false
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> matrix = [], target = 0
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>0 &lt;= m, n &lt;= 100</code></li>
	<li><code>-10<sup>4</sup> &lt;= matrix[i][j], target &lt;= 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Search a 2D Matrix II (Medium)](https://leetcode.com/problems/search-a-2d-matrix-ii/)

## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/search-a-2d-matrix/
// Author: github.com/lzl124631x
// Time: O(log(MN))
// Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        if (A.empty() || A[0].empty()) return false;
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M][0] == target) return true;
            if (A[M][0] < target) L = M + 1;
            else R = M - 1;
        }
        if (R == -1) return false;
        int row = R;
        L = 0, R = A[0].size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[row][M] == target) return true;
            if (A[row][M] < target) L = M + 1;
            else R = M - 1;
        }
        return false;
    }
};
```

## Solution 2. Binary Search

```cpp
// OJ: https://leetcode.com/problems/search-a-2d-matrix/
// Author: github.com/lzl124631x
// Time: O(log(MN))
// Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        if (A.empty() || A[0].empty()) return false;
        int M = A.size(), N = A[0].size(), L = 0, R = M * N - 1;
        while (L <= R) {
            int mid = (L + R) / 2, val = A[mid / N][mid % N];
            if (val == target) return true;
            if (val < target) L = mid + 1;
            else R = mid - 1;
        }
        return false;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/search-a-2d-matrix/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        if (A.empty() || A[0].empty()) return false;
        int M = A.size(), N = A[0].size(), i = 0, j = N - 1;
        while (i < M && j >= 0) {
            if (A[i][j] == target) return true;
            if (A[i][j] < target) ++i;
            else --j;
        }
        return false;
    }
};
```
