// OJ: https://leetcode.com/problems/smallest-sufficient-team/
// Author: github.com/lzl124631x
// Time: O(2^M * N) where M is the size of `req_skills`, N is the number of people
// Space: O(2^M * N)
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> m;
        int M = 0, N = people.size();
        for (auto &s : req_skills) m[s] = M++;
        vector<int> p(N);
        for (int i = 0; i < N; ++i) {
            for (auto &s : people[i]) {
                p[i] |= 1 << m[s];
            }
        }
        vector<vector<int>> dp(1 << M, vector<int>(N + 1, N));
        for (int i = 0; i <= N; ++i) dp[0][i] = 0;
        for (int state = 0; state < 1 << M; ++state) {
            for (int j = 0; j < N; ++j) {
                int next = state & ~p[j];
                dp[state][j + 1] = min(dp[state][j], dp[next][j] + 1);
            }
        }
        vector<int> ans;
        int state = (1 << M) - 1, j = N - 1;
        for (; state; --j) {
            if (dp[state][j + 1] == dp[state][j]) continue; 
            ans.push_back(j);
            state &= ~p[j];
        }
        return ans;
    }
};