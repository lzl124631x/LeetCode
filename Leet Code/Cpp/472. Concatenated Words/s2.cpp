// https://discuss.leetcode.com/topic/72393/c-772-ms-dp-solution
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        vector<string> v;
        for (string word : words) {
            int n = word.size();
            vector<bool> dp(n, false);
            for (int i = 0; i < n - 1; ++i) {
                if (s.count(word.substr(0, i + 1))) dp[i] = true;
                if (!dp[i]) continue;
                for (int j = i + 1; j < n; ++j) {
                    if (s.count(word.substr(i + 1, j - i))) dp[j] = true;
                }
                if (dp[n - 1]) {
                    v.push_back(word);
                    break;
                }
            }
        }
        return v;
    }
};