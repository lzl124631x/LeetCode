# [227. Basic Calculator II (Medium)](https://leetcode.com/problems/basic-calculator-ii/)

<p>Given a string <code>s</code> which represents an expression, <em>evaluate this expression and return its value</em>.&nbsp;</p>

<p>The integer division should truncate toward zero.</p>

<p><b data-stringify-type="bold">Note:&nbsp;</b>You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as&nbsp;<code data-stringify-type="code">eval()</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s = "3+2*2"
<strong>Output:</strong> 7
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s = " 3/2 "
<strong>Output:</strong> 1
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> s = " 3+5 / 2 "
<strong>Output:</strong> 5
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code> consists of integers and operators <code>('+', '-', '*', '/')</code> separated by some number of spaces.</li>
	<li><code>s</code> represents <strong>a valid expression</strong>.</li>
	<li>All the integers in the expression are non-negative integers in the range <code>[0, 2<sup>31</sup> - 1]</code>.</li>
	<li>The answer is <strong>guaranteed</strong> to fit in a <strong>32-bit integer</strong>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Roblox](https://leetcode.com/company/roblox), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple), [Snapchat](https://leetcode.com/company/snapchat), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Basic Calculator (Hard)](https://leetcode.com/problems/basic-calculator/)
* [Expression Add Operators (Hard)](https://leetcode.com/problems/expression-add-operators/)
* [Basic Calculator III (Hard)](https://leetcode.com/problems/basic-calculator-iii/)

## Solution 1. Stack

Use two stacks. One for operands `nums`, another for operators `ops`.

We push numbers into `nums`, and operators into `ops`. Before we push a new operator `c` into the `ops`, we need to `eval` the stacks -- calculating all the operators whose priorities are greater than or equal to the priority of `c`.

We also need to `eval` when we exhaust the input string to calculate all the operands. 

In the end, `nums.top()` is the answer.

```cpp
// OJ: https://leetcode.com/problems/basic-calculator-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) becase we at most store two operators and their corresponding operands in the stacks
class Solution {
    stack<int> nums;
    stack<char> ops;
    void eval() {
        int b = nums.top(); nums.pop();
        switch (ops.top()) {
            case '+': nums.top() += b; break;
            case '-': nums.top() -= b; break;
            case '*': nums.top() *= b; break;
            case '/': nums.top() /= b; break;
        }
        ops.pop();
    }
public:
    unordered_map<char, int> priority{{'+',0},{'-',0},{'*',1},{'/',1}};
    int calculate(string s) {
        int N = s.size();
        for (int i = 0; i < N; ++i) {
            if (isdigit(s[i])) {
                int n = 0;
                while (i < N && isdigit(s[i])) n = n * 10 + (s[i++] - '0');
                --i;
                nums.push(n);
            } else if (s[i] != ' ') {
                while (ops.size() && priority[ops.top()] >= priority[s[i]]) eval(); // Note that it's `while` here. Consider 1+2*3-4. When we see `-`, we need to `eval` twice.
                ops.push(s[i]);
            }
        }
        while (ops.size()) eval();
        return nums.top();
    }
};
```

## Solution 2. Reverse Polish Notation

```cpp
// OJ: https://leetcode.com/problems/basic-calculator-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    inline int priority(char op) {
        if (op == '\0') return 0;
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 3;
    }
    vector<string> tokenize(string &s) {
        vector<string> ans;
        for (int i = 0, N = s.size(); i < N; ) {
            while (i < N && s[i] == ' ') ++i;
            if (i >= N) break;
            if (isdigit(s[i])) {
                int j = i;
                while (i < N && isdigit(s[i])) ++i;
                ans.push_back(s.substr(j, i - j));
            } else ans.push_back(s.substr(i++, 1));
        }
        return ans;
    }
    void pushOps(vector<string> &ans, stack<string> &ops, string op = "") {
        while (ops.size() && priority(op[0]) <= priority(ops.top()[0])) {
            ans.push_back(ops.top());
            ops.pop();
        }
        ops.push(op);
    }
    vector<string> toRpn(vector<string> tokens) {
        vector<string> ans;
        stack<string> ops;
        for (auto &s : tokens) {
            if (isdigit(s[0])) ans.push_back(s);
            else pushOps(ans, ops, s);
        }
        pushOps(ans, ops);
        return ans;
    }
    int calc(vector<string> rpn) {
        stack<int> s;
        int n;
        for (auto &t : rpn) {
            if (isdigit(t[0])) s.push(stoi(t));
            else {
                n = s.top();
                s.pop();
                switch (t[0]) {
                    case '+': s.top() += n; break;
                    case '-': s.top() -= n; break;
                    case '*': s.top() *= n; break;
                    case '/': s.top() /= n; break;
                }
            }
        }
        return s.top();
    }
public:
    int calculate(string s) {
        return calc(toRpn(tokenize(s)));
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/basic-calculator-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    int getNum(string &s, int &i) {
        int ans = 0;
        while (i < s.size() && isdigit(s[i])) ans = ans * 10 + (s[i++] - '0');
        return ans;
    }
public:
    int calculate(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        int i = 0, cur = getNum(s, i), prev = cur;
        while (i < s.size()) {
            char c = s[i++];
            int n = getNum(s, i);
            if (c == '+') {
                cur += n;
                prev = n;
            } else if (c == '-') {
                cur -= n;
                prev = -n;
            } else if (c == '*') {
                cur = cur - prev + prev * n;
                prev = prev * n;
            } else {
                cur = cur - prev + prev / n;
                prev = prev / n;
            }
        }
        return cur;
    }
};
```

## Solution 4.

```cpp
// OJ: https://leetcode.com/problems/basic-calculator-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int ans = 0, num = 0;
        char op = '+';
        for (int i = 0, N = s.size(); i < N; ++i) {
            if (isdigit(s[i])) {
                while (i < N && isdigit(s[i])) num = 10 * num + (s[i++] - '0');
                --i;
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i == N - 1) {
                if (op == '+') st.push(num);
                else if (op == '-') st.push(-num);
                else if (op == '*') st.top() *= num;
                else if (op == '/') st.top() /= num;
                op = s[i];
                num = 0;
            }
        }
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
```

## Solution 5.

```cpp
// OJ: https://leetcode.com/problems/basic-calculator-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int calculate(string s) {
        int num = 0, ans = 0, cur = 0;
        char op = '+';
        for (int i = 0, N = s.size(); i < N; ++i) {
            if (isdigit(s[i])) num = 10 * num + (s[i] - '0');
            if ((!isdigit(s[i]) && s[i] != ' ') || i == N - 1) {
                if (op == '+') cur += num;
                else if (op == '-') cur -= num;
                else if (op == '*') cur *= num;
                else cur /= num;
                if (s[i] == '+' || s[i] == '-' || i == N - 1) {
                    ans += cur;
                    cur = 0;
                }
                op = s[i];
                num = 0;
            }
        }
        return ans;
    }
};
```