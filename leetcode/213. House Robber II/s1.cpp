class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int prevA = 0, prevA2 = 0, prevB = 0, prevB2 = 0, N = nums.size();
        for (int i = 1; i < N; ++i) {
            int a = nums[i], b = nums[i - 1];
            int curA = max(prevA, prevA2 + a), curB = max(prevB, prevB2 + b);
            prevA2 = prevA, prevB2 = prevB;
            prevA = curA, prevB = curB;
        }
        return max(prevA, prevB);
    }
};