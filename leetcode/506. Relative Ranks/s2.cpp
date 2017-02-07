// https://discuss.leetcode.com/topic/77912/c-easy-to-understand
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < nums.size(); ++i) q.push({ nums[i], i });
        int rank = 1;
        vector<string> ans(nums.size());
        while (q.size()) {
            string &s = ans[q.top().second];
            q.pop();
            if (rank == 1) s = "Gold Medal";
            else if (rank == 2) s = "Silver Medal";
            else if (rank == 3) s = "Bronze Medal";
            else s = to_string(rank);
            ++rank;
        }
        return ans;
    }
};