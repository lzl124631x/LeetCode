# [2552. Count Increasing Quadruplets (Hard)](https://leetcode.com/problems/count-increasing-quadruplets)

<p>Given a <strong>0-indexed</strong> integer array <code>nums</code> of size <code>n</code> containing all numbers from <code>1</code> to <code>n</code>, return <em>the number of increasing quadruplets</em>.</p>
<p>A quadruplet <code>(i, j, k, l)</code> is increasing if:</p>
<ul>
	<li><code>0 &lt;= i &lt; j &lt; k &lt; l &lt; n</code>, and</li>
	<li><code>nums[i] &lt; nums[k] &lt; nums[j] &lt; nums[l]</code>.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,2,4,5]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
- When i = 0, j = 1, k = 2, and l = 3, nums[i] &lt; nums[k] &lt; nums[j] &lt; nums[l].
- When i = 0, j = 1, k = 2, and l = 4, nums[i] &lt; nums[k] &lt; nums[j] &lt; nums[l]. 
There are no other quadruplets, so we return 2.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There exists only one quadruplet with i = 0, j = 1, k = 2, l = 3, but since nums[j] &lt; nums[k], we return 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>4 &lt;= nums.length &lt;= 4000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
	<li>All the integers of <code>nums</code> are <strong>unique</strong>. <code>nums</code> is a permutation.</li>
</ul>

**Companies**:
[TikTok](https://leetcode.com/company/tiktok), [SAP](https://leetcode.com/company/sap)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/), [Enumeration](https://leetcode.com/tag/enumeration/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Increasing Triplet Subsequence (Medium)](https://leetcode.com/problems/increasing-triplet-subsequence/)
* [Count Special Quadruplets (Easy)](https://leetcode.com/problems/count-special-quadruplets/)
* [Count Good Triplets in an Array (Hard)](https://leetcode.com/problems/count-good-triplets-in-an-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-increasing-quadruplets
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
// Ref: https://leetcode.com/problems/count-increasing-quadruplets/solutions/3111697
class Solution {
public:
    long long countQuadruplets(vector<int>& A) {
        long long N = A.size(), ans = 0;
        vector<long long> cnt(N); // cnt[i] is the number of all 132 triplets with A[i] as the middle number
        for (int j = 0; j < N; ++j) {
            long long prevSmall = 0; // the number of values smaller than A[j]
            for (int i = 0; i < j; ++i) {
                if (A[i] < A[j]) {
                    prevSmall++;
                    ans += cnt[i];
                } else if (A[i] > A[j]) cnt[i] += prevSmall;
            }
        }
        return ans;
    }
};
```