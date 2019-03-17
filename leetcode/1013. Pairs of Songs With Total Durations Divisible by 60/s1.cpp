// OJ: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
// Author: github.com/lzl124631x
// Time: O(T)
// Space: O(1)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(501, 0);
        int ans = 0;
        for (int t : time) cnt[t]++;
        for (int i = 1; i <= 500; ++i) {
            if (!cnt[i]) continue;
            if (cnt[i] >= 2 && 2 * i % 60 == 0) ans += cnt[i] * (cnt[i] - 1) / 2;
            for (int j = i + 1; j <= 500; ++j) {
                if (!cnt[j] || (i + j) % 60) continue;
                ans += cnt[i] * cnt[j];
            }
        }
        return ans;
    }
};