# [640. Solve the Equation (Medium)](https://leetcode.com/problems/solve-the-equation/)

<p>
Solve a given equation and return the value of <code>x</code> in the form of string "x=#value". The equation contains only '+', '-' operation, the variable <code>x</code> and its coefficient.
</p>

<p>
If there is no solution for the equation, return "No solution".
</p>
<p>
If there are infinite solutions for the equation, return "Infinite solutions".
</p>
<p>
If there is exactly one solution for the equation, we ensure that the value of <code>x</code> is an integer.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> "x+5-3+x=6+x-2"
<b>Output:</b> "x=2"
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> "x=x"
<b>Output:</b> "Infinite solutions"
</pre>
<p></p>

<p><b>Example 3:</b><br>
</p><pre><b>Input:</b> "2x=x"
<b>Output:</b> "x=0"
</pre>
<p></p>

<p><b>Example 4:</b><br>
</p><pre><b>Input:</b> "2x+3x-6x=x+2"
<b>Output:</b> "x=-1"
</pre>
<p></p>

<p><b>Example 5:</b><br>
</p><pre><b>Input:</b> "x=x+2"
<b>Output:</b> "No solution"
</pre>
<p></p>

**Companies**:  
[Google](https://leetcode.com/company/google), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Fraction Addition and Subtraction (Medium)](https://leetcode.com/problems/fraction-addition-and-subtraction/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/solve-the-equation/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    int read(string &equation, int pos, bool &isNum, int &num) {
        if (equation[pos] == '=') ++pos;
        int sign = 1, N = equation.size();
        if (equation[pos] == '+' || equation[pos] == '-') {
            if (equation[pos] == '-') sign = -1;
            ++pos;
        }
        if (pos < N && equation[pos] == 'x') {
            num = 1;
        } else {
            num = 0;
            while (pos < N && isdigit(equation[pos])) {
                num = num * 10 + equation[pos++] - '0';
            }
        }
        isNum = true;
        if (pos < N && equation[pos] == 'x') {
            isNum = false;
            ++pos;
        }
        num *= sign;
        return pos;
    }
public:
    string solveEquation(string equation) {
        int i = 0, N = equation.size(), space = equation.find_first_of("=");
        int coef = 0, val = 0;
        while (i < N) {
            bool isNum;
            int num;
            i = read(equation, i, isNum, num);
            int sign = i <= space ? 1 : -1;
            if (isNum) val -= sign * num;
            else coef += sign * num;
        }
        if (coef) return "x=" + to_string(val / coef);
        return val ? "No solution" : "Infinite solutions";
    }
};
```