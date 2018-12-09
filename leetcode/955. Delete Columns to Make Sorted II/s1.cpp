// OJ: https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
// Author: github.com/lzl124631x
// Time: O(N^2 * M)
// Space: O(MN)
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int M = A.size();
        vector<string> v(M, "");
        for (int i = 0; i < A[0].size(); ++i) {
            int j = 1;
            while (j < M) {
                if (v[j] == v[j - 1] && A[j][i] < A[j - 1][i]) break;
                ++j;
            }
            if (j < M) continue;
            for (int k = 0; k < M; ++k) {
                v[k].push_back(A[k][i]);
            }
        }
        return A[0].size() - v[0].size();
    }
};