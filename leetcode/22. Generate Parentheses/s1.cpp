class Solution {
private:
    vector<string> ans;
    void generate(int leftCnt, int rightCnt, string &s) {
        if (!leftCnt && !rightCnt) {
            ans.push_back(s);
            return;
        }
        if (leftCnt) {
            s.push_back('(');
            generate(leftCnt - 1, rightCnt, s);
            s.pop_back();
        }
        if (rightCnt > leftCnt) {
            s.push_back(')');
            generate(leftCnt, rightCnt - 1, s);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s;
        generate(n, n, s);
        return ans;
    }
};