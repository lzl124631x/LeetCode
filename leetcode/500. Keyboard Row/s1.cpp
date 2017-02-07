class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> m;
        for (char c : "qwertyuiopQWERTYUIOP") m[c] = 0;
        for (char c : "asdfghjklASDFGHJKL") m[c] = 1;
        for (char c : "zxcvbnmZXCVBNM") m[c] = 2;
        vector<string> ans;
        for (string word : words) {
            int i = m[word[0]];
            bool valid = true;
            for (char c : word) {
                if (m[c] != i) {
                    valid = false;
                    break;
                }
            }
            if (valid) ans.push_back(word);
        }
        return ans;
    }
};