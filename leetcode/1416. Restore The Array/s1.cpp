// OJ: https://leetcode.com/problems/restore-the-array/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    typedef long long LL;
public:
    int numberOfArrays(string s, int k) {
        if (s[0] - '0' > k) return 0;
        int cnt = 0, tmp = k;
        while (tmp) {
            tmp /= 10;
            ++cnt;
        }
        int N = s.size(), mod = 1e9+7;
        vector<int> dp(N + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= N; ++i) {
            LL p = 1, n = 0;
            for (int j = i - 1; j >= 0; --j) {
                n += (s[j] - '0') * p;
                p *= 10;
                if (n > k || i - j > cnt) break;
                if (n == 0 || s[j] == '0') continue;
                dp[i] = (dp[i] + dp[j]) % mod;
            }
        }
        return dp[N];
    }
};