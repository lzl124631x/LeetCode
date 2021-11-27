# [972. Equal Rational Numbers (Hard)](https://leetcode.com/problems/equal-rational-numbers/)

<p>Given two strings <code>s</code> and <code>t</code>, each of which represents a non-negative rational number, return <code>true</code> if and only if they represent the same number. The strings may use parentheses to denote the repeating part of the rational number.</p>

<p>A <strong>rational number</strong> can be represented using up to three parts: <code>&lt;IntegerPart&gt;</code>, <code>&lt;NonRepeatingPart&gt;</code>, and a <code>&lt;RepeatingPart&gt;</code>. The number will be represented in one of the following three ways:</p>

<ul>
	<li><code>&lt;IntegerPart&gt;</code>

	<ul>
		<li>For example, <code>12</code>, <code>0</code>, and <code>123</code>.</li>
	</ul>
	</li>
	<li><code>&lt;IntegerPart&gt;<strong>&lt;.&gt;</strong>&lt;NonRepeatingPart&gt;</code>
	<ul>
		<li>For example, <code>0.5</code>, <code>1.</code>, <code>2.12</code>, and <code>123.0001</code>.</li>
	</ul>
	</li>
	<li><code>&lt;IntegerPart&gt;<strong>&lt;.&gt;</strong>&lt;NonRepeatingPart&gt;<strong>&lt;(&gt;</strong>&lt;RepeatingPart&gt;<strong>&lt;)&gt;</strong></code>
	<ul>
		<li>For example, <code>0.1(6)</code>, <code>1.(9)</code>, <code>123.00(1212)</code>.</li>
	</ul>
	</li>
</ul>

<p>The repeating portion of a decimal expansion is conventionally denoted within a pair of round brackets. For example:</p>

<ul>
	<li><code>1/6 = 0.16666666... = 0.1(6) = 0.1666(6) = 0.166(66)</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "0.(52)", t = "0.5(25)"
<strong>Output:</strong> true
<strong>Explanation:</strong> Because "0.(52)" represents 0.52525252..., and "0.5(25)" represents 0.52525252525..... , the strings represent the same number.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "0.1666(6)", t = "0.166(66)"
<strong>Output:</strong> true
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "0.9(9)", t = "1."
<strong>Output:</strong> true
<strong>Explanation:</strong> "0.9(9)" represents 0.999999999... repeated forever, which equals 1.  [<a href="https://en.wikipedia.org/wiki/0.999..." target="_blank">See this link for an explanation.</a>]
"1." represents the number 1, which is formed correctly: (IntegerPart) = "1" and (NonRepeatingPart) = "".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>Each part consists only of digits.</li>
	<li>The <code>&lt;IntegerPart&gt;</code> does not have leading zeros (except for the zero itself).</li>
	<li><code>1 &lt;= &lt;IntegerPart&gt;.length &lt;= 4</code></li>
	<li><code>0 &lt;= &lt;NonRepeatingPart&gt;.length &lt;= 4</code></li>
	<li><code>1 &lt;= &lt;RepeatingPart&gt;.length &lt;= 4</code></li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/equal-rational-numbers/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
struct Number {
    string prefix, repeat;
    Number(string p, string r) : prefix(p), repeat(r) {
        int N = r.size(), len = 1; // find the minimal repeat part
        for (; len <= N / 2; ++len) { 
            int i = 0;
            while (i < N && repeat[i] == repeat[i % len]) ++i;
            if (i == N) break;
        }
        if (len <= N / 2) repeat = repeat.substr(0, len);
        if (repeat == "0") repeat = "";
        normalizePrefix();
    }
    void normalizePrefix() {
        if (prefix.find_first_of(".") == string::npos) {
            prefix += '.';
        } else if (repeat.empty()) { // only pop trailing zeroes if repeat is empty
            while (prefix.back() == '0') prefix.pop_back();
        }
    }
};
class Solution {
    string increment(string &s) {
        int i = s.size() - 1, carry = 1;
        for (; i >= 0 && carry; --i) {
            if (s[i] == '.') continue;
            carry += s[i] - '0';
            s[i] = '0' + carry % 10;
            carry /= 10;
        }
        if (carry) s.insert(begin(s), '1');
        return s;
    }
    Number getNumber(string &s) {
        auto i = s.find_first_of("(");
        if (i == string::npos) return Number(s, "");
        auto ans = Number(s.substr(0, i), s.substr(i + 1, s.size() - i - 2));
        if (ans.repeat == "9") {
            ans.repeat = "";
            ans.prefix = increment(ans.prefix);
            ans.normalizePrefix();
        }
        return ans;
    }
public:
    bool isRationalEqual(string s, string t) {
        auto a = getNumber(s), b = getNumber(t);
        if (a.repeat.size() != b.repeat.size()) return false;
        if (a.repeat.size() == 0) return a.prefix == b.prefix;
        if (a.prefix.size() > b.prefix.size()) swap(a, b);
        int i = 0, N = b.prefix.size();
        for (; i < N; ++i) {
            if (i < a.prefix.size()) {
                if (a.prefix[i] != b.prefix[i]) return false;
            } else {
                if (a.repeat[(i - a.prefix.size()) % a.repeat.size()] != b.prefix[i]) return false;
            }
        }
        i = (i - a.prefix.size()) % a.repeat.size();
        return a.repeat.substr(i) + a.repeat.substr(0, i) == b.repeat;
    }
};
```