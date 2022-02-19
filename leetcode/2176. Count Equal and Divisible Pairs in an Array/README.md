# [2176. Count Equal and Divisible Pairs in an Array (Easy)](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/)

Given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code> and an integer <code>k</code>, return <em>the <strong>number of pairs</strong></em> <code>(i, j)</code> <em>where</em> <code>0 &lt;= i &lt; j &lt; n</code>, <em>such that</em> <code>nums[i] == nums[j]</code> <em>and</em> <code>(i * j)</code> <em>is divisible by</em> <code>k</code>.
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,1,2,2,2,1,3], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong>
There are 4 pairs that meet all the requirements:
- nums[0] == nums[6], and 0 * 6 == 0, which is divisible by 2.
- nums[2] == nums[3], and 2 * 3 == 6, which is divisible by 2.
- nums[2] == nums[4], and 2 * 4 == 8, which is divisible by 2.
- nums[3] == nums[4], and 3 * 4 == 12, which is divisible by 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4], k = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> Since no value in nums is repeated, there are no pairs (i,j) that meet all the requirements.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 100</code></li>
</ul>


**Similar Questions**:
* [Count Number of Pairs With Absolute Difference K (Easy)](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int countPairs(vector<int>& A, int k) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                ans += A[i] == A[j] && i * j % k == 0;
            }
        }
        return ans;
    }
};
```