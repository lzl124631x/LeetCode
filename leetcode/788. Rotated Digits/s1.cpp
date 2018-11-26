// OJ: https://leetcode.com/problems/rotated-digits/
// Author: github.com/lzl124631x
// Time: O(ND) where D is the count of digits in N
// Space: O(1)
class Solution {
private:
    bool isGood(int N) {
        bool good = false;
        while (N) {
            int d = N % 10;
            if (d == 3 || d == 4 || d == 7) return false;
            if (d == 2 || d == 5 || d == 6 || d == 9) good = true;
            N /= 10;
        }
        return good;
    }
public:
    int rotatedDigits(int N) {
        int cnt = 0;
        for (int i = 1; i <= N; ++i) {
            if (isGood(i)) ++cnt;
        }
        return cnt;
    }
};