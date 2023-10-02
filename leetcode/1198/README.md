# [1198. Find Smallest Common Element in All Rows (Medium)](https://leetcode.com/problems/find-smallest-common-element-in-all-rows/)

<p>Given an <code>m x n</code> matrix <code>mat</code> where every row is sorted in <strong>strictly</strong> <strong>increasing</strong> order, return <em>the <strong>smallest common element</strong> in all rows</em>.</p>

<p>If there is no common element, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
<strong>Output:</strong> 5
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> mat = [[1,2,3],[2,3,4],[2,3,5]]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 10<sup>4</sup></code></li>
	<li><code>mat[i]</code> is sorted in strictly increasing order.</li>
</ul>


**Companies**:  
[Qualtrics](https://leetcode.com/company/qualtrics), [Intel](https://leetcode.com/company/intel), [Walmart Labs](https://leetcode.com/company/walmart-labs)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Binary Search](https://leetcode.com/tag/binary-search/), [Matrix](https://leetcode.com/tag/matrix/), [Counting](https://leetcode.com/tag/counting/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-smallest-common-element-in-all-rows/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(M)
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        vector<int> index(M);
        for (int j = 0; j < N; ++j) {
            int n = A[0][j], i = 1;
            for (; i < M; ++i) {
                while (index[i] < N && A[i][index[i]] < n) ++index[i];
                if (index[i] == N) return -1;
                if (A[i][index[i]] != n) break;
            }
            if (i == M) return n;
        }
        return -1;
    }
};
```

## Solution 2. Binary Search

```cpp
// OJ: https://leetcode.com/problems/find-smallest-common-element-in-all-rows/
// Author: github.com/lzl124631x
// Time: O(NMlogN)
// Space: O(1)
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        for (int j = 0; j < N; ++j) {
            int n = A[0][j], i = 1;
            for (; i < M; ++i) {
                int k = lower_bound(begin(A[i]), end(A[i]), n) - begin(A[i]);
                if (k > N) return -1;
                if (A[i][k] != n) break;
            }
            if (i == M) return n;
        }
        return -1;
    }
};
```