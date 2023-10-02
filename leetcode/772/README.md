# [772. Basic Calculator III (Hard)](https://leetcode.com/problems/basic-calculator-iii/)

<p>Implement a basic calculator to evaluate a simple expression string.</p>

<p>The expression string contains only non-negative integers, <code>'+'</code>, <code>'-'</code>, <code>'*'</code>, <code>'/'</code> operators, and open <code>'('</code> and closing parentheses <code>')'</code>. The integer division should <strong>truncate toward zero</strong>.</p>

<p>You may assume that the given expression is always valid. All intermediate results will be in the range of <code>[-2<sup>31</sup>, 2<sup>31</sup> - 1]</code>.</p>

<p><b data-stringify-type="bold">Note:&nbsp;</b>You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as&nbsp;<code data-stringify-type="code">eval()</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "1+1"
<strong>Output:</strong> 2
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "6-4/2"
<strong>Output:</strong> 4
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "2*(5+5*2)/3+(6/2+8)"
<strong>Output:</strong> 21
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "(2+6*3+5-(3*14/7+2)*5)+3"
<strong>Output:</strong> -12
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> s = "0"
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of digits, <code>'+'</code>, <code>'-'</code>, <code>'*'</code>, <code>'/'</code>, <code>'('</code>,&nbsp;and&nbsp;<code>')'</code>.</li>
	<li><code>s</code> is a <strong>valid</strong> expression.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Basic Calculator (Hard)](https://leetcode.com/problems/basic-calculator/)
* [Basic Calculator II (Medium)](https://leetcode.com/problems/basic-calculator-ii/)
* [Basic Calculator IV (Hard)](https://leetcode.com/problems/basic-calculator-iv/)
* [Build Binary Expression Tree From Infix Expression (Hard)](https://leetcode.com/problems/build-binary-expression-tree-from-infix-expression/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/basic-calculator-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    stack<long> num;
    stack<char> op;
    unordered_map<char, int> priority{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    void eval() {
        long b = num.top(); num.pop();
        char c = op.top(); op.pop();
        switch (c) {
            case '+': num.top() += b; break;
            case '-': num.top() -= b; break;
            case '*': num.top() *= b; break;
            case '/': num.top() /= b; break;
        }
    }
public:
    int calculate(string s) {
        for (int i = 0, N = s.size(); i < N; ++i) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                long n = 0;
                while (i < N && isdigit(s[i])) n = n * 10 + s[i++] - '0';
                --i;
                num.push(n);
            } else if (s[i] == '(') op.push(s[i]);
            else if (s[i] == ')') {
                while (op.top() != '(') eval();
                op.pop();
            } else {
                while (op.size() && op.top() != '(' && priority[op.top()] >= priority[s[i]]) eval();
                op.push(s[i]);
            }
        }
        while (op.size()) eval();
        return num.top();
    }
};
```