// OJ: https://leetcode.com/problems/set-mismatch
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto n : nums) m[n]++;
        int missing, dup;
        for (int i = 1; i <= nums.size(); ++i) {
            if (!m[i]) missing = i;
            if (m[i] == 2) dup = i;
        }
        return { dup, missing };
    }
};