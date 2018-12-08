// OJ: https://leetcode.com/problems/buddy-strings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        int cnts[26] = {0}, first = -1, second = -1;
        bool hasDup = false;
        for (int i = 0; i < A.size(); ++i) {
            if (++cnts[A[i] - 'a'] == 2) hasDup = true;
            if (A[i] == B[i]) continue;
            if (first == -1) first = i;
            else if (second == -1) second = i;
            else return false;
        }
        return (first != -1 && second != -1 && A[first] == B[second] && A[second] == B[first])
            || (first == -1 && second == -1 && hasDup);
    }
};