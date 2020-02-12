// OJ: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int getCount(int n) {
        int cnt = 0;
        while (n) {
            n /= 10;
            ++cnt;
        }
        return cnt;
    }
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int n : nums) {
            if (getCount(n) % 2 == 0) cnt++;
        }
        return cnt;
    }
};