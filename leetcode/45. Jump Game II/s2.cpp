// OJ: https://leetcode.com/problems/jump-game-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, jumpsEnd = 0, furthest = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            furthest = max(furthest, i + nums[i]);
            if (i == jumpsEnd) {
                ++jumps;
                jumpsEnd = furthest;
            }
        }
        return jumps;
    }
};