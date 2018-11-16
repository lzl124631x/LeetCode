// OJ: https://leetcode.com/problems/self-dividing-numbers/
// Author: github.com/lzl124631x
// Time: O(ND) where N = right - left + 1, D = digit count of right.
// Space: O(1)
class Solution {
private:
    bool isSelfDividing(int n) {
        int m = n;
        while (m) {
            int d = m % 10;
            if (!d || n % d != 0) return false;
            m /= 10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; ++i) {
            if (isSelfDividing(i)) ans.push_back(i);
        }
        return ans;
    }
};