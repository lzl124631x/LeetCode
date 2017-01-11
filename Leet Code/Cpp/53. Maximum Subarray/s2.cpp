class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        for (int n : nums) {
            sum += n;
            ans = max(sum, ans);
            sum = max(sum, 0);
        }
        return ans;
    }
};