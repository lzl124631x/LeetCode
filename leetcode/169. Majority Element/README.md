# [169. Majority Element (Easy)](https://leetcode.com/problems/majority-element/)

<p>Given an array of size <i>n</i>, find the majority element. The majority element is the element that appears <b>more than</b> <code>⌊ n/2 ⌋</code> times.</p>

<p>You may assume that the array is non-empty and the majority element always exist in the array.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [3,2,3]
<strong>Output:</strong> 3</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [2,2,1,1,1,2,2]
<strong>Output:</strong> 2
</pre>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/majority-element/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for (int n : nums) {
            if (ans == n) ++cnt;
            else if (cnt > 0) --cnt;
            else {
                ans = n;
                cnt = 1;
            }
        }
        return ans;
    }
};
```