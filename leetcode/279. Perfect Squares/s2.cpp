// OJ: https://leetcode.com/problems/perfect-squares/
// Author: github.com/lzl124631x
// Time: O(NS) where S is the count of square numbers less than n.
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/24255/summary-of-4-different-solutions-bfs-dp-static-dp-and-mathematics
class Solution {
public:
    int numSquares(int n) {
        static vector<int> v{0};
        while (v.size() <= n) {
            int m = v.size(), minVal = INT_MAX;
            for (int j = 1; j * j <= m; ++j) {
                minVal = min(minVal, 1 + v[m - j * j]);
            }
            v.push_back(minVal);
        }
        return v[n];
    }
};