class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int N = A.size(), ans = INT_MAX;
        vector<int> sum(N + 1, 0);
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + A[i];
        for (int i = 0; i < N; ++i) {
            if (A[i] <= 0) continue;
            for (int j = i + 1; j <= N && j - i < ans; ++j) {
                if (sum[j] - sum[i] >= K) {
                    ans = min(ans, j - i);
                } 
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};