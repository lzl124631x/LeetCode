// OJ: https://leetcode.com/problems/decompress-run-length-encoded-list/
// Author: github.com/lzl124631x
// Time: O(N) where N is the length of the output array.
// Space: O(1)
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i += 2) {
            for (int j = 0; j < nums[i]; ++j) ans.push_back(nums[i + 1]);
        }
        return ans;
    }
};