class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string s;
        for (int i = 0; i < 8 && num; ++i) {
            int x = num & ((1 << 4) - 1);
            if (x < 10) {
                s += '0' + x;
            } else {
                s += 'a' + (x - 10);
            }
            num >>= 4;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};