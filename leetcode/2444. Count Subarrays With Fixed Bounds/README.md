# [2444. Count Subarrays With Fixed Bounds (Hard)](https://leetcode.com/problems/count-subarrays-with-fixed-bounds)

<p>You are given an integer array <code>nums</code> and two integers <code>minK</code> and <code>maxK</code>.</p>
<p>A <strong>fixed-bound subarray</strong> of <code>nums</code> is a subarray that satisfies the following conditions:</p>
<ul>
	<li>The <strong>minimum</strong> value in the subarray is equal to <code>minK</code>.</li>
	<li>The <strong>maximum</strong> value in the subarray is equal to <code>maxK</code>.</li>
</ul>
<p>Return <em>the <strong>number</strong> of fixed-bound subarrays</em>.</p>
<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,5,2,7,5], minK = 1, maxK = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,1,1], minK = 1, maxK = 1
<strong>Output:</strong> 10
<strong>Explanation:</strong> Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], minK, maxK &lt;= 10<sup>6</sup></code></li>
</ul>

**Companies**:
[MathWorks](https://leetcode.com/company/mathworks), [DoorDash](https://leetcode.com/company/doordash), [Oracle](https://leetcode.com/company/oracle)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Queue](https://leetcode.com/tag/queue/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Monotonic Queue](https://leetcode.com/tag/monotonic-queue/)

**Similar Questions**:
* [Count Number of Nice Subarrays (Medium)](https://leetcode.com/problems/count-number-of-nice-subarrays/)
* [Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit (Medium)](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

## Solution 1. Find Minimum Sliding Window

```cpp
// OJ: https://leetcode.com/problems/count-subarrays-with-fixed-bounds
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& A, int minK, int maxK) {
        long long N = A.size(), ans = 0, i = 0;
        auto count = [&](int start, int end) {
            int mn = 0, mx = 0, valid = 0;
            for (int i = start, j = start; j < end; ++j) {
                mx += A[j] == maxK;
                mn += A[j] == minK;
                valid = valid || (mx && mn);
                while (mx && mn) {
                    mx -= A[i] == maxK;
                    mn -= A[i] == minK;
                    ++i;
                }
                if (valid) ans += i - start;
            }
        };
        for (; i < N; ++i) {
            if (A[i] < minK || A[i] > maxK) continue;
            int j = i;
            while (j < N && A[j] >= minK && A[j] <= maxK) ++j;
            count(i, j);
            i = j;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/count-subarrays-with-fixed-bounds
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& A, int minK, int maxK) {
        long long N = A.size(), ans = 0, left = -1, mnPos = -1, mxPos = -1;
        for (int i = 0; i < N; ++i) {
            if (A[i] < minK || A[i] > maxK) {
                left = i;
                continue;
            }
            if (A[i] == minK) mnPos = i;
            if (A[i] == maxK) mxPos = i;
            ans += max(0LL, min(mxPos, mnPos) - left);
        }
        return ans;
    }
};
```