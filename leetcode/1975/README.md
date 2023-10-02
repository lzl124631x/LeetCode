# [1975. Maximum Matrix Sum (Medium)](https://leetcode.com/problems/maximum-matrix-sum/)

<p>You are given an <code>n x n</code> integer <code>matrix</code>. You can do the following operation <strong>any</strong> number of times:</p>

<ul>
	<li>Choose any two <strong>adjacent</strong> elements of <code>matrix</code> and <strong>multiply</strong> each of them by <code>-1</code>.</li>
</ul>

<p>Two elements are considered <strong>adjacent</strong> if and only if they share a <strong>border</strong>.</p>

<p>Your goal is to <strong>maximize</strong> the summation of the matrix's elements. Return <em>the <strong>maximum</strong> sum of the matrix's elements using the operation mentioned above.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/16/pc79-q2ex1.png" style="width: 401px; height: 81px;">
<pre><strong>Input:</strong> matrix = [[1,-1],[-1,1]]
<strong>Output:</strong> 4
<b>Explanation:</b> We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/16/pc79-q2ex2.png" style="width: 321px; height: 121px;">
<pre><strong>Input:</strong> matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
<strong>Output:</strong> 16
<b>Explanation:</b> We can follow the following step to reach sum equals 16:
- Multiply the 2 last elements in the second row by -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 250</code></li>
	<li><code>-10<sup>5</sup> &lt;= matrix[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution 1. Brain Teaser + Greedy

If there are even number of negative numbers, we can make all of them positive.

If there are odd number of negative numbers, we can leave one number negative. We can greedily pick the number with the smallest absolute value.

```cpp
// OJ: https://leetcode.com/problems/maximum-matrix-sum/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& A) {
        long long cnt = 0, sum = 0, N = A.size(), mn = INT_MAX;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cnt += A[i][j] < 0;
                sum += abs(A[i][j]);
                mn = min(mn, (long long)abs(A[i][j]));
            }
        }
        return cnt % 2 ? sum - 2 * mn : sum;
    }
};
```