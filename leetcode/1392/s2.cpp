// OJ: https://leetcode.com/problems/longest-happy-prefix/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/longest-happy-prefix/discuss/547446/C%2B%2BJava-with-picture-incremental-hash-and-DP
class Solution {
    typedef unsigned long long ULL;
public:
    string longestPrefix(string s) {
        ULL N = s.size(), len = 0, mod = 1e9+7, L = 0 , R = 0, mul = 1;
        for (int i = 0; i < N - 1; ++i) {
            L = (L * 26 + s[i] - 'a') % mod;
            R = (R + mul * (s[N - 1 - i] - 'a')) % mod;
            if (L == R) len = i + 1;
            mul = mul * 26 % mod;
        }
        return s.substr(0, len);
    }
};