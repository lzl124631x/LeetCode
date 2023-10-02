# [166. Fraction to Recurring Decimal (Medium)](https://leetcode.com/problems/fraction-to-recurring-decimal)

<p>Given two integers representing the <code>numerator</code> and <code>denominator</code> of a fraction, return <em>the fraction in string format</em>.</p>

<p>If the fractional part is repeating, enclose the repeating part in parentheses.</p>

<p>If multiple answers are possible, return <strong>any of them</strong>.</p>

<p>It is <strong>guaranteed</strong> that the length of the answer string is less than <code>10<sup>4</sup></code> for all the given inputs.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> numerator = 1, denominator = 2
<strong>Output:</strong> &quot;0.5&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> numerator = 2, denominator = 1
<strong>Output:</strong> &quot;2&quot;
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> numerator = 4, denominator = 333
<strong>Output:</strong> &quot;0.(012)&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;=&nbsp;numerator, denominator &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>denominator != 0</code></li>
</ul>


**Companies**:
[ServiceNow](https://leetcode.com/company/servicenow), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Airbnb](https://leetcode.com/company/airbnb), [MathWorks](https://leetcode.com/company/mathworks), [Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon), [Snapchat](https://leetcode.com/company/snapchat), [IXL](https://leetcode.com/company/ixl), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table), [Math](https://leetcode.com/tag/math), [String](https://leetcode.com/tag/string)

## Solution 1.

The integer part is of length `lg(N/D)`. The fractional part is at most of length `D` according to pigeon hole principle.

```cpp
// OJ: https://leetcode.com/problems/fraction-to-recurring-decimal
// Author: github.com/lzl124631x
// Time: O(lg(N/D) + D)
// Space: O(lg(N/D) + D)
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        long long n = numerator, d = denominator;
        if ((n < 0 && d > 0) || (n > 0 && d < 0)) ans += '-';
        n = abs(n);
        d = abs(d);
        ans += to_string(n / d);
        if (n % d) ans += '.';
        unordered_map<int, int> numToIndex;
        while ((n = n % d * 10) && numToIndex.count(n) == 0) {
            numToIndex[n] = ans.size();
            ans += '0' + n / d;
        }
        if (n) { // repeating part detected
            ans.insert(numToIndex[n], 1, '(');
            ans += ')';
        }
        return ans;
    }
};
```