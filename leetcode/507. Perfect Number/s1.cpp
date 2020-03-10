// OJ: https://leetcode.com/problems/perfect-number/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        int sum = 0, end = sqrt(num);
        for (int i = 1; i <= end; ++i) {
            if (num % i) continue;
            int j = num / i;
            sum += i;
            if (j != i && j != num) sum += j;
        }
        return sum == num;
    }
};