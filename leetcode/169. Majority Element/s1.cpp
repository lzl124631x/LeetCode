// OJ: https://leetcode.com/problems/majority-element/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for (int n : nums) {
            if (ans == n) ++cnt;
            else if (cnt > 0) --cnt;
            else {
                ans = n;
                cnt = 1;
            }
        }
        return ans;
    }
};