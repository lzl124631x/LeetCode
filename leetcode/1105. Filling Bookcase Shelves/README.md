# [1105. Filling Bookcase Shelves (Medium)](https://leetcode.com/problems/filling-bookcase-shelves/submissions/)

<p>We have a sequence of <code>books</code>: the <code>i</code>-th book has thickness <code>books[i][0]</code> and height <code>books[i][1]</code>.</p>

<p>We want to place these books <strong>in order</strong>&nbsp;onto bookcase shelves that have total width <code>shelf_width</code>.</p>

<p>We choose&nbsp;some of the books to place on this shelf (such that the sum of their thickness is <code>&lt;= shelf_width</code>), then build another level of shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down.&nbsp; We repeat this process until there are no more books to place.</p>

<p>Note again that at each step of the above&nbsp;process, <u>the order of the books we place is the same order as the given sequence of books</u>.&nbsp; For example, if we have an ordered list of 5&nbsp;books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.</p>

<p>Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/06/24/shelves.png" style="width: 250px; height: 370px;">
<pre><strong>Input:</strong> books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
<strong>Output:</strong> 6
<strong>Explanation:</strong>
The sum of the heights of the 3 shelves are 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= books.length &lt;= 1000</code></li>
	<li><code>1 &lt;= books[i][0] &lt;= shelf_width &lt;= 1000</code></li>
	<li><code>1 &lt;= books[i][1] &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Let `dp[i]` be the answer of the subproblem in `A[0..i]`.

```
dp[i] = min( dp[j-1] + max(j, i) | 0 <= j <= i && sum(j, i) <= width )
```

where `max(j, i)` is `max(A[j], ..., A[i])`, and `sum(j, i)` is `sum(A[j], ..., A[i])`.

```cpp
// OJ: https://leetcode.com/problems/filling-bookcase-shelves/
// Author: github.com/lzl124631x
// Time: O(NW)
// Space: O(N)
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& A, int W) {
        int N = A.size();
        vector<int> dp(N, INT_MAX);
        for (int i = 0; i < N; ++i) {
            int sum = 0, mx = 0;
            for (int j = i; j >= 0 && sum + A[j][0] <= W; --j) {
                sum += A[j][0];
                mx = max(mx, A[j][1]);
                dp[i] = min(dp[i], (j - 1 >= 0 ? dp[j - 1] : 0) + mx);
            }
        }
        return dp[N - 1];
    }
};
```