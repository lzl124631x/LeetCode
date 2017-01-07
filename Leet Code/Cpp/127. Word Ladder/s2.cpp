// https://discuss.leetcode.com/topic/16983/easy-76ms-c-solution-using-bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        wordList.erase(beginWord);
        tail.insert(endWord);
        wordList.erase(endWord);
        int d = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> tmp;
            for (string s : *phead) {
                for (int i = 0; i < s.size(); ++i) {
                    char ch = s[i];
                    for (int j = 0; j < 26; ++j) {
                        s[i] = 'a' + j;
                        if (ptail->find(s) != ptail->end()) return d;
                        if (wordList.find(s) != wordList.end()) {
                            tmp.insert(s);
                            wordList.erase(s);
                        }
                    }
                    s[i] = ch;
                }
            }
            ++d;
            *phead = tmp;
        }
        return 0;
    }
};