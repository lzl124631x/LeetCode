# [1105. Filling Bookcase Shelves (Medium)](https://leetcode.com/problems/filling-bookcase-shelves/)

<p>You are given an array <code>books</code> where <code>books[i] = [thickness<sub>i</sub>, height<sub>i</sub>]</code> indicates the thickness and height of the <code>i<sup>th</sup></code> book. You are also given an integer <code>shelfWidth</code>.</p>

<p>We want to place these books in order onto bookcase shelves that have a total width <code>shelfWidth</code>.</p>

<p>We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to <code>shelfWidth</code>, then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are no more books to place.</p>

<p>Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.</p>

<ul>
	<li>For example, if we have an ordered list of <code>5</code> books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.</li>
</ul>

<p>Return <em>the minimum possible height that the total bookshelf can be after placing shelves in this manner</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/06/24/shelves.png" style="height: 500px; width: 337px;">
<pre><strong>Input:</strong> books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
<strong>Output:</strong> 6
<strong>Explanation:</strong>
The sum of the heights of the 3 shelves is 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> books = [[1,3],[2,4],[3,2]], shelfWidth = 6
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= books.length &lt;= 1000</code></li>
	<li><code>1 &lt;= thickness<sub>i</sub> &lt;= shelfWidth &lt;= 1000</code></li>
	<li><code>1 &lt;= height<sub>i</sub> &lt;= 1000</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Let `dp[i+1]` be the answer to the subproblem in `A[0..i]`.

```
dp[i+1] = min( dp[j] + max(j, i) | 0 <= j <= i && sum(j, i) <= width )
        where max(j, i) is the maximum height of A[j..i], and sum(j, i) is the sum of width of A[j..i]
dp[0] = 0
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
        int N = A.size(), dp[1001] = {};
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < N; ++i) {
            int sum = 0, mx = 0;
            for (int j = i; j >= 0 && sum + A[j][0] <= W; --j) {
                sum += A[j][0];
                mx = max(mx, A[j][1]);
                dp[i + 1] = min(dp[i + 1], dp[j] + mx);
            }
        }
        return dp[N];
    }
};
```