class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size() - 3; ++i) {
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                int t = target - nums[i] - nums[j], L = j + 1, R = nums.size() - 1;
                while (L < R) {
                    int sum = nums[L] + nums[R];
                    if (sum == t) {
                        vector<int> v{nums[i], nums[j], nums[L++], nums[R--]};
                        ret.push_back(v);
                        while (L < R && nums[L] == nums[L - 1]) ++L;
                        while (L < R && nums[R] == nums[R + 1]) --R;
                    } else if (sum > t) --R;
                    else ++L;
                }
                while (j + 1 < nums.size() - 2 && nums[j] == nums[j + 1]) ++j;
            }
            while (i + 1 < nums.size() - 3 && nums[i] == nums[i + 1]) ++i;
        }
        return ret;
    }
};