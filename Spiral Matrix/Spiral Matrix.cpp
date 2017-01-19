#include <vector>
using namespace std;

// 问题可以简化为扫描矩阵的最外层一圈
// 警惕特殊情形: 仅有一行或仅有一列
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> v;
        int m = matrix.size();
        if(!m) return v;
        int n = matrix[0].size();
        int xl = 0, xh = m - 1, yl = 0, yh = n - 1;
        while(xl <= xh && yl <= yh){
            int x = xl, y = yl;
            if(xl == xh){ // only one row
                while(y <= yh) v.push_back(matrix[x][y++]);
                break;
            }else if(yl == yh){ // only one column
                while(x <= xh) v.push_back(matrix[x++][y]);
                break;
            }else{
                while(y < yh) v.push_back(matrix[x][y++]);
                yh--;
                while(x < xh) v.push_back(matrix[x++][y]);
                xh--;
                while(y > yl) v.push_back(matrix[x][y--]);
                yl++;
                while(x > xl) v.push_back(matrix[x--][y]);
                xl++;
            }
        }
        return v;
    }
};