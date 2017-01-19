bool cmp (pair<int, int> a, pair<int, int> b) {
    return a.first != b.first ? a.first < b.first : a.second < b.second;
}
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        int N = envelopes.size();
        vector<int> memo(N, 1);
        int ans = 0;
        for (int i = N - 1; i >= 0; --i) {
            auto p = envelopes[i];
            for (int j = i + 1; j < N; ++j) {
                auto q = envelopes[j];
                if (p.first < q.first && p.second < q.second) {
                    memo[i] = max(memo[i], memo[j] + 1);
                }
            }
            ans = max(ans, memo[i]);
        }
        return ans;
    }
};