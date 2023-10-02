// OJ: https://leetcode.com/problems/generate-parentheses/
// Author: github.com/lzl124631x
// Time: O(C(N)) where C(N) is the Nth Catalan number
// Space: O(N)
class Solution {
private:
    vector<string> ans;
    void generate(int leftCnt, int rightCnt, int i, string &s) {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }
        if (leftCnt) {
            s[i] = '(';
            generate(leftCnt - 1, rightCnt, i + 1, s);
        }
        if (rightCnt > leftCnt) {
            s[i] = ')';
            generate(leftCnt, rightCnt - 1, i + 1, s);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s(2 * n, '\0');
        generate(n, n, 0, s);
        return ans;
    }
};