// OJ: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409188/C%2B%2B-with-picture
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> idx(startTime.size());
        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), [&](int i, int j) { return startTime[i] > startTime[j]; });
        map<int, int> memo; // start time to max profit
        int maxProfit = 0;
        for (int i = 0; i < idx.size(); ++i) {
            auto j = memo.lower_bound(endTime[idx[i]]);
            maxProfit = max(maxProfit, (j == end(memo) ? 0 : j->second) + profit[idx[i]]);
            memo[startTime[idx[i]]] = maxProfit;
        }
        return maxProfit;
    }
};