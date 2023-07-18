# [2401. Longest Nice Subarray (Medium)](https://leetcode.com/problems/longest-nice-subarray)

<p>You are given an array <code>nums</code> consisting of <strong>positive</strong> integers.</p>
<p>We call a subarray of <code>nums</code> <strong>nice</strong> if the bitwise <strong>AND</strong> of every pair of elements that are in <strong>different</strong> positions in the subarray is equal to <code>0</code>.</p>
<p>Return <em>the length of the <strong>longest</strong> nice subarray</em>.</p>
<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>
<p><strong>Note</strong> that subarrays of length <code>1</code> are always considered nice.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,8,48,10]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3,1,5,11,13]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Paytm](https://leetcode.com/company/paytm)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Longest Substring Without Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
* [Bitwise AND of Numbers Range (Medium)](https://leetcode.com/problems/bitwise-and-of-numbers-range/)
* [Bitwise ORs of Subarrays (Medium)](https://leetcode.com/problems/bitwise-ors-of-subarrays/)
* [Fruit Into Baskets (Medium)](https://leetcode.com/problems/fruit-into-baskets/)
* [Max Consecutive Ones III (Medium)](https://leetcode.com/problems/max-consecutive-ones-iii/)
* [Get Equal Substrings Within Budget (Medium)](https://leetcode.com/problems/get-equal-substrings-within-budget/)
* [Frequency of the Most Frequent Element (Medium)](https://leetcode.com/problems/frequency-of-the-most-frequent-element/)
* [Longest Substring Of All Vowels in Order (Medium)](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/)
* [Maximize the Confusion of an Exam (Medium)](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/)
* [Maximum Sum of Distinct Subarrays With Length K (Medium)](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/)

## Solution 1. Sliding Window

Use the shrinkable template.

```cpp
// OJ: https://leetcode.com/problems/longest-nice-subarray
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestNiceSubarray(vector<int>& A) {
        int cnt[32] = {}, i = 0, j = 0, N = A.size(), ans = 0;
        auto valid = [&]() {
            for (int k = 0; k < 32; ++k) {
                if (cnt[k] > 1) return false;
            }
            return true;
        };
        for (; j < N; ++j) {
            for (int k = 0; k < 32; ++k) {
                cnt[k] += (A[j] >> k & 1);
            }
            while (!valid()) {
                for (int k = 0; k < 32; ++k) {
                    cnt[k] -= (A[i] >> k & 1);
                }
                ++i;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
```

Or use the non-shrinkable template:

```cpp
// OJ: https://leetcode.com/problems/longest-nice-subarray
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestNiceSubarray(vector<int>& A) {
        int cnt[32] = {}, i = 0, j = 0, N = A.size(), ans = 0;
        auto valid = [&]() {
            for (int k = 0; k < 32; ++k) {
                if (cnt[k] > 1) return false;
            }
            return true;
        };
        for (; j < N; ++j) {
            for (int k = 0; k < 32; ++k) {
                cnt[k] += (A[j] >> k & 1);
            }
            if (!valid()) {
                for (int k = 0; k < 32; ++k) {
                    cnt[k] -= (A[i] >> k & 1);
                }
                ++i;
            }
        }
        return j - i;
    }
};
```