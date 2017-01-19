class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0, sum = 0, mask = 1;
        int da, db;
        for (int i = 0; i < 32; ++i) {
            da = a & mask;
            db = b & mask;
            sum |= da ^ db ^ carry;
            mask <<= 1;
            carry = (da && db || da && carry || db && carry) ? mask: 0;
        }
        return sum;
    }
};