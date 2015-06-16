class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        int i = 0;
        while(i < m && matrix[i][n - 1] < target) i++;
        if(i == m) return false;
        int j = 0;
        while(j < n && matrix[i][j] < target) j++;
        if(j == n) return false;
        return matrix[i][j] == target;
    }
};