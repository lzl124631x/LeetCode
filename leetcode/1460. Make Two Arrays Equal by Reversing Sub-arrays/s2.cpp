// OJ: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    bool canBeEqual(vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        return A == B;
    }
};