// OJ: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(2^K)
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> st;
        int n = 0, mask = (1 << k) - 1;
        for (int i = 0; i < s.size(); ++i) {
            n = (n << 1) & mask | (s[i] - '0');
            if (i >= k - 1) st.insert(n);
            if (st.size() == (1 << k)) return true;
        }
        return false;
    }
};