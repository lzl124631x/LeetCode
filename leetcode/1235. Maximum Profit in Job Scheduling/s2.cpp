// OJ: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409188/C%2B%2B-with-picture
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int, int> times; // start time to max profit
        unordered_map<int, vector<pair<int, int>>> jobs; // start time to job info
        for (int i = 0; i < startTime.size(); ++i) {
            times[startTime[i]] = 0;
            jobs[startTime[i]].emplace_back(endTime[i], profit[i]);
        }
        int maxProfit = 0;
        for (auto it = rbegin(times); it != rend(times); ++it) {
            for (auto &job : jobs[it->first]) {
                auto j = times.lower_bound(job.first);
                maxProfit = max(maxProfit, (j == end(times) ? 0 : j->second) + job.second);
            }
            it->second = maxProfit;
        }
        return maxProfit;
    }
};