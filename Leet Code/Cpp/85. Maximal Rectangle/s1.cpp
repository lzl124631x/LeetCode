class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int ret = 0, M = matrix.size(), N = matrix[0].size();
        vector<int> left(N, 0), right(N, N), height(N, 0);
        for (int i = 0; i < M; ++i) {
            int curLeft = 0, curRight = N;
            for (int j = 0; j < N; ++j) {
                if (matrix[i][j] == '1') ++height[j];
                else height[j] = 0;
            }
            for (int j = 0; j < N; ++j) {
                if (matrix[i][j] == '1') left[j] = max(left[j], curLeft);
                else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }
            for (int j = N - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') right[j] = min(right[j], curRight);
                else {
                    right[j] = N;
                    curRight = j;
                }
            }
            for (int j = 0; j < N; ++j) {
                ret = max(ret, (right[j] - left[j]) * height[j]);
            }
        }
        return ret;
    }
};