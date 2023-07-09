# [2469. Convert the Temperature (Easy)](https://leetcode.com/problems/convert-the-temperature)

<p>You are given a non-negative floating point number rounded to two decimal places <code>celsius</code>, that denotes the <strong>temperature in Celsius</strong>.</p>
<p>You should convert Celsius into <strong>Kelvin</strong> and <strong>Fahrenheit</strong> and return it as an array <code>ans = [kelvin, fahrenheit]</code>.</p>
<p>Return <em>the array <code>ans</code>. </em>Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</p>
<p><strong>Note that:</strong></p>
<ul>
	<li><code>Kelvin = Celsius + 273.15</code></li>
	<li><code>Fahrenheit = Celsius * 1.80 + 32.00</code></li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> celsius = 36.50
<strong>Output:</strong> [309.65000,97.70000]
<strong>Explanation:</strong> Temperature at 36.50 Celsius converted in Kelvin is 309.65 and converted in Fahrenheit is 97.70.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> celsius = 122.11
<strong>Output:</strong> [395.26000,251.79800]
<strong>Explanation:</strong> Temperature at 122.11 Celsius converted in Kelvin is 395.26 and converted in Fahrenheit is 251.798.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>0 &lt;= celsius &lt;= 1000</code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Smallest Even Multiple (Easy)](https://leetcode.com/problems/smallest-even-multiple/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/convert-the-temperature
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.8 + 32};
    }
};
```