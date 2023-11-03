# [2909. Minimum Sum of Mountain Triplets II (Medium)](https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii)

<p>You are given a <strong>0-indexed</strong> array <code>nums</code> of integers.</p>

<p>A triplet of indices <code>(i, j, k)</code> is a <strong>mountain</strong> if:</p>

<ul>
	<li><code>i &lt; j &lt; k</code></li>
	<li><code>nums[i] &lt; nums[j]</code> and <code>nums[k] &lt; nums[j]</code></li>
</ul>

<p>Return <em>the <strong>minimum possible sum</strong> of a mountain triplet of</em> <code>nums</code>. <em>If no such triplet exists, return</em> <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [8,6,1,5,3]
<strong>Output:</strong> 9
<strong>Explanation:</strong> Triplet (2, 3, 4) is a mountain triplet of sum 9 since: 
- 2 &lt; 3 &lt; 4
- nums[2] &lt; nums[3] and nums[4] &lt; nums[3]
And the sum of this triplet is nums[2] + nums[3] + nums[4] = 9. It can be shown that there are no mountain triplets with a sum of less than 9.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,4,8,7,10,2]
<strong>Output:</strong> 13
<strong>Explanation:</strong> Triplet (1, 3, 5) is a mountain triplet of sum 13 since: 
- 1 &lt; 3 &lt; 5
- nums[1] &lt; nums[3] and nums[5] &lt; nums[3]
And the sum of this triplet is nums[1] + nums[3] + nums[5] = 13. It can be shown that there are no mountain triplets with a sum of less than 13.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [6,5,4,3,4,5]
<strong>Output:</strong> -1
<strong>Explanation:</strong> It can be shown that there are no mountain triplets in nums.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>8</sup></code></li>
</ul>


**Companies**:
[ION](https://leetcode.com/company/ion-2)

**Related Topics**:  
[Array](https://leetcode.com/tag/array)

**Similar Questions**:
* [3Sum (Medium)](https://leetcode.com/problems/3sum)
* [Maximum Value of an Ordered Triplet II (Medium)](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii)

**Hints**:
* If you fix index <code>j</code>, <code>i</code> will be the smallest integer to the left of <code>j</code>, and <code>k</code> the largest integer to the right of <code>j</code>.
* To find <code>i</code> and <code>k</code>, preprocess the prefix minimum array <code>prefix_min[i] = min(nums[0], nums[1], ..., nums[i])</code>, and the suffix minimum array <code>suffix_min[i] = min(nums[i], nums[i + 1], ..., nums[i - 1])</code>.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minimumSum(vector<int>& A) {
        int N = A.size(), minLeft = INT_MAX, ans = INT_MAX;
        vector<int> minRight(N, INT_MAX);
        for (int i = N - 2; i >= 0; --i) minRight[i] = min(minRight[i + 1], A[i + 1]);
        for (int i = 1; i < N - 1; ++i) {
            minLeft = min(minLeft, A[i - 1]);
            if (minLeft < A[i] && minRight[i] < A[i]) ans = min(ans, minLeft + minRight[i] + A[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```