# [2681. Power of Heroes (Hard)](https://leetcode.com/problems/power-of-heroes)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> representing the strength of some heroes. The<b> power</b> of a group of heroes is defined as follows:</p>

<ul>
	<li>Let <code>i<sub>0</sub></code>, <code>i<sub>1</sub></code>, ... ,<code>i<sub>k</sub></code> be the indices of the heroes in a group. Then, the power of this group is <code>max(nums[i<sub>0</sub>], nums[i<sub>1</sub>], ... ,nums[i<sub>k</sub>])<sup>2</sup> * min(nums[i<sub>0</sub>], nums[i<sub>1</sub>], ... ,nums[i<sub>k</sub>])</code>.</li>
</ul>

<p>Return <em>the sum of the <strong>power</strong> of all <strong>non-empty</strong> groups of heroes possible.</em> Since the sum could be very large, return it <strong>modulo</strong> <code>10<sup>9 </sup>+ 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,1,4]
<strong>Output:</strong> 141
<strong>Explanation:</strong> 
1<sup>st</sup>&nbsp;group: [2] has power = 2<sup>2</sup>&nbsp;* 2 = 8.
2<sup>nd</sup>&nbsp;group: [1] has power = 1<sup>2</sup> * 1 = 1. 
3<sup>rd</sup>&nbsp;group: [4] has power = 4<sup>2</sup> * 4 = 64. 
4<sup>th</sup>&nbsp;group: [2,1] has power = 2<sup>2</sup> * 1 = 4. 
5<sup>th</sup>&nbsp;group: [2,4] has power = 4<sup>2</sup> * 2 = 32. 
6<sup>th</sup>&nbsp;group: [1,4] has power = 4<sup>2</sup> * 1 = 16. 
​​​​​​​7<sup>th</sup>&nbsp;group: [2,1,4] has power = 4<sup>2</sup>​​​​​​​ * 1 = 16. 
The sum of powers of all groups is 8 + 1 + 64 + 4 + 32 + 16 + 16 = 141.

</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,1]
<strong>Output:</strong> 7
<strong>Explanation:</strong> A total of 7 groups are possible, and the power of each group will be 1. Therefore, the sum of the powers of all groups is 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Math](https://leetcode.com/tag/math), [Sorting](https://leetcode.com/tag/sorting), [Prefix Sum](https://leetcode.com/tag/prefix-sum)

**Hints**:
* Try something with sorting the array.
* For a pair of array elements nums[i] and nums[j] (i < j), the power would be nums[i]*nums[j]^2 regardless of how many elements in between are included.
* The number of subsets with the above as power will correspond to 2^(j-i-1).
* Try collecting the terms for nums[0], nums[1], …, nums[j-1] when computing the power of heroes ending at index j to get the power in a single pass.

## Solution 1.

Assume `A=[1,2,3,4]`, the answer is the sum of the following

```
// group of numbers ending with 1
1 * 1^2 * 2^0

// group of numbers ending with 2
1 * 2^2 * 2^0
2 * 2^2 * 2^0

// group of numbers ending with 3
1 * 3^2 * 2^1
2 * 3^2 * 2^0
3 * 3^2 * 2^0

// group of numbers ending with 4
1 * 4^2 * 2^2
2 * 4^2 * 2^1
3 * 4^2 * 2^0
4 * 4^2 * 2^0
```
```cpp
// OJ: https://leetcode.com/problems/power-of-heroes
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int sumOfPower(vector<int>& A) {
        sort(begin(A), end(A));
        long N = A.size(), mod = 1e9 + 7, sum = 0, ans = 0;
        for (long n : A) {
            ans = (ans + n * n % mod * (sum + n) % mod) % mod;
            sum = (sum * 2 % mod + n);
        }
        return ans;
    }
};
```