class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        sort(strs.begin(), strs.end());
        int len = 0;
        while (strs[0][len] && strs.back()[len] && strs[0][len] == strs.back()[len]) ++len;
        return strs[0].substr(0, len);
    }
};