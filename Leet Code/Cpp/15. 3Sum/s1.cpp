class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int L = i + 1, R = nums.size() - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (!sum) {
                    vector<int> v { nums[i], nums[L++], nums[R--] };
                    ret.push_back(v);
                    while (L < R && nums[L] == nums[L - 1]) ++L;
                    while (L < R && nums[R] == nums[R + 1]) --R;
                } else if (sum > 0) --R;
                else ++L;
            }
            while (i + 1 < nums.size() - 2 && nums[i + 1] == nums[i]) ++i;
        }
        return ret;
    }
};