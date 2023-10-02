# [2310. Sum of Numbers With Units Digit K (Medium)](https://leetcode.com/problems/sum-of-numbers-with-units-digit-k)

<p>Given two integers <code>num</code> and <code>k</code>, consider a set of positive integers with the following properties:</p>
<ul>
	<li>The units digit of each integer is <code>k</code>.</li>
	<li>The sum of the integers is <code>num</code>.</li>
</ul>
<p>Return <em>the <strong>minimum</strong> possible size of such a set, or </em><code>-1</code><em> if no such set exists.</em></p>
<p>Note:</p>
<ul>
	<li>The set can contain multiple instances of the same integer, and the sum of an empty set is considered <code>0</code>.</li>
	<li>The <strong>units digit</strong> of a number is the rightmost digit of the number.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> num = 58, k = 9
<strong>Output:</strong> 2
<strong>Explanation:</strong>
One valid set is [9,49], as the sum is 58 and each integer has a units digit of 9.
Another valid set is [19,39].
It can be shown that 2 is the minimum possible size of a valid set.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> num = 37, k = 2
<strong>Output:</strong> -1
<strong>Explanation:</strong> It is not possible to obtain a sum of 37 using only integers that have a units digit of 2.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> num = 0, k = 7
<strong>Output:</strong> 0
<strong>Explanation:</strong> The sum of an empty set is considered 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>0 &lt;= num &lt;= 3000</code></li>
	<li><code>0 &lt;= k &lt;= 9</code></li>
</ul>

**Companies**:
[Codenation](https://leetcode.com/company/codenation)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/), [Enumeration](https://leetcode.com/tag/enumeration/)

**Similar Questions**:
* [Digit Count in Range (Hard)](https://leetcode.com/problems/digit-count-in-range/)
* [Count Integers With Even Digit Sum (Easy)](https://leetcode.com/problems/count-integers-with-even-digit-sum/)
* [Sum of Number and Its Reverse (Medium)](https://leetcode.com/problems/sum-of-number-and-its-reverse/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sum-of-numbers-with-units-digit-k
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int minimumNumbers(int n, int k) {
        if (n == 0) return 0;
        for (int i = 1; i * k <= n && i <= 10; ++i) {
            if (i * k % 10 == n % 10) return i;
        }
        return -1;
    }
};
```