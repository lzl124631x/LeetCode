// OJ: https://leetcode.com/problems/range-sum-query-mutable/
// Author: github.com/lzl124631x
// Time: 
//      NumArray: O(N)
//      update: O(1)
//      sumRange: O(logN)
// Space: O(N)
class NumArray {
    vector<int> tree;
    int N;
    void buildTree(vector<int> &nums) {
        for (int i = 0, j = N; i < N;) tree[j++] = nums[i++];
        for (int i = N - 1; i > 0; --i) tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
public:
    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        N = nums.size();
        tree = vector<int>(N * 2);
        buildTree(nums);
    }
    
    void update(int i, int val) {
        i += N;
        tree[i] = val;
        while (i > 0) {
            i /= 2;
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
    
    int sumRange(int i, int j) {
        i += N;
        j += N;
        int sum = 0;
        while (i <= j) {
            if (i % 2) sum += tree[i++];
            if (j % 2 == 0) sum += tree[j--];
            i /= 2;
            j /= 2;
        }
        return sum;
    }
};