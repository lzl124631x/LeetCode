# [658. Find K Closest Elements (Medium)](https://leetcode.com/problems/find-k-closest-elements/)

<p>Given a <strong>sorted</strong> integer array <code>arr</code>, two integers <code>k</code> and <code>x</code>, return the <code>k</code> closest integers to <code>x</code> in the array. The result should also be sorted in ascending order.</p>

<p>An integer <code>a</code> is closer to <code>x</code> than an integer <code>b</code> if:</p>

<ul>
	<li><code>|a - x| &lt; |b - x|</code>, or</li>
	<li><code>|a - x| == |b - x|</code> and <code>a &lt; b</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> arr = [1,2,3,4,5], k = 4, x = 3
<strong>Output:</strong> [1,2,3,4]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> arr = [1,2,3,4,5], k = 4, x = -1
<strong>Output:</strong> [1,2,3,4]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= arr.length</code></li>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>4</sup></code></li>
	<li><code>arr</code> is sorted in <strong>ascending</strong> order.</li>
	<li><code>-10<sup>4</sup> &lt;= arr[i], x &lt;= 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Guess Number Higher or Lower (Easy)](https://leetcode.com/problems/guess-number-higher-or-lower/)
* [Guess Number Higher or Lower II (Medium)](https://leetcode.com/problems/guess-number-higher-or-lower-ii/)
* [Find K-th Smallest Pair Distance (Hard)](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-k-closest-elements/
// Author: github.com/lzl124631x
// Time: O(logN + K)
// Space: O(1)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int N = A.size(), j = lower_bound(begin(A), end(A), x) - begin(A), i = j - 1;
        while (j - i - 1 < k) {
            if (i == -1 || (j < N && abs(A[j] - x) < abs(A[i] - x))) ++j;
            else --i;
        }
        return vector<int>(begin(A) + i + 1, begin(A) + j);
    }
};
```

## Solution 2. Binary Search Left Edge (L < R)

Binary Search (L <= R) doesn't fit this problem because `L` and `R` might go out of boundary.

We binary search the left edge.

```cpp
// OJ: https://leetcode.com/problems/find-k-closest-elements/
// Author: github.com/lzl124631x
// Time: O(log(N - k) + k)
// Space: O(1)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int L = 0, R = A.size() - k;
        while (L < R) {
            int M = (L + R) / 2;
            if (x - A[M] > A[M + k] - x) L = M + 1;
            else R = M;
        }
        return vector<int>(begin(A) + R, begin(A) + R + k);
    }
};
```