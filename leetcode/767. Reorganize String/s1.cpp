// OJ: https://leetcode.com/problems/reorganize-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reorganizeString(string S) {
        int cnts[26] = {0};
        for (char c : S) cnts[c - 'a']++;
        string ans(S.size(), '\0');
        for (int i = 0; i < S.size(); ++i) {
            int maxIndex = -1;
            for (int j = 0; j < 26; ++j) {
                if (!cnts[j] || (i > 0 && ans[i - 1] == j + 'a')) continue;
                if (maxIndex == -1 || cnts[j] > cnts[maxIndex]) maxIndex = j;
            }
            if (maxIndex == -1) return "";
            cnts[maxIndex]--;
            ans[i] = maxIndex + 'a';
        }
        return ans;
    }
};