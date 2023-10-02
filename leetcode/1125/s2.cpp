// OJ: https://leetcode.com/problems/smallest-sufficient-team/
// Author: github.com/lzl124631x
// Time: O(2^M * N) where M is the size of `req_skills`, N is the number of people
// Space: O(2^M + N)
// Ref: https://leetcode.com/problems/smallest-sufficient-team/discuss/342120/C%2B%2B-DP-32ms-DP-solution.-Easy-to-implement
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> m;
        int M = req_skills.size(), N = people.size();
        for (int i = 0; i < M; ++i) m[req_skills[i]] = i;
        vector<int> p(N), dp(1 << M, INT_MAX), pick(1 << M, -1), prevState(1 << M);
        dp[0] = 0;
        for (int i = 0; i < N; ++i) {
            for (auto &s : people[i]) {
                p[i] |= (1 << m[s]);
            }
        }
        for (int state = 0; state < 1 << M; ++state) {
            for (int j = 0; j < N; ++j) {
                if (dp[state] == INT_MAX) continue;
                int next = state | p[j];
                if (dp[next] > dp[state] + 1) {
                    pick[next] = j;
                    prevState[next] = state;
                    dp[next] = dp[state] + 1;
                }
            }
        }
        int state = (1 << M) - 1;
        vector<int> ans;
        while (pick[state] != -1) {
            ans.push_back(pick[state]);
            state = prevState[state];
        }
        return ans;
    }
};