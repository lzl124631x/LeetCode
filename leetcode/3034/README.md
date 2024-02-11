# [3034. Number of Subarrays That Match a Pattern I (Medium)](https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of size <code>n</code>, and a <strong>0-indexed</strong> integer array <code>pattern</code> of size <code>m</code> consisting of integers <code>-1</code>, <code>0</code>, and <code>1</code>.</p>

<p>A <span data-keyword="subarray">subarray</span> <code>nums[i..j]</code> of size <code>m + 1</code> is said to match the <code>pattern</code> if the following conditions hold for each element <code>pattern[k]</code>:</p>

<ul>
	<li><code>nums[i + k + 1] &gt; nums[i + k]</code> if <code>pattern[k] == 1</code>.</li>
	<li><code>nums[i + k + 1] == nums[i + k]</code> if <code>pattern[k] == 0</code>.</li>
	<li><code>nums[i + k + 1] &lt; nums[i + k]</code> if <code>pattern[k] == -1</code>.</li>
</ul>

<p>Return <em>the<strong> count</strong> of subarrays in</em> <code>nums</code> <em>that match the</em> <code>pattern</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4,5,6], pattern = [1,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The pattern [1,1] indicates that we are looking for strictly increasing subarrays of size 3. In the array nums, the subarrays [1,2,3], [2,3,4], [3,4,5], and [4,5,6] match this pattern.
Hence, there are 4 subarrays in nums that match the pattern.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,4,4,1,3,5,5,3], pattern = [1,0,-1]
<strong>Output:</strong> 2
<strong>Explanation: </strong>Here, the pattern [1,0,-1] indicates that we are looking for a sequence where the first number is smaller than the second, the second is equal to the third, and the third is greater than the fourth. In the array nums, the subarrays [1,4,4,1], and [3,5,5,3] match this pattern.
Hence, there are 2 subarrays in nums that match the pattern.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n == nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= m == pattern.length &lt; n</code></li>
	<li><code>-1 &lt;= pattern[i] &lt;= 1</code></li>
</ul>


**Similar Questions**:
* [Count the Number of Incremovable Subarrays I (Easy)](https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i)

**Hints**:
* Iterate over all indices <code>i</code> then, using a second loop, check if the subarray starting at index <code>i</code> matches the pattern.

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i
// Author: github.com/lzl124631x
// Time: O((N - M - 1) * M)
// Space: O(1)
class Solution {
public:
    int countMatchingSubarrays(vector<int>& A, vector<int>& P) {
        int ans = 0, N = A.size(), M = P.size();
        for (int i = 0; i < N - M; ++i) {
            int prev = A[i], j = 0;
            for (int ; j < M; ++j) {
                if (P[j] == 1 && A[i + j + 1] <= A[i + j]) break;
                if (P[j] == 0 && A[i + j + 1] != A[i + j]) break;
                if (P[j] == -1 && A[i + j + 1] >= A[i + j]) break;
            }
            ans += j == M;
        }
        return ans;
    }
};
```
