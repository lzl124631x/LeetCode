// OJ: https://leetcode.com/problems/unique-morse-code-words/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    string dict[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        for (string word : words) {
            string code;
            for (char c : word) code += dict[c - 'a'];
            s.insert(code);
        }
        return s.size();
    }
};