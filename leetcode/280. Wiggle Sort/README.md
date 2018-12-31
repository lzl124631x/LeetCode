# [280. Wiggle Sort (Medium)](https://leetcode.com/problems/wiggle-sort/)

<p>Given an unsorted array <code>nums</code>, reorder it <b>in-place</b> such that <code>nums[0] &lt;= nums[1] &gt;= nums[2] &lt;= nums[3]...</code>.</p>

<p><b>Example:</b></p>

<pre><b>Input:</b> <code>nums = [3,5,2,1,6,4]</code>
<b>Output:</b> One possible answer is [3,5,1,6,2,4]</pre>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sort](https://leetcode.com/tag/sort/)

**Similar Questions**:
* [Sort Colors (Medium)](https://leetcode.com/problems/sort-colors/)
* [Wiggle Sort II (Medium)](https://leetcode.com/problems/wiggle-sort-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/wiggle-sort/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i + 1 < nums.size(); i += 2) {
            swap(nums[i], nums[i + 1]);
        }
    }
};
```