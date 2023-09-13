# [1250. Check If It Is a Good Array (Hard)](https://leetcode.com/problems/check-if-it-is-a-good-array/)

<p>Given an array <code>nums</code> of&nbsp;positive integers. Your task is to select some subset of <code>nums</code>, multiply each element by an integer and add all these numbers.&nbsp;The array is said to be&nbsp;<strong>good&nbsp;</strong>if you can obtain a sum of&nbsp;<code>1</code>&nbsp;from the array by any possible subset and multiplicand.</p>

<p>Return&nbsp;<code>True</code>&nbsp;if the array is <strong>good&nbsp;</strong>otherwise&nbsp;return&nbsp;<code>False</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [12,5,7,23]
<strong>Output:</strong> true
<strong>Explanation:</strong> Pick numbers 5 and 7.
5*3 + 7*(-2) = 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [29,6,10]
<strong>Output:</strong> true
<strong>Explanation:</strong> Pick numbers 29, 6 and 10.
29*1 + 6*(-3) + 10*(-1) = 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,6]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^9</code></li>
</ul>


**Companies**:  
[Dropbox](https://leetcode.com/company/dropbox)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Number Theory](https://leetcode.com/tag/number-theory/)

## Solution 1. Bézout's identity

https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity#For_three_or_more_integers

If $\gcd(a_1, a_2, \ldots, a_n) = d$, then there are integers $x_{1},x_{2},\ldots ,x_{n}$ such that

$$
d=a_{1}x_{1}+a_{2}x_{2}+\cdots +a_{n}x_{n}
$$

has the following properties:

* $d$ is the smallest positive integer of this form
* every number of this form is a multiple of $d$

```cpp
// OJ: https://leetcode.com/problems/check-if-it-is-a-good-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isGoodArray(vector<int>& A) {
        int d = A[0];
        for (int i = 1; i < A.size(); ++i) {
            d = gcd(d, A[i]);
        }
        return d == 1;
    }
};
```