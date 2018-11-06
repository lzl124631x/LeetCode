// OJ: https://leetcode.com/problems/dungeon-game
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int M = dungeon.size(), N = dungeon[0].size();
    for (int i = M - 1; i >= 0; --i) {
      for (int j = N - 1; j >= 0; --j) {
        int val = INT_MAX;
        if (i + 1 < M) val = min(val, dungeon[i + 1][j]);
        if (j + 1 < N) val = min(val, dungeon[i][j + 1]);
        dungeon[i][j] = max(1, (val == INT_MAX ? 1 : val) - dungeon[i][j]);
      }
    }
    return dungeon[0][0];
  }
};