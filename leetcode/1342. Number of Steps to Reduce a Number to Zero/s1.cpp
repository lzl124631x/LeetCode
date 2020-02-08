// OJ: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int numberOfSteps (int num) {
        int cnt = 0;
        while (num) {
            cnt++;
            if (num % 2 == 0) num /= 2;
            else num--;
        }
        return cnt;
    }
};