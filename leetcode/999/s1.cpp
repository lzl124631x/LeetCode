// OJ: https://leetcode.com/problems/available-captures-for-rook/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
private:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int capture(vector<vector<char>>& board, int dir[2], int x, int y) {
        while (true) {
            x += dir[0];
            y += dir[1];
            if (x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] == 'B') return 0;
            if (board[x][y] == 'p') return 1;
        }
    }
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int i, j, ans = 0;
        for (i = 0; i < 8; ++i) {
            for (j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') break;
            }
            if (j < 8) break;
        }
        for (auto dir : dirs) ans += capture(board, dir, i, j);
        cout << i << " " << j << endl;
        return ans;
    }
};