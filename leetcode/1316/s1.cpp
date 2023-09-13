// OJ: https://leetcode.com/problems/distinct-echo-substrings/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int distinctEchoSubstrings(string s) {
        int N = s.size(), mod = 1e8 + 7, cnt = 0;
        vector<long> v(N);
        for (int len = 1; len <= N / 2; ++len) {
            long hash = s[0] - 'a', p = 1;
            unordered_set<string> seen;
            for (int i = 1; i < N; ++i) {
                if (i < len) {
                    hash = (hash * 26 + s[i] - 'a') % mod;
                    p = (p * 26) % mod;
                } else {
                    hash = ((hash - (s[i - len] - 'a') * p) * 26 + s[i] - 'a') % mod;
                    if (hash < 0) hash += mod;
                    if (i - 2 * len + 1 >= 0 && v[i - len] == hash) {
                        auto a = s.substr(i - 2 * len + 1, len);
                        if (seen.count(a)) continue;
                        seen.insert(a);
                        if (a == s.substr(i - len + 1, len)) ++cnt;
                    }
                }
                v[i] = hash;
            }
        }
        return cnt;
    }
};