// OJ: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
// Author: github.com/lzl124631x
// Time: O(N^2 * logN)
// Space: O(N)
// Ref: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/solution/
class Solution {
public:
    double mincostToHireWorkers(vector<int>& Q, vector<int>& W, int K) {
        int N = Q.size();
        double ans = DBL_MAX;
        for (int i = 0; i < N; ++i) {
            double factor = (double) W[i] / Q[i];
            vector<double> costs;
            for (int j = 0; j < N; ++j) {
                double c = factor * Q[j];
                if (c < W[j]) continue;
                costs.push_back(c);
            }
            if (costs.size() < K) continue;
            sort(costs.begin(), costs.end());
            double sum = accumulate(costs.begin(), costs.begin() + K, 0);
            ans = min(ans, sum);
        }
        return ans;
    }
};