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

## Solution 1. Reverse Polish Notation (RPN)

Converts the expression to RPN then evaluate the RPN.

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
                switch(str[0]) {
                    case '+': s.top() += num; break;
                    case '-': s.top() -= num; break;
                }
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

## Solution 2.

Similar idea as Solution 1, but compute the data on the fly.

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
      switch (op.top()) {
        case '+': num.top() += n; break;
        case '-': num.top() -= n; break;
      }
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