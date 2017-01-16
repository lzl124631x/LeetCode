// https://discuss.leetcode.com/topic/72107/java-dfs-solution-with-explanation
class Solution {
private:
    int len;
    bool dfs(vector<int> &nums, vector<int> sums, int index) {
        if (index == nums.size()) return sums[0] == len && sums[1] == len && sums[2] == len;
        for (int i = 0; i < 4; ++i) {
            if (sums[i] + nums[index] > len) continue;
            sums[i] += nums[index];
            if (dfs(nums, sums, index + 1)) return true;
            sums[i] -= nums[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        len = sum / 4;
        if (sum <= 0 || sum % 4 != 0) return false;
        vector<int> sums(4, 0);
        return dfs(nums, sums, 0);
    }
};