class Solution {
public:
    int arrangeCoins(int n) {
        int k = 0, sum = 0;
        while (n - sum > k) {
            ++k;
            sum += k;
        }
        return k;
    }
};