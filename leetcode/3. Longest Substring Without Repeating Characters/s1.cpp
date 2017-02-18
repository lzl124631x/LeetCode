class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, i = 0, j = 0;
        set<char> st;
        while (j < s.size()) {
            while (j < s.size() && !st.count(s[j])) st.insert(s[j++]);
            ans = max(ans, j - i);
            while (i < j && s[i] != s[j]) st.erase(s[i++]);
            ++i;
            ++j;
        }
        return ans;
    }
};