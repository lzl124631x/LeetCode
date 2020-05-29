# [227. Basic Calculator II (Medium)](https://leetcode.com/problems/basic-calculator-ii/submissions/)

<p>Implement a basic calculator to evaluate a simple expression string.</p>

<p>The expression string contains only <b>non-negative</b> integers, <code>+</code>, <code>-</code>, <code>*</code>, <code>/</code> operators and empty spaces <code> </code>. The integer division should truncate toward zero.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>"3+2*2"
<strong>Output:</strong> 7
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> " 3/2 "
<strong>Output:</strong> 1</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> " 3+5 / 2 "
<strong>Output:</strong> 5
</pre>

<p><b>Note:</b></p>

<ul>
	<li>You may assume that the given expression is always valid.</li>
	<li><b>Do not</b> use the <code>eval</code> built-in library function.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Basic Calculator (Hard)](https://leetcode.com/problems/basic-calculator/)
* [Expression Add Operators (Hard)](https://leetcode.com/problems/expression-add-operators/)
* [Basic Calculator III (Hard)](https://leetcode.com/problems/basic-calculator-iii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/basic-calculator-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    stack<char> ops;
    stack<int> nums;
    inline int priority(char op) {
        if (op == '\0') return 0;
        return op == '*' || op == '/' ? 2 : 1;
    }
    void eval(char op = '\0') {
        while (ops.size() && priority(op) <= priority(ops.top())) {
            int n = nums.top();
            nums.pop();
            switch(ops.top()) {
                case '+': nums.top() += n; break;
                case '-': nums.top() -= n; break;
                case '*': nums.top() *= n; break;
                case '/': nums.top() /= n; break;
            }
            ops.pop();
        }
        ops.push(op);
    }
public:
    int calculate(string s) {
        for (int i = 0, N = s.size(); i < N; ++i) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                int n = 0;
                while (i < N && isdigit(s[i])) n = n * 10 + (s[i++] - '0');
                --i;
                nums.push(n);
            } else eval(s[i]);
        }
        eval();
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