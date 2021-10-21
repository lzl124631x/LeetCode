# [302. Smallest Rectangle Enclosing Black Pixels (Hard)](https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/)

<p>You are given an <code>m x n</code> binary matrix <code>image</code> where <code>0</code> represents a white pixel and <code>1</code> represents a black pixel.</p>

<p>The black pixels are connected (i.e., there is only one black region). Pixels are connected horizontally and vertically.</p>

<p>Given two integers <code>x</code> and <code>y</code> that represents the location of one of the black pixels, return <em>the area of the smallest (axis-aligned) rectangle that encloses all black pixels</em>.</p>

<p>You must write an algorithm with less than <code>O(mn)</code> runtime complexity</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/pixel-grid.jpg" style="width: 333px; height: 253px;">
<pre><strong>Input:</strong> image = [["0","0","1","0"],["0","1","1","0"],["0","1","0","0"]], x = 0, y = 2
<strong>Output:</strong> 6
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> image = [["1"]], x = 0, y = 0
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == image.length</code></li>
	<li><code>n == image[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>image[i][j]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
	<li><code>1 &lt;= x &lt; m</code></li>
	<li><code>1 &lt;= y &lt; n</code></li>
	<li><code>image[x][y] == '1'.</code></li>
	<li>The black pixels in the <code>image</code> only form <strong>one component</strong>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Matrix](https://leetcode.com/tag/matrix/)

## Solution 1. Binary Search (L <= R)

```cpp
// OJ: https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/
// Author: github.com/lzl124631x
// Time: O(MlogN + NlogM)
// Space: O(M + N)
class Solution {
public:
    int minArea(vector<vector<char>>& A, int x, int y) {
        int M = A.size(), N = A[0].size();
        auto getRowLength = [&]() {
            int L = 0, R = x; // search min x
            while (L <= R) {
                int mid = (L + R) / 2, j = 0;
                while (j < N && A[mid][j] == '0') ++j;
                if (j < N) R = mid - 1;
                else L = mid + 1;
            }
            int mn = L; // minX = L
            L = x, R = M - 1;
            while (L <= R) {
                int mid = (L + R) / 2, j = 0;
                while (j < N && A[mid][j] == '0') ++j;
                if (j < N) L = mid + 1;
                else R = mid - 1;
            }
            return L - mn; // maxX = R = L - 1
        };
        auto getColumnLength = [&]() {
            int L = 0, R = y; // search min y
            while (L <= R) {
                int mid = (L + R) / 2, i = 0;
                while (i < M && A[i][mid] == '0') ++i;
                if (i < M) R = mid - 1;
                else L = mid + 1;
            }
            int mn = L; // minY = L
            L = y, R = N - 1;
            while (L <= R) {
                int mid = (L + R) / 2, i = 0;
                while (i < M && A[i][mid] == '0') ++i;
                if (i < M) L = mid + 1;
                else R = mid - 1;
            }
            return L - mn; // maxX = R = L - 1
        };
        return getRowLength() * getColumnLength();
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/
// Author: github.com/lzl124631x
// Time: O(MlogN + NlogM)
// Space: O(M + N)
class Solution {
public:
    int minArea(vector<vector<char>>& A, int x, int y) {
        int M = A.size(), N = A[0].size();
        auto searchRow = [&](int L, int R, bool leftBound) {
            while (L <= R) {
                int mid = (L + R) / 2, j = 0;
                while (j < N && A[mid][j] == '0') ++j;
                if (j < N == leftBound) R = mid - 1;
                else L = mid + 1;
            }
            return L;
        };
        auto searchColumn = [&](int L, int R, bool leftBound) {
            while (L <= R) {
                int mid = (L + R) / 2, i = 0;
                while (i < M && A[i][mid] == '0') ++i;
                if (i < M == leftBound) R = mid - 1;
                else L = mid + 1;
            }
            return L;
        };
        return (searchRow(x, M - 1, false) - searchRow(0, x, true)) * (searchColumn(y, N - 1, false) - searchColumn(0, y, true));
    }
};
```

## Solution 2. Binary Search (L < R)

```cpp
// OJ: https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/
// Author: github.com/lzl124631x
// Time: O(MlogN + NlogM)
// Space: O(M + N)
class Solution {
public:
    int minArea(vector<vector<char>>& A, int x, int y) {
        int M = A.size(), N = A[0].size();
        auto getRowLength = [&]() {
            int L = 0, R = x; // search min x
            while (L < R) {
                int mid = (L + R) / 2, j = 0;
                while (j < N && A[mid][j] == '0') ++j;
                if (j < N) R = mid;
                else L = mid + 1;
            }
            int mn = L; // minX = L
            L = x, R = M - 1; // If we search for the maxX, the range should be [x, M - 1]
            while (L < R) {
                int mid = (L + R + 1) / 2, j = 0;
                while (j < N && A[mid][j] == '0') ++j;
                if (j < N) L = mid;
                else R = mid - 1;
            }
            return L + 1 - mn; // maxX = L
        };
        auto getColumnLength = [&]() {
            int L = 0, R = y; // search min y
            while (L < R) {
                int mid = (L + R) / 2, i = 0;
                while (i < M && A[i][mid] == '0') ++i;
                if (i < M) R = mid;
                else L = mid + 1;
            }
            int mn = L; // minY = L
            L = y, R = N - 1;
            while (L < R) {
                int mid = (L + R + 1) / 2, i = 0;
                while (i < M && A[i][mid] == '0') ++i;
                if (i < M) L = mid;
                else R = mid - 1;
            }
            return L + 1 - mn; // maxX = L
        };
        return getRowLength() * getColumnLength();
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/
// Author: github.com/lzl124631x
// Time: O(MlogN + NlogM)
// Space: O(M + N)
class Solution {
public:
    int minArea(vector<vector<char>>& A, int x, int y) {
        int M = A.size(), N = A[0].size();
        auto getRowLength = [&]() {
            int L = 0, R = x; // search min x
            while (L < R) {
                int mid = (L + R) / 2, j = 0;
                while (j < N && A[mid][j] == '0') ++j;
                if (j < N) R = mid;
                else L = mid + 1;
            }
            int mn = L; // minX = L
            L = x + 1, R = M; // If we search for the one after the maxX, the range should be `[x + 1, M]`.
            while (L < R) {
                int mid = (L + R) / 2, j = 0;
                while (j < N && A[mid][j] == '0') ++j;
                if (j < N) L = mid + 1;
                else R = mid;
            }
            return L - mn; // maxX = L
        };
        auto getColumnLength = [&]() {
            int L = 0, R = y; // search min y
            while (L < R) {
                int mid = (L + R) / 2, i = 0;
                while (i < M && A[i][mid] == '0') ++i;
                if (i < M) R = mid;
                else L = mid + 1;
            }
            int mn = L; // minY = L
            L = y + 1, R = N;
            while (L < R) {
                int mid = (L + R) / 2, i = 0;
                while (i < M && A[i][mid] == '0') ++i;
                if (i < M) L = mid + 1;
                else R = mid;
            }
            return L - mn; // maxX = L
        };
        return getRowLength() * getColumnLength();
    }
};
```

We can shorten the 2nd version:

```cpp
// OJ: https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/
// Author: github.com/lzl124631x
// Time: O(MlogN + NlogM)
// Space: O(M + N)
class Solution {
public:
    int minArea(vector<vector<char>>& A, int x, int y) {
        int M = A.size(), N = A[0].size();
        auto searchRow = [&](int L, int R, bool leftBound) {
            while (L < R) {
                int mid = (L + R) / 2, j = 0;
                while (j < N && A[mid][j] == '0') ++j;
                if (j < N == leftBound) R = mid;
                else L = mid + 1;
            }
            return L;
        };
        auto searchColumn = [&](int L, int R, bool leftBound) {
            while (L < R) {
                int mid = (L + R) / 2, i = 0;
                while (i < M && A[i][mid] == '0') ++i;
                if (i < M == leftBound) R = mid;
                else L = mid + 1;
            }
            return L;
        };
        return (searchRow(x + 1, M, false) - searchRow(0, x, true)) * (searchColumn(y + 1, N, false) - searchColumn(0, y, true));
    }
};
```