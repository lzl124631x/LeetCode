class Solution {
private:
    vector<vector<int>> matrix;
    vector<vector<int>> memo;
    int M, N;
    void bfs(int i, int j, int mask) {
        if (memo[i][j] & mask) return;
        memo[i][j] |= mask;
        if (i - 1 >= 0 && matrix[i - 1][j] >= matrix[i][j]) bfs(i - 1, j, mask);
        if (j - 1 >= 0 && matrix[i][j - 1] >= matrix[i][j]) bfs(i, j - 1, mask);
        if (i + 1 < M && matrix[i + 1][j] >= matrix[i][j]) bfs(i + 1, j, mask);
        if (j + 1 < N && matrix[i][j + 1] >= matrix[i][j]) bfs(i, j + 1, mask);
    }
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        if (matrix.empty() || matrix[0].empty()) return {};
        vector<pair<int, int>> ans;
        M = matrix.size(), N = matrix[0].size();
        memo = vector<vector<int>>(M, vector<int>(N, 0));
        for (int i = 0; i < N; ++i) bfs(0, i, 1);
        for (int i = 0; i < M; ++i) bfs(i, 0, 1);
        for (int i = 0; i < M; ++i) bfs(i, N - 1, 2);
        for (int i = 0; i < N; ++i) bfs(M - 1, i, 2);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (memo[i][j] == 3) ans.push_back(make_pair(i, j));
            }
        }
        return ans;
    }
};