# [1738. Find Kth Largest XOR Coordinate Value (Medium)](https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/)

<p>You are given a 2D <code>matrix</code> of size <code>m x n</code>, consisting of non-negative integers. You are also given an integer <code>k</code>.</p>

<p>The <strong>value</strong> of coordinate <code>(a, b)</code> of the matrix is the XOR of all <code>matrix[i][j]</code> where <code>0 &lt;= i &lt;= a &lt; m</code> and <code>0 &lt;= j &lt;= b &lt; n</code> <strong>(0-indexed)</strong>.</p>

<p>Find the <code>k<sup>th</sup></code> largest value <strong>(1-indexed)</strong> of all the coordinates of <code>matrix</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> matrix = [[5,2],[1,6]], k = 1
<strong>Output:</strong> 7
<strong>Explanation:</strong> The value of coordinate (0,1) is 5 XOR 2 = 7, which is the largest value.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> matrix = [[5,2],[1,6]], k = 2
<strong>Output:</strong> 5
<strong>Explanation: </strong>The value of coordinate (0,0) is 5 = 5, which is the 2nd largest value.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> matrix = [[5,2],[1,6]], k = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> The value of coordinate (1,0) is 5 XOR 1 = 4, which is the 3rd largest value.</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> matrix = [[5,2],[1,6]], k = 4
<strong>Output:</strong> 0
<strong>Explanation:</strong> The value of coordinate (1,1) is 5 XOR 2 XOR 1 XOR 6 = 0, which is the 4th largest value.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
	<li><code>0 &lt;= matrix[i][j] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= m * n</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
// Author: github.com/lzl124631x
// Time: O(MNlog(MN))
// Space: O(MN)
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& A, int k) {
        vector<int> v;
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            int val = 0;
            for (int j = 0; j < N; ++j) {
                val ^= A[i][j];
                A[i][j] = val;
                if (i - 1 >= 0) A[i][j] ^= A[i - 1][j];
                v.push_back(A[i][j]);
            }
        }
        sort(begin(v), end(v), greater<>());
        return v[k - 1];
    }
};
```

Or use Heap

```cpp
// OJ: https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
// Author: github.com/lzl124631x
// Time: O(MNlog(K))
// Space: O(K)
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& A, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        int M= A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            int val = 0;
            for (int j = 0; j < N; ++j) {
                val ^= A[i][j];
                A[i][j] = val;
                if (i - 1 >= 0)  A[i][j] ^= A[i - 1][j];
                if (pq.size() < k || A[i][j] > pq.top()) pq.push(A[i][j]);
                if (pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};
```