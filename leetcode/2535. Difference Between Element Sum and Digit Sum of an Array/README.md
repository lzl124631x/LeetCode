# [2535. Difference Between Element Sum and Digit Sum of an Array (Easy)](https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array)

<p>You are given a positive integer array <code>nums</code>.</p>
<ul>
	<li>The <strong>element sum</strong> is the sum of all the elements in <code>nums</code>.</li>
	<li>The <strong>digit sum</strong> is the sum of all the digits (not necessarily distinct) that appear in <code>nums</code>.</li>
</ul>
<p>Return <em>the <strong>absolute</strong> difference between the <strong>element sum</strong> and <strong>digit sum</strong> of </em><code>nums</code>.</p>
<p><strong>Note</strong> that the absolute difference between two integers <code>x</code> and <code>y</code> is defined as <code>|x - y|</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,15,6,3]
<strong>Output:</strong> 9
<strong>Explanation:</strong> 
The element sum of nums is 1 + 15 + 6 + 3 = 25.
The digit sum of nums is 1 + 1 + 5 + 6 + 3 = 16.
The absolute difference between the element sum and digit sum is |25 - 16| = 9.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> 0
<strong>Explanation:</strong>
The element sum of nums is 1 + 2 + 3 + 4 = 10.
The digit sum of nums is 1 + 2 + 3 + 4 = 10.
The absolute difference between the element sum and digit sum is |10 - 10| = 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2000</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Add Digits (Easy)](https://leetcode.com/problems/add-digits/)
* [Minimum Sum of Four Digit Number After Splitting Digits (Easy)](https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int differenceOfSum(vector<int>& A) {
        int digitSum = 0;
        for (int n : A) {
            while (n) {
                digitSum += n % 10;
                n /= 10;
            }
        }
        return abs(accumulate(begin(A), end(A), 0) - digitSum);
    }
};
```