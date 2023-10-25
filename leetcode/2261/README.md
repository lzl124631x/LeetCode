# [2261. K Divisible Elements Subarrays (Medium)](https://leetcode.com/problems/k-divisible-elements-subarrays)

<p>Given an integer array <code>nums</code> and two integers <code>k</code> and <code>p</code>, return <em>the number of <strong>distinct subarrays,</strong> which have <strong>at most</strong></em> <code>k</code> <em>elements </em>that are <em>divisible by</em> <code>p</code>.</p>

<p>Two arrays <code>nums1</code> and <code>nums2</code> are said to be <strong>distinct</strong> if:</p>

<ul>
	<li>They are of <strong>different</strong> lengths, or</li>
	<li>There exists <strong>at least</strong> one index <code>i</code> where <code>nums1[i] != nums2[i]</code>.</li>
</ul>

<p>A <strong>subarray</strong> is defined as a <strong>non-empty</strong> contiguous sequence of elements in an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [<u><strong>2</strong></u>,3,3,<u><strong>2</strong></u>,<u><strong>2</strong></u>], k = 2, p = 2
<strong>Output:</strong> 11
<strong>Explanation:</strong>
The elements at indices 0, 3, and 4 are divisible by p = 2.
The 11 distinct subarrays which have at most k = 2 elements divisible by 2 are:
[2], [2,3], [2,3,3], [2,3,3,2], [3], [3,3], [3,3,2], [3,3,2,2], [3,2], [3,2,2], and [2,2].
Note that the subarrays [2] and [3] occur more than once in nums, but they should each be counted only once.
The subarray [2,3,3,2,2] should not be counted because it has 3 elements that are divisible by 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4], k = 4, p = 1
<strong>Output:</strong> 10
<strong>Explanation:</strong>
All element of nums are divisible by p = 1.
Also, every subarray of nums will have at most 4 elements that are divisible by 1.
Since all subarrays are distinct, the total number of subarrays satisfying all the constraints is 10.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i], p &lt;= 200</code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<p>Can you solve this problem in O(n<sup>2</sup>) time complexity?</p>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Trie](https://leetcode.com/tag/trie), [Rolling Hash](https://leetcode.com/tag/rolling-hash), [Hash Function](https://leetcode.com/tag/hash-function), [Enumeration](https://leetcode.com/tag/enumeration)

**Similar Questions**:
* [Subarrays with K Different Integers (Hard)](https://leetcode.com/problems/subarrays-with-k-different-integers)
* [Count Number of Nice Subarrays (Medium)](https://leetcode.com/problems/count-number-of-nice-subarrays)
* [Subarray With Elements Greater Than Varying Threshold (Hard)](https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold)

**Hints**:
* Enumerate all subarrays and find the ones that satisfy all the conditions.
* Use any suitable method to hash the subarrays to avoid duplicates.

## Solution 1. Fixed Length Sliding Window + Rabin Karp

* Use a fixed-length sliding window to count the number of elements divisible by `p` within the window
* Use Rabin Karp to avoid duplicates subarrays

```cpp
// OJ: https://leetcode.com/problems/k-divisible-elements-subarrays
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int countDistinct(vector<int>& A, int k, int p) {
        int N = A.size(), ans = 0;
        for (int len = 1; len <= N; ++len) {
            unsigned long long cnt = 0, pow = 1, h = 0, d = 1099511628211;
            unordered_set<unsigned long long> seen;
            for (int i = 0; i < N; ++i) {
                if (i < len) pow *= d;
                h = h * d + A[i];
                cnt += A[i] % p == 0;
                if (i - len >= 0) {
                    cnt -= A[i - len] % p == 0;
                    h -= pow * A[i - len];
                }
                if (i >= len - 1 && cnt <= k && seen.count(h) == 0) {
                    ++ans;
                    seen.insert(h);
                }
            }
        }
        return ans;
    }
};
```