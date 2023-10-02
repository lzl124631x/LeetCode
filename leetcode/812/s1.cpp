// OJ: https://leetcode.com/problems/largest-triangle-area/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(1)
// Ref: https://leetcode.com/problems/largest-triangle-area/solution/
class Solution {
private:
    double area (vector<int> &a, vector<int> &b, vector<int> &c) {
        return .5 * abs(a[0]*b[1] + b[0]*c[1] + c[0]*a[1]
                       -a[1]*b[0] - b[1]*c[0] - c[1]*a[0]);
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for (int i = 0, N = points.size(); i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = j + 1; k < N; ++k) {
                    ans = max(ans, area(points[i], points[j], points[k]));
                }
            }
        }
        return ans;
    }
};