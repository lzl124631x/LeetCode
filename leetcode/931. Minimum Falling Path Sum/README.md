# [931. Minimum Falling Path Sum (Medium)](https://leetcode.com/problems/minimum-falling-path-sum/)

<p>Given a <strong>square</strong> array of integers <code>A</code>, we want the <strong>minimum</strong> sum of a <em>falling path</em> through <code>A</code>.</p>

<p>A falling path starts at any element in the first row, and chooses one element from each row.&nbsp; The next row's choice must be in a column that is different from the previous row's column by at most one.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[1,2,3],[4,5,6],[7,8,9]]</span>
<strong>Output: </strong><span id="example-output-1">12</span>
<strong>Explanation: </strong>
The possible falling paths are:
</pre>

<ul>
	<li><code>[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]</code></li>
	<li><code>[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]</code></li>
	<li><code>[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]</code></li>
</ul>

<p>The falling path with the smallest sum is <code>[1,4,7]</code>, so the answer is <code>12</code>.</p>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length == A[0].length &lt;= 100</code></li>
	<li><code>-100 &lt;= A[i][j] &lt;= 100</code></li>
</ol>

**Companies**:  
[Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/minimum-falling-path-sum/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        vector<vector<int>> dp(2, vector<int>(N, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[(i + 1) % 2][j] = A[i][j] + min({ j - 1 >= 0 ? dp[i % 2][j - 1] : INT_MAX,
                                                     dp[i % 2][j],
                                                     j + 1 < N ? dp[i % 2][j + 1] : INT_MAX });
            }
        }
        return *min_element(dp[N % 2].begin(), dp[N % 2].end());
    }
};
```

## Solution 2.

Same idea as Solution 1, but use `A` to cache DP values.

```cpp
// OJ: https://leetcode.com/problems/minimum-falling-path-sum/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                A[i][j] += min({ j - 1 >= 0 ? A[i - 1][j - 1] : INT_MAX,
                                 A[i - 1][j],
                                 j + 1 < N ? A[i - 1][j + 1] : INT_MAX });
            }
        }
        return *min_element(A.back().begin(), A.back().end());
    }
};
```