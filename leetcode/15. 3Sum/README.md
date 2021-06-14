# [15. 3Sum (Medium)](https://leetcode.com/problems/3sum/)

<p>Given an integer array nums, return all the triplets <code>[nums[i], nums[j], nums[k]]</code> such that <code>i != j</code>, <code>i != k</code>, and <code>j != k</code>, and <code>nums[i] + nums[j] + nums[k] == 0</code>.</p>

<p>Notice that the solution set must not contain duplicate triplets.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [-1,0,1,2,-1,-4]
<strong>Output:</strong> [[-1,-1,2],[-1,0,1]]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = []
<strong>Output:</strong> []
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [0]
<strong>Output:</strong> []
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 3000</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple), [Bloomberg](https://leetcode.com/company/bloomberg), [Uber](https://leetcode.com/company/uber), [Google](https://leetcode.com/company/google), [Yahoo](https://leetcode.com/company/yahoo), [VMware](https://leetcode.com/company/vmware), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Cisco](https://leetcode.com/company/cisco), [Rubrik](https://leetcode.com/company/rubrik), [Salesforce](https://leetcode.com/company/salesforce), [eBay](https://leetcode.com/company/ebay), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [3Sum Closest (Medium)](https://leetcode.com/problems/3sum-closest/)
* [4Sum (Medium)](https://leetcode.com/problems/4sum/)
* [3Sum Smaller (Medium)](https://leetcode.com/problems/3sum-smaller/)

## Solution 1.

Sort the array in ascending order.

Pin the first number as `A[i]`. For the other two numbers, we can use two pointers to scan `A[(i+1)..(N-1)]`, one from `i+1` rightward, one from `N-1` leftward.

```cpp
// OJ: https://leetcode.com/problems/3sum/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        sort(begin(A), end(A));
        vector<vector<int>> ans;
        int N = A.size();
        for (int i = 0; i < N - 2; ++i) {
            if (i && A[i] == A[i - 1]) continue;
            int L = i + 1, R = N - 1;
            while (L < R) {
                int sum = A[i] + A[L] + A[R];
                if (sum == 0) ans.push_back({ A[i], A[L], A[R] });
                if (sum >= 0) {
                    --R;
                    while (L < R && A[R] == A[R + 1]) --R;
                }
                if (sum <= 0) {
                    ++L;
                    while (L < R && A[L] == A[L - 1]) ++L;
                }
            }
        }
        return ans;
    }
};
```