// OJ: https://leetcode.com/problems/goat-latin/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(W) where W is max word length
class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string toGoatLatin(string S) {
        istringstream ss(S);
        string word, ans;
        string suffix = "a";
        while (ss >> word) {
            if (!isVowel(word[0])) rotate(word.begin(), word.begin() + 1, word.end());
            ans += (suffix.size() > 1 ? " " : "") + word + "ma" + suffix;
            suffix += "a";
        }
        return ans;
    }
};