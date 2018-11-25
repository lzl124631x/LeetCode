// OJ: https://leetcode.com/problems/jump-game/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int furthest = 0, N = nums.size();
        for (int i = 0; i < N - 1 && i <= furthest; ++i) {
            furthest = max(furthest, i + nums[i]);
            if (furthest >= N - 1) return true;
        }
        return false;
    }
};