# [2733. Neither Minimum nor Maximum (Easy)](https://leetcode.com/problems/neither-minimum-nor-maximum)

<p>Given an integer array <code>nums</code> containing <strong>distinct</strong> <strong>positive</strong> integers, find and return <strong>any</strong> number from the array that is neither the <strong>minimum</strong> nor the <strong>maximum</strong> value in the array, or <strong><code>-1</code></strong> if there is no such number.</p>
<p>Return <em>the selected integer.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,1,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> In this example, the minimum value is 1 and the maximum value is 4. Therefore, either 2 or 3 can be valid answers.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,2]
<strong>Output:</strong> -1
<strong>Explanation:</strong> Since there is no number in nums that is neither the maximum nor the minimum, we cannot select a number that satisfies the given condition. Therefore, there is no answer.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [2,1,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Since 2 is neither the maximum nor the minimum value in nums, it is the only valid answer. 
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li>All values in <code>nums</code> are distinct</li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Third Maximum Number (Easy)](https://leetcode.com/problems/third-maximum-number/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/neither-minimum-nor-maximum
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findNonMinOrMax(vector<int>& A) {
        int mn = *min_element(begin(A), end(A)), mx = *max_element(begin(A), end(A));
        if (mn == mx) return -1;
        for (int n : A) {
            if (n != mn && n != mx) return n;
        }
        return -1;
    }
};
```