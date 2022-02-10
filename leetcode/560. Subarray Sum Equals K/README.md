# [560. Subarray Sum Equals K (Medium)](https://leetcode.com/problems/subarray-sum-equals-k/)

<p>Given an array of integers <code>nums</code> and an integer <code>k</code>, return <em>the total number of continuous subarrays whose sum equals to <code>k</code></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,1], k = 2
<strong>Output:</strong> 2
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3], k = 3
<strong>Output:</strong> 2
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>-10<sup>7</sup> &lt;= k &lt;= 10<sup>7</sup></code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Oracle](https://leetcode.com/company/oracle), [ByteDance](https://leetcode.com/company/bytedance), [Quora](https://leetcode.com/company/quora), [tiktok](https://leetcode.com/company/tiktok), [Microsoft](https://leetcode.com/company/microsoft), [LinkedIn](https://leetcode.com/company/linkedin), [Bloomberg](https://leetcode.com/company/bloomberg), [Apple](https://leetcode.com/company/apple), [Snapchat](https://leetcode.com/company/snapchat), [Expedia](https://leetcode.com/company/expedia), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Tesla](https://leetcode.com/company/tesla), [Paypal](https://leetcode.com/company/paypal), [Visa](https://leetcode.com/company/visa), [DoorDash](https://leetcode.com/company/doordash)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [Continuous Subarray Sum (Medium)](https://leetcode.com/problems/continuous-subarray-sum/)
* [Subarray Product Less Than K (Medium)](https://leetcode.com/problems/subarray-product-less-than-k/)
* [Find Pivot Index (Easy)](https://leetcode.com/problems/find-pivot-index/)
* [Subarray Sums Divisible by K (Medium)](https://leetcode.com/problems/subarray-sums-divisible-by-k/)
* [Minimum Operations to Reduce X to Zero (Medium)](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)
* [K Radius Subarray Averages (Medium)](https://leetcode.com/problems/k-radius-subarray-averages/)

## Solution 1. Prefix State Map

```cpp
// OJ: https://leetcode.com/problems/subarray-sum-equals-k/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        unordered_map<int, int> m{{0, 1}};
        for (int n : nums) {
            sum += n;
            auto it = m.find(sum - k);
            if (it != m.end()) ans += it->second;
            m[sum]++;
        }
        return ans;
    }
};
```