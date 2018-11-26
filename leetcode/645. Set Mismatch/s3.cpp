// OJ: https://leetcode.com/problems/set-mismatch/solution/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> cnts(nums.size(), 0);
        int dup, missing;
        for (int n : nums) cnts[n - 1]++;
        for (int i = 0; i < cnts.size(); ++i) {
            if (cnts[i] == 0) missing = i + 1;
            else if (cnts[i] == 2) dup = i + 1;
        }
        return { dup, missing };
    }
};