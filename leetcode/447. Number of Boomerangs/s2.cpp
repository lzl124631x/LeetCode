//https://discuss.leetcode.com/topic/66574/7-lines-1050-ms-c
class Solution {
public:
  int numberOfBoomerangs(vector<pair<int, int>>& points) {
    int booms = 0;
    for (auto &p : points) {
      unordered_map<double, int> ctr(points.size());
      for (auto &q : points)
        booms += 2 * ctr[hypot(p.first - q.first, p.second - q.second)]++;
    }
    return booms;
  }
};
// Time O(n^2), Space O(n)