// OJ: https://leetcode.com/problems/largest-time-for-given-digits/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
    string ans;
    void permute(string &s, int start) {
        if (start == s.size()) {
            ans = max(ans, s);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if ((start == 0 && s[i] > '2')
               || (start == 1 && s[start - 1] == '2' && s[i] > '3')
               || (start == 2 && s[i] > '5')) continue;
            swap(s[start], s[i]);
            permute(s, start + 1);
            swap(s[start], s[i]);
        }
    }
public:
    string largestTimeFromDigits(vector<int>& A) {
        string s;
        for (int i : A) s.push_back('0' + i);
        permute(s, 0);
        if (ans.size()) ans.insert(2, ":");
        return ans.size() ? ans : "";
    }
};