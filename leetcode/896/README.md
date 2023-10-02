# [896. Monotonic Array (Easy)](https://leetcode.com/problems/monotonic-array)

<p>An array is <strong>monotonic</strong> if it is either monotone increasing or monotone decreasing.</p>

<p>An array <code>nums</code> is monotone increasing if for all <code>i &lt;= j</code>, <code>nums[i] &lt;= nums[j]</code>. An array <code>nums</code> is monotone decreasing if for all <code>i &lt;= j</code>, <code>nums[i] &gt;= nums[j]</code>.</p>

<p>Given an integer array <code>nums</code>, return <code>true</code><em> if the given array is monotonic, or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,2,3]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [6,5,4,4]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,2]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [TikTok](https://leetcode.com/company/tiktok), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Databricks](https://leetcode.com/company/databricks), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array)

**Similar Questions**:
* [Count Hills and Valleys in an Array (Easy)](https://leetcode.com/problems/count-hills-and-valleys-in-an-array)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/monotonic-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int dir = 0;
        for (int i = 1; i < A.size(); ++i) {
            int d = A[i] == A[i - 1] ? 0 : (A[i] > A[i - 1] ? 1 : -1);
            if (dir && d && dir != d) return false;
            if (d) dir = d;
        }
        return true;
    }
};
```