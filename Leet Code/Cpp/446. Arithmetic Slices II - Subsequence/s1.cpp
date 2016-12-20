class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.empty()) return 0;
        int cnt = 0, N = A.size();
        vector<unordered_map<long long, int>> dp(N);
        unordered_set<int> s(A.begin(), A.end());
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                long long d = (long long)A[i] - A[j];
                int count = dp[j].count(d) ? dp[j][d] : 0;
                cnt += count;
                if (s.count(A[i] + d)) dp[i][d] += 1 + count;
            }
        }
        return cnt;
    }
};