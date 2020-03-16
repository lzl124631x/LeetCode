// OJ: https://leetcode.com/problems/range-sum-query-mutable/
// Author: github.com/lzl124631x
// Time:
//      NumArray: O(N)
//      update: O(1)
//      sumRange: O(N)
// Space: O(N)
class NumArray {
private:
    vector<int> sums;
    vector<int> nums;
    int firstDirty;
public:
    NumArray(vector<int> &nums) : sums(nums.size() + 1), nums(nums), firstDirty(0) {
    }

    void update(int i, int val) {
        nums[i] = val;
        firstDirty = min(firstDirty, i);
    }

    int sumRange(int i, int j) {
        if (firstDirty != nums.size()) {
            for (int i = firstDirty; i < nums.size(); ++i) {
                sums[i + 1] = sums[i] + nums[i];
            }
            firstDirty = nums.size();
        }
        return sums[j + 1] - sums[i];
    }
};