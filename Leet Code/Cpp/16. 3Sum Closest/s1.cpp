class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, ret;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int L = i + 1, R = nums.size() - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == target) return target;
                if (abs(target - sum) < diff) {
                    ret = sum;
                    diff = abs(target - sum);
                }
                if (sum > target) --R;
                else ++L;
            }
        }
        return ret;
    }
};