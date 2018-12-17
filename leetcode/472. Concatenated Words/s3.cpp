// OJ: https://leetcode.com/problems/concatenated-words/
// Author: github.com/lzl124631x
// Time: O(N*W^3)
// Space: O(C) where C is the length sum of words.
// Ref: https://discuss.leetcode.com/topic/72393/c-772-ms-dp-solution
class Solution {
private:
    unordered_set<string> s;
    bool isConcatenatedWord(string &word) {
        int W = word.size();
        vector<bool> dp(W, false);
        for (int i = 0; i < W - 1; ++i) {
            if (s.count(word.substr(0, i + 1))) dp[i] = true;
            if (!dp[i]) continue;
            for (int j = i + 1; j < W; ++j) {
                if (s.count(word.substr(i + 1, j - i))) dp[j] = true;
            }
            if (dp[W - 1]) return true;
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        s = unordered_set<string>(words.begin(), words.end());
        vector<string> ans;
        for (string &word : words) {
            if (isConcatenatedWord(word)) ans.push_back(word);
        }
        return ans;
    }
};