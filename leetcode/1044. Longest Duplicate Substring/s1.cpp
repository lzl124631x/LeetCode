// OJ: https://leetcode.com/problems/longest-duplicate-substring/
// Author: github.com/lzl124631x
// Time: O(N^2logN)
// Space: O(N)
class Solution {
    typedef long long LL;
    string getDup(string &S, int len) {
        unordered_map<LL, vector<int>> m;
        LL h = S[0], p = 1, d = 128, mod = 1e9 + 7;
        for (int i = 1; i < len; ++i) {
            h = (h * d + S[i]) % mod;
            p = (p * d) % mod;
        }
        m[h].push_back(0);
        for (int i = len; i < S.size(); ++i) {
            h = ((h - S[i - len] * p) * d + S[i]) % mod;
            if (h < 0) h += mod;
            if (m.count(h)) {
                auto s = S.substr(i - len + 1, len);
                for (int start : m[h]) {
                    if (S.substr(start, len) == s) return s;
                }
            }
            m[h].push_back(i - len + 1);
        }
        return "";
    }
public:
    string longestDupSubstring(string S) {
        int L = 0, R = S.size() - 1;
        string ans;
        while (L <= R) {
            int M = (L + R) / 2;
            auto s = getDup(S, M);
            if (s.size()) {
                L = M + 1;
                ans = s;
            } else R = M - 1;
        }
        return ans;
    }
};