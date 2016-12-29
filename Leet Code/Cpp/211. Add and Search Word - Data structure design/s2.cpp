class WordDictionary {
private:
    vector<string> v;
    set<int> lengths;
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        v.push_back(word);
        lengths.insert((int)word.size());
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if (lengths.find((int)word.size()) == lengths.end()) return false;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].size() != word.size()) continue;
            bool match = true;
            for (int j = 0; j < v[i].size(); ++j) {
                if (word[j] != '.' && v[i][j] != word[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return true;
            }
        }
        return false;
    }
};