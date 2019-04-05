// OJ: https://leetcode.com/problems/valid-word-square/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (int i = 0, M = words.size(); i < M; ++i) {
            for (int j = 0, N = words[i].size(); j < N; ++j) {
                if (j >= M || i >= words[j].size() || words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};