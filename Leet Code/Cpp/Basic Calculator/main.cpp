#include <stack>
#include <iostream>
#include "../+Helper/helper.h"
using namespace std;

/*
* Number might be multi-digit.
* infixToSuffix: Remember push from the stack all the signs of the same or GEATER significance.
*/

class Solution {
public:
    int calculate(string str) {
        return evalSuffix(infixToSuffix(str));
    }
public:
    string infixToSuffix(string str) {
        string out;
        stack<char> s;
        bool afterDigit = false;
        for (int i = 0; i < str.length(); ++i) {
            char c = str[i];
            if (isspace(c)) continue;
            if (isdigit(c)) {
                out += c;
                afterDigit = true;
            } else {
                if (afterDigit) {
                    out += '#'; // number separater.
                    afterDigit = false;
                }
                if (c == '+' || c == '-') {
                    if (!s.empty() && s.top() != '(') {
                        out += s.top();
                        s.pop();
                    }
                    s.push(c);
                } else if (c == '(') {
                    s.push(c);
                } else if (c == ')') {
                    while (!s.empty() && s.top() != '(') {
                        out += s.top();
                        s.pop();
                    }
                    if (!s.empty()) {
                        s.pop();
                    }
                }
            }
        }
        if (afterDigit) {
            out += '#';
        }
        while (!s.empty()) {
            out += s.top();
            s.pop();
        }
        return out;
    }
    
    int evalSuffix(string str) {
        stack<int> s;
        for (int i = 0; i < str.length(); ++i) {
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
                if (c == '+') {
                    s.push(a + b);
                } else {
                    s.push(a - b);
                }
            }
        }
        return s.top();
    }
    
    int evalNum(string str) {
        int out = 0;
        for (int i = 0; i < str.length(); ++i) {
            out = out * 10 + (str[i] - '0');
        }
        return out;
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    CLK_INIT;
    Solution s;
    CASET{
        string str;
        cin >> str;
        PRINTCASE;
        CLK_START;
        cout << s.calculate(str) << endl;
        CLK_END;
    }
}