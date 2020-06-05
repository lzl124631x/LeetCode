// OJ: https://leetcode.com/problems/spiral-matrix
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return {};
        vector<int> ans;
        int M = A.size(), N = A[0].size(), i = 0, j = 0, lv = 0;
        for (; ans.size() < M * N; ++lv) {
            for (int k = lv; k < N - lv; ++k) ans.push_back(A[i][j++]);
            --j, ++i;
            for (int k = lv; k < M - 1 - lv; ++k) ans.push_back(A[i++][j]);
            --i, --j;
            if (ans.size() == M * N) break;
            for (int k = lv; k < N - 1 - lv; ++k) ans.push_back(A[i][j--]);
            ++j, --i;
            for (int k = lv; k < M - 2 - lv; ++k) ans.push_back(A[i--][j]);
            ++i, ++j;
        }
        return ans;
    }
};