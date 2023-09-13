// OJ: https://leetcode.com/problems/most-common-word/
// Author: github.com/lzl124631x
// Time: O(N) where N is character count in paragraph
// Space: O(N)
// Ref: https://leetcode.com/problems/most-common-word/discuss/184971/C%2B%2B-4ms-straightforward-solution
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for (auto &c : paragraph) {
            c = isalpha(c) ? tolower(c) : ' ';
        }
        
        istringstream iss(paragraph);
        string word;
        unordered_map<string, int> cnt;
        while (iss >> word) ++cnt[word];
        
        for (auto b : banned) cnt[b] = 0;
        
        int maxCnt = 0;
        for (auto p : cnt) {
            if (p.second > maxCnt) {
                maxCnt = p.second;
                word = p.first;
            }
        }
        return word;
    }
};