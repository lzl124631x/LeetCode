class Solution {
private:
    map<unsigned, bool> m;
    unsigned used = 0;
    int maxInt;
    
    bool rec(int total) {
        if (m.find(used) != m.end()) return m[used];
        bool canWin = false;
        for (int i = 1; i <= maxInt && !canWin; ++i) {
            unsigned mask = (1 << i);
            if (!(used & mask)) {
                used |= mask;
                canWin = i >= total || !rec(total - i);
                used &= ~mask;
            }
        }
        return m[used] = canWin;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;
        if (desiredTotal > (1 + maxChoosableInteger) * maxChoosableInteger / 2) return false;
        maxInt = maxChoosableInteger;
        return rec(desiredTotal);
    }
};