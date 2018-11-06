// OJ: https://leetcode.com/problems/lemonade-change/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto b : bills) {
            if (b == 5) {
                ++five;
            } else if (b == 10) {
                if (!five) return false;
                --five;
                ++ten;
            } else {
                if (five && ten) {
                    --five;
                    --ten;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};