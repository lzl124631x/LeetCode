// OJ: https://leetcode.com/problems/matrix-cells-in-distance-order/
// Author: github.com/lzl124631x
// Time: O(RC)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>{ r0, c0 });
        int starts[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        for (int level = 1;; level++) {
            int cnt = 0;
            for (int i = 0; i < 4; ++i) {
                int x = r0 + level * starts[i][0], y = c0 + level * starts[i][1];
                for (int j = 0; j < level; ++j) {
                    if (x >= 0 && x < R && y >= 0 && y < C) {
                        ans.push_back(vector<int>{ x, y });
                        ++cnt;
                    }
                    x += dirs[i][0];
                    y += dirs[i][1];
                }
            }
            if (!cnt) return ans;
        }
    }
};