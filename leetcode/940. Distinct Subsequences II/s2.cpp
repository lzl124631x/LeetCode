// OJ: https://leetcode.com/problems/distinct-subsequences-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int distinctSubseqII(string S) {
        int N = S.size(), mod = pow(10, 9) + 7;
        int picks[26] = {0};
        int pick = 0, noPick = 1;
        for (int i = 0; i < N; ++i) {
            noPick = (noPick + pick) % mod;
            pick = (noPick - picks[S[i] - 'a'] + mod) % mod;
            picks[S[i] - 'a'] = (picks[S[i] - 'a'] + pick) % mod;
        }
        return (pick + noPick - 1) % mod;
    }
};