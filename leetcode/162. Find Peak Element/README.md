# [162. Find Peak Element (Medium)](https://leetcode.com/problems/find-peak-element/)

<p>A peak element is an element that is greater than its neighbors.</p>

<p>Given an input array <code>nums</code>, where <code>nums[i] ≠ nums[i+1]</code>, find a peak element and return its index.</p>

<p>The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.</p>

<p>You may imagine that <code>nums[-1] = nums[n] = -∞</code>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> <strong>nums</strong> = <code>[1,2,3,1]</code>
<strong>Output:</strong> 2
<strong>Explanation:</strong> 3 is a peak element and your function should return the index number 2.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> <strong>nums</strong> = <code>[</code>1,2,1,3,5,6,4]
<strong>Output:</strong> 1 or 5 
<strong>Explanation:</strong> Your function can return either index number 1 where the peak element is 2, 
&nbsp;            or index number 5 where the peak element is 6.
</pre>

<p><strong>Follow up:</strong>&nbsp;Your solution should be in logarithmic complexity.</p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Peak Index in a Mountain Array (Easy)](https://leetcode.com/problems/peak-index-in-a-mountain-array/)

## Solution 1. Binary Search (L <= R)

```cpp
// OJ: https://leetcode.com/problems/find-peak-element/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int findPeakElement(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            long M = (L + R) / 2, left = M == 0 ? LONG_MIN : A[M - 1], right = M == A.size() - 1 ? LONG_MIN : A[M + 1];
            if (A[M] > left && A[M] > right) return M;
            if (A[M] < left) R = M - 1;
            else L = M + 1;
        }
        return -1;
    }
};
```

## Solution 2. Binary Search (L < R)

```cpp
// OJ: https://leetcode.com/problems/find-peak-element/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int findPeakElement(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (A[M] > A[M + 1]) R = M;
            else L = M + 1;
        }
        return L;
    }
};
```