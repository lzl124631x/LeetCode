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