// OJ: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    double dist(vector<int> &point) {
        return sqrt(pow(point[0], 2) + pow(point[1], 2));
    }
    int quickSelect(vector<vector<int>> &points, int start, int end) {
        int pivot = rand() % (end - start) + start, i = start, j = end - 1;
        double p = dist(points[pivot]);
        swap(points[start], points[pivot]);
        while (i < j) {
            while (i < j && dist(points[j]) >= p) --j;
            while (i < j && dist(points[i]) <= p) ++i;
            if (i < j) swap(points[i], points[j]);
        }
        swap(points[start], points[i]);
        return i;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int L = 0, R = points.size();
        while (L < R) {
            int M = quickSelect(points, L, R);
            if (M + 1 == K) break;
            if (M + 1 > K) R = M;
            else L = M + 1;
        }
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};