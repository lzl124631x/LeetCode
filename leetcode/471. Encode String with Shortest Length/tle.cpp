// OJ: https://leetcode.com/problems/encode-string-with-shortest-length/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N)
class Solution {
private:
    bool compare(string &s, int s1, int s2, int len) {
        if (s1 + len > s.size() || s2 + len > s.size()) return false;
        int i = 0;
        for (; i < len && s[s1 + i] == s[s2 + i]; ++i);
        return i == len;
    }
public:
    string encode(string s) {
        if (s.size() <= 4) return s;
        string ans = s;
        for (int len = s.size() / 2; len >= 1; --len) {
            for (int i = 0; i + len <= s.size(); ++i) {
                int cnt = 1;
                while (compare(s, i, i + cnt * len, len)) ++cnt;
                if (cnt == 1) continue;
                string prefix = i > 0 ? encode(s.substr(0, i)) : "";
                string suffix = i + cnt * len < s.size() ? encode(s.substr(i + cnt * len)) : "";
                string middle = to_string(cnt) + "[" + encode(s.substr(i, len)) + "]";
                string encoded = prefix + middle + suffix;
                if (ans == "" || encoded.size() < ans.size()) ans = encoded;
            }
        }
        return ans;
    }
};