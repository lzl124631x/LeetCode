# [16. 3Sum Closest (Medium)](https://leetcode.com/problems/3sum-closest/)

<p>Given an array <code>nums</code> of <em>n</em> integers and an integer <code>target</code>, find three integers in <code>nums</code>&nbsp;such that the sum is closest to&nbsp;<code>target</code>. Return the sum of the three integers. You may assume that each input would have exactly one solution.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [-1,2,1,-4], target = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong> The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10^3</code></li>
	<li><code>-10^3&nbsp;&lt;= nums[i]&nbsp;&lt;= 10^3</code></li>
	<li><code>-10^4&nbsp;&lt;= target&nbsp;&lt;= 10^4</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Adobe](https://leetcode.com/company/adobe), [Uber](https://leetcode.com/company/uber), [Google](https://leetcode.com/company/google), [Capital One](https://leetcode.com/company/capital-one)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [3Sum (Medium)](https://leetcode.com/problems/3sum/)
* [3Sum Smaller (Medium)](https://leetcode.com/problems/3sum-smaller/)

## Solution 1. Two pointers

```cpp
// OJ: https://leetcode.com/problems/3sum-closest/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& A, int target) {
        sort(begin(A), end(A));
        int N = A.size(), ans = A[0] + A[1] + A[2];
        for (int i = 0; i < N - 2; ++i) {
            int L = i + 1, R = N - 1;
            while (L < R) {
                long sum = A[L] + A[R] + A[i];
                if (abs(sum - target) < abs(ans - target)) ans = sum;
                if (sum == target) return target;
                if (sum > target) --R;
                else ++L;
            }
        }
        return ans;
    }
};
```