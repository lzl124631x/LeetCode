// OJ: https://leetcode.com/problems/reorder-log-files
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLogs, letterLogs;
        for (string &s : logs) {
            int i = 0;
            while (s[i] != ' ') ++i;
            if (isalpha(s[i + 1])) letterLogs.push_back(s.substr(i + 1) + " " + s.substr(0, i));
            else digitLogs.push_back(s);
        }
        sort(letterLogs.begin(), letterLogs.end());
        for (string &s : letterLogs) {
            int i = s.size() - 1;
            while (s[i] != ' ') --i;
            s = s.substr(i + 1) + " " + s.substr(0, i);
        }
        for (string &s : digitLogs) letterLogs.push_back(s);
        return letterLogs;
    }
};