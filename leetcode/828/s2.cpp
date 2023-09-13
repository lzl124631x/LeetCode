// OJ: https://leetcode.com/problems/unique-letter-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int uniqueLetterString(string S) {
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < S.size(); ++i) {
            m[S[i]].push_back(i);
        }
        int ans = 0, mod = 1e9 + 7;
        for (auto it = m.begin(); it != m.end(); ++it) {
            char c = it->first;
            auto &v = it->second;
            for (int i = 0; i < v.size(); ++i) {
                int prev = i == 0 ? -1 : v[i - 1];
                int next = i < v.size() - 1 ? v[i + 1] : S.size();
                ans = (ans + (v[i] - prev) * (next - v[i]) % mod) % mod;
            }
        }
        return ans;
    }
};