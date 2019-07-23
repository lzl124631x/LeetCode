# [674. Longest Continuous Increasing Subsequence (Easy)](https://leetcode.com/problems/longest-continuous-increasing-subsequence/)

<p>
Given an unsorted array of integers, find the length of longest <code>continuous</code> increasing subsequence (subarray).
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [1,3,5,4,7]
<b>Output:</b> 3
<b>Explanation:</b> The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> [2,2,2,2,2]
<b>Output:</b> 1
<b>Explanation:</b> The longest continuous increasing subsequence is [2], its length is 1. 
</pre>
<p></p>

<p><b>Note:</b>
Length of the array will not exceed 10,000.
</p>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Number of Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)
* [Minimum Window Subsequence (Hard)](https://leetcode.com/problems/minimum-window-subsequence/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-continuous-increasing-subsequence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0, len = 0, prev = INT_MAX;
        for (int n : nums) {
            if (n > prev) ++len;
            else len = 1;
            prev = n;
            ans = max(ans, len);
        }
        return ans;
    }
};
```