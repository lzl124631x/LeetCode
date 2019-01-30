// OJ: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
private:
    double dist(vector<int> &point) {
        return sqrt(pow(point[0], 2) + pow(point[1], 2));
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b) {
            return dist(a) < dist(b);
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};