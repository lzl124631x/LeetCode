// OJ: https://leetcode.com/problems/sort-transformed-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    int eval(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        float mid = (float)-b / (2 * a);
        int j = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();
        int i = j - 1, N = nums.size(), nil = a > 0 ? INT_MAX : INT_MIN;
        vector<int> ans(N);
        for (int k = 0; k < N; ++k) {
            int m = i >= 0 ? eval(nums[i], a, b, c) : nil;
            int n = j < N ? eval(nums[j], a, b, c) : nil;
            if (a > 0 ? m < n : n < m) {
                ans[k] = m;
                --i;
            } else {
                ans[k] = n;
                ++j;
            }
        }
        if (a < 0) reverse(ans.begin(), ans.end());
        return ans;
    }
};