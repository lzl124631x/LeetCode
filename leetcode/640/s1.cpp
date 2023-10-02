// OJ: https://leetcode.com/problems/solve-the-equation/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    int read(string &equation, int pos, bool &isNum, int &num) {
        if (equation[pos] == '=') ++pos;
        int sign = 1, N = equation.size();
        if (equation[pos] == '+' || equation[pos] == '-') {
            if (equation[pos] == '-') sign = -1;
            ++pos;
        }
        if (pos < N && equation[pos] == 'x') {
            num = 1;
        } else {
            num = 0;
            while (pos < N && isdigit(equation[pos])) {
                num = num * 10 + equation[pos++] - '0';
            }
        }
        isNum = true;
        if (pos < N && equation[pos] == 'x') {
            isNum = false;
            ++pos;
        }
        num *= sign;
        return pos;
    }
public:
    string solveEquation(string equation) {
        int i = 0, N = equation.size(), space = equation.find_first_of("=");
        int coef = 0, val = 0;
        while (i < N) {
            bool isNum;
            int num;
            i = read(equation, i, isNum, num);
            int sign = i <= space ? 1 : -1;
            if (isNum) val -= sign * num;
            else coef += sign * num;
        }
        if (coef) return "x=" + to_string(val / coef);
        return val ? "No solution" : "Infinite solutions";
    }
};