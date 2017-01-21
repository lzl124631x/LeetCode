class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) return 0;
        long long y = 1;
        while (y * y <= (long long) x) ++y;
        return y - 1;
    }
};