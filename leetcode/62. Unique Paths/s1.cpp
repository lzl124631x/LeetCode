class Solution {
public:
    int uniquePaths(int m, int n) {
        long long a = 1, b = 1;
        for (int i = 1; i <= n - 1; ++i) {
            a *= m - 1 + i;
            if (a / i) a /= i;
            else b *= i;
        }
        return a / b;
    }
};