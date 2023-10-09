# [34. Find First and Last Position of Element in Sorted Array (Medium)](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array)

<p>Given an array of integers <code>nums</code> sorted in non-decreasing order, find the starting and ending position of a given <code>target</code> value.</p>

<p>If <code>target</code> is not found in the array, return <code>[-1, -1]</code>.</p>

<p>You must&nbsp;write an algorithm with&nbsp;<code>O(log n)</code> runtime complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [5,7,7,8,8,10], target = 8
<strong>Output:</strong> [3,4]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [5,7,7,8,8,10], target = 6
<strong>Output:</strong> [-1,-1]
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [], target = 0
<strong>Output:</strong> [-1,-1]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= nums[i]&nbsp;&lt;= 10<sup>9</sup></code></li>
	<li><code>nums</code> is a non-decreasing array.</li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= target&nbsp;&lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[Facebook](https://leetcode.com/company/facebook), [Adobe](https://leetcode.com/company/adobe), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple), [Bloomberg](https://leetcode.com/company/bloomberg), [Oracle](https://leetcode.com/company/oracle), [Microsoft](https://leetcode.com/company/microsoft), [LinkedIn](https://leetcode.com/company/linkedin), [Uber](https://leetcode.com/company/uber), [Intuit](https://leetcode.com/company/intuit), [Qualtrics](https://leetcode.com/company/qualtrics), [Yahoo](https://leetcode.com/company/yahoo), [Nutanix](https://leetcode.com/company/nutanix), [TikTok](https://leetcode.com/company/tiktok), [instacart](https://leetcode.com/company/instacart), [SAP](https://leetcode.com/company/sap), [Samsung](https://leetcode.com/company/samsung)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Binary Search](https://leetcode.com/tag/binary-search)

**Similar Questions**:
* [First Bad Version (Easy)](https://leetcode.com/problems/first-bad-version)
* [Plates Between Candles (Medium)](https://leetcode.com/problems/plates-between-candles)
* [Find Target Indices After Sorting Array (Easy)](https://leetcode.com/problems/find-target-indices-after-sorting-array)

## Solution 1. Binary Search (L <= R)

Pro:
* `M` is always `(L + R) / 2`
* Symmetrical and no-brainer: `L = M + 1` and `R = M - 1`.

Con:
* `L` and `R` might go out of boundary.  
**Solution**: Simply do a out-of-boundary check.
* Need to think about using `L` or `R` in the end.  
**Solution**: Take the first binary search for example, if `A[M] < target`, we move `L`. If `A[M] >= target`, we move `R`. In the end, `L` and `R` will swap order, so `R` will point to the last `A[i] < target`, and `L` will point to the first `A[i] >= target`. Thus, we should use `L` as the left boundary.

```cpp
// OJ: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target) {
        int N = A.size(), L = 0, R = N - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] < target) L = M + 1;
            else R = M - 1;
        }
        if (L == N || A[L] != target) return {-1,-1};
        int left = L;
        R = N - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] > target) R = M - 1;
            else L = M + 1;
        }
        return {left, R};
    }
};
```

## Solution 2. Binary Search (L < R)

Pro:
* In the end, `L` and `R` points to the same position.

Con:
* Need to think about setting `L = M` or `R = M`.
**Solution**: Take the first binary search for example. If `A[M] < target`, we want to move `L` to `M + 1` because `A[M] != target`. If `A[M] >= target`, we want to move `R` to `M`. Since we are using `R = M`, we need to make sure `M != R`, thus we should round down `M` as `(L + R) / 2`.

Now consider the second binary search. If `A[M] > target`, we want to move `R` to `M - 1`. If `A[M] <= target`, we want to move `L` to `M`. Since we are using `L = M`, we need to make sure `M != R`, thus we should round up `M` as `(L + R + 1) / 2`.

Overall, if we do `L = M`, we round up. If we do `R = M`, we round down.

Round up: `(L + R) / 2` or `L + (R - L) / 2`.

Round down: `(L + R + 1) / 2` or `R - (R - L) / 2`.

```cpp
// OJ: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target) {
        if (A.empty()) return {-1,-1};
        int N = A.size(), L = 0, R = N - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (A[M] < target) L = M + 1;
            else R = M;
        }
        if (A[L] != target) return {-1,-1};
        int left = L;
        L = 0, R = N - 1;
        while (L < R) {
            int M = (L + R + 1) / 2;
            if (A[M] > target) R = M - 1;
            else L = M;
        }
        return {left, L};
    }
};
```