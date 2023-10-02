// OJ: https://leetcode.com/problems/rotate-function/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) return 0;
        long long f = 0, ans = INT_MIN, N = A.size(), sum = accumulate(A.begin(), A.end(), (long long)0);
        for (int i = 0; i < N; ++i) f += i * A[i];
        for (int i = N - 1; i >= 0; --i) ans = max(ans, f += (sum - N * A[i]));
        return ans;
    }
};