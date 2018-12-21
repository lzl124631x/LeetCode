// OJ: https://leetcode.com/problems/strobogrammatic-number-ii/
// Author: github.com/lzl124631x
// Time: O(5^(N/2))
// Space: O(N)
class Solution {
private:
    char pairs[5][2] = { { '0', '0' }, { '1', '1' }, { '6', '9' }, { '8', '8' }, { '9', '6' }};
    vector<string> ans;
    void dfs(int start, int n, string &tmp) {
        if (start == (n + 1) / 2) {
            ans.push_back(tmp);
            return;
        }
        for (auto &p : pairs) {
            if (start == 0 && n != 1 && p[0] == '0') continue;
            if (start == n / 2 && n % 2 && p[0] != p[1]) continue;
            tmp[start] = p[0];
            tmp[n - start - 1] = p[1];
            dfs(start + 1, n, tmp);
        }
    }
public:
    vector<string> findStrobogrammatic(int n) {
        string tmp(n, '\0');
        dfs(0, n, tmp);
        return ans;
    }
};