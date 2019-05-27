# [53. Maximum Subarray (Easy)](https://leetcode.com/problems/maximum-subarray/)

<p>Given an integer array <code>nums</code>, find the contiguous subarray&nbsp;(containing at least one number) which has the largest sum and return its sum.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> [-2,1,-3,4,-1,2,1,-5,4],
<strong>Output:</strong> 6
<strong>Explanation:</strong>&nbsp;[4,-1,2,1] has the largest sum = 6.
</pre>

<p><strong>Follow up:</strong></p>

<p>If you have figured out the O(<em>n</em>) solution, try coding another solution using the divide and conquer approach, which is more subtle.</p>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon), [LinkedIn](https://leetcode.com/company/linkedin), [Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg), [Facebook](https://leetcode.com/company/facebook), [Adobe](https://leetcode.com/company/adobe), [SAP](https://leetcode.com/company/sap), [Oracle](https://leetcode.com/company/oracle), [Paypal](https://leetcode.com/company/paypal), [Cisco](https://leetcode.com/company/cisco), [Intel](https://leetcode.com/company/intel), [Uber](https://leetcode.com/company/uber), [Yahoo](https://leetcode.com/company/yahoo), [Capital One](https://leetcode.com/company/capital-one), [Zillow](https://leetcode.com/company/zillow), [JPMorgan](https://leetcode.com/company/jpmorgan), [Atlassian](https://leetcode.com/company/atlassian), [ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Let `dp[i + 1]` be the sub of maximum subarray ending with `nums[i]`.

```
dp[i + 1] = max{
                dp[i] + A[i],   if dp[i] > 0
                A[i]            if dp[i] <= 0
            }
```

Since `dp[i+1]` is only dependent on `dp[i]`, we can use `O(1)` space to store `dp` array -- only store the last value.

```cpp
// OJ: https://leetcode.com/problems/maximum-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, cur = INT_MIN;
        for (int n : nums) {
            cur = max(cur, 0) + n;
            ans = max(ans, cur);
        }
        return ans;
    }
};
```