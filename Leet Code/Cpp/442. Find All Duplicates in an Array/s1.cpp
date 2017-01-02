class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        int i = 0;
        while (i < nums.size()) {
            while (nums[i] && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
            if (nums[i] && nums[i] != i + 1) {
                v.push_back(nums[i]);
                nums[i] = nums[nums[i] - 1] = 0;
            }
            ++i;
        }
        return v;
    }
};