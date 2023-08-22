# [2824. Count Pairs Whose Sum is Less than Target (Easy)](https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target)

<strong>0-indexed</strong>
<code>nums</code>
<code>n</code>
<code>target</code>
<em>the number of pairs</em>
<code>(i, j)</code>
<em>where</em>
<code>0 &lt;= i &lt; j &lt; n</code>
<em>and</em>
<code>nums[i] + nums[j] &lt; target</code>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [-1,1,2,3,1], target = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 pairs of indices that satisfy the conditions in the statement:
- (0, 1) since 0 &lt; 1 and nums[0] + nums[1] = 0 &lt; target
- (0, 2) since 0 &lt; 2 and nums[0] + nums[2] = 1 &lt; target 
- (0, 4) since 0 &lt; 4 and nums[0] + nums[4] = 0 &lt; target
Note that (0, 3) is not counted since nums[0] + nums[3] is not strictly less than the target.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [-6,2,5,-2,-7,-1,3], target = -2
<strong>Output:</strong> 10
<strong>Explanation:</strong> There are 10 pairs of indices that satisfy the conditions in the statement:
- (0, 1) since 0 &lt; 1 and nums[0] + nums[1] = -4 &lt; target
- (0, 3) since 0 &lt; 3 and nums[0] + nums[3] = -8 &lt; target
- (0, 4) since 0 &lt; 4 and nums[0] + nums[4] = -13 &lt; target
- (0, 5) since 0 &lt; 5 and nums[0] + nums[5] = -7 &lt; target
- (0, 6) since 0 &lt; 6 and nums[0] + nums[6] = -3 &lt; target
- (1, 4) since 1 &lt; 4 and nums[1] + nums[4] = -5 &lt; target
- (3, 4) since 3 &lt; 4 and nums[3] + nums[4] = -9 &lt; target
- (3, 5) since 3 &lt; 5 and nums[3] + nums[5] = -3 &lt; target
- (4, 5) since 4 &lt; 5 and nums[4] + nums[5] = -8 &lt; target
- (4, 6) since 4 &lt; 6 and nums[4] + nums[6] = -4 &lt; target
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length == n &lt;= 50</code></li>
	<li><code>-50 &lt;= nums[i], target &lt;= 50</code></li>
</ul>

**Companies**:
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [Count the Number of Fair Pairs (Medium)](https://leetcode.com/problems/count-the-number-of-fair-pairs/)

## Solution 1. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int countPairs(vector<int>& A, int target) {
        sort(begin(A), end(A));
        int ans = 0, N = A.size();
        for (int i = 0, j = N - 1; i < j;) {
            if (A[i] + A[j] < target) {
                ans += j - i;
                ++i;
            } else --j;
        }
        return ans;
    }
};
```