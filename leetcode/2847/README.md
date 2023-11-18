# [2847. Smallest Number With Given Digit Product (Medium)](https://leetcode.com/problems/smallest-number-with-given-digit-product)

<p>Given a <strong>positive</strong> integer <code>n</code>, return <em>a string representing the <strong>smallest positive</strong> integer such that the product of its digits is equal to</em> <code>n</code><em>, or </em><code>&quot;-1&quot;</code><em> if no such number exists</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 105
<strong>Output:</strong> &quot;357&quot;
<strong>Explanation:</strong> 3 * 5 * 7 = 105. It can be shown that 357 is the smallest number with a product of digits equal to 105. So the answer would be &quot;105&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 7
<strong>Output:</strong> &quot;7&quot;
<strong>Explanation:</strong> Since 7 has only one digit, its product of digits would be 7. We will show that 7 is the smallest number with a product of digits equal to 7. Since the product of numbers 1 to 6 is 1 to 6 respectively, so &quot;7&quot; would be the answer.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 44
<strong>Output:</strong> &quot;-1&quot;
<strong>Explanation:</strong> It can be shown that there is no number such that its product of digits is equal to 44. So the answer would be &quot;-1&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>18</sup></code></li>
</ul>


**Companies**:
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Math](https://leetcode.com/tag/math), [Greedy](https://leetcode.com/tag/greedy)

**Hints**:
* Find the prime factors of <code>n</code>.
* If there is a prime factor <code>p</code> such that <code>p >= 11</code>, the answer is <code>-1</code>. Since there are no digits whose products equal <code>p</code>.
* Factors <code>5</code> and <code>7</code> should be included in the answer since their product with any number bigger than <code>1</code> is a 2-digit number.
* For factors <code>2</code> and <code>3</code>, we group every three <code>2</code> into an <code>8</code> and every two <code>3</code> into a <code>9</code>.
* For any leftover <code>2</code> or <code>3</code>, check all the possible combinations.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/smallest-number-with-given-digit-product
// Author: github.com/lzl124631x
// Time: O(logN * log(logN))
// Space: O(1) extra space
class Solution {
public:
    string smallestNumber(long long n) {
        if (n == 1) return "1";
        string ans;
        for (int i = 9; i > 1; --i) {
            while (n % i == 0) {
                ans += '0' + i;
                n /= i;
            }
        }
        if (n != 1) return "-1";
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```