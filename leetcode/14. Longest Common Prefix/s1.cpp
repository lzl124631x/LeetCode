class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        int len = strs[0].size();
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            while (strs[i][j] && strs[0][j] && strs[i][j] == strs[0][j]) ++j;
            len = min(len, j);
        }
        return strs[0].substr(0, len);
    }
};