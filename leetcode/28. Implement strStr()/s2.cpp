// OJ: https://leetcode.com/problems/implement-strstr/
// Author: github.com/lzl124631x
// Time: average O(S+T), worst O(ST)
// Space: O(1)
class Solution {
    typedef long long LL;
public:
    int strStr(string s, string t) {
        int S = s.size(), T = t.size(), d = 128; 
        if (!S || !T || T > S) return T ? -1 : 0;
        LL m = 1e9+7, p = 1, hs = s[0], ht = t[0];
        for (int i = 1; i < T; ++i) {
            p = (p * d) % m; // we need d^(T-1)
            ht = (ht * d + t[i]) % m;
            hs = (hs * d + s[i]) % m;
        }
        for (int i = 0; i <= S - T; ++i) { // Loop for each start/pop point
            if (hs == ht) { // in case of collision, check the equity.
                int j = 0;
                for (; j < T && s[i + j] == t[j]; ++j);
                if (j == T) return i;
            }
            if (i < S - T) hs = ((hs - s[i] * p) * d + s[i + T]) % m;
            if (hs < 0) hs += m; // we might get negative hs, converting it to positive
        }
        return -1;
    }
};