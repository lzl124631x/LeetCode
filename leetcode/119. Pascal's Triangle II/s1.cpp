// OJ: https://leetcode.com/problems/pascals-triangle-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = i - 1; j >= 1; --j) {
                ans[j] += ans[j - 1];
            }
        }
        return ans;
    }
};