# [65. Valid Number (Hard)](https://leetcode.com/problems/valid-number/)

<p>Validate if a given string can be interpreted as&nbsp;a decimal number.</p>

<p>Some examples:<br>
<code>"0"</code> =&gt; <code>true</code><br>
<code>" 0.1 "</code> =&gt; <code>true</code><br>
<code>"abc"</code> =&gt; <code>false</code><br>
<code>"1 a"</code> =&gt; <code>false</code><br>
<code>"2e10"</code> =&gt; <code>true</code><br>
<code>" -90e3&nbsp; &nbsp;"</code> =&gt; <code>true</code><br>
<code>" 1e"</code> =&gt; <code>false</code><br>
<code>"e3"</code> =&gt; <code>false</code><br>
<code>" 6e-1"</code> =&gt; <code>true</code><br>
<code>" 99e2.5&nbsp;"</code> =&gt; <code>false</code><br>
<code>"53.5e93"</code> =&gt; <code>true</code><br>
<code>" --6 "</code> =&gt; <code>false</code><br>
<code>"-+3"</code> =&gt; <code>false</code><br>
<code>"95a54e53"</code> =&gt; <code>false</code></p>

<p><strong>Note:</strong> It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:</p>

<ul>
	<li>Numbers 0-9</li>
	<li>Exponent - "e"</li>
	<li>Positive/negative sign - "+"/"-"</li>
	<li>Decimal point - "."</li>
</ul>

<p>Of course, the context of these characters also matters in the input.</p>

<p><strong>Update (2015-02-10):</strong><br>
The signature of the <code>C++</code> function had been updated. If you still see your function signature accepts a <code>const char *</code> argument, please click the reload button to reset your code definition.</p>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [String to Integer (atoi) (Medium)](https://leetcode.com/problems/string-to-integer-atoi/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/valid-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isNumber(string s) {
        int i = 0, N = s.size();
        while (i < N && s[i] == ' ') ++i;
        if (i < N && (s[i] == '+' || s[i] == '-')) ++i;
        bool digitFound = false;
        while (i < N && isdigit(s[i])) { ++i; digitFound = true; }
        if (i < N && s[i] == '.') ++i;
        while (i < N && isdigit(s[i])) { ++i; digitFound = true; }
        if (!digitFound) return false;
        if (i < N && s[i] == 'e') {
            ++i;
            if (i < N && (s[i] == '+' || s[i] == '-')) ++i;
            bool expFound = false;
            while (i < N && isdigit(s[i])) { ++i; expFound = true; }
            if (!expFound) return false;
        }
        while (i < N && s[i] == ' ') ++i;
        return i == N;
    }
};
```