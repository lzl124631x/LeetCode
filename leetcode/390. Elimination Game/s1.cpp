class Solution {
public:
    int lastRemaining(int n) {
        int d = 2, i = 1, next = 2;
        while (next >= 1 && next <= n) {
            i = next;
            while (i + d <= n && i + d >= 1) i += d;
            next = i - d;
            d *= -2;
        }
        return i;
    }
};