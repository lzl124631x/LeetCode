class TrieNode {
public:
    bool end = false;
    TrieNode *next[26];
    TrieNode() {
        memset(next, 0, sizeof(next));
    }
};
class Solution {
private:
    TrieNode *root = new TrieNode();
    void insert(string &word) {
        TrieNode *node = root;
        for (char c : word) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->end = true;
    }
    vector<string> v;
    vector<vector<char>> board;
    int M;
    int N;
    void rec(int x, int y, TrieNode *node, string &path) {
        char c = board[x][y];
        if (c == '\0' || !node->next[c - 'a']) return;
        node = node->next[c - 'a'];
        path.push_back(c);
        if (node->end) {
            v.push_back(path);
            node->end = false;
        }
        board[x][y] = '\0';
        if (x - 1 >= 0) rec(x - 1, y, node, path);
        if (x + 1 < M) rec(x + 1, y, node, path);
        if (y - 1 >= 0) rec(x, y - 1, node, path);
        if (y + 1 < N) rec(x, y + 1, node, path);
        board[x][y] = c;
        path.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->board = board;
        if (board.empty() || board[0].empty()) return {};
        M = board.size();
        N = board[0].size();
        for (string word : words) insert(word);
        string path;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                rec(i, j, root, path);
            }
        }
        return v;
    }
};