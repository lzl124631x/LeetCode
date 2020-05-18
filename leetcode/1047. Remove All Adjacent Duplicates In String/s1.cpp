// OJ: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for (char c : s) {
            if (ans.empty() || c != ans.back()) ans += c;
            else ans.pop_back();
        }
        return ans;
    }
};