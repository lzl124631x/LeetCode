// OJ: https://leetcode.com/problems/reshape-the-matrix/
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int M = nums.size(), N = nums[0].size();
        if (M * N != r * c) return nums;
        vector<vector<int>> ans;
        for (int i = 0; i < r; ++i) {
            vector<int> row;
            for (int j = 0; j < c; ++j) {
                int index = i * c + j;
                row.push_back(nums[index / N][index % N]);
            }
            ans.push_back(row);
        }
        return ans;
    }
};