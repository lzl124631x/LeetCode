// OJ: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/discuss/151685/Shortest-and-cleanest-Java-solution-so-far
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int L, R = 1;
        while (reader.get(R) < target) R *= 2;
        L = R / 2;
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