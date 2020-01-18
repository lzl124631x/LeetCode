// OJ: https://leetcode.com/problems/cracking-the-safe/
// Author: github.com/lzl124631x
// Time: O((NK)^(K^N))
// Space: O(N*(K^N))
class Solution {
private:
    unordered_set<string> s;
    string ans;
    int N, K, cnt;
    bool dfs(string &str) {
        if (s.size() == cnt) {
            ans = str;
            return true;
        }
        for (int i = 0; i < K; ++i) {
            str.push_back('0' + i);
            auto pwd = str.substr(str.size() - N, N);
            if (!s.count(pwd)) {
                s.insert(pwd);
                if (dfs(str)) return true;
                s.erase(pwd);
            }
            str.pop_back();
        }
        return false;
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