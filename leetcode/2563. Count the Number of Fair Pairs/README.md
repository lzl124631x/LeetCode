# [2563. Count the Number of Fair Pairs (Medium)](https://leetcode.com/problems/count-the-number-of-fair-pairs)

<p>Given a <strong>0-indexed</strong> integer array <code>nums</code> of size <code>n</code> and two integers <code>lower</code> and <code>upper</code>, return <em>the number of fair pairs</em>.</p>
<p>A pair <code>(i, j)</code> is <b>fair </b>if:</p>
<ul>
	<li><code>0 &lt;= i &lt; j &lt; n</code>, and</li>
	<li><code>lower &lt;= nums[i] + nums[j] &lt;= upper</code></li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [0,1,7,4,4,5], lower = 3, upper = 6
<strong>Output:</strong> 6
<strong>Explanation:</strong> There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,7,9,2,5], lower = 11, upper = 11
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is a single fair pair: (2,3).
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums.length == n</code></li>
	<li><code><font face="monospace">-10<sup>9</sup></font>&nbsp;&lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code><font face="monospace">-10<sup>9</sup>&nbsp;&lt;= lower &lt;= upper &lt;= 10<sup>9</sup></font></code></li>
</ul>

**Companies**:
[Salesforce](https://leetcode.com/company/salesforce)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Count of Range Sum (Hard)](https://leetcode.com/problems/count-of-range-sum/)
* [Finding Pairs With a Certain Sum (Medium)](https://leetcode.com/problems/finding-pairs-with-a-certain-sum/)
* [Count Number of Pairs With Absolute Difference K (Easy)](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-the-number-of-fair-pairs
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    long long countFairPairs(vector<int>& A, int lower, int upper) {
        sort(begin(A), end(A));
        long long N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += upper_bound(begin(A) + i + 1, end(A), upper - A[i]) - lower_bound(begin(A) + i + 
1, end(A), lower - A[i]);
        }
        return ans;
    }
};
```