class Solution {
private:
    vector<string> M{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        for (char c : digits) {
            if (c <= '1' || c > '9') return {};
            vector<string> next;
            string m = M[c - '2'];
            if (ans.empty()) ans.push_back("");
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