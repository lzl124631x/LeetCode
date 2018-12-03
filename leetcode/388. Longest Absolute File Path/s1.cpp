// OJ: https://leetcode.com/problems/longest-absolute-file-path/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> len;
        stringstream ss(input);
        string line;
        int ans = 0;
        while (getline(ss, line)) {
            int lv = 0;
            while (lv < line.size() && line[lv] == '\t') ++lv;
            while (len.size() > lv) len.pop();
            int pathLen = len.empty() ? 0 : len.top(), curLen = line.size() - lv;
            if (line.find('.') != string::npos) {
                ans = max(ans, pathLen + curLen);
            } else {
                len.push(pathLen + 1 + curLen);
            }
        }
        return ans;
    }
};