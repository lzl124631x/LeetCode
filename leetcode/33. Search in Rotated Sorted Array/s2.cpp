// https://discuss.leetcode.com/topic/3538/concise-o-log-n-binary-search-solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int N = nums.size(), L = 0, R = N - 1, pivot;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (nums[M] < nums[R]) R = M;
            else L = M + 1;
        }
        pivot = L;
        L = 0, R = N - 1;
        while (L <= R) {
            int M = L + (R - L) / 2;
            int MM = (M + pivot) % N;
            if (nums[MM] == target) return MM;
            if (target > nums[MM]) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};