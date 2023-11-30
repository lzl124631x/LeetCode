# [2588. Count the Number of Beautiful Subarrays (Medium)](https://leetcode.com/problems/count-the-number-of-beautiful-subarrays)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>. In one operation, you can:</p>

<ul>
	<li>Choose two different indices <code>i</code> and <code>j</code> such that <code>0 &lt;= i, j &lt; nums.length</code>.</li>
	<li>Choose a non-negative integer <code>k</code> such that the <code>k<sup>th</sup></code> bit (<strong>0-indexed</strong>) in the binary representation of <code>nums[i]</code> and <code>nums[j]</code> is <code>1</code>.</li>
	<li>Subtract <code>2<sup>k</sup></code> from <code>nums[i]</code> and <code>nums[j]</code>.</li>
</ul>

<p>A subarray is <strong>beautiful</strong> if it is possible to make all of its elements equal to <code>0</code> after applying the above operation any number of times.</p>

<p>Return <em>the number of <strong>beautiful subarrays</strong> in the array</em> <code>nums</code>.</p>

<p>A subarray is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,3,1,2,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are 2 beautiful subarrays in nums: [4,<u>3,1,2</u>,4] and [<u>4,3,1,2,4</u>].
- We can make all elements in the subarray [3,1,2] equal to 0 in the following way:
  - Choose [<u>3</u>, 1, <u>2</u>] and k = 1. Subtract 2<sup>1</sup> from both numbers. The subarray becomes [1, 1, 0].
  - Choose [<u>1</u>, <u>1</u>, 0] and k = 0. Subtract 2<sup>0</sup> from both numbers. The subarray becomes [0, 0, 0].
- We can make all elements in the subarray [4,3,1,2,4] equal to 0 in the following way:
  - Choose [<u>4</u>, 3, 1, 2, <u>4</u>] and k = 2. Subtract 2<sup>2</sup> from both numbers. The subarray becomes [0, 3, 1, 2, 0].
  - Choose [0, <u>3</u>, <u>1</u>, 2, 0] and k = 0. Subtract 2<sup>0</sup> from both numbers. The subarray becomes [0, 2, 0, 2, 0].
  - Choose [0, <u>2</u>, 0, <u>2</u>, 0] and k = 1. Subtract 2<sup>1</sup> from both numbers. The subarray becomes [0, 0, 0, 0, 0].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,10,4]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no beautiful subarrays in nums.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation), [Prefix Sum](https://leetcode.com/tag/prefix-sum)

**Similar Questions**:
* [Maximum XOR for Each Query (Medium)](https://leetcode.com/problems/maximum-xor-for-each-query)
* [Count the Number of Ideal Arrays (Hard)](https://leetcode.com/problems/count-the-number-of-ideal-arrays)

**Hints**:
* A subarray is beautiful if its xor is equal to zero.
* Compute the prefix xor for every index, then the xor of subarray [left, right] is equal to zero if prefix_xor[left] ^ perfix_xor[right] == 0
* Iterate from left to right and maintain a hash table to count the number of indices equal to the current prefix xor.

## Solution 1. Prefix State Map

```cpp
// OJ: https://leetcode.com/problems/count-the-number-of-beautiful-subarrays
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long beautifulSubarrays(vector<int>& A) {
        unordered_map<int, long long> m{{0,1}};
        long long mask = 0, ans = 0;
        for (int n : A) {
            mask ^= n;
            ans += m[mask]++;
        }
        return ans;
    }
};
```