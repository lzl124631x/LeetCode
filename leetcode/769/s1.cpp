// OJ: https://leetcode.com/problems/max-chunks-to-make-sorted/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        int N = A.size(), ans = 0, sum = 0;
        for (int i = 0; i < N; ++i) {
            if ((sum += A[i] - i) == 0) ++ans;
        }
        return ans;
    }
};