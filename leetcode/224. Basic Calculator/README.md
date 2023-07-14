# [224. Basic Calculator (Hard)](https://leetcode.com/problems/basic-calculator/)

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open `(` and closing parentheses `)`, the plus `+` or minus sign `-`, **non-negative** integers and empty spaces .

**Example 1:**

**Input:** "1 + 1"  
**Output:** 2

**Example 2:**

**Input:** " 2-1 + 2 "  
**Output:** 3

**Example 3:**

**Input:** "(1+(4+5+2)-3)+(6+8)"  
**Output:** 23

**Note:**

*   You may assume that the given expression is always valid.
*   **Do not** use the `eval` built-in library function.

## Solution 1. Stack

```cpp
// OJ: https://leetcode.com/problems/basic-calculator/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(P) where P is the maximum level of nested parenthesis
class Solution {
public:
    int calculate(string s) {
        stack<long> st;
        long ans = 0, sign = 1;
        for (int i = 0, N = s.size(); i < N; ++i) {
            if (isdigit(s[i])) {
                long num = 0;
                while (i < N && isdigit(s[i])) num = num * 10 + s[i++] - '0';
                --i;
                ans += sign * num;
            } else if (s[i] == '+') sign = 1;
            else if (s[i] == '-') sign = -1;
            else if (s[i] == '(') {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            } else if (s[i] == ')') {
                ans *= st.top(); st.pop();
                ans += st.top(); st.pop();
            }
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/basic-calculator/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int calculate(string s) {
        stack<int> signs;
        int n = 0, ans = 0, sign = 1;
        signs.push(sign);
        for (char c : s) {
            if (isdigit(c)) n = 10 * n + (c - '0');
            else if (c == '(') signs.push(sign);
            else if (c == ')') signs.pop();
            else if (c == '+' || c == '-') {
                ans += sign * n;
                n = 0;
                sign = signs.top() * (c == '+' ? 1 : -1);
            }
        }
        return ans + sign * n;
    }
};
```

## Solution 1. Reverse Polish Notation (RPN)

1. Tokenize the string
2. Convert the tokens to a reverse polish notation.
3. Calculate the RPN.

```cpp
// OJ: https://leetcode.com/problems/basic-calculator/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
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
    vector<string> toRpn(vector<string> tokens) {
        vector<string> ans;
        stack<string> ops;
        for (auto &s : tokens) {
            switch (s[0]) {
                case '(': ops.push(s); break;
                case ')':
                    while (ops.top() != "(") {
                        ans.push_back(ops.top());
                        ops.pop();
                    }
                    ops.pop();
                    break;
                case '+': 
                case '-':
                    if (ops.size() && (ops.top() == "+" || ops.top() == "-")) {
                        ans.push_back(ops.top());
                        ops.pop();
                    }
                    ops.push(s);
                    break;
                default: ans.push_back(s); break;
            }
        }
        while (ops.size()) {
            ans.push_back(ops.top());
            ops.pop();
        }
        return ans;
    }
    int calc(vector<string> rpn) {
        stack<int> s;
        for (auto &t : rpn) {
            switch (t[0]) {
                case '+':
                case '-': {
                    int b = s.top();
                    s.pop();
                    s.top() += t == "+" ? b : -b;
                    break;
                }
                default: s.push(stoi(t)); break;
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

## Solution 2.

Directly convert the string to RPN.

```cpp
// https://leetcode.com/problems/basic-calculator
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    vector<string> toRPN(string &s) {
        vector<string> rpn;
        stack<char> ops;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                int begin = i;
                while (i + 1 < s.size() && isdigit(s[i + 1])) ++i;
                rpn.push_back(s.substr(begin, i - begin + 1));
            } else {
                switch(s[i]) {
                    case '+':
                    case '-':
                        if (ops.size() && ops.top() != '(') {
                            rpn.push_back(string(1, ops.top()));
                            ops.pop();
                        }
                        // fall through
                    case '(': ops.push(s[i]); break;
                    case ')': 
                        while (ops.top() != '(') {
                            rpn.push_back(string(1, ops.top()));
                            ops.pop();
                        }
                        ops.pop();
                        break;
                }
            }
        }
        while (ops.size()) {
            rpn.push_back(string(1, ops.top()));
            ops.pop();
        }
        return rpn;
    }
    int calcRPN(vector<string> rpn) {
        stack<int> s;
        for (auto &str : rpn) {
            if (isdigit(str[0])) {
                s.push(stoi(str));
            } else {
                int num = s.top();
                s.pop();
                s.top() += str[0] == '+' ? num : -num;
            }
        }
        return s.top();
    }
public:
    int calculate(string s) {
        return calcRPN(toRPN(s));
    }
};
```

## Solution 3.

Compute the data on the fly.

```cpp
// https://leetcode.com/problems/basic-calculator
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
  stack<int> num;
  stack<char> op;
  void eval(bool popLeftParen) {
    while (op.size() && op.top() != '(') {
      int n = num.top();
      num.pop();
      num.top() += op.top() == '+' ? n : -n;
      op.pop();
    }
    if (popLeftParen) op.pop();
  }
public:
  int calculate(string s) {
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') continue;
      if (isdigit(s[i])) {
        int begin = i;
        while (i + 1 < s.size() && isdigit(s[i + 1])) ++i;
        num.push(stoi(s.substr(begin, i - begin + 1)));
      } else {
        switch(s[i]) {
          case '+':
          case '-': eval(false);
          // fall through
          case '(': op.push(s[i]); break;
          case ')': eval(true); break;
        }
      }
    }
    eval(false);
    return num.top();
  }
};
```

## Solution 4.

```cpp
// OJ: https://leetcode.com/problems/basic-calculator/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int ans = 0, sign = 1;
        for (int i = 0, N = s.size(); i < N; ++i) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < N && isdigit(s[i])) num = 10 * num + (s[i++] - '0');
                --i;
                ans += sign * num;
            } else if (s[i] == '+') sign = 1;
            else if (s[i] == '-') sign = -1;
            else if (s[i] == '(') {
                st.push(ans);
                st.push(sign);
                sign = 1;
                ans = 0;
            } else if (s[i] == ')') {
                ans *= st.top(); st.pop();
                ans += st.top(); st.pop();
            }
        }
        return ans;
    }
};
```
