// OJ: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    int get(vector<int> &v, int i) {
        return (i >= 0 && i < v.size()) ? v[i] : 0;
    }
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int N = A.size(), ans = 0;
        partial_sum(A.begin(), A.end(), A.begin());
        vector<int> maxLeft(N, 0), maxRight(N, 0);
        for (int i = L - 1; i < N; ++i) maxLeft[i] = max(get(maxLeft, i - 1), A[i] - get(A, i - L));
        for (int i = N - L; i >= 0; --i) maxRight[i] = max(get(maxRight, i + 1), A[i + L - 1] - get(A, i - 1));
        for (int i = M - 1; i < N; ++i) {
            int sum = A[i] - get(A, i - M)
                + max(get(maxLeft, i - M), get(maxRight, i + 1));
            ans = max(ans, sum);
        }
        return ans;
    }
};