// OJ: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Author: github.com/lzl124631x
// Time: O(min(N, 2^K))
// Space: O(2^K)
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<bool> v(1 << k);
        int n = 0, mask = (1 << k) - 1;
        for (int i = 0; i < s.size(); ++i) {
            n = (n << 1) & mask | (s[i] - '0');
            if (i >= k - 1) v[n] = true;
        }
        for (int i = 0; i < (1 << k); ++i) {
            if (!v[i]) return false;
        }
        return true;
    }
};