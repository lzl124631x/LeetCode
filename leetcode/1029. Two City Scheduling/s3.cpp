// OJ: https://leetcode.com/problems/two-city-scheduling/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& A) {
        int N = A.size(), ans = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < N; ++i) v.emplace_back(A[i][0] - A[i][1], i);
        sort(begin(v), end(v));
        for (int i = 0; i < N / 2; ++i) ans += A[v[i].second][0];
        for (int i = N / 2; i < N; ++i) ans += A[v[i].second][1];
        return ans;
    }
};