// OJ: https://leetcode.com/problems/cracking-the-safe/
// Author: github.com/lzl124631x
// Time: O((NK)^(K^N))
// Space: O(N*(K^N))
class Solution {
private:
    unordered_set<string> s;
    string ans;
    int N, K, cnt;
    void dfs(string &str) {
        if (ans.size()) {
            return;
        }
        if (s.size() == cnt) {
            ans = str;
            return;
        }
        for (int i = 0; i < K; ++i) {
            str.push_back('0' + i);
            auto pwd = str.size() >= N ? str.substr(str.size() - N, N) : "";
            if (pwd.size() && !s.count(pwd)) {
                s.insert(pwd);
                dfs(str);
                s.erase(pwd);
            }
            str.pop_back();
        }
    }
public:
    string crackSafe(int n, int k) {
        string str(n, '0');
        s.insert(str);
        N = n, K = k, cnt = pow(K, N);
        dfs(str);
        return ans;
    }
};