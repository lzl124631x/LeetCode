// OJ: https://leetcode.com/problems/xor-operation-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for (int i = 0; i < n; ++i) ans ^= start + 2 * i;
        return ans;
    }
};