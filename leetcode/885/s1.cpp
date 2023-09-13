// OJ: https://leetcode.com/problems/spiral-matrix-iii/
// Author: github.com/lzl124631x
// Time: O(max(R, C)^2)
// Space: O(1)
class Solution {
private:
    vector<vector<int>> ans;
    int r, c;
    void add(int x, int y) {
        if (x < 0 || x >= r || y < 0 || y >= c) return;
        ans.push_back({ x, y });
    }
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        r = R;
        c = C;
        int x = r0, y = c0, cnt = R * C, d = 2;
        ans.push_back({ x, y });
        while (ans.size() < cnt) {
            add(x, ++y);
            for (int i = 1; i < d; ++i) add(++x, y);
            for (int i = 0; i < d; ++i) add(x, --y);
            for (int i = 0; i < d; ++i) add(--x, y);
            for (int i = 0; i < d; ++i) add(x, ++y);
            d += 2;
        }
        return ans;
    }
};