// OJ: https://leetcode.com/problems/global-and-local-inversions/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/global-and-local-inversions/discuss/113656/My-3-lines-C%2B%2B-Solution
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i) {
            if (abs(A[i] - i) > 1) return false;
        }
        return true;
    }
};