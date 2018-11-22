// OJ: https://leetcode.com/problems/di-string-match/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans(S.size() + 1, 0);
        int lo = 0, hi = S.size();
        for (int i = 0; i < S.size(); ++i) {
            ans[i] = S[i] == 'I' ? lo++ : hi--;
        }
        ans[S.size()] = lo;
        return ans;
    }
};