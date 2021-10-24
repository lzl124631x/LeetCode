# [995. Minimum Number of K Consecutive Bit Flips (Hard)](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/)

<p>You are given a binary array <code>nums</code> and an integer <code>k</code>.</p>

<p>A <strong>k-bit flip</strong> is choosing a <strong>subarray</strong> of length <code>k</code> from <code>nums</code> and simultaneously changing every <code>0</code> in the subarray to <code>1</code>, and every <code>1</code> in the subarray to <code>0</code>.</p>

<p>Return <em>the minimum number of <strong>k-bit flips</strong> required so that there is no </em><code>0</code><em> in the array</em>. If it is not possible, return <code>-1</code>.</p>

<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,0], k = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong> Flip nums[0], then flip nums[2].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,0], k = 2
<strong>Output:</strong> -1
<strong>Explanation:</strong> No matter how we flip subarrays of size 2, we cannot make the array become [1,1,1].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [0,0,0,1,0,1,1,0], k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Bulb Switcher (Medium)](https://leetcode.com/problems/bulb-switcher/)

## Solution 1. Queue

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(K)
class Solution {
public:
    int minKBitFlips(vector<int>& A, int k) {
        queue<int> q;
        int ans = 0;
        for (int i = 0, N = A.size(); i < N; ++i) {
            if (q.size() && q.front() <= i) q.pop();
            int flip = q.size() % 2;
            if ((A[i] ^ flip) == 0) {
                if (i + k > N) return -1;
                ++ans;
                q.push(i + k);
            }
        }
        return ans;
    }
};
```

## TODO

Checkout https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/discuss/238609/JavaC%2B%2BPython-One-Pass-and-O(1)-Space 