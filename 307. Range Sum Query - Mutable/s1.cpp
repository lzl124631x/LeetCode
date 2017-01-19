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


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);