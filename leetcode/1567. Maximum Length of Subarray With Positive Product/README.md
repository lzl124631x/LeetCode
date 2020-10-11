# [1567. Maximum Length of Subarray With Positive Product (Medium)](https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/)

<p>Given an array of integers&nbsp;<code>nums, find</code>&nbsp;the maximum length of a subarray where the product of all its elements is positive.</p>

<p>A subarray of an array is a consecutive sequence of zero or more values taken out of that array.</p>

<p>Return&nbsp;<em>the maximum length of a subarray with positive product</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,-2,-3,4]
<strong>Output:</strong> 4
<strong>Explanation: </strong>The array nums already has a positive product of 24.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,-2,-3,-4]
<strong>Output:</strong> 3
<strong>Explanation: </strong>The longest subarray with positive product is [1,-2,-3] which has a product of 6.
Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [-1,-2,-3,0,1]
<strong>Output:</strong> 2
<strong>Explanation: </strong>The longest subarray with positive product is [-1,-2] or [-2,-3].
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [-1,2]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,5,-6,4,0,10]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>-10^9 &lt;= nums[i]&nbsp;&lt;= 10^9</code></li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

* We shouldn't include `0` in the subarray. So we just handle each of the subarrays surrounded by `0`s.
* If there are even number of negative numbers in the subarray, the entire subarray has a positive product.
* If there are odd number of negative numbers in the subarray, we have two candidates:
    1. From the first element of the subarray to the element before the last negative element
    2. From the next element of first negative element to the last element of the subarray.

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int getMaxLen(vector<int>& A) {
        int j = 0, N = A.size(), ans = 0;
        while (j < N) {
            int i = j, cnt = 0, first = -1, last;
            for (; j < N && A[j] != 0; ++j) {
                cnt += A[j] < 0;
                if (A[j] < 0) {
                    if (first == -1) first = j;
                    last = j;
                }
            }
            if (cnt % 2) ans = max({ ans, j - first - 1, last - i });
            else ans = max(ans, j - i);
            while (j < N && A[j] == 0) ++j;
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int getMaxLen(vector<int>& A) {
        int N = A.size(), i = 0, ans = 0;
        while (i < N) {
            while (i < N && A[i] == 0) ++i;
            if (i == N) break;
            int start = i, cnt = 0, first = -1;
            for (; i < N && A[i] != 0; ++i) {
                cnt += A[i] < 0;
                if (A[i] < 0 && first == -1) first = i; 
                if (cnt % 2 == 0) ans = max(ans, i - start + 1);
                else ans = max(ans, i - first);
            }
        }
        return ans;
    }
};
```

## Note

Similar problem: [152. Maximum Product Subarray (Medium)](https://leetcode.com/problems/maximum-product-subarray/)