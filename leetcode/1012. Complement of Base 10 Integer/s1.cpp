// OJ: https://leetcode.com/problems/complement-of-base-10-integer/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int bitwiseComplement(int N) {
        if (!N) return 1;
        unsigned mask = ~0;
        while (mask & N) mask <<= 1;
        return ~N & ~mask;
    }
};