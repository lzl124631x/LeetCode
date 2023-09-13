# [4. Median of Two Sorted Arrays (Hard)](https://leetcode.com/problems/median-of-two-sorted-arrays/)

<p>There are two sorted arrays <b>nums1</b> and <b>nums2</b> of size m and n respectively.</p>

<p>Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).</p>

<p>You may assume <strong>nums1</strong> and <strong>nums2</strong>&nbsp;cannot be both empty.</p>

<p><b>Example 1:</b></p>

<pre>nums1 = [1, 3]
nums2 = [2]

The median is 2.0
</pre>

<p><b>Example 2:</b></p>

<pre>nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
</pre>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Uber](https://leetcode.com/company/uber), [Bloomberg](https://leetcode.com/company/bloomberg), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Facebook](https://leetcode.com/company/facebook), [Rubrik](https://leetcode.com/company/rubrik), [Tencent](https://leetcode.com/company/tencent), [Alibaba](https://leetcode.com/company/alibaba), [VMware](https://leetcode.com/company/vmware)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author: github.com/lzl124631x
// Time: O(log(min(M, N)))
// Space: O(1)
// Ref: https://leetcode.com/problems/median-of-two-sorted-arrays/solution/
// Ref: https://youtu.be/LPFhl65R7ww
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int M = nums1.size(), N = nums2.size(), L = 0, R = M, K = (M + N + 1) / 2;
        while (true) {
            int i = (L + R) / 2, j = K - i;
            if (i < M && nums2[j - 1] > nums1[i]) L = i + 1;
            else if (i > L && nums1[i - 1] > nums2[j]) R = i - 1;
            else {
                int maxLeft = max(i ? nums1[i - 1] : INT_MIN, j ? nums2[j - 1] : INT_MIN);
                if ((M + N) % 2) return maxLeft;
                int minRight = min(i == M ? INT_MAX : nums1[i], j == N ? INT_MAX : nums2[j]);
                return (maxLeft + minRight) / 2.0;
            }
        }
    }
};
```