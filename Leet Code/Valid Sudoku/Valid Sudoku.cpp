class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<bool> tag;
        for(int i = 0; i < 9; ++i){
            tag = vector<bool>(10, false);
            for(int j = 0; j < 9; ++j){
                char c = board[i][j];
                if(c != '.'){
                    if(tag[c - '0']) return false;
                    else tag[c - '0'] = true;
                }
            }
        }
        for(int j = 0; j < 9; ++j){
            tag = vector<bool>(10, false);
            for(int i = 0; i < 9; ++i){
                char c = board[i][j];
                if(c != '.'){
                    if(tag[c - '0']) return false;
                    else tag[c - '0'] = true;
                }
            }
        }
        for(int i = 0; i < 9; ++i){
            tag = vector<bool>(10, false);
            for(int j = 0; j < 9; ++j){
                char c = board[i/3*3 + j/3][i%3*3 + j%3];
                if(c != '.'){
                    if(tag[c - '0']) return false;
                    else tag[c - '0'] = true;
                }
            }
        }
        return true;
    }
};