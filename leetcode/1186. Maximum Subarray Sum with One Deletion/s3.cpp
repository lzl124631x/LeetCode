// OJ: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/discuss/377397/Intuitive-Java-Solution-With-Explanation
class Solution {
public:
    int maximumSum(vector<int>& A) {
        int N = A.size(), ans = A[0];
        vector<int> maxEndHere(N), maxStartHere(N);
        maxEndHere[0] = A[0];
        for (int i = 1; i < N; ++i) {
            maxEndHere[i] = max(A[i], maxEndHere[i - 1] + A[i]);
            ans = max(ans, maxEndHere[i]);
        }
        maxStartHere[N - 1] = A[N - 1];
        for (int i = N - 2; i >= 0; --i) maxStartHere[i] = max(A[i], maxStartHere[i + 1] + A[i]);
        for (int i = 1; i < N - 1; ++i) ans = max(ans, maxEndHere[i - 1] + maxStartHere[i + 1]);
        return ans;
    }
};