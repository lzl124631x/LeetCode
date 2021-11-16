# [668. Kth Smallest Number in Multiplication Table (Hard)](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/)

<p>Nearly everyone has used the <a href="https://en.wikipedia.org/wiki/Multiplication_table" target="_blank">Multiplication Table</a>. The multiplication table of size <code>m x n</code> is an integer matrix <code>mat</code> where <code>mat[i][j] == i * j</code> (<strong>1-indexed</strong>).</p>

<p>Given three integers <code>m</code>, <code>n</code>, and <code>k</code>, return <em>the </em><code>k<sup>th</sup></code><em> smallest element in the </em><code>m x n</code><em> multiplication table</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/02/multtable1-grid.jpg" style="width: 500px; height: 254px;">
<pre><strong>Input:</strong> m = 3, n = 3, k = 5
<strong>Output:</strong> 3
<strong>Explanation:</strong> The 5<sup>th</sup> smallest number is 3.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/02/multtable2-grid.jpg" style="width: 493px; height: 293px;">
<pre><strong>Input:</strong> m = 2, n = 3, k = 6
<strong>Output:</strong> 6
<strong>Explanation:</strong> The 6<sup>th</sup> smallest number is 6.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= m * n</code></li>
</ul>


**Companies**:  
[Rubrik](https://leetcode.com/company/rubrik)

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Kth Smallest Element in a Sorted Matrix (Medium)](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)
* [Find K-th Smallest Pair Distance (Hard)](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)
* [K-th Smallest Prime Fraction (Hard)](https://leetcode.com/problems/k-th-smallest-prime-fraction/)
## Solution 1. Binary Answer

The range of the answer is `[1, m * n]`. We can use binary answer to find it.

Let `L = 1, R = m * n, M = (L + R) / 2`.

Define `cnt(M)` as the count of numbers less than or equal to `M`.

For the answer `ans`, the corresponding `cnt(ans)` could be exactly `k` (when there is only one `ans` in the table) or greater than `k` (when there are multiple `ans` in the table).

The goal is to find the first element `M` whose `cnt(M)` is greater than or equal to `k`.

So let the left part of the array be those elements whose `cnt < k`, and the right part be `cnt >= k`.

In the end, `L` will point to the first element whose `cnt >= k` and it is the answer.

```cpp
// OJ: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
// Author: github.com/lzl124631x
// Time: O(Mlog(MN))
// Space: O(1)
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int L = 1, R = m * n;
        auto valid = [&](int num) {
            int cnt = 0, last = min(m, num);  // count the numbers that are less than or equal to `num`
            for (int i = 1; i <= last; ++i) cnt += min(num / i, n);
            return cnt >= k;
        };
        while (L <= R) {
            int M = L + (R - L) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
```

Or use `L < R` template

```cpp
// OJ: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
// Author: github.com/lzl124631x
// Time: O(Mlog(MN))
// Space: O(1)
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int L = 1, R = m * n;
        auto valid = [&](int num) { 
            int cnt = 0, last = min(m, num);// count the numbers that are less than or equal to `num`
            for (int i = 1; i <= last; ++i) cnt += min(num / i, n);
            return cnt >= k;
        };
        while (L < R) {
            int M = L + (R - L) / 2;
            if (valid(M)) R = M;
            else L = M + 1;
        }
        return L;
    }
};
```