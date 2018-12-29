// OJ: https://leetcode.com/problems/output-contest-matches/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) ans[i] = to_string(1 + i);
        while (n != 1) {
            for (int i = 0, j = 0; i < n / 2; ++i) {
                ans[j++] = "(" + ans[i] + "," + ans[n - i - 1] + ")";
            }
            n /= 2;
        }
        return ans[0];
    }
};