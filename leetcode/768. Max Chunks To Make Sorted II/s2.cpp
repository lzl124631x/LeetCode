// OJ: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        int N = A.size(), ans = 1;
        vector<int> mx(N), mn(N);
        mx[0] = A[0];
        mn[N - 1] = A[N - 1];
        for (int i = 1; i < N; ++i) mx[i] = max(mx[i - 1], A[i]);
        for (int i = N - 2; i >= 0; --i) mn[i] = min(mn[i + 1], A[i]);
        for (int i = 1; i < N; ++i) {
            if (mn[i] >= mx[i - 1]) ++ans;
        }
        return ans;
    }
};