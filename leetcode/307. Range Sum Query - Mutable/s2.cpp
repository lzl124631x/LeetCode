// OJ: https://leetcode.com/problems/range-sum-query-mutable/
// Author: github.com/lzl124631x
// Time:
//      NumArray: O(N)
//      update: O(1)
//      sumRange: O(sqrt(N))
// Space: O(N)
// Ref: https://leetcode.com/problems/range-sum-query-mutable/solution/
class NumArray {
private:
    vector<int> sums;
    vector<int> nums;
    int len; // length of each section.
public:
    NumArray(vector<int> &nums) : nums(nums) {
        if (nums.empty()) return;
        len = ceil(sqrt(nums.size()));
        sums = vector<int>(ceil((double)nums.size() / len));
        for (int i = 0; i < nums.size(); ++i) {
            sums[i / len] += nums[i];
        }
    }

    void update(int i, int val) {
        sums[i / len] += val - nums[i];
        nums[i] = val;
    }

    int sumRange(int i, int j) {
        int sum = 0, start = i / len, end = j / len;
        if (start == end) {
            while (i <= j) sum += nums[i++];
        } else {
            for (int k = (start + 1) * len - 1; k >= i; --k) sum += nums[k];
            for (int k = start + 1; k < end; ++k) sum += sums[k];
            for (int k = end * len; k <= j; ++k) sum += nums[k];
        }
        return sum;
    }
};