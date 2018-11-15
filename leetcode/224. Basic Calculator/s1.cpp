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