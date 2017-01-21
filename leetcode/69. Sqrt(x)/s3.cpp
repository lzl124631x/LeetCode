// https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
// Newton's method
class Solution {
public:
    int mySqrt(int x) {
        long long r = x;
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;
    }
};