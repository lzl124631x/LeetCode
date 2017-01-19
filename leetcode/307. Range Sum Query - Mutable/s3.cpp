// https://leetcode.com/articles/range-sum-query-mutable/
class NumArray {
private:
    vector<int> tree;
    int n;
    
    void buildTree(vector<int> &nums) {
        for (int i = n, j = 0; j < n; ++i, ++j) tree[i] = nums[j];
        for (int i = n - 1; i > 0; --i) tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
public:
    NumArray(vector<int> &nums) : n(nums.size()) {
        if (n == 0) return;
        tree = vector<int>(2 * n);
        buildTree(nums);
    }

    void update(int i, int val) {
        i += n;
        tree[i] = val;
        while (i > 0) {
            int left = i, right = i;
            if (i % 2 == 0) ++right;
            else --left;
            tree[i / 2] = tree[left] + tree[right];
            i /= 2;
        }
    }

    int sumRange(int i, int j) {
        int sum = 0;
        i += n;
        j += n;
        while (i <= j) {
            if (i % 2 == 1) {
                sum += tree[i];
                ++i;
            }
            if (j % 2 == 0) {
                sum += tree[j];
                --j;
            }
            i /= 2;
            j /= 2;
        }
        return sum;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);