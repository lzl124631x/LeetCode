// OJ: https://leetcode.com/problems/generate-parentheses/
// Author: github.com/lzl124631x
// Time: O(N^2 * C(N)) where C(N) is the Nth Catalan number
// Space: O(C(N))
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) return { "" };
        auto prev = generateParenthesis(n - 1);
        unordered_set<string> s;
        for (int i = 0; i < prev.size(); ++i) {
            for (int j = 0; j < 2 * n - 1; ++j) {
                s.insert(prev[i].substr(0, j) + "()" + prev[i].substr(j));
            }
        }
        return vector<string>(s.begin(), s.end());
    }
};