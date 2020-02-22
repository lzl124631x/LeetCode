// OJ: https://leetcode.com/contest/biweekly-contest-20/problems/count-all-valid-pickup-and-delivery-options/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
typedef long long LL;
class Solution {
public:
    int countOrders(int n) {
        LL ans = 1, mod = 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            LL prev = ans, cnt = 2 * i - 1;
            ans = ((cnt + 1) * cnt / 2) % mod;
            ans = (ans * prev) % mod;
        }
        return ans;
    }
};