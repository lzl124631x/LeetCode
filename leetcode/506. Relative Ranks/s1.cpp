// Slow because of `distance`. 569 ms
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        set<int, greater<int>> s(nums.begin(), nums.end());
        vector<string> ans;
        for (int n : nums) {
            int rank = distance(s.begin(), s.find(n));
            if (rank == 0) ans.push_back("Gold Medal");
            else if (rank == 1) ans.push_back("Silver Medal");
            else if (rank == 2) ans.push_back("Bronze Medal");
            else ans.push_back(to_string(rank + 1));
        }
        return ans;
    }
};