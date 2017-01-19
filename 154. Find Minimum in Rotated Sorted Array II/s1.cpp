class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = 0, R = nums.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (nums[M] > nums[R]) L = M + 1;
            else if (nums[M] < nums[R]) R = M;
            else if (nums[M] > nums[L]) break;
            else if (nums[M] < nums[L]) R = M;
            else {
                while (L < M && nums[L] == nums[M]) ++L;
                if (nums[L] < nums[M]) break;
                else L = M + 1;
            }
        }
        return nums[L];
    }
};