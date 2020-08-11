# [81. Search in Rotated Sorted Array II (Medium)](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

<p>Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.</p>

<p>(i.e., <code>[0,0,1,2,2,5,6]</code> might become <code>[2,5,6,0,0,1,2]</code>).</p>

<p>You are given a target value to search. If found in the array return <code>true</code>, otherwise return <code>false</code>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2<code>,5,6,0,0,1,2]</code>, target = 0
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2<code>,5,6,0,0,1,2]</code>, target = 3
<strong>Output:</strong> false</pre>

<p><strong>Follow up:</strong></p>

<ul>
	<li>This is a follow up problem to&nbsp;<a href="/problems/search-in-rotated-sorted-array/description/">Search in Rotated Sorted Array</a>, where <code>nums</code> may contain duplicates.</li>
	<li>Would this affect the run-time complexity? How and why?</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Search in Rotated Sorted Array (Medium)](https://leetcode.com/problems/search-in-rotated-sorted-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author: github.com/lzl124631x
// Time: average O(logN), worst O(N)
// Space: O(1)
class Solution {
private:
    int findPivot (vector<int> &nums) {
        int L = 0, R = nums.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (nums[M] > nums[R]) L = M + 1;
            else if (nums[M] < nums[R]) R = M;
            else if (nums[M] > nums[L]) break;
            else if (nums[M] < nums[L]) R = M;
            else {
                int LL = L;
                while (L < R && nums[L] == nums[R]) ++L;
                if (L == R) L = LL;
                if (nums[L] > nums[R]) continue;
                break;
            }
        }
        return L;
    }
public:
    bool search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        int N = nums.size(), L = 0, R = N - 1;
        while (L <= R) {
            int M = L + (R - L) / 2;
            int MM = (M + pivot) % N;
            if (target == nums[MM]) return true;
            if (target > nums[MM]) L = M + 1;
            else R = M - 1;
        }
        return false;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author: github.com/lzl124631x
// Time: average O(logN), worst O(N)
// Space: O(1)
class Solution {
public:
    bool search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return true;
            if (A[0] > A[M]) {
                if (target > A[M]) {
                    if (target <= A.back()) L = M + 1;
                    else R = M - 1;
                } else R = M - 1;
            } else if (A[0] < A[M]) {
                if (target > A[M]) L = M + 1;
                else {
                    if (target >= A[0]) R = M - 1; 
                    else L = M + 1;
                }
            } else if (A[L] == target) return true;
            else ++L;
        }
        return false;
    }
};
```

We can compress the code a bit if we want.

```cpp
// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author: github.com/lzl124631x
// Time: average O(logN), worst O(N)
// Space: O(1)
class Solution {
public:
    bool search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target || A[L] == target) return true;
            if (A[0] == A[M]) ++L;
            else if ((A[0] > A[M] && target > A[M] && target <= A.back())
                || (A[0] < A[M] && (target > A[M] || target < A[0]))) L = M + 1;
            else R = M - 1;
        }
        return false;
    }
};
```