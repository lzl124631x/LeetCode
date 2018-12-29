// OJ: https://leetcode.com/problems/shortest-word-distance/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int prev1 = -1, prev2 = -1, ans = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                if (prev2 != -1) ans = min(ans, i - prev2);
                prev1 = i;
            }
            if (words[i] == word2) {
                if (prev1 != -1) ans = min(ans, i - prev1);
                prev2 = i;
            }
        }
        return ans;
    }
};