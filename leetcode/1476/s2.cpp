// OJ: https://leetcode.com/problems/subrectangle-queries/
// Author: github.com/lzl124631x
// Time:
//      O(MN) for SubrectangleQueries
//      O(1) for updateSubrectangle
//      O(Update) for getValue
// Space: O(MN)
class SubrectangleQueries {
    vector<vector<int>> A, sub;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : A(rectangle) {}
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        sub.push_back({ row1, col1, row2, col2, newValue });
    }
    
    int getValue(int row, int col) {
        for (int i = sub.size() - 1; i >= 0; --i) {
            if (row >= sub[i][0] && row <= sub[i][2] && col >= sub[i][1] && col <= sub[i][3]) return sub[i][4];
        }
        return A[row][col];
    }
};