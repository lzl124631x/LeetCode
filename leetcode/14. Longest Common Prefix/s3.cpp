class Solution {
private:
    string longestCommonPrefix(vector<string>& strs, int begin, int end) {
        if (begin == end) return "";
        if (begin == end - 1) return strs[begin];
        int mid = (begin + end) / 2, len = 0;
        string left = longestCommonPrefix(strs, begin, mid);
        string right = longestCommonPrefix(strs, mid, end);
        while (left[len] && right[len] && left[len] == right[len]) ++len;
        return left.substr(0, len);
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        return longestCommonPrefix(strs, 0, strs.size());
    }
};