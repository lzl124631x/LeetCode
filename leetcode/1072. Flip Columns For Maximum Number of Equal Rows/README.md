# [1072. Flip Columns For Maximum Number of Equal Rows (Medium)](https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/)

<p>Given a <code>matrix</code> consisting of 0s and 1s, we may choose any number of columns in the matrix and flip <strong>every</strong>&nbsp;cell in that column.&nbsp; Flipping a cell changes the value of that cell from 0 to 1 or from 1 to 0.</p>

<p>Return the maximum number of rows that have all values equal after some number of flips.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[0,1],[1,1]]</span>
<strong>Output: </strong><span id="example-output-1">1</span>
<strong>Explanation: </strong>After flipping no values, 1 row has all values equal.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[[0,1],[1,0]]</span>
<strong>Output: </strong><span id="example-output-2">2</span>
<strong>Explanation: </strong>After flipping values in the first column, both rows have equal values.
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[[0,0,0],[0,0,1],[1,1,0]]</span>
<strong>Output: </strong><span id="example-output-3">2</span>
<strong>Explanation: </strong>After flipping values in the first two columns, the last two rows have equal values.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= matrix.length &lt;= 300</code></li>
	<li><code>1 &lt;= matrix[i].length &lt;= 300</code></li>
	<li>All <code>matrix[i].length</code>'s are equal</li>
	<li><code>matrix[i][j]</code> is&nbsp;<code>0</code> or <code>1</code></li>
</ol>
</div>
</div>
</div>

## Solution 1.

1. For each row, if the first element is not `0`, flip the row.
1. Find the maximum count of the rows having the same content.

Why does this work?

Let's say "an array `a` is clean" if all the elements in `a` are the same.

If two rows `a` and `b` can become clean after flips, their `xor` result must also be clean.

For example, the following two arrays can be clean after flips
```
a:   0 1 0
b:   1 0 1
xor: 1 1 1
```
The following two can't be both clean however you flip them.
```
a:   0 1 0
b:   1 1 1
xor: 1 0 1
```

If `xor` of row `a` and `b` is clean, then either `a == b` (`a` and `b` are identical) or `a == ^b` (`a` and `b` are inverted).

For `a == ^b` case, we can simply flip row `b` to make `a == b'`.

So to make sure all the arrays are aligned, we flip the arrays not starting with `0`. And we can easily get the result by finding the maximum count of rows identical.

```cpp
// OJ: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size(), ans = 0;
        unordered_map<string, int> cnt;
        for (int i = 0; i < M; ++i) {
            string s;
            bool flip = matrix[i][0] == 1;
            for (int j = 0; j < N; ++j) s += flip ? ('1' - matrix[i][j]) : ('0' + matrix[i][j]);
            ans = max(ans, ++cnt[s]);
        }
        return ans;
    }
};
```