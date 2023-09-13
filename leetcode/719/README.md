# [719. Find K-th Smallest Pair Distance (Hard)](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)

<p>Given an integer array, return the k-th smallest <b>distance</b> among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B. </p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b>
nums = [1,3,1]
k = 1
<b>Output: 0</b> 
<b>Explanation:</b>
Here are all the pairs:
(1,3) -&gt; 2
(1,1) -&gt; 0
(3,1) -&gt; 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li><code>2 &lt;= len(nums) &lt;= 10000</code>.</li>
<li><code>0 &lt;= nums[i] &lt; 1000000</code>.</li>
<li><code>1 &lt;= k &lt;= len(nums) * (len(nums) - 1) / 2</code>.</li>
</ol>
<p></p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Heap](https://leetcode.com/tag/heap/)

**Similar Questions**:
* [Find K Pairs with Smallest Sums (Medium)](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)
* [Kth Smallest Element in a Sorted Matrix (Medium)](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)
* [Find K Closest Elements (Medium)](https://leetcode.com/problems/find-k-closest-elements/)
* [Kth Smallest Number in Multiplication Table (Hard)](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/)
* [K-th Smallest Prime Fraction (Hard)](https://leetcode.com/problems/k-th-smallest-prime-fraction/)

## Solution 1. Binary Answer

```cpp
// OJ: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
// Author: github.com/lzl124631x
// Time: O(NlogN + NlogNlogD) where D is the distance between the minimal distance and the maximal distance.
// Space: O(1)
class Solution {
    int count(vector<int> &A, int M) {
        int cnt = 0;
        for (int i = 0; i < A.size(); ++i) cnt += upper_bound(begin(A), end(A), A[i] + M) - begin(A) - i - 1;
        return cnt;
    }
public:
    int smallestDistancePair(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int L = INT_MAX, R = A.back() - A[0];
        for (int i = 1; i < A.size(); ++i) L = min(L, A[i] - A[i - 1]);
        while (L <= R) {
            int M = (L + R) / 2, cnt = count(A, M);
            if (cnt < k) L = M + 1;
            else R = M - 1;
        }
        return L;
    }
};
```

## Solution 2.

We can reduce the time complexity of `count` function from `O(NlogN)` to `O(N)`.

```cpp
// OJ: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
// Author: github.com/lzl124631x
// Time: O(NlogN + NlogD) where D is the distance between the minimal distance and the maximal distance.
// Space: O(1)
class Solution {
    int count(vector<int> &A, int M) {
        int cnt = 0, i = 0, j = 0, N = A.size();
        while (i < N) {
            while (j < N && A[j] - A[i] <= M) ++j;
            cnt += j - i - 1;
            ++i;
        }
        return cnt;
    }
public:
    int smallestDistancePair(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int L = INT_MAX, R = A.back() - A[0];
        for (int i = 1; i < A.size(); ++i) L = min(L, A[i] - A[i - 1]);
        while (L <= R) {
            int M = (L + R) / 2, cnt = count(A, M);
            if (cnt < k) L = M + 1;
            else R = M - 1;
        }
        return L;
    }
};
```