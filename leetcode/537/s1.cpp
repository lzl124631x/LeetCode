// OJ: https://leetcode.com/problems/complex-number-multiplication/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    vector<int> parse(string &s) {
        vector<int> ans(2, 0);
        ans[0] = stoi(s);
        int i = s.find_first_of("+");
        ans[1] = stoi(s.substr(i + 1));
        return ans;
    }
public:
    string complexNumberMultiply(string a, string b) {
        auto m = parse(a), n = parse(b);
        int x = m[0] * n[0] - m[1] * n[1], y = m[1] * n[0] + m[0] * n[1];
        return to_string(x) + "+" + to_string(y) + "i";
    }
};