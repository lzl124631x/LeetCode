# [259. 3Sum Smaller (Medium)](https://leetcode.com/problems/3sum-smaller/)

<p>Given an array of <i>n</i> integers <i>nums</i> and a <i>target</i>, find the number of index triplets <code>i, j, k</code> with <code>0 &lt;= i &lt; j &lt; k &lt; n</code> that satisfy the condition <code>nums[i] + nums[j] + nums[k] &lt; target</code>.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> <i>nums</i> = <code>[-2,0,1,3]</code>, and <i>target</i> = 2
<strong>Output:</strong> 2 
<strong>Explanation:</strong>&nbsp;Because there are two triplets which sums are less than 2:
&nbsp;            [-2,0,1]
             [-2,0,3]
</pre>

<p><b style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;">Follow up:</b> Could you solve it in <i>O</i>(<i>n</i><sup>2</sup>) runtime?</p>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [3Sum (Medium)](https://leetcode.com/problems/3sum/)
* [3Sum Closest (Medium)](https://leetcode.com/problems/3sum-closest/)
* [Valid Triangle Number (Medium)](https://leetcode.com/problems/valid-triangle-number/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/3sum-smaller/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
private:
    int twoSumSmaller(vector<int>& nums, int start, int target) {
        int i = start, j = nums.size() - 1, ans = 0;
        while (i < j) {
            if (nums[i] + nums[j] < target) {
                ans += j - i;
                ++i;
            } else --j;
        }
        return ans;
    }
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int N = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N; ++i) 
            ans += twoSumSmaller(nums, i + 1, target - nums[i]);
        return ans;
    }
};
```