// OJ: https://leetcode.com/problems/orderly-queue/
// Author: github.com/lzl124631x
// Time: O(S^2)
// Space: O(S)
class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        string ans = S;
        for (int i = 0; i < S.size(); ++i) {
            rotate(S.begin(), S.begin() + 1, S.end());
            if (S < ans) ans = S;
        }
        return ans;
    }
};