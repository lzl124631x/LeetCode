# [209. Minimum Size Subarray Sum (Medium)](https://leetcode.com/problems/minimum-size-subarray-sum/)

<p>Given an array of <strong>n</strong> positive integers and a positive integer <strong>s</strong>, find the minimal length of a <b>contiguous</b> subarray of which the sum ≥ <strong>s</strong>. If there isn't one, return 0 instead.</p>

<p><strong>Example:&nbsp;</strong></p>

<pre><strong>Input:</strong> <code>s = 7, nums = [2,3,1,2,4,3]</code>
<strong>Output:</strong> 2
<strong>Explanation: </strong>the subarray <code>[4,3]</code> has the minimal length under the problem constraint.</pre>

<div class="spoilers"><b>Follow up:</b></div>

<div class="spoilers">If you have figured out the <i>O</i>(<i>n</i>) solution, try coding another solution of which the time complexity is <i>O</i>(<i>n</i> log <i>n</i>).&nbsp;</div>


**Companies**:  
[Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Minimum Window Substring (Hard)](https://leetcode.com/problems/minimum-window-substring/)
* [Maximum Size Subarray Sum Equals k (Medium)](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/)
* [Maximum Length of Repeated Subarray (Medium)](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)

## Solution 1. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/minimum-size-subarray-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, i = 0, j = 0, N = nums.size(), ans = INT_MAX;
        while (j < N) {
            while (j < N && sum < s) sum += nums[j++];
            if (sum < s) break;
            while (i < j && sum >= s) sum -= nums[i++];
            ans = min(ans, j - i + 1);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
```