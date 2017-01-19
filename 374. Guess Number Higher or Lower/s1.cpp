// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int L = 1, R = n, M, G;
        while (L <= R) {
            M = L + (R - L) / 2;
            G = guess(M);
            if (G == 0) {
                return M;
            } else if (G == 1) {
                L = M + 1;
            } else {
                R = M - 1;
            }
        }
        return -1;
    }
};