// OJ: https://leetcode.com/problems/delete-columns-to-make-sorted-ii
// Author: github.com/lzl124631x
// Time: O(MN) where M is size of A, N is length of strings in A.
// Space: O(M)
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int M = A.size(), cnt = 0;
        vector<bool> equalPrev(M, true);
        for (int i = 0; i < A[0].size(); ++i) {
            int j = 1;
            while (j < M) {
                if (equalPrev[j] && A[j][i] < A[j - 1][i]) break;
                ++j;
            }
            if (j < M) {
                ++cnt;
                continue;
            }
            for (j = 1; j < M; ++j) {
                equalPrev[j] = equalPrev[j] && (A[j][i] == A[j - 1][i]);
            }
        }
        return cnt;
    }
};