// https://discuss.leetcode.com/topic/16983/easy-76ms-c-solution-using-bfs
class Solution {
private:
    void addWords(string &word, unordered_set<string> &wordList, queue<string> &q) {
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            for (int j = 0; j < 26; ++j) {
                word[i] = 'a' + j;
                if (wordList.find(word) != wordList.end()) {
                    q.push(word);
                    wordList.erase(word);
                }
            }
            word[i] = c;
        }
    }
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<string> q;
        int d = 1;
        q.push(beginWord);
        wordList.insert(endWord);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string s = q.front();
                q.pop();
                if (s == endWord) return d;
                addWords(s, wordList, q);
            }
            ++d;
        }
        return 0;
    }
};