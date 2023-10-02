// OJ: https://leetcode.com/problems/student-attendance-record-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int checkRecord(int n) {
        auto v = vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(3)));
        long long ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            for (int A = 0; A <= 1; ++A) {
                for (int L = 0; L <= 2; ++L) {
                    v[(i + 1) % 2][A][L] = 0;
                }
            }
            for (int A = 0; A <= 1; ++A) {
                for (int L = 0; L <= 2; ++L) {
                    if (A + L > i + 1) continue;
                    int val = i == 0 ? 1 : v[i % 2][A][L];
                    if (A != 1) v[(i + 1) % 2][A + 1][0] = (v[(i + 1) % 2][A + 1][0] + val) % mod;
                    if (L != 2) v[(i + 1) % 2][A][L + 1] = (v[(i + 1) % 2][A][L + 1] + val) % mod;
                    v[(i + 1) % 2][A][0] = (v[(i + 1) % 2][A][0] + val) % mod;
                    if (i == n - 1) ans = (ans + val) % mod;
                }
            }
        }
        return ans;
    }
};