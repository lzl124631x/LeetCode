class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> v;
        if (nums.empty()) return v;
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> prev(nums.size(), -1);
        int maxLen = 1, maxEnd = 0;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if ((nums[i] % nums[j] == 0
                || nums[j] % nums[i] == 0)
                && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                    if (dp[i] > maxLen) {
                        maxLen = dp[i];
                        maxEnd = i;
                    }
                }
            }
        }
        while (maxEnd != -1) {
            v.push_back(nums[maxEnd]);
            maxEnd = prev[maxEnd];
        }
        return v;
    }
};