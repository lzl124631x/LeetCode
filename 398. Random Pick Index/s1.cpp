class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) : nums(nums) {}
    
    int pick(int target) {
        int cnt = 0, val;
        for (int i = 0;i < nums.size(); ++i) {
            if (nums[i] != target) continue;
            ++cnt;
            if (cnt == 1 || !(rand() % cnt)) val = i;
        }
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */