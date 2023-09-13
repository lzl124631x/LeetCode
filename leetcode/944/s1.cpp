// OJ: https://leetcode.com/problems/delete-columns-to-make-sorted
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            int j = 1;
            for (; j < M && A[j][i] >= A[j - 1][i]; ++j);
            if (j < M) ans++;
        }
        return ans;
    }
};