// OJ: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int minVal = reader.get(0);
        int L = 0, R = 9999 - minVal;
        while (L <= R) {
            int M = (L + R) / 2;
            int val = reader.get(M);
            if (val == target) return M;
            if (val > target) R = M - 1;
            else L = M + 1;
        }
        return -1;
    }
};