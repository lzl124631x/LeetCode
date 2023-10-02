// OJ: https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/
// Author: github.com/lzl124631x
// Time: O((logK)^2)
// Space: O(1)
class Solution {
private:
    int getZeros(int i) {
        int ans = 0;
        while (i) {
            ans += i;
            i /= 5;
        }
        return ans;
    }
public:
    int preimageSizeFZF(int K) {
        if (!K) return 5;
        int i = 1;
        while (getZeros(i) < K) i *= 5;
        int L = i / 5, R = i;
        while (L <= R) {
            int M = (L + R) / 2;
            int z = getZeros(M);
            if (z == K) return 5;
            if (z < K) L = M + 1;
            else R = M - 1;
        }
        return 0;
    }
};