// OJ: https://leetcode.com/problems/best-sightseeing-pair/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        stack<pair<int, int>> s;
        for (int i = A.size() - 1; i >= 0; --i) {
            if (s.empty() || s.top().second < A[i] - i) s.emplace(i, A[i] - i);
        }
        int ans = INT_MIN;
        for (int i = 0; i < A.size() - 1; ++i) {
            if (s.top().first <= i) s.pop();
            ans = max(ans, A[i] + i + s.top().second);
        }
        return ans;
    }
};