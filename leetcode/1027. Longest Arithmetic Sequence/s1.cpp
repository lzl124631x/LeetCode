// OJ: https://leetcode.com/problems/longest-arithmetic-sequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> m;
        int ans = 0;
        for (int n : A) {
            m[n] = {};
            for (auto &p : m) {
                int d = n - p.first;
                ans = max(ans, m[n][d] = p.second.count(d) ? p.second[d] + 1 : 2);
            }
        }
        return ans;
    }
};