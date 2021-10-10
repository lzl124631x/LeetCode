# [2033. Minimum Operations to Make a Uni-Value Grid (Medium)](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/)

<p>You are given a 2D integer <code>grid</code> of size <code>m x n</code> and an integer <code>x</code>. In one operation, you can <strong>add</strong> <code>x</code> to or <strong>subtract</strong> <code>x</code> from any element in the <code>grid</code>.</p>

<p>A <strong>uni-value grid</strong> is a grid where all the elements of it are equal.</p>

<p>Return <em>the <strong>minimum</strong> number of operations to make the grid <strong>uni-value</strong></em>. If it is not possible, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/gridtxt.png" style="width: 164px; height: 165px;">
<pre><strong>Input:</strong> grid = [[2,4],[6,8]], x = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/gridtxt-1.png" style="width: 164px; height: 165px;">
<pre><strong>Input:</strong> grid = [[1,5],[2,3]], x = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> We can make every element equal to 3.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/gridtxt-2.png" style="width: 164px; height: 165px;">
<pre><strong>Input:</strong> grid = [[1,2],[3,4]], x = 2
<strong>Output:</strong> -1
<strong>Explanation:</strong> It is impossible to make every element equal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= x, grid[i][j] &lt;= 10<sup>4</sup></code></li>
</ul>


**Similar Questions**:
* [Minimum Moves to Equal Array Elements II (Medium)](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)

## Solution 1. Left-to-right State Transition

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
// Author: github.com/lzl124631x
// Time: O(NlogN) where `N` is the count of all elements in `A`.
// Space: O(N)
class Solution {
public:
    int minOperations(vector<vector<int>>& A, int x) {
        vector<int> B;
        for (auto &r : A) {
            for (int n : r) B.push_back(n);
        }
        sort(begin(B), end(B));
        long mn = B[0], val = 0;
        for (int i = 0; i < B.size(); ++i) {
            if ((B[i] - mn) % x) return -1;
            val += (B[i] - mn) / x;
        }
        long ans = val;
        for (int i = 1; i < B.size(); ++i) {
            int diff = (B[i] - B[i - 1]) / x;
            val += i * diff - (B.size() - i) * diff;
            ans = min(ans, val);
        }
        return ans;
    }
};
```

## Solution 2. Median Minimizes Sum of Absolute Deviations

Any median minimizes the sum of absolute deviations. ([Reference](https://math.stackexchange.com/questions/113270/the-median-minimizes-the-sum-of-absolute-deviations-the-ell-1-norm))

If the array has odd number of elements, there is only a single median which minimizes the sum of absolute deviations.

If the array has even number of elements, any numbers between (including) the two median numbers minimizes the sum of absolute deviations.

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
// Author: github.com/lzl124631x
// Time: O(NlogN) where `N` is the count of all elements in `A`.
// Space: O(N)
class Solution {
public:
    int minOperations(vector<vector<int>>& A, int x) {
        vector<int> B;
        for (auto &r : A) {
            for (int n : r) B.push_back(n);
        }
        sort(begin(B), end(B));
        int median = B[B.size() / 2], ans = 0;
        for (int i = 0; i < B.size(); ++i) {
            int d = abs(B[i] - median);
            if (d % x) return -1;
            ans += abs(d) / x;
        }
        return ans;
    }
};
```