# [560. Subarray Sum Equals K (Medium)](https://leetcode.com/problems/subarray-sum-equals-k/)

<p>Given an array of integers and an integer <b>k</b>, you need to find the total number of continuous subarrays whose sum equals to <b>k</b>.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b>nums = [1,1,1], k = 2
<b>Output:</b> 2
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The length of the array is in range [1, 20,000].</li>
<li>The range of numbers in the array is [-1000, 1000] and the range of the integer <b>k</b> is [-1e7, 1e7].</li>
</ol>
<p></p>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Amazon](https://leetcode.com/company/amazon), [Twilio](https://leetcode.com/company/twilio), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft), [Yandex](https://leetcode.com/company/yandex), [Expedia](https://leetcode.com/company/expedia)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [Continuous Subarray Sum (Medium)](https://leetcode.com/problems/continuous-subarray-sum/)
* [Subarray Product Less Than K (Medium)](https://leetcode.com/problems/subarray-product-less-than-k/)
* [Find Pivot Index (Easy)](https://leetcode.com/problems/find-pivot-index/)
* [Subarray Sums Divisible by K (Medium)](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

## Solution 1.

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