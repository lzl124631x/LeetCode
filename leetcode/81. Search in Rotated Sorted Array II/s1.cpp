class Solution {
private:
    int findPivot (vector<int> &nums) {
        int L = 0, R = nums.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (nums[M] > nums[R]) L = M + 1;
            else if (nums[M] < nums[R]) R = M;
            else if (nums[M] > nums[L]) break;
            else if (nums[M] < nums[L]) R = M;
            else {
                int LL = L;
                while (L < R && nums[L] == nums[R]) ++L;
                if (L == R) L = LL;
                if (nums[L] > nums[R]) continue;
                break;
            }
        }
        return L;
    }
public:
    bool search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        int N = nums.size(), L = 0, R = N - 1;
        while (L <= R) {
            int M = L + (R - L) / 2;
            int MM = (M + pivot) % N;
            if (target == nums[MM]) return true;
            if (target > nums[MM]) L = M + 1;
            else R = M - 1;
        }
        return false;
    }
};