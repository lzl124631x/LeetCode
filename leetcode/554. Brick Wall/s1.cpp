// OJ: https://leetcode.com/problems/brick-wall
// Auther: github.com/lzl124631x
// Time: O(N)
// Space: O(K) (K is # of unique numbers)
class Solution {
public:
  int leastBricks(vector<vector<int>>& wall) {
    if (wall.empty() || wall[0].empty()) return 0;
    int maxCnt = 0;
    unordered_map<int, int> cnt;
    for (auto row : wall) {
      int w = 0;
      for (int i = 0; i < row.size() - 1; ++i) {
        w += row[i];
        cnt[w]++;
        maxCnt = max(maxCnt, cnt[w]);
      }
    }
    return wall.size() - maxCnt;
  }
};