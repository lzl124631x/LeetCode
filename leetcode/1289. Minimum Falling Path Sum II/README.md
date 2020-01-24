# [1289. Minimum Falling Path Sum II (Hard)](https://leetcode.com/problems/minimum-falling-path-sum-ii/)

<p>Given a square grid&nbsp;of integers&nbsp;<code>arr</code>, a <em>falling path with non-zero shifts</em>&nbsp;is a choice of&nbsp;exactly one element from each row of <code>arr</code>, such that no two elements chosen in adjacent rows are in&nbsp;the same column.</p>

<p>Return the&nbsp;minimum&nbsp;sum of a falling path with non-zero shifts.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> 13
<strong>Explanation: </strong>
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is&nbsp;[1,5,7], so the answer is&nbsp;13.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length == arr[i].length &lt;= 200</code></li>
	<li><code>-99 &lt;= arr[i][j] &lt;= 99</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Minimum Falling Path Sum (Medium)](https://leetcode.com/problems/minimum-falling-path-sum/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/minimum-falling-path-sum-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
    pair<int, int> getSmallestTwo(vector<int> &A) {
        auto p = make_pair(-1, -1);
        for (int i = 0; i < A.size(); ++i) {
            if (p.first == -1 || A[i] < A[p.first]) {
                p.second = p.first;
                p.first = i;
            } else if (p.second == -1 || A[i] < A[p.second]) p.second = i;
        }
        return p;
    }
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        if (N == 1) return A[0][0];
        for (int i = 1; i < N; ++i) {
            auto p = getSmallestTwo(A[i - 1]);
            for (int j = 0; j < N; ++j) {
                A[i][j] += A[i - 1][p.first == j ? p.second : p.first];
            }
        }
        return *min_element(A.back().begin(), A.back().end());
    }
};
```

## Solution 2. DP

In case it's not allowed to change input array.

```cpp
// OJ: https://leetcode.com/problems/minimum-falling-path-sum-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    pair<int, int> getSmallestTwo(vector<int> &A) {
        auto p = make_pair(-1, -1);
        for (int i = 0; i < A.size(); ++i) {
            if (p.first == -1 || A[i] < A[p.first]) {
                p.second = p.first;
                p.first = i;
            } else if (p.second == -1 || A[i] < A[p.second]) p.second = i;
        }
        return p;
    }
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        if (N == 1) return A[0][0];
        vector<vector<int>> dp(2, vector<int>(N));
        for (int i = 0; i < N; ++i) dp[1][i] = A[0][i];
        for (int i = 1; i < N; ++i) {
            auto p = getSmallestTwo(dp[i % 2]);
            for (int j = 0; j < N; ++j) {
                dp[(i + 1) % 2][j] = A[i][j] + dp[i % 2][p.first == j ? p.second : p.first];
            }
        }
        return *min_element(dp[N % 2].begin(), dp[N % 2].end());
    }
};
```