// OJ: https://leetcode.com/problems/maximum-swap/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumSwap(int num) {
        string digits = to_string(num), memo(digits.size(), '\0');
        int maxIndex = digits.size() - 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] > digits[maxIndex]) maxIndex = i;
            memo[i] = maxIndex;
        }
        for (int i = 0; i < digits.size(); ++i) {
            if (memo[i] > i && digits[i] != digits[memo[i]]) {
                swap(digits[i], digits[memo[i]]);
                return stoi(digits);
            }
        }
        return num;
    }
};