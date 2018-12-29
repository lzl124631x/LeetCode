// OJ: https://leetcode.com/problems/flip-game/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        for (int i = 1, N = s.size(); i < N; ++i) {
            if (s[i] != '+' || s[i - 1] != '+') continue;
            ans.push_back(s);
            ans.back()[i] = ans.back()[i - 1] = '-';
        }
        return ans;
    }
};