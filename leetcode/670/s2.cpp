// OJ: https://leetcode.com/problems/maximum-swap/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumSwap(int num) {
        string digits = to_string(num);
        int last[10] = {};
        for (int i = 0; i < digits.size(); ++i) last[digits[i] - '0'] = i;
        for (int i = 0; i < digits.size(); ++i) {
            for (int j = 9; j > digits[i] - '0'; --j) {
                if (last[j] > i) {
                    swap(digits[i], digits[last[j]]);
                    return stoi(digits);
                }
            }
        }
        return num;
    }
};