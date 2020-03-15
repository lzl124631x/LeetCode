// OJ: https://leetcode.com/problems/maximum-performance-of-a-team/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-performance-of-a-team/discuss/539687/JavaC%2B%2BPython-Priority-Queue
class Solution {
public:
    int maxPerformance(int N, vector<int>& S, vector<int>& E, int K) {
        vector<pair<int, int>> ps(N);
        for (int i = 0; i < N; ++i) ps[i] = {E[i], S[i]};
        sort(ps.begin(), ps.end());
        long sum = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = N - 1; i >= 0; --i) {
            pq.push(ps[i].second);
            sum += ps[i].second;
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum * ps[i].first);
        }
        return ans % (int)(1e9+7);
    }
};