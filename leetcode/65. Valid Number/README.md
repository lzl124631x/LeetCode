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

Pro:
* Each function has a single responsibility and relatively simpler than the original problem.

Con:
* Multiple passes
* `O(N)` space (but can be changed to `O(1)` space if we just pass in string reference and `begin` `end` pointers.)

```cpp
// OJ: https://leetcode.com/problems/valid-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    bool isInteger(string s) {
        if (s.empty()) return false;
        int i = 0, N = s.size();
        if (s[i] == '+' || s[i] == '-') ++i;
        if (i == N) return false;
        while (i < N && isdigit(s[i])) ++i;
        return i == N;
    }
    bool isDecimal(string s) {
        if (s.empty()) return false;
        int i = 0, N = s.size();
        if (s[i] == '+' || s[i] == '-') ++i;
        if (i == N) return false;
        bool hasInteger = isdigit(s[i]);
        while (i < N && isdigit(s[i])) ++i;
        if (i == N || s[i] != '.') return false;
        ++i;
        if (i == N) return hasInteger;
        while (i < N && isdigit(s[i])) ++i;
        return i == N;
    }
public:
    bool isNumber(string s) {
        auto eIndex = s.find_first_of("eE");
        if (eIndex == string::npos) return isDecimal(s) || isInteger(s);
        auto first = s.substr(0, eIndex), second = s.substr(eIndex + 1);
        return (isDecimal(first) || isInteger(first)) && isInteger(second);
    }
};
```

## Solution 2.

Pro:
* Strictly single pass

Con:
* Easy to miss corner cases.

```cpp
// OJ: https://leetcode.com/problems/valid-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isNumber(string s) {
        int i = 0, N = s.size();
        if (i < N && (s[i] == '+' || s[i] == '-')) ++i;
        if (i == N) return false;
        bool hasDigit = isdigit(s[i]);
        while (i < N && isdigit(s[i])) ++i; 
        if (i == N) return true;
        if (s[i] == '.') ++i;
        if (i == N) return hasDigit;
        hasDigit = hasDigit || isdigit(s[i]);
        while (i < N && isdigit(s[i])) ++i;
        if (i == N) return hasDigit;
        if (s[i] == 'e' || s[i] == 'E') {
            if (!hasDigit) return false;
            ++i;
            if (i == N) return false;
            if (s[i] == '+' || s[i] == '-') ++i;
            if (i == N) return false;
            while (i < N && isdigit(s[i])) ++i;
        }
        return i == N;
    }
};
```

## Solution 3.

Pro:
* Short code and space efficient.
* For each character type, the check is straight forward.

```cpp
// OJ: https://leetcode.com/problems/valid-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/valid-number/solution/
class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false, seenExp = false, seenDot = false;
        int i = 0, N = s.size();
        for (; i < N; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                seenDigit = true;
            } else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') return false;
            } else if (c == 'e' || c == 'E') {
                if (seenExp || !seenDigit) return false;
                seenExp = true;
                seenDigit = false;
            } else if (c == '.') {
                if (seenDot || seenExp) return false;
                seenDot = true;
            } else return false;
        }
        return seenDigit;
    }
};
```