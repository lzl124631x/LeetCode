# [74. Search a 2D Matrix (Medium)](https://leetcode.com/problems/search-a-2d-matrix)

<p>You are given an <code>m x n</code> integer matrix <code>matrix</code> with the following two properties:</p>
<ul>
	<li>Each row is sorted in non-decreasing order.</li>
	<li>The first integer of each row is greater than the last integer of the previous row.</li>
</ul>
<p>Given an integer <code>target</code>, return <code>true</code> <em>if</em> <code>target</code> <em>is in</em> <code>matrix</code> <em>or</em> <code>false</code> <em>otherwise</em>.</p>
<p>You must write a solution in <code>O(log(m * n))</code> time complexity.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/mat.jpg" style="width: 322px; height: 242px;">
<pre><strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
<strong>Output:</strong> true
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg" style="width: 322px; height: 242px;">
<pre><strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>-10<sup>4</sup> &lt;= matrix[i][j], target &lt;= 10<sup>4</sup></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Search a 2D Matrix II (Medium)](https://leetcode.com/problems/search-a-2d-matrix-ii/)
* [Split Message Based on Limit (Hard)](https://leetcode.com/problems/split-message-based-on-limit/)

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

`L <= R` template:

```cpp
// OJ: https://leetcode.com/problems/search-a-2d-matrix/
// Author: github.com/lzl124631x
// Time: O(log(MN))
// Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        int M = A.size(), N = A[0].size(), L = 0, R = M * N - 1;
        while (L <= R) {
            int mid = (L + R) / 2, x = mid / N, y = mid % N;
            if (A[x][y] == target) return true;
            if (A[x][y] < target) L = mid + 1;
            else R = mid - 1;
        }
        return false;
    }
};
```

`L < R` template:

```cpp
// OJ: https://leetcode.com/problems/search-a-2d-matrix/
// Author: github.com/lzl124631x
// Time: O(log(MN))
// Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        int M = A.size(), N = A[0].size(), L = 0, R = M * N - 1;
        while (L < R) {
            int M = (L + R) / 2, i = M / N, j = M % N;
            if (A[i][j] < target) L = M + 1;
            else R = M;
        }
        return A[L / N][L % N] == target;
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
