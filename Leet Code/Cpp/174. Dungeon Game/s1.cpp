class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) return 0;
        int M = dungeon.size(), N = dungeon[0].size();
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (i == M - 1 && j == N - 1) {
                    dungeon[i][j] = 1 + max(0, -dungeon[i][j]);
                    continue;
                }
                int val = INT_MAX;
                if (i + 1 < M) val = min(val, max(1, dungeon[i + 1][j] - dungeon[i][j]));
                if (j + 1 < N) val = min(val, max(1, dungeon[i][j + 1] - dungeon[i][j]));
                dungeon[i][j] = val;
            }
        }
        return dungeon[0][0];
    }
};