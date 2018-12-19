// OJ: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/articles/shortest-subarray-with-sum-atleast-k/
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int N = A.size(), ans = INT_MAX;
        vector<long long> P(N + 1);
        for (int i = 0; i < N; ++i) P[i + 1] = P[i] + A[i];
        deque<int> q;
        for (int y = 0; y < P.size(); ++y) {
            while (q.size() && P[y] <= P[q.back()]) q.pop_back();
            while (q.size() && P[y] >= P[q.front()] + K) {
                ans = min(ans, y - q.front());
                q.pop_front();
            }
            q.push_back(y);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};