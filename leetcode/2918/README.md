# [2918. Minimum Equal Sum of Two Arrays After Replacing Zeros (Medium)](https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros)

<p>You are given two arrays <code>nums1</code> and <code>nums2</code> consisting of positive integers.</p>

<p>You have to replace <strong>all</strong> the <code>0</code>&#39;s in both arrays with <strong>strictly</strong> positive integers such that the sum of elements of both arrays becomes <strong>equal</strong>.</p>

<p>Return <em>the <strong>minimum</strong> equal sum you can obtain, or </em><code>-1</code><em> if it is impossible</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [3,2,0,1,0], nums2 = [6,5,0]
<strong>Output:</strong> 12
<strong>Explanation:</strong> We can replace 0&#39;s in the following way:
- Replace the two 0&#39;s in nums1 with the values 2 and 4. The resulting array is nums1 = [3,2,2,1,4].
- Replace the 0 in nums2 with the value 1. The resulting array is nums2 = [6,5,1].
Both arrays have an equal sum of 12. It can be shown that it is the minimum sum we can obtain.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [2,0,2,0], nums2 = [1,4]
<strong>Output:</strong> -1
<strong>Explanation:</strong> It is impossible to make the sum of both arrays equal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>6</sup></code></li>
</ul>


**Hints**:
* Consider we replace all the 0’s with 1’s on both arrays, the answer will be <code>-1</code> if there was no <code>0</code> in the array with the smaller sum of elements.
* Otherwise, how can you update the value of exactly one of these <code>1</code>’s to make the sum of the two arrays equal?
* Consider we replace all the 0’s with 1’s on both arrays, the answer will be <code>-1</code> if there was no <code>0</code> in the array with the smaller sum of elements.
* Otherwise, how can you update the value of exactly one of these <code>1</code>’s to make the sum of the two arrays equal?

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(1)
class Solution {
public:
    long long minSum(vector<int>& A, vector<int>& B) {
        long long ca = 0, cb = 0, sa = 0, sb = 0, ka = 0, kb = 0;
        for (int n : A) {
            ca += n == 0;
            sa += n;
        }
        for (int n : B){
            cb += n == 0;
            sb += n;
        }
        ka = ca + sa;
        kb = cb + sb;
        if (ka < kb && ca == 0) return -1;
        if (kb < ka && cb == 0) return -1;
        return max(ka, kb);
    }
};
```