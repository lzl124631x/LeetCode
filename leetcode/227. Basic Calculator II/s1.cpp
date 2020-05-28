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