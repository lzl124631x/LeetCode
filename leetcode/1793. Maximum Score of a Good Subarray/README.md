# [1793. Maximum Score of a Good Subarray (Hard)](https://leetcode.com/problems/maximum-score-of-a-good-subarray/)

<p>You are given an array of integers <code>nums</code> <strong>(0-indexed)</strong> and an integer <code>k</code>.</p>

<p>The <strong>score</strong> of a subarray <code>(i, j)</code> is defined as <code>min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1)</code>. A <strong>good</strong> subarray is a subarray where <code>i &lt;= k &lt;= j</code>.</p>

<p>Return <em>the maximum possible <strong>score</strong> of a <strong>good</strong> subarray.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,4,3,7,4,5], k = 3
<strong>Output:</strong> 15
<strong>Explanation:</strong> The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15. 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,5,4,5,4,1,1,1], k = 0
<strong>Output:</strong> 20
<strong>Explanation:</strong> The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= k &lt; nums.length</code></li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Largest Rectangle in Histogram (Hard)](https://leetcode.com/problems/largest-rectangle-in-histogram/)

## Solution 1. Greedy + Two Pointers


Use a window `[i + 1, j - 1]` starting from `[k, k]` and extend it to the length of `A`.

The length of the window will mono-increase with the same amount = 1 in either direction, so we just always pick the direction which has a greater min value.

If `lmin == rmin`, extending either direction is fine. Assume we keep extending leftwards until `lmin != rmin`, and in this case `lmin` must be `< rmin`, so our algorithm will start to extend rightwards.

```cpp
// OJ: https://leetcode.com/contest/weekly-contest-232/problems/maximum-score-of-a-good-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumScore(vector<int>& A, int k) {
        int i = k - 1, j = k + 1, N = A.size(), ans = A[k], mn = A[k];  // `i` and `j` point to the next left and right element to extend, respectively. `mn` is the min value within window `[i + 1, j - 1]`.
        for (int len = 2; len <= N; ++len) {
            int lmin = min(mn, i >= 0 ? A[i] : 0); // if extending leftwards, the new min value is lmin
            int rmin = min(mn, j < N ? A[j] : 0); // if extending rightwards, the new min value is rmin
            if (lmin >= rmin) --i; // extending leftwards is as good as or better than extending rightwards.
            else ++j;
            mn = max(lmin, rmin);
            ans = max(ans, mn * len);
        }
        return ans;
    }
};
```