# [2537. Count the Number of Good Subarrays (Medium)](https://leetcode.com/problems/count-the-number-of-good-subarrays)

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the number of <strong>good</strong> subarrays of</em> <code>nums</code>.</p>
<p>A subarray <code>arr</code> is <strong>good</strong> if it there are <strong>at least </strong><code>k</code> pairs of indices <code>(i, j)</code> such that <code>i &lt; j</code> and <code>arr[i] == arr[j]</code>.</p>
<p>A <strong>subarray</strong> is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,1,1,1], k = 10
<strong>Output:</strong> 1
<strong>Explanation:</strong> The only good subarray is the array nums itself.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3,1,4,3,2,2,4], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 10<sup>9</sup></code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Count Number of Homogenous Substrings (Medium)](https://leetcode.com/problems/count-number-of-homogenous-substrings/)
* [Maximum Sum of Distinct Subarrays With Length K (Medium)](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/)

## Solution 1. Find Minimum Sliding Window

```cpp
// OJ: https://leetcode.com/problems/count-the-number-of-good-subarrays
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long countGood(vector<int>& A, int k) {
        unordered_map<int, int> cnt;
        long long N = A.size(), ans = 0, sum = 0, valid = 0;
        for (int i = 0, j = 0; j < N; ++j) {
            sum += cnt[A[j]]++;
            valid = valid || sum >= k;
            while (sum >= k) sum -= --cnt[A[i++]]; // shift the left edge until the window becomes invalid
            if (valid) ans += i; // once the window has ever became valid, 0~(i-1) can be used as the starting point of a valid subarray
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/count-the-number-of-good-subarrays
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long countGood(vector<int>& A, int k) {
        unordered_map<int, int> cnt;
        long long N = A.size(), ans = 0, sum = 0;
        for (int i = 0, j = 0; i < N; ++i) {
            while (j < N && sum < k) {
                sum += cnt[A[j++]]++;
            }
            if (sum < k) break;
            ans += N - j + 1;
            sum -= --cnt[A[i]];
        }
        return ans;
    }
};
```