// OJ: https://leetcode.com/problems/minimum-time-visiting-all-points/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int getDist(vector<int> &a, vector<int> &b) {
        return max(abs(a[0] - b[0]), abs(a[1] - b[1]));
    }
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 1; i < points.size(); ++i) {
            ans += getDist(points[i - 1], points[i]);
        }
        return ans;
    }
};