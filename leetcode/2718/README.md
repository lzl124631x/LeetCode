# [2718. Sum of Matrix After Queries (Medium)](https://leetcode.com/problems/sum-of-matrix-after-queries)

<p>You are given an integer <code>n</code> and a <strong>0-indexed</strong>&nbsp;<strong>2D array</strong> <code>queries</code> where <code>queries[i] = [type<sub>i</sub>, index<sub>i</sub>, val<sub>i</sub>]</code>.</p>

<p>Initially, there is a <strong>0-indexed</strong> <code>n x n</code> matrix filled with <code>0</code>&#39;s. For each query, you must apply one of the following changes:</p>

<ul>
	<li>if <code>type<sub>i</sub> == 0</code>, set the values in the row with <code>index<sub>i</sub></code> to <code>val<sub>i</sub></code>, overwriting any previous values.</li>
	<li>if <code>type<sub>i</sub> == 1</code>, set the values in the column with <code>index<sub>i</sub></code> to <code>val<sub>i</sub></code>, overwriting any previous values.</li>
</ul>

<p>Return <em>the sum of integers in the matrix after all queries are applied</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/05/11/exm1.png" style="width: 681px; height: 161px;" />
<pre>
<strong>Input:</strong> n = 3, queries = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]
<strong>Output:</strong> 23
<strong>Explanation:</strong> The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 23. 
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/05/11/exm2.png" style="width: 681px; height: 331px;" />
<pre>
<strong>Input:</strong> n = 3, queries = [[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]
<strong>Output:</strong> 17
<strong>Explanation:</strong> The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 17.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>queries[i].length == 3</code></li>
	<li><code>0 &lt;= type<sub>i</sub> &lt;= 1</code></li>
	<li><code>0 &lt;= index<sub>i</sub>&nbsp;&lt; n</code></li>
	<li><code>0 &lt;= val<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table)

**Similar Questions**:
* [Range Sum Query 2D - Mutable (Hard)](https://leetcode.com/problems/range-sum-query-2d-mutable)
* [Range Addition II (Easy)](https://leetcode.com/problems/range-addition-ii)

**Hints**:
* Process queries in reversed order, as the latest queries represent the most recent changes in the matrix.
* Once you encounter an operation on some row/column, no further operations will affect the values in this row/column. Keep track of seen rows and columns with a set.
* When operating on an unseen row/column, the number of affected cells is the number of columns/rows you haven’t previously seen.

## Solution 1.

**Intuition**:

I first considered traversing the queries in order. When I meet queries writing to row/columns that have been written before, I need to overwrite the previous query. Also, assume the current query is writing to a row and there is no other query writing to the same row, to know to how many cells the current query writes, I need to know how many unique column queries after this query. If I also consider that there might be another row query writing to the same row as the current query, the problem becomes more complicated.

Here, I thought about traversing the queries in the reverse order. In this way, I don't need to do overwriting; I just need to check if a row/column has been written, and skip any earlier queries. Also, computing how many column queries are after the current row query is trivial now, we can simply count unique column queries we've seen so far.

**Algorithm**:

Traverse the queries in reverse order. Using a `vector<unordered_set<int>> seen(2)` to check if an index has been seen before.

If it has been seen before, skip this query.

Otherwise, `seen[type].insert(index)`, and increase answer by `(n - seen[1 - type].size()) * val`.

```cpp
// OJ: https://leetcode.com/problems/sum-of-matrix-after-queries
// Author: github.com/lzl124631x
// Time: O(Q)
// Space: O(min(N, Q))
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& Q) {
        long long ans = 0;
        vector<unordered_set<int>> seen(2);
        for (int i = Q.size() - 1; i >= 0; --i) {
            int type = Q[i][0], index = Q[i][1], val = Q[i][2];
            if (seen[type].count(index)) continue;
            seen[type].insert(index);
            ans += (n - seen[1 - type].size()) * val;
        }
        return ans;
    }
};
```

Using array can save a bit of time.

```cpp
// OJ: https://leetcode.com/problems/sum-of-matrix-after-queries
// Author: github.com/lzl124631x
// Time: O(Q)
// Space: O(N)
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& Q) {
        long long ans = 0;
        bool seen[2][10000] = {};
        int cnt[2] = {};
        for (int i = Q.size() - 1; i >= 0; --i) {
            int type = Q[i][0], index = Q[i][1], val = Q[i][2];
            if (seen[type][index]) continue;
            seen[type][index] = true;
            cnt[type]++;
            ans += (n - cnt[1 - type]) * val;
        }
        return ans;
    }
};
```