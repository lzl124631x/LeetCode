class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minSub = 0, ans = INT_MIN, sum = 0;
        for (int n : nums) {
            sum += n;
            ans = max(ans, sum - minSub);
            minSub = min(minSub, sum);
        }
        return ans;
    }
};