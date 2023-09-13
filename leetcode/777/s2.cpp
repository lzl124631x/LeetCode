// OJ: https://leetcode.com/problems/swap-adjacent-in-lr-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0, j = 0, N = start.size();
        for (; i < N && j < N; ++i, ++j) {
            while (i < N && start[i] == 'X') ++i;
            while (j < N && end[j] == 'X') ++j;
            if ((i < N) ^ (j < N)) return false;
            if (i < N && j < N) {
                if (start[i] != end[j]
                   || (start[i] == 'L' && i < j)
                   || (start[i] == 'R' && i > j)) return false;
            }
        }
        return true;
    }
};