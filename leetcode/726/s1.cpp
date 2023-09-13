// OJ: https://leetcode.com/problems/number-of-atoms/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    int N;
    int readNum(string &s, int &i) {
        int cnt = 0;
        while (i < N && isdigit(s[i])) cnt = cnt * 10 + (s[i++] - '0');
        return cnt ? cnt : 1;
    }
    map<string, int> dfs(string &s, int &i, bool isInParens = false) {
        map<string, int> m;
        if (isInParens) ++i;
        while (i < N && s[i] != ')') {
            if (s[i] == '(') {
                auto mm = dfs(s, i, true);
                for (auto &p : mm) m[p.first] += p.second;
            } else {
                string symbol = string(1, s[i++]);
                while (i < N && islower(s[i])) symbol += s[i++];
                m[symbol] += readNum(s, i);
            }
        }
        if (isInParens) {
            ++i;
            int cnt = readNum(s, i);
            for (auto &p : m) p.second *= cnt;
        }
        return m;
    }
public:
    string countOfAtoms(string formula) {
        N = formula.size();
        int i = 0;
        auto m = dfs(formula, i);
        string ans;
        for (auto &p : m) ans += p.first + (p.second > 1 ? to_string(p.second) : "");
        return ans;
    }
};