// OJ: https://leetcode.com/problems/shortest-completing-word/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    vector<int> count(string &s) {
        vector<int> cnt(26, 0);
        for (char c : s) {
            if (isalpha(c)) {
                cnt[tolower(c) - 'a']++;
            }
        }
        return cnt;
    }
    bool isComplete(string &s, vector<int> target) {
        auto cnt = count(s);
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] < target[i]) return false;
        }
        return true;
    }
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        auto cnt = count(licensePlate);
        string ans;
        for (string &w : words) {
            if (!isComplete(w, cnt)) continue;
            if (ans.empty() || w.size() < ans.size()) ans = w;
        }
        return ans;
    }
};