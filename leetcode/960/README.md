# [960. Delete Columns to Make Sorted III (Hard)](https://leetcode.com/problems/delete-columns-to-make-sorted-iii/)

<p>We are given an array&nbsp;<code>A</code> of <code>N</code> lowercase letter strings, all of the same length.</p>

<p>Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.</p>

<p>For example, if we have an array <code>A = ["babca","bbazb"]</code> and deletion indices <code>{0, 1, 4}</code>, then the final array after deletions is <code>["bc","az"]</code>.</p>

<p>Suppose we chose a set of deletion indices <code>D</code> such that after deletions, the final array has <strong>every element (row) in&nbsp;lexicographic</strong> order.</p>

<p>For clarity, <code>A[0]</code> is in lexicographic order (ie. <code>A[0][0] &lt;= A[0][1] &lt;= ... &lt;= A[0][A[0].length - 1]</code>), <code>A[1]</code> is in lexicographic order (ie. <code>A[1][0] &lt;= A[1][1] &lt;= ... &lt;= A[1][A[1].length - 1]</code>), and so on.</p>

<p>Return the minimum possible value of <code>D.length</code>.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">["babca","bbazb"]</span>
<strong>Output: </strong><span id="example-output-1">3</span>
<strong>Explanation: </strong>After deleting columns 0, 1, and 4, the final array is A = ["bc", "az"].
Both these rows are individually in lexicographic order (ie. A[0][0] &lt;= A[0][1] and A[1][0] &lt;= A[1][1]).
Note that A[0] &gt; A[1] - the array A isn't necessarily in lexicographic order.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">["edcba"]</span>
<strong>Output: </strong><span id="example-output-2">4</span>
<strong>Explanation: </strong>If we delete less than 4 columns, the only row won't be lexicographically sorted.
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">["ghi","def","abc"]</span>
<strong>Output: </strong><span id="example-output-3">0</span>
<strong>Explanation: </strong>All rows are already lexicographically sorted.
</pre>

<p>&nbsp;</p>
</div>
</div>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 100</code></li>
	<li><code>1 &lt;= A[i].length &lt;= 100</code></li>
</ol>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Let `dp[i]` be the maximum number of columns that are non-decreasing in the first `i + 1` columns.

```
dp[i] = max( 1, max( dp[j] + 1 | column j can go after column i ) )
```

```cpp
// OJ: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
// Author: github.com/lzl124631x
// Time: O(M * N^2)
// Space: O(N)
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int M = A.size(), N = A[0].size(), ans = N - 1, k;
        vector<int> dp(N, 1);
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                for (k = 0; k < M; ++k) {
                    if (A[k][j] > A[k][i]) break;
                }
                if (k == M) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = min(ans, N - dp[i]);
        }
        return ans;
    }
};
```