# [1085. Sum of Digits in the Minimum Number (Easy)](https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/)

<p>Given an integer array <code>nums</code>, return <code>0</code><em> if the sum of the digits of the minimum integer in </em><code>nums</code><em> is odd, or </em><code>1</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [34,23,1,24,75,33,54,8]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The minimal element is 1, and the sum of those digits is 1 which is odd, so the answer is 0.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [99,77,33,66,55]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The minimal element is 33, and the sum of those digits is 3 + 3 = 6 which is even, so the answer is 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Add Digits (Easy)](https://leetcode.com/problems/add-digits/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int n = *min_element(begin(A), end(A)), sum = 0;
        while (n) {
            sum += n;
            n /= 10;
        }
        return 1 - sum % 2;
    }
};
```