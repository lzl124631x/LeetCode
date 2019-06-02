// OJ: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size(), ans = 0;
        unordered_map<string, int> cnt;
        for (int i = 0; i < M; ++i) {
            string s;
            bool flip = matrix[i][0] == 1;
            for (int j = 0; j < N; ++j) s += flip ? ('1' - matrix[i][j]) : ('0' + matrix[i][j]);
            ans = max(ans, ++cnt[s]);
        }
        return ans;
    }
};