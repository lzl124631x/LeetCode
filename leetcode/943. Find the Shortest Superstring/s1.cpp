// OJ: https://leetcode.com/problems/find-the-shortest-superstring/
// Author: github.com/lzl124631x
// Time: O(N^2 * (2^N + W))
// Space: O(N * (2^N + W))
// Ref: https://leetcode.com/problems/find-the-shortest-superstring/solution/
class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int N = A.size();
        vector<vector<int>> overlaps(N, vector<int>(N));
        for (int i = 0; i < N ; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                int len = min(A[i].size(), A[j].size());
                for (int k = len; k >= 0; --k) {
                    if (A[i].substr(A[i].size() - k) != (A[j].substr(0, k))) continue;
                    overlaps[i][j] = k;
                    break;
                }
            }
        }
        vector<vector<int>> dp(1 << N, vector<int>(N));
        vector<vector<int>> parent(1 << N, vector<int>(N, -1));
        for (int mask = 0; mask < (1 << N); ++mask) {
            for (int bit = 0; bit < N; ++bit) {
                if (((mask >> bit) & 1) == 0) continue;
                int pmask = mask ^ (1 << bit);
                if (pmask == 0) continue;
                for (int i = 0; i < N; ++i) {
                    if (((pmask >> i) & 1) == 0) continue;
                    int val = dp[pmask][i] + overlaps[i][bit];
                    if (val > dp[mask][bit]) {
                        dp[mask][bit] = val;
                        parent[mask][bit] = i;
                    }
                }
            }
        }
        vector<int> perm(N);
        vector<bool> seen(N);
        int t = 0, mask = (1 << N) - 1, p = 0;
        for (int j = 0; j < N; ++j) {
            if (dp[(1 << N) - 1][j] > dp[(1 << N) - 1][p]) p = j;
        }
        while (p != -1) {
            perm[t++] = p;
            seen[p] = true;
            int p2 = parent[mask][p];
            mask ^= 1 << p;
            p = p2;
        }
        reverse(perm.begin(), perm.begin() + t);
        for (int i = 0; i < N; ++i) {
            if (!seen[i]) perm[t++] = i;
        }
        string ans = A[perm[0]];
        for (int i = 1; i < N; ++i) {
            int overlap = overlaps[perm[i - 1]][perm[i]];
            ans += A[perm[i]].substr(overlap);
        }
        return ans;
    }
};