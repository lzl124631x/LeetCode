// OJ: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool kLengthApart(vector<int>& A, int k) {
        int prev = -k-1;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == 0) continue;
            if (i - prev <= k) return false;  
            prev = i;
        }
        return true;
    }
};