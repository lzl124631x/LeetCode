class Solution {
public:
    bool isPerfectSquare(int num) {
        int L = 1, R = num;
        while (L <= R) {
            int M = L + (R - L) / 2;
            if (M * M == num) return true;
            if (num / M < M) R = M - 1;
            else L = M + 1;
        }
        return false;
    }
};