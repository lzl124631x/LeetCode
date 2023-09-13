// OJ: https://leetcode.com/problems/maximum-sum-circular-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int N = A.size(), sum = 0, ans = INT_MIN;
        vector<int> p(2 * N + 1);
        for (int i = 0; i < 2 * N; ++i) {
            p[i + 1] = (sum += A[i % N]);
        }
        deque<int> q;
        for (int i = 0; i < 2 * N + 1; ++i) {
            if (i >= N && q.front() == i - N - 1) q.pop_front();
            if (q.size()) ans = max(ans, p[i] - p[q.front()]);
            while (q.size() && p[q.back()] >= p[i]) q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};