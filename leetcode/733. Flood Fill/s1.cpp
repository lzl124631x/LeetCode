// OJ: https://leetcode.com/problems/flood-fill/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
private:
    int M, N, color, dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (sr < 0 || sr >= M || sc < 0 || sc >= N || image[sr][sc] != color) return;
        image[sr][sc] = newColor;
        for (auto dir : dirs) {
            dfs(image, sr + dir[0], sc + dir[1], newColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        color = image[sr][sc];
        if (color == newColor) return image;
        M = image.size();
        N = image[0].size();
        dfs(image, sr, sc, newColor);
        return image;
    }
};