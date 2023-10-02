// OJ: https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/
// Author: github.com/lzl124631x
// Time: O(2^N * M)
// Space: O(2^N)
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        vector<vector<int>> persons(40);
        int N = hats.size(), mod = 1e9+7;
        vector<int> masks(1 << N);
        masks[0] = 1;
        for (int i = 0; i < N; ++i) {
            for (int h : hats[i]) persons[h - 1].push_back(i);
        }
        for (int i = 0; i < 40; ++i) {
            for (int j = (1 << N) - 1; j >= 0; --j) {
                for (int p : persons[i]) {
                    if (j & (1 << p)) continue;
                    masks[j | (1 << p)] += masks[j];
                    masks[j | (1 << p)] %= mod;
                }
            }
        }
        return masks[(1 << N) - 1];
    }
};