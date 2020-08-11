# [33. Search in Rotated Sorted Array (Medium)](https://leetcode.com/problems/search-in-rotated-sorted-array/)

<p>Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.</p>

<p>(i.e., <code>[0,1,2,4,5,6,7]</code> might become <code>[4,5,6,7,0,1,2]</code>).</p>

<p>You are given a target value to search. If found in the array return its index, otherwise return <code>-1</code>.</p>

<p>You may assume no duplicate exists in the array.</p>

<p>Your algorithm's runtime complexity must be in the order of&nbsp;<em>O</em>(log&nbsp;<em>n</em>).</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [<code>4,5,6,7,0,1,2]</code>, target = 0
<strong>Output:</strong> 4
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [<code>4,5,6,7,0,1,2]</code>, target = 3
<strong>Output:</strong> -1</pre>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Search in Rotated Sorted Array II (Medium)](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)
* [Find Minimum in Rotated Sorted Array (Medium)](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

## Solution 1.

Use the solution to [153. Find Minimum in Rotated Sorted Array (Medium)](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/).

We first find the pivot point, then we can do a normal binary search on `[0, pivot - 1]` or `[pivot, N - 1]`.

```cpp
// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int L = 0, R = nums.size() - 1, pivot;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (nums[M] < nums[R]) R = M;
            else L = M + 1;
        }
        pivot = L;
        if (pivot && target >= nums[0] && target <= nums[pivot - 1]) L = 0, R = pivot - 1;
        else L = pivot, R = nums.size() - 1;
        while (L <= R) {
            int M = L + (R - L) / 2;
            if (nums[M] == target) return M;
            if (target > nums[M]) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};
```

## Solution 2.

Similar to the Solution 1, but we shift the `M` by `pivot` to find the real mid point (need to `% N`).

```cpp
// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
// https://discuss.leetcode.com/topic/3538/concise-o-log-n-binary-search-solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int N = nums.size(), L = 0, R = N - 1, pivot;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (nums[M] < nums[R]) R = M;
            else L = M + 1;
        }
        pivot = L;
        L = 0, R = N - 1;
        while (L <= R) {
            int M = L + (R - L) / 2;
            int MM = (M + pivot) % N;
            if (nums[MM] == target) return MM;
            if (target > nums[MM]) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};
```

## Solution 3.

Let `L = 0, R = N - 1, M = (L + R) / 2`.

* If `A[M] == target`, return `M`
* If `A[M] > A[R]`, the min point in the array is to the right of `A[M]`, we then compare `target` with `A[M]` or `A[L]` to see if we should move `L` or `R`.
* If `A[M] <= A[R]`, the min point in the array is to the left of `A[M]`, we can then compare target with `A[M]` or `A[R]` to see if we should move `L` or `R`.

```cpp
// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int search(vector<int>& A, int target) {
        if (A.empty()) return -1;
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if (A[M] > A[R]) {
                if (target > A[M]) L = M + 1;
                else if (target >= A[L]) R = M - 1;
                else L = M + 1;
            } else {
                if (target > A[M]) {
                    if (target <= A[R]) L = M + 1;
                    else R = M - 1;
                } else R = M - 1;
            }
        }
        return -1;
    }
};
```

We can simplify it by combining the cases.

```cpp
// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if ((A[M] > A[R] && (target > A[M] || target < A[L]))
               || (A[M] <= A[R] && (target > A[M] && target <= A[R]))) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};
```

## Solution 4.

```cpp
// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if (A[0] <= A[M]) {
                if (A[M] < target || target < A[0]) L = M + 1;
                else R = M - 1;
            } else {
                if (target < A[M] || target >= A[0]) R = M - 1;
                else L = M + 1;
            }
        }
        return -1;
    }
};
```

Or simplify the code by combining the cases:

```cpp
// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if ((A[0] <= A[M] && (A[M] < target || target < A[0]))
               || (A[0] > A[M] && target > A[M] && target < A[0])) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};
```