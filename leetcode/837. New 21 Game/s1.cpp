// OJ: https://leetcode.com/problems/new-21-game/
// Author: github.com/lzl124631x
// Time: O(KW)
// Space: O(1)
// NOTE: This solution will get TLE
class Solution {
public:
    double new21Game(int N, int K, int W) {
        vector<double> p(K + W + 1);
        p[0] = 1;
        for (int i = 0; i < K; ++i) {
            for (int j = 1; j <= W && i + j <= N; ++j) {
                p[i + j] += p[i] / W;
            }
        }
        double ans = 0;
        for (int i = K; i <= N; ++i) ans += p[i];
        return ans;
    }
};