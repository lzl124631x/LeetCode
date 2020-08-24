# [1552. Magnetic Force Between Two Balls (Medium)](https://leetcode.com/problems/magnetic-force-between-two-balls/)

<p>In universe Earth&nbsp;C-137, Rick discovered a special form of magnetic force between&nbsp;two balls if they are put in his new invented basket. Rick has&nbsp;<code>n</code> empty baskets, the <code>i<sup>th</sup></code> basket is at <code>position[i]</code>, Morty has <code>m</code> balls and needs to distribute the balls into the baskets such that the <strong>minimum&nbsp;magnetic force</strong>&nbsp;between any two balls is <strong>maximum</strong>.</p>

<p>Rick stated that&nbsp;magnetic force between two different balls at positions <code>x</code> and <code>y</code> is <code>|x - y|</code>.</p>

<p>Given the integer array <code>position</code>&nbsp;and the integer <code>m</code>. Return <em>the required force</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/11/q3v1.jpg" style="width: 562px; height: 195px;">
<pre><strong>Input:</strong> position = [1,2,3,4,7], m = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> position = [5,4,3,2,1,1000000000], m = 2
<strong>Output:</strong> 999999999
<strong>Explanation:</strong> We can use baskets 1 and 1000000000.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == position.length</code></li>
	<li><code>2 &lt;= n &lt;= 10^5</code></li>
	<li><code>1 &lt;= position[i] &lt;= 10^9</code></li>
	<li>All integers in <code>position</code> are <strong>distinct</strong>.</li>
	<li><code>2 &lt;= m &lt;= position.length</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Binary Answer

The range of the answer is `[1, A[N-1] - A[0]]`. We can use binary search to find the maximum valid distance (i.e. force).

We just need to write a function `valid(A, M, m)` to check if we can place the `m` balls with the minimum distance `M`. This is doable with a linear scan -- keep finding the smallest `A[i]` which is greater than or equal to `A[prev] + M` where `prev` is the previously selected busket.

If we can't find `m` buskets with `M` then this `M` is too large, we need to do `R = M - 1`, otherwise, we do `L = M + 1`.

In the end since we are looking for the maximum valid distance, `R` is the answer.

```
// Initially
L                                         R
v                                         v
[      valid      ] [       invalid       ]

// Finally
                  R L
                  v v
[      valid      ] [       invalid       ]
```

```cpp
// OJ: https://leetcode.com/problems/magnetic-force-between-two-balls/
// Author: github.com/lzl124631x
// Time: O(log(max(A)) * N + NlogN)
// Space: O(1)
class Solution {
    bool valid(vector<int> &A, int d, int m) {
        int prev = -1;
        for (int i = 0; i < A.size(); ++i) {
            if (prev != -1 && A[i] - prev < d) continue;
            if (--m == 0) return true;
            prev = A[i];
        }
        return false;
    }
public:
    int maxDistance(vector<int>& A, int m) {
        sort(begin(A), end(A));
        int L = 1, R = A.back() - A[0];
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(A, M, m)) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};
```