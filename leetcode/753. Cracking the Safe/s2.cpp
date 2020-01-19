// OJ: https://leetcode.com/problems/cracking-the-safe/
// Author: github.com/lzl124631x
// Time: O(N^(K^N))
// Space: O(N*(K^N))
// Ref: https://leetcode.com/problems/cracking-the-safe/solution/
class Solution {
private:
    unordered_set<string> s;
    string ans;
    void dfs(string node, int k) {
        for (char i = '0'; i < '0' + k; ++i) {
            auto pwd = node + i;
            if (!s.count(pwd)) {
                s.insert(pwd);
                dfs(pwd.substr(1), k);
                ans.push_back(i);
            }
        }
    }
public:
    string crackSafe(int n, int k) {
        if (n == 1 && k == 1) return "0";
        string str(n - 1, '0');
        dfs(str, k);
        return ans + str;
    }
};