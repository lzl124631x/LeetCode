# [2874. Maximum Value of an Ordered Triplet II (Medium)](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>.</p>

<p>Return <em><strong>the maximum value over all triplets of indices</strong></em> <code>(i, j, k)</code> <em>such that</em> <code>i &lt; j &lt; k</code><em>. </em>If all such triplets have a negative value, return <code>0</code>.</p>

<p>The <strong>value of a triplet of indices</strong> <code>(i, j, k)</code> is equal to <code>(nums[i] - nums[j]) * nums[k]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [12,6,1,2,7]
<strong>Output:</strong> 77
<strong>Explanation:</strong> The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,10,3,4,19]
<strong>Output:</strong> 133
<strong>Explanation:</strong> The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


**Companies**:
[Media.net](https://leetcode.com/company/medianet)

**Related Topics**:  
[Array](https://leetcode.com/tag/array)

**Similar Questions**:
* [Trapping Rain Water (Hard)](https://leetcode.com/problems/trapping-rain-water)
* [Sum of Beauty in the Array (Medium)](https://leetcode.com/problems/sum-of-beauty-in-the-array)

**Hints**:
* Preprocess the prefix maximum array, <code>prefix_max[i] = max(nums[0], nums[1], …, nums[i])</code> and the suffix maximum array, <code>suffix_max[i] = max(nums[i], nums[i + 1], …, nums[i - 1])</code>.
* For each index <code>j</code>, find two indices <code>i</code> and <code>k</code> such that <code>i < j < k</code> and <code>(nums[i] - nums[j]) * nums[k]</code> is the maximum, using the prefix and suffix maximum arrays.
* For index <code>j</code>, the maximum triplet value is <code>(prefix_max[j - 1] - nums[j]) * suffix_max[j + 1]</code>.

## Solution 1. Kadane

```cpp
// OJ: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& A) {
        long long ans = 0, mx = A[0], first = A[0] - A[1];
        for (int i = 2, N = A.size(); i < N; ++i) {
            mx = max(mx, (long long)A[i - 2]);
            first = max(first, mx - A[i - 1]);
            ans = max(ans, first * A[i]);
        }
        return ans;
    }
};
```

Or 

```cpp
// OJ: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& A) {
        long long ans = 0, mx = 0, first = 0;
        for (int n : A) {
            ans = max(ans, first * n);
            first = max(first, mx - n);
            mx = max(mx, (long long)n);
        }
        return ans;
    }
};
```