// OJ: https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
// Author: github.com/lzl124631x
// Time: O(N^2loglogN)
// Space: O(N)
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> cnt;
        for (int n : deck) cnt[n]++;
        int minCnt = INT_MAX;
        for (auto p : cnt) minCnt = min(minCnt, p.second);
        if (minCnt == 1) return false;
        for (int x = 2; x <= minCnt; ++x) {
            bool found = true;
            for (auto p : cnt) {
                if (p.second % x) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        }
        return false;
    }
};