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