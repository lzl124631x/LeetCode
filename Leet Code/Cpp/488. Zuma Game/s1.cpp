class Solution {
private:
    unordered_map<char, int> m;
    string board;
    void clean(string &board) {
        bool found = true;
        while (found && !board.empty()) {
            found = false;
            int start, i = 0;
            while (i < board.size() && !found) {
                start = i;
                do { ++i; } while (i < board.size() && board[i] == board[i - 1]);
                if (i - start >= 3) found = true;
            }
            if (found) {
                board.erase(start, i - start);
            }
        }
    }
    int dfs(string board) {
        if (board.empty()) return 0;
        int minStep = INT_MAX;
        for (int i = 0; i < board.size();) {
            do { ++i; } while (i < board.size() && board[i] == board[i - 1]);
            char c = board[i - 1];
            if (m[c]) {
                --m[c];
                string newBoard(board);
                newBoard.insert(i, 1, c);
                clean(newBoard);
                int ans = dfs(newBoard);
                if (ans != INT_MAX) minStep = min(minStep, 1 + ans);
                ++m[c];
            }
        }
        return minStep;
    }
public:
    int findMinStep(string board, string hand) {
        this->board = board;
        for (char c : hand) m[c]++;
        int ans = dfs(board);
        return ans == INT_MAX ? -1 : ans;
    }
};