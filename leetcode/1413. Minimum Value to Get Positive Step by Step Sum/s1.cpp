// OJ: https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        partial_sum(begin(nums), end(nums), begin(nums));
        int m = *min_element(begin(nums), end(nums));
        return 1 - min(0, m);
    }
};