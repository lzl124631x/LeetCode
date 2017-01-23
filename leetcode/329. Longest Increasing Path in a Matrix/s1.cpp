class Solution {
private:
    vector<vector<int>> dir {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<int>> memo;
    int M, N;
    vector<vector<int>> matrix;
    int ans = 0;
    int dfs(int i, int j) {
        if (memo[i][j] > 0) return memo[i][j];
        int maxLen = 1;
        for (auto d : dir) {
            int dx = i + d[0], dy = j + d[1];
            if (dx >= 0 && dx < M && dy >= 0 && dy < N && matrix[dx][dy] < matrix[i][j]) {
                int len = dfs(dx, dy);
                maxLen = max(maxLen, 1 + len);
            } 
        }
        ans = max(ans, maxLen);
        return memo[i][j] = maxLen;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        if (matrix.empty() || matrix[0].empty()) return 0;
        M = matrix.size(), N = matrix[0].size();
        memo = vector<vector<int>>(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dfs(i, j);
            }
        }
        return ans;
    }
};