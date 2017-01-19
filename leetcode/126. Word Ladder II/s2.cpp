class Solution {
private:
    vector<vector<string>> ret;
    unordered_map<string, vector<string>> m;
    string endWord;
    void dfs(string s, vector<string> &path) {
        if (path.size() > d) return;
        if (s == endWord) {
            ret.push_back(path);
            return;
        }
        for (string next : m[s]) {
            path.push_back(next);
            dfs(next, path);
            path.pop_back();
        }
    }
    int d;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        this->endWord = endWord;
        wordList.insert(beginWord);
        wordList.insert(endWord);
        queue<string> q;
        q.push(beginWord);
        bool found = false;
        d = 1;
        while (!q.empty() && !found) {
            int n = q.size();
            unordered_set<string> added;
            while (n--) {
                string s = q.front();
                q.pop();
                wordList.erase(s);
                auto &neighbor = m[s];
                for (int i = 0; i < s.size(); ++i) {
                    char c = s[i];
                    for (char j = 'a'; j <= 'z'; ++j) {
                        s[i] = j;
                        if (wordList.find(s) != wordList.end()) {
                            if (s == endWord) found = true;
                            neighbor.push_back(s);
                            if (added.find(s) == added.end()) {
                                q.push(s);
                            }
                            added.insert(s);
                        }
                    }
                    s[i] = c;
                }
            }
            ++d;
        }
        if (!found) return {};
        vector<string> path {beginWord};
        dfs(beginWord, path);
        return ret;
    }
};