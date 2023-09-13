// OJ: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        int ans = 0, N = A.size();
        for (int N = A.size(); N > 1; --N) {
            int best = 1;
            for (int i = 2; i < N; ++i) {
                if (A[i] * A[i - 1] < A[best] * A[best - 1]) best = i;
            }
            ans += A[best] * A[best - 1];
            if (A[best] > A[best - 1]) --best;
            A.erase(A.begin() + best);
        }
        return ans;
    }
};