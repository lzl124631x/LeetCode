# [330. Patching Array (Hard)](https://leetcode.com/problems/patching-array)

<p>Given a sorted integer array <code>nums</code> and an integer <code>n</code>, add/patch elements to the array such that any number in the range <code>[1, n]</code> inclusive can be formed by the sum of some elements in the array.</p>

<p>Return <em>the minimum number of patches required</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3], n = 6
<strong>Output:</strong> 1
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,5,10], n = 20
<strong>Output:</strong> 2
Explanation: The two patches can be [2, 4].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,2], n = 5
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> is sorted in <strong>ascending order</strong>.</li>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Snowflake](https://leetcode.com/company/snowflake), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Greedy](https://leetcode.com/tag/greedy)

**Similar Questions**:
* [Maximum Number of Consecutive Values You Can Make (Medium)](https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/patching-array
// Author: github.com/lzl124631x
// Time: O(L + sqrt(N)) where L is the length of A
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/35494/solution-explanation
class Solution {
public:
    int minPatches(vector<int>& A, int n) {
        long miss = 1, ans = 0, i = 0, N = A.size(); // miss is the next missing number
        while (miss <= n) { // keep looping while miss <= n
            if (i < N && A[i] <= miss) miss += A[i++]; // if the current missing number is covered, extend miss by A[i] and increment i
            else {
                miss += miss; // if miss is not covered, patch miss. Extend miss by miss, and increment answer.
                ++ans;
            }
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/patching-array
// Author: github.com/lzl124631x
// Time: O(L + sqrt(N)) where L is the length of A
// Space: O(1)
class Solution {
public:
    int minPatches(vector<int>& A, int n) {
        long i = 0, ans = 0, miss = 1, N = A.size();
        while (true) {
            while (i < N && A[i] <= miss) miss += A[i++]; // keep consuming A[i] until we find the next missing number
            if (miss > n) break; // break if the missing number > n
            ++ans; // patch miss
            miss += miss;
        }
        return ans;
    }
};
```