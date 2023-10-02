# [33. Search in Rotated Sorted Array (Medium)](https://leetcode.com/problems/search-in-rotated-sorted-array)

<p>There is an integer array <code>nums</code> sorted in ascending order (with <strong>distinct</strong> values).</p>
<p>Prior to being passed to your function, <code>nums</code> is <strong>possibly rotated</strong> at an unknown pivot index <code>k</code> (<code>1 &lt;= k &lt; nums.length</code>) such that the resulting array is <code>[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]</code> (<strong>0-indexed</strong>). For example, <code>[0,1,2,4,5,6,7]</code> might be rotated at pivot index <code>3</code> and become <code>[4,5,6,7,0,1,2]</code>.</p>
<p>Given the array <code>nums</code> <strong>after</strong> the possible rotation and an integer <code>target</code>, return <em>the index of </em><code>target</code><em> if it is in </em><code>nums</code><em>, or </em><code>-1</code><em> if it is not in </em><code>nums</code>.</p>
<p>You must write an algorithm with <code>O(log n)</code> runtime complexity.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [4,5,6,7,0,1,2], target = 0
<strong>Output:</strong> 4
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [4,5,6,7,0,1,2], target = 3
<strong>Output:</strong> -1
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1], target = 0
<strong>Output:</strong> -1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li>All values of <code>nums</code> are <strong>unique</strong>.</li>
	<li><code>nums</code> is an ascending array that is possibly rotated.</li>
	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Search in Rotated Sorted Array II (Medium)](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)
* [Find Minimum in Rotated Sorted Array (Medium)](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
* [Pour Water Between Buckets to Make Water Levels Equal (Medium)](https://leetcode.com/problems/pour-water-between-buckets-to-make-water-levels-equal/)

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
        int N = A.size(), L = 0, R = N - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if (A[M] > A[R]) {
                if (target >= A[L] && target < A[M]) R = M - 1;
                else L = M + 1;
            } else {
                if (target > A[M] && target <= A[R]) L = M + 1;
                else R = M - 1;
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