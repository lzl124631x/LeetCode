class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        while (L <= R) {
            int M = L + (R - L) / 2;
            if (target > nums[M]) L = M + 1;
            else R = M - 1;
        }
        return L;
    }
};