// OJ: https://leetcode.com/problems/find-the-town-judge/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> indegree(N + 1), outdegree(N + 1);
        for (auto &t : trust) {
            outdegree[t[0]]++;
            indegree[t[1]]++;
        }
        int judge = -1;
        for (int i = 1; i <= N; ++i) {
            if (indegree[i] != N - 1 || outdegree[i] != 0) continue;
            if (judge != -1) return false;
            judge = i;
        }
        return judge;
    }
};