# [974. Subarray Sums Divisible by K (Medium)](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

<p>Given an array <code>nums</code> of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by <code>k</code>.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>nums = <span id="example-input-1-1">[4,5,0,-2,-3,1]</span>, k = <span id="example-input-1-2">5</span>
<strong>Output: </strong><span id="example-output-1">7</span>
<strong>Explanation: </strong>There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= nums.length &lt;= 30000</code></li>
	<li><code>-10000 &lt;= nums[i] &lt;= 10000</code></li>
	<li><code>2 &lt;= k &lt;= 10000</code></li>
</ol>
</div>


**Companies**:  
[Twilio](https://leetcode.com/company/twilio), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Subarray Sum Equals K (Medium)](https://leetcode.com/problems/subarray-sum-equals-k/)
* [Make Sum Divisible by P (Medium)](https://leetcode.com/problems/make-sum-divisible-by-p/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/subarray-sums-divisible-by-k/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(K)
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        unordered_map<int, int> m{{0,1}};
        int sum = 0, ans = 0;
        for (int n : A) {
            sum += n;
            if (sum >= 0) sum %= k;
            else sum = (k - (-sum % k)) % k;
            ans += m[sum];
            m[sum]++;
        }
        return ans;
    }
};
```