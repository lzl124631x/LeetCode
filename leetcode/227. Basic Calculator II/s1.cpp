class Solution {
private:
    string infixToSuffix(string &infix) {
        string ans;
        stack<char> op;
        bool afterDigit = false;
        for (int i = 0; i < infix.length(); ++i) {
            char c = infix[i];
            if (isspace(c)) continue;
            if (isdigit(c)) {
                ans += c;
                afterDigit = true;
            } else {
                if (afterDigit) {
                    ans += '#';
                    afterDigit = false;
                }
                if (c == '+' || c == '-') {
                    while (!op.empty() && op.top() != '(') {
                        ans += op.top();
                        op.pop();
                    }
                    op.push(c);
                } else if (c == '*' || c == '/') {
                    if (!op.empty() && op.top() != '(' && op.top() != '+' && op.top() != '-') {
                        ans += op.top();
                        op.pop();
                    }
                    op.push(c);
                } else if (c == '(') {
                    op.push(c);
                } else if (c == ')') {
                    while (!op.empty() && op.top() != '(') {
                        ans += op.top();
                        op.pop();
                    }
                    op.pop();
                }
            }
        }
        if (afterDigit) ans += '#';
        while (!op.empty()) {
            ans += op.top();
            op.pop();
        }
        return ans;
    }
    int evalSuffix(string str) {
        stack<int> s;
        for (int i = 0; i < str.size(); ++i) {
            char c = str[i];
            if (isdigit(c)) {
                int start = i;
                while (i < str.length() && isdigit(str[i])) ++i;
                s.push(evalNum(str.substr(start, i - start)));
            } else {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                switch (c) {
                    case '+': s.push(a + b); break;
                    case '-': s.push(a - b); break;
                    case '*': s.push(a * b); break;
                    case '/': s.push(a / b); break;
                }
            }
        }
        return s.top();
    }
    int evalNum(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            ans = ans * 10 + (s[i] - '0');
        }
        return ans;
    }
public:
    int calculate(string s) {
        return evalSuffix(infixToSuffix(s));
    }
};