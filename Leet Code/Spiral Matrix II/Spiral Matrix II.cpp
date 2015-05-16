class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if(n <= 0) return vector<vector<int> >();
        vector<vector<int> > m(n, vector<int>(n, 0));
        int k, v = 1;
        for(k = 0; k < (n >> 1); ++k){
            int x = k, y = k, b = n - k - 1;
            while(y < b) m[x][y++] = v++;
            while(x < b) m[x++][y] = v++;
            while(y > k) m[x][y--] = v++;
            while(x > k) m[x--][y] = v++;
        }
        if(n%2){
            m[k][k] = v; 
        }
        return m;
    }
};