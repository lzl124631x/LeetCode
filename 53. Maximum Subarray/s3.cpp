// Kadane's Algorithm: https://www.youtube.com/watch?v=86CQq3pKSUw
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax = 0, ans = INT_MIN;
        for (int n : nums) {
            currMax = max(n, n + currMax);
            ans = max(currMax, ans);
        }
        return ans;
    }
};