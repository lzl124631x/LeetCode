// OJ: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author: github.com/lzl124631x
// Time: O(4^N * N)
// Space: O(4^N * N)
class Solution {
private:
    vector<string> M{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans{""};
        for (char c : digits) {
            vector<string> next;
            string m = M[c - '2'];
            for (string s : ans) {
                for (char c : m) {
                    next.push_back(s + c);
                }
            }
            ans = next;
        }
        return ans;
    }
};