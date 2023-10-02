// OJ: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    int getBitCount(int n) {
        int cnt = 0;
        while (n) {
            cnt += n % 2;
            n >>= 1;
        }
        return cnt;
    }
public:
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> s{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
        int ans = 0;
        for (; L <= R; ++L) {
            int cnt = getBitCount(L);
            if (s.find(cnt) != s.end()) ++ans;
        }
        return ans;
    }
};