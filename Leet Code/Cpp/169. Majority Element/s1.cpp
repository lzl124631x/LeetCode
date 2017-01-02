class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) return 0;
        int cnt = 1, val = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (!cnt) {
                val = nums[i];
                ++cnt;
            } else if (val != nums[i]) --cnt;
            else ++cnt;
        }
        return val;
    }
};