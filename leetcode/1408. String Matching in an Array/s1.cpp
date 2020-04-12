// OJ: https://leetcode.com/problems/string-matching-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N^2 * D)
// Space: O(1)
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int N = words.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                if (words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};