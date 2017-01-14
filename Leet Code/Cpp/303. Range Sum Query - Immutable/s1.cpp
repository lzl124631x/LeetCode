class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int> &nums) {
        sums.push_back(0);
        for (int n : nums) sums.push_back(sums.back() + n);
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);