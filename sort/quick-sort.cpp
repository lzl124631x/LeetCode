// OJ: https://leetcode.com/problems/sort-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN) on average
// Space: O(1)
class Solution {
private:
    int partition(vector<int> &nums, int L, int R, int pivot) {
        swap(nums[pivot], nums[R]);
        for (int i = L; i < R; ++i) {
            if (nums[i] >= nums[R]) continue;
            swap(nums[i], nums[L++]);
        }
        swap(nums[L], nums[R]);
        return L;
    }
    void quickSort(vector<int> &nums, int L, int R) {
        if (L >= R) return;
        int M = partition(nums, L, R, rand() % (R - L + 1) + L);
        quickSort(nums, L, M - 1);
        quickSort(nums, M + 1, R);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        srand (time(NULL));
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};