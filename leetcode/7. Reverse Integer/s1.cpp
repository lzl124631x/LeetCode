class Solution {
public:
    int reverse(int x) {
        long long ans = 0, sign = x > 0 ? 1 : -1;
        x = abs(x);
        while (x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        ans *= sign;
        return ans > INT_MAX || ans < INT_MIN ? 0 : ans;
    }
};