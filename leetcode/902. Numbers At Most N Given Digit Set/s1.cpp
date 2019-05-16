// OJ: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
// Author: github.com/lzl124631x
// Time: O(D)
// Space: O(D)
class Solution {
private:
    int getCount(vector<string>& D, int N, int digits) {
        int maxDigits = (int)log10(N) + 1;
        if (digits > maxDigits) return 0;
        if (digits < maxDigits) return pow(D.size(), digits);
        int firstDigit = N / pow(10, maxDigits - 1), sum = 0;
        for (auto &d : D) {
            if (d[0] - '0' < firstDigit) sum += pow(D.size(), digits - 1);
            else if (d[0] - '0' == firstDigit) sum += maxDigits == 1 ? 1 : getCount(D, N % (int)pow(10, maxDigits - 1), maxDigits - 1);
            else break;
        }
        return sum;
    }
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int sum = 0, maxDigits = (int)log10(N) + 1;
        for (int d = 1; d <= maxDigits; ++d) sum += getCount(D, N, d);
        return sum;
    }
};