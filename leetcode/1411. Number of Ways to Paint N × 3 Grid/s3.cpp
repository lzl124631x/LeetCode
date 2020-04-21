// OJ: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
// Ref: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/discuss/575485/C%2B%2BPython-O(logN)-Time
class Solution {
    typedef long long LL;
    int mod = 1e9+7;
    vector<vector<LL>> mul(vector<vector<LL>> &A, vector<vector<LL>> &B) {
        int N = A.size(), L = B.size(), M = B[0].size();
        vector<vector<LL>> C(N, vector<LL>(M));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                for (int k = 0; k < L; ++k) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
        return C;
    }
public:
    int numOfWays(int n) {
        vector<vector<LL>> ans = {{6, 6}}, M = {{3, 2}, {2, 2}};
        for (--n; n; n >>= 1, M = mul(M, M)) {
            if (n % 2) ans = mul(ans, M);
        }
        return (ans[0][0] + ans[0][1]) % mod;
    }
};