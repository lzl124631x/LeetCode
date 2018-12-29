// OJ: https://leetcode.com/problems/shortest-distance-to-a-character/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int N = S.size(), prevJ;
        vector<int> ans(N);
        for (int i = 0, j = -1; i < N; ++i) {
            if (i > j) {
                prevJ = j;
                do { ++j; } while (j < N && S[j] != C);
            }
            ans[i] = min(j == N ? INT_MAX : j - i, prevJ == -1 ? INT_MAX : i - prevJ);
        }
        return ans;
    }
};