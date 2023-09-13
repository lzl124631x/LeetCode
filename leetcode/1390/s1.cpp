// OJ: https://leetcode.com/problems/four-divisors/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int n : nums) {
            int cnt = 0, sum = 0;
            for (int i = 1; i * i <= n && cnt <= 4; ++i) {
                if (n % i) continue;
                int j = n / i;
                ++cnt;
                sum += i;
                if (i != j) {
                    ++cnt;
                    sum += j;
                }
            }
            if (cnt != 4) continue;
            ans += sum;
        }
        return ans;
    }
};