class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.size() <= 0) return 0;
        int cnt = 0, m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X'
                && (i - 1 < 0 || board[i - 1][j] != 'X')
                && (j - 1 < 0 || board[i][j - 1] != 'X')) ++cnt;
            }
        }
        return cnt;
    }
};