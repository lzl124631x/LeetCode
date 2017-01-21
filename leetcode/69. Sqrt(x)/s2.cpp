class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) return 0;
        int L = 1, R = INT_MAX;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (x / M == M) return M;
            else if (x / M > M) L = M + 1;
            else R = M - 1;
        }
        return x / L >= L ? L : L - 1;
    }
};