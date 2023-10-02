// OJ: https://leetcode.com/problems/arithmetic-slices/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int N = A.size(), ans = 0, i = 0;
        while (i + 2 < N) {
            int j = i + 1, d = A[j] - A[i];
            while (j + 1 < N && A[j + 1] - A[j] == d) ++j;
            int L = j - i + 1;
            ans += (L - 1) * (L - 2) / 2;
            i = j;
        }
        return ans;
    }
};