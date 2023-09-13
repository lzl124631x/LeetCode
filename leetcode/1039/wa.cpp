// OJ: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
// Author: github.com/lzl124631x
// Note: WA on input [1,3,1,4,1,5]. It's because dp function might work outside of the current polygon.
class Solution {
private:
    int getKey(int i, int len) {
        return i * 100 + len;
    }
    unordered_map<int, int> m;
    int dp(vector<int>& A, int i, int len) {
        int N = A.size();
        i %= N;
        if (len == 3) return A[i] * A[(i + 1) % N] * A[(i + 2) % N];
        int k = getKey(i, len);
        if (m.find(k) != m.end()) return m[k];
        int ans = INT_MAX;
        for (int j = 0; j < len; ++j) {
            int val = dp(A, i + j, 3) + dp(A, i + (j + 2) % len, len - 1);
            ans = min(ans, val);
        }
        return m[k] = ans;
    }
public:
    int minScoreTriangulation(vector<int>& A) {
        return dp(A, 0, A.size());
    }
};