// OJ: https://leetcode.com/problems/most-common-word/
// Author: github.com/lzl124631x
// Time: O(N) where N is character count in paragraph
// Space: O((B + P)W)
//     where B is the size of ban list,
//     P is unique count of words in paragraph that are not banned,
//     and W is average word length
class Solution {
private:
    string getWord(string::iterator& it, string::iterator end) {
        while (it != end && !isalpha(*it)) ++it;
        string res;
        for (; it != end && isalpha(*it); ++it) {
            res += tolower(*it);
        }
        return res;
    }
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        unordered_set<string> ban(banned.begin(), banned.end());
        string word;
        string res;
        int maxCnt = 0;
        auto it = paragraph.begin();
        while ((word = getWord(it, paragraph.end())) != "") {
            if (ban.find(word) != ban.end()) continue;
            m[word]++;
            if (m[word] > maxCnt) {
                maxCnt = m[word];
                res = word;
            }
        }
        return res;
    }
};