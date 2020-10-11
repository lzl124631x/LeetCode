# [1590. Make Sum Divisible by P (Medium)](https://leetcode.com/problems/make-sum-divisible-by-p)

<p>Given an array of positive integers <code>nums</code>, remove the <strong>smallest</strong> subarray (possibly <strong>empty</strong>) such that the <strong>sum</strong> of the remaining elements is divisible by <code>p</code>. It is <strong>not</strong> allowed to remove the whole array.</p>

<p>Return <em>the length of the smallest subarray that you need to remove, or </em><code>-1</code><em> if it's impossible</em>.</p>

<p>A <strong>subarray</strong> is defined as a contiguous block of elements in the array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,1,4,2], p = 6
<strong>Output:</strong> 1
<strong>Explanation:</strong> The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [6,3,5,2], p = 9
<strong>Output:</strong> 2
<strong>Explanation:</strong> We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3], p = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3], p = 7
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no way to remove a subarray in order to get a sum divisible by 7.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> nums = [1000000000,1000000000,1000000000], p = 3
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= p &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Subarray Sums Divisible by K (Medium)](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

## Solution 1. Prefix State Map

```cpp
// OJ: https://leetcode.com/problems/make-sum-divisible-by-p
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minSubarray(vector<int>& A, int p) {
        long N = A.size(), sum = 0, total = 0, ans = N;
        for (int n : A) total = (total + n) % p;
        if (total == 0) return 0;
        unordered_map<int, int> m{{0,-1}};
        for (int i = 0; i < N; ++i) {
            sum = (sum + A[i]) % p;
            int r = (sum - total + p) % p;
            if (m.count(r)) ans = min(ans, (long)i - m[r]);
            m[sum] = i;
        }
        return ans == N ? -1 : ans;
    }
};
```