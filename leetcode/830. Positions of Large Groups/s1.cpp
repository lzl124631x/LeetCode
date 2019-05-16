// OJ: https://leetcode.com/problems/positions-of-large-groups/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        for (int N = S.size(), i = 0; i < N;) {
            int j = i + 1;
            while (j < N && S[j] == S[i]) ++j;
            if (j - i >= 3) ans.push_back({ i, j - 1 });
            i = j;
        }
        return ans;
    }
};