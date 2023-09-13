# [2419. Longest Subarray With Maximum Bitwise AND (Medium)](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and)

<p>You are given an integer array <code>nums</code> of size <code>n</code>.</p>

<p>Consider a <strong>non-empty</strong> subarray from <code>nums</code> that has the <strong>maximum</strong> possible <strong>bitwise AND</strong>.</p>

<ul>
	<li>In other words, let <code>k</code> be the maximum value of the bitwise AND of <strong>any</strong> subarray of <code>nums</code>. Then, only subarrays with a bitwise AND equal to <code>k</code> should be considered.</li>
</ul>

<p>Return <em>the length of the <strong>longest</strong> such subarray</em>.</p>

<p>The bitwise AND of an array is the bitwise AND of all the numbers in it.</p>

<p>A <strong>subarray</strong> is a contiguous sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,3,2,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


**Companies**:
[Siemens](https://leetcode.com/company/siemens), [fourkites](https://leetcode.com/company/fourkites)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation), [Brainteaser](https://leetcode.com/tag/brainteaser)

**Similar Questions**:
* [Number of Different Integers in a String (Easy)](https://leetcode.com/problems/number-of-different-integers-in-a-string)
* [Remove Colored Pieces if Both Neighbors are the Same Color (Medium)](https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color)
* [Count Number of Maximum Bitwise-OR Subsets (Medium)](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets)
* [Smallest Subarrays With Maximum Bitwise OR (Medium)](https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int mx = *max_element(begin(A), end(A)), len = 0, ans = 0;
        for (int n : A) {
            if (n == mx) ans = max(ans, ++len);
            else len = 0;
        }
        return ans;
    }
};
```