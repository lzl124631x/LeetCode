// OJ: https://leetcode.com/problems/counting-bits/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        for (int i = 1; i <= num; ++i) ans[i] = 1 + ans[i - (i & -i)];
        return ans;
    }
};