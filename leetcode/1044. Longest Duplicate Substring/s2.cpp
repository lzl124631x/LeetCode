// OJ: https://leetcode.com/problems/longest-duplicate-substring/
// Author: github.com/lzl124631x
// Time: O(N^2 * logN)
// Space: O(N)
// Ref: https://leetcode.com/problems/longest-duplicate-substring/discuss/695101/C%2B%2B-short-O(n-log(n))-solution-with-std%3A%3Aunordered_setlessstd%3A%3Astring_viewgreater
class Solution {
public:
    string longestDupSubstring(string S) {
        int N = S.size(), L = 0, R = N - 1;
        string_view ans;
        while (L <= R) {
            unordered_set<string_view> s;
            int M = (L + R) / 2;
            bool found = false;
            for (int i = 0; i <= N - M; ++i) {
                const auto [it, inserted] = s.emplace(S.data() + i, M);
                if (!inserted) {
                    found = true;
                    ans = *it;
                    break;
                }
            }
            if (found) L = M + 1;
            else R = M - 1;
        }
        return {ans.begin(), ans.end()};
    }
};