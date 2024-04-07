# [3107. Minimum Operations to Make Median of Array Equal to K (Medium)](https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k)

<p>You are given an integer array <code>nums</code> and a <strong>non-negative</strong> integer <code>k</code>. In one operation, you can increase or decrease any element by 1.</p>

<p>Return the <strong>minimum</strong> number of operations needed to make the <strong><span data-keyword="median-array">median</span></strong> of <code>nums</code> <em>equal</em> to <code>k</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,5,6,8,5], k = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>We can subtract one from <code>nums[1]</code> and <code>nums[4]</code> to obtain <code>[2, 4, 6, 8, 4]</code>. The median of the resulting array is equal to <code>k</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,5,6,8,5], k = 7</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>We can add one to <code>nums[1]</code> twice and add one to <code>nums[2]</code> once to obtain <code>[2, 7, 7, 8, 5]</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3,4,5,6], k = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>The median of the array is already equal to <code>k</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

**Similar Questions**:

- [Find Median from Data Stream (Hard)](https://leetcode.com/problems/find-median-from-data-stream)
- [Sliding Window Median (Hard)](https://leetcode.com/problems/sliding-window-median)

**Hints**:

- Sort <code>nums</code> in non-descending order.
- For all the smaller values on the left side of the median, change them to <code>k</code> if they are larger than <code>k</code>.
- For all the larger values on the right side of the median, change them to <code>k</code> if they are smaller than <code>k</code>.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& A, int k) {
        sort(begin(A), end(A));
        long long N = A.size(), ans = 0, mid = N / 2;
        if (A[mid] >= k) {
            for (int i = mid; i >= 0 && A[i] > k; --i) {
                ans += A[i] - k;
            }
            return ans;
        }
        for (int i = mid; i < N && A[i] < k; ++i) {
            ans += k - A[i];
        }
        return ans;
    }
};
```
