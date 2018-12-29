// OJ: https://leetcode.com/problems/swap-adjacent-in-lr-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool canTransform(string start, string end) {
        int N = start.size();
        string a = start, b = end;
        a.erase(remove(a.begin(), a.end(), 'X'), a.end());
        b.erase(remove(b.begin(), b.end(), 'X'), b.end());
        if (a != b) return false;
        for (int i = 0, j = 0; i < N; ++i) {
            if (start[i] == 'L') {
                while (end[j] != 'L') ++j;
                if (i < j++) return false;
            }
        }
        for (int i = 0, j = 0; i < N; ++i) {
            if (start[i] == 'R') {
                while (end[j] != 'R') ++j;
                if (i > j++) return false;
            }
        }
        return true;
    }
};