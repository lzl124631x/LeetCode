// OJ: https://leetcode.com/problems/h-index-ii/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int hIndex(vector<int>& A) {
        int N = A.size(), L = 0, R = N - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] >= N - M) R = M - 1;
            else L = M + 1;
        }
        return N - L;
    }
};