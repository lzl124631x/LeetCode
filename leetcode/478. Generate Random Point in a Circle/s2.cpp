// OJ: https://leetcode.com/problems/generate-random-point-in-a-circle/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/generate-random-point-in-a-circle/solution/
class Solution {
private:
    double radius, x_center, y_center, area;
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{0, 1};
public:
    Solution(double radius, double x_center, double y_center) : radius(radius), x_center(x_center), y_center(y_center) {
    }
    vector<double> randPoint() {
        double d = radius * sqrt(uni(rng)), theta = uni(rng) * 2 * M_PI;
        return { x_center + d * cos(theta), y_center + d * sin(theta) };
    }
};