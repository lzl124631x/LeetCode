// OJ: https://leetcode.com/problems/sort-colors/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3, 0);
        for (int n : nums) cnt[n]++;
        int i = 0;
        for (int j = 0; j < 3; ++j) {
            while (cnt[j]--) nums[i++] = j;
        }
    }
};