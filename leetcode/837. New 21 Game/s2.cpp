// OJ: https://leetcode.com/problems/new-21-game/
// Author: github.com/lzl124631x
// Time: O(K + W)
// Space: O(K + W)
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (!K || N >= K + W - 1) return 1;
        vector<double> p(K + W + 1);
        p[0] = 1;
        double ans = 0;
        for (int i = 1; i <= N; ++i) {
            if (i > 1) p[i] += p[i - 1];
            if (i <= K) p[i] += p[i - 1] / W;
            if (i > W) p[i] -= p[i - W - 1] / W;
            if (i >= K) ans += p[i]; 
        }
        return ans;
    }
};