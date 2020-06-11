// OJ: https://leetcode.com/problems/maximal-rectangle/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int ans = 0, M = A.size(), N = A[0].size();
        vector<int> left(N, 0), right(N, N), height(N, 0);
        for (int i = 0; i < M; ++i) {
            int curLeft = 0, curRight = N;
            for (int j = 0; j < N; ++j) height[j] = A[i][j] == '1' ? height[j] + 1 : 0;
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == '1') left[j] = max(left[j], curLeft);
                else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }
            for (int j = N - 1; j >= 0; --j) {
                if (A[i][j] == '1') right[j] = min(right[j], curRight);
                else {
                    right[j] = N;
                    curRight = j;
                }
            }
            for (int j = 0; j < N; ++j) ans = max(ans, (right[j] - left[j]) * height[j]);
        }
        return ans;
    }
};