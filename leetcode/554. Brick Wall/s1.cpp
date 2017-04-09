// OJ: https://leetcode.com/problems/brick-wall
// Auther: github.com/lzl124631x
// Time: O(N)
// Space: O(K) (K is # of unique numbers)
class Solution {
public:
  int leastBricks(vector<vector<int>>& wall) {
    int maxCnt = 0;
    unordered_map<int, int> cnt;
    for (auto row : wall)
      for (int i = 0, w = 0; i < row.size() - 1; ++i)
        maxCnt = max(maxCnt, ++cnt[w += row[i]]);
    return wall.size() - maxCnt;
  }
};