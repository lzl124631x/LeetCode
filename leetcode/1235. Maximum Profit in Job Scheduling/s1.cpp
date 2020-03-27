// OJ: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int N = startTime.size();
        vector<vector<int>> v(N, vector<int>(3));
        for (int i = 0; i < N; ++i) {
            v[i][0] = startTime[i];
            v[i][1] = endTime[i];
            v[i][2] = profit[i];
        }
        sort(v.begin(), v.end());
        vector<int> dp(N + 1);
        for (int i = N - 1; i >= 0; --i) {
            dp[i] = dp[i + 1];
            int e = v[i][1];
            vector<int> c{ e, e, 0 };
            int j = upper_bound(v.begin(), v.end(), c) - v.begin();
            dp[i] = max(dp[i], dp[j] + v[i][2]);
        }
        return dp[0];
    }
};