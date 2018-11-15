// OJ: https://leetcode.com/problems/koko-eating-bananas/
// Author: github.com/lzl124631x
// Time: O(P*log(P_max)) where P is count of piles, P_max is max pile size.
// Space: O(K)
class Solution {
private:
    int countH(vector<int> &piles, int K) {
        int cnt = 0;
        for (int p : piles) cnt += (p + K - 1) / K;
        return cnt;
    }
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int L = 1, R = *max_element(piles.begin(), piles.end());
        while (L <= R) {
            int M = L + (R - L) / 2;
            int h = countH(piles, M);
            if (h > H) L = M + 1;
            else R = M - 1;
        }
        return L;
    }
};