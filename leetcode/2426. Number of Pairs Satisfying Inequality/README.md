# [2426. Number of Pairs Satisfying Inequality (Hard)](https://leetcode.com/problems/number-of-pairs-satisfying-inequality)

<p>You are given two <strong>0-indexed</strong> integer arrays <code>nums1</code> and <code>nums2</code>, each of size <code>n</code>, and an integer <code>diff</code>. Find the number of <strong>pairs</strong> <code>(i, j)</code> such that:</p>
<ul>
	<li><code>0 &lt;= i &lt; j &lt;= n - 1</code> <strong>and</strong></li>
	<li><code>nums1[i] - nums1[j] &lt;= nums2[i] - nums2[j] + diff</code>.</li>
</ul>
<p>Return<em> the <strong>number of pairs</strong> that satisfy the conditions.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong>
There are 3 pairs that satisfy the conditions:
1. i = 0, j = 1: 3 - 2 &lt;= 2 - 2 + 1. Since i &lt; j and 1 &lt;= 1, this pair satisfies the conditions.
2. i = 0, j = 2: 3 - 5 &lt;= 2 - 1 + 1. Since i &lt; j and -2 &lt;= 2, this pair satisfies the conditions.
3. i = 1, j = 2: 2 - 5 &lt;= 2 - 1 + 1. Since i &lt; j and -3 &lt;= 2, this pair satisfies the conditions.
Therefore, we return 3.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums1 = [3,-1], nums2 = [-2,2], diff = -1
<strong>Output:</strong> 0
<strong>Explanation:</strong>
Since there does not exist any pair that satisfies the conditions, we return 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums1[i], nums2[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= diff &lt;= 10<sup>4</sup></code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/), [Segment Tree](https://leetcode.com/tag/segment-tree/), [Merge Sort](https://leetcode.com/tag/merge-sort/), [Ordered Set](https://leetcode.com/tag/ordered-set/)

**Similar Questions**:
* [K-diff Pairs in an Array (Medium)](https://leetcode.com/problems/k-diff-pairs-in-an-array/)
* [Count Nice Pairs in an Array (Medium)](https://leetcode.com/problems/count-nice-pairs-in-an-array/)
* [Count Number of Bad Pairs (Medium)](https://leetcode.com/problems/count-number-of-bad-pairs/)

## Solution 1. Merge Sort

```
A[i] - A[j] <= B[i] - B[j] + diff

A[i] - B[i] <= A[j] - B[j] + diff
```

Let `C[i] = A[i] - B[i]`

```
C[i] <= C[j] + diff
```

This is similar to [493. Reverse Pairs (Hard)](https://leetcode.com/problems/reverse-pairs/). We can use Merge Sort (Divide and Conquer) to solve it.

```cpp
// OJ: https://leetcode.com/problems/number-of-pairs-satisfying-inequality
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    long long numberOfPairs(vector<int>& A, vector<int>& B, int diff) {
        long long N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) A[i] -= B[i];
        function<void(int, int)> merge = [&](int start, int end) {
            if (start + 1 >= end) return;
            int mid = (start + end) / 2;
            merge(start, mid);
            merge(mid, end);
            for (int i = start, j = mid, k = start, t = start; k < end; ++k) {
                if (j == end || (i < mid && A[i] <= A[j])) B[k] = A[i++];
                else {
                    while (t < mid && A[t] <= A[j] + diff) ++t;
                    ans += t - start;
                    B[k] = A[j++];
                }
            }
            for (int i = start; i < end; ++i) A[i] = B[i];
        };
        merge(0, N);
        return ans;
    }
};
```