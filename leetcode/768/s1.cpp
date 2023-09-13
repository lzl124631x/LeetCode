// OJ: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        deque<int> q;
        int N = A.size(), ans = 0, mx = A[0];
        for (int i = N - 1; i >= 0; --i) {
            if (q.empty() || A[i] <= q.front()) q.push_front(A[i]);
        }
        for (int i = 0; i < N; ++i) {
            mx = max(mx, A[i]);
            if (q.front() != A[i]) continue;
            q.pop_front();
            if (q.empty() || mx <= q.front()) ++ans;
        }
        return ans;
    }
};