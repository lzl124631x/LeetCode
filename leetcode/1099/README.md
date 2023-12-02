# [1099. Two Sum Less Than K (Easy)](https://leetcode.com/problems/two-sum-less-than-k)

<p>Given an array <code>nums</code> of integers and&nbsp;integer <code>k</code>, return the maximum <code>sum</code> such that there exists <code>i &lt; j</code> with <code>nums[i] + nums[j] = sum</code> and <code>sum &lt; k</code>. If no <code>i</code>, <code>j</code> exist satisfying this equation, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [34,23,1,24,75,33,54,8], k = 60
<strong>Output:</strong> 58
<strong>Explanation: </strong>We can use 34 and 24 to sum 58 which is less than 60.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,20,30], k = 15
<strong>Output:</strong> -1
<strong>Explanation: </strong>In this case it is not possible to get a pair sum less that 15.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 2000</code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Capital One](https://leetcode.com/company/capital-one), [TikTok](https://leetcode.com/company/tiktok), [Facebook](https://leetcode.com/company/facebook), [turing](https://leetcode.com/company/turing)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Two Pointers](https://leetcode.com/tag/two-pointers), [Binary Search](https://leetcode.com/tag/binary-search), [Sorting](https://leetcode.com/tag/sorting)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum)
* [Two Sum II - Input Array Is Sorted (Medium)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted)
* [3Sum Smaller (Medium)](https://leetcode.com/problems/3sum-smaller)
* [Subarray Product Less Than K (Medium)](https://leetcode.com/problems/subarray-product-less-than-k)

**Hints**:
* What if we have the array sorted?
* Loop the array and get the value A[i] then we need to find a value A[j] such that A[i] + A[j] < K  which means A[j] < K - A[i]. In order to do that we can find that value with a binary search.

## Solution 1. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/two-sum-less-than-k/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int i = 0, j = A.size() - 1, ans = INT_MIN;
        while (i < j) {
            int sum = A[i] + A[j];
            if (sum < k) {
                ans = max(ans, sum);
                ++i;
            } else --j;
        }
        return ans == INT_MIN ? -1 : ans;
    }
};
```