// OJ: https://leetcode.com/problems/minimum-increment-to-make-array-unique/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > A[i - 1]) continue;
            ans += A[i - 1] + 1 - A[i];
            A[i] = A[i - 1] + 1;
        }
        return ans;
    }
};