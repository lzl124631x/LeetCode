# [415. Add Strings (Easy)](https://leetcode.com/problems/add-strings/)

<p>Given two non-negative integers <code>num1</code> and <code>num2</code> represented as string, return the sum of <code>num1</code> and <code>num2</code>.</p>

<p><b>Note:</b>
</p><ol>
<li>The length of both <code>num1</code> and <code>num2</code> is &lt; 5100.</li>
<li>Both <code>num1</code> and <code>num2</code> contains only digits <code>0-9</code>.</li>
<li>Both <code>num1</code> and <code>num2</code> does not contain any leading zero.</li>
<li>You <b>must not use any built-in BigInteger library</b> or <b>convert the inputs to integer</b> directly.</li>
</ol>
<p></p>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Add Two Numbers (Medium)](https://leetcode.com/problems/add-two-numbers/)
* [Multiply Strings (Medium)](https://leetcode.com/problems/multiply-strings/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/add-strings/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum;
        int carry = 0;
        auto i1 = num1.rbegin(), i2 = num2.rbegin();
        while (i1 != num1.rend() || i2 != num2.rend() || carry) {
            int n = carry;
            if (i1 != num1.rend()) n += *i1++ - '0';
            if (i2 != num2.rend()) n += *i2++ - '0';
            carry = n / 10;
            sum += (n % 10) + '0';
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
```