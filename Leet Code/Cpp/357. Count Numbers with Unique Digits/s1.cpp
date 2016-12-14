class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        if (n == 1) return 10;
        int cnt = 10, d = 9;
        for (int i = 0; i < n - 1 && i < 9; ++i) {
            d *= 9 - i;
            cnt += d;
        }
        return cnt;
    }
};