// OJ: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/discuss/278251/JavaC%2B%2BPython-O(N)Time-O(1)-Space
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        partial_sum(A.begin(), A.end(), A.begin());
        int ans = A[L + M - 1], Lmax = A[L - 1], Mmax = A[M - 1];
        for (int i = L + M; i < A.size(); ++i) {
            Lmax = max(Lmax, A[i - M] - A[i - L - M]);
            Mmax = max(Mmax, A[i - L] - A[i - L - M]);
            ans = max(ans, max(Lmax + A[i] - A[i - M], Mmax + A[i] - A[i - L]));
        }
        return ans;
    }
};