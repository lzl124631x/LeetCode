# [2460. Apply Operations to an Array (Easy)](https://leetcode.com/problems/apply-operations-to-an-array)

<p>You are given a <strong>0-indexed</strong> array <code>nums</code> of size <code>n</code> consisting of <strong>non-negative</strong> integers.</p>
<p>You need to apply <code>n - 1</code> operations to this array where, in the <code>i<sup>th</sup></code> operation (<strong>0-indexed</strong>), you will apply the following on the <code>i<sup>th</sup></code> element of <code>nums</code>:</p>
<ul>
	<li>If <code>nums[i] == nums[i + 1]</code>, then multiply <code>nums[i]</code> by <code>2</code> and set <code>nums[i + 1]</code> to <code>0</code>. Otherwise, you skip this operation.</li>
</ul>
<p>After performing <strong>all</strong> the operations, <strong>shift</strong> all the <code>0</code>'s to the <strong>end</strong> of the array.</p>
<ul>
	<li>For example, the array <code>[1,0,2,0,0,1]</code> after shifting all its <code>0</code>'s to the end, is <code>[1,2,1,0,0,0]</code>.</li>
</ul>
<p>Return <em>the resulting array</em>.</p>
<p><strong>Note</strong> that the operations are applied <strong>sequentially</strong>, not all at once.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,2,1,1,0]
<strong>Output:</strong> [1,4,2,0,0,0]
<strong>Explanation:</strong> We do the following operations:
- i = 0: nums[0] and nums[1] are not equal, so we skip this operation.
- i = 1: nums[1] and nums[2] are equal, we multiply nums[1] by 2 and change nums[2] to 0. The array becomes [1,<strong><u>4</u></strong>,<strong><u>0</u></strong>,1,1,0].
- i = 2: nums[2] and nums[3] are not equal, so we skip this operation.
- i = 3: nums[3] and nums[4] are equal, we multiply nums[3] by 2 and change nums[4] to 0. The array becomes [1,4,0,<strong><u>2</u></strong>,<strong><u>0</u></strong>,0].
- i = 4: nums[4] and nums[5] are equal, we multiply nums[4] by 2 and change nums[5] to 0. The array becomes [1,4,0,2,<strong><u>0</u></strong>,<strong><u>0</u></strong>].
After that, we shift the 0's to the end, which gives the array [1,4,2,0,0,0].
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [0,1]
<strong>Output:</strong> [1,0]
<strong>Explanation:</strong> No operation can be applied, we just shift the 0 to the end.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Remove Duplicates from Sorted Array (Easy)](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
* [Move Zeroes (Easy)](https://leetcode.com/problems/move-zeroes/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/apply-operations-to-an-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> applyOperations(vector<int>& A) {
        int N = A.size();
        for (int i = 0; i < N - 1; ++i) {
            if (A[i] == A[i + 1]) {
                A[i] *= 2;
                A[i + 1] = 0;
            }
        }
        int i = 0, j = 0;
        for (; j < N; ++j) {
            if (A[j]) A[i++] = A[j];
        }
        for (; i < N; ++i) A[i] = 0;
        return A;
    }
};
```