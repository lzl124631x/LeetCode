// OJ: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(M+N)
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> row(n, 0), col(m, 0);
        for (auto &v : indices) {
            row[v[0]]++;
            col[v[1]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((row[i] + col[j]) % 2) ans++;
            }
        }
        return ans;
    }
};