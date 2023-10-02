// OJ: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
// Author: github.com/lzl124631x
// Time: O(3^N)
// Space: O(1)
class Solution {
    string addOne(string &s) {
        int i = s.size() - 1;
        for (; i >= 0; --i) {
            if (s[i] == 'c') {
                s[i] = 'a';
                continue;
            }
            s[i]++;
            break;
        }
        return i == -1 ? (s = "") : s;
    }
    bool valid(string &s) {
        int i = s.size() - 1;
        for (; i > 0; --i) {
            if (s[i] == s[i - 1]) return false;
        }
        return true;
    }
    string next(string &s) {
        do {
            addOne(s);
        } while (s != "" && !valid(s));
        return s;
    }
public:
    string getHappyString(int n, int k) {
        string ans;
        for (int i = 0; i < n; ++i) ans.push_back(i % 2 == 0 ? 'a' : 'b');
        while (--k) {
            ans = next(ans);
            if (ans == "") return "";
        }
        return ans;
    }
};