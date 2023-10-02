# [229. Majority Element II (Medium)](https://leetcode.com/problems/majority-element-ii)

<p>Given an integer array of size <code>n</code>, find all elements that appear more than <code>⌊ n/3 ⌋</code> times.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,3]
<strong>Output:</strong> [3]
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> [1]
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1,2]
<strong>Output:</strong> [1,2]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>
<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you solve the problem in linear time and in <code>O(1)</code> space?</p>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Sorting](https://leetcode.com/tag/sorting/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Majority Element (Easy)](https://leetcode.com/problems/majority-element/)
* [Check If a Number Is Majority Element in a Sorted Array (Easy)](https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/)
* [Most Frequent Even Element (Easy)](https://leetcode.com/problems/most-frequent-even-element/)

## Solution 1. Boyer-Moore Majority Vote algorithm

```cpp
// OJ: https://leetcode.com/problems/majority-element-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/17564/boyer-moore-majority-vote-algorithm-and-my-elaboration
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0, v1 = 0, v2 = 1;
        for (int n : nums) {
            if (v1 == n) ++c1;
            else if (v2 == n) ++c2;
            else if (!c1) v1 = n, ++c1;
            else if (!c2) v2 = n, ++c2;
            else --c1, --c2;
        }
        c1 = c2 = 0;
        for (int n : nums) {
            if (v1 == n) ++c1;
            if (v2 == n) ++c2;
        }
        vector<int> v;
        if (c1 > nums.size() / 3) v.push_back(v1);
        if (c2 > nums.size() / 3) v.push_back(v2);
        return v;
    }
};
```