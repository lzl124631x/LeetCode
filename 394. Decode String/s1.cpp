class Solution {
private:
    string dfs(string &s, int &i) {
        string ans;
        while (i < s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                int n = 0;
                while (isdigit(s[i])) n = n * 10 + s[i++] - '0';
                ++i;
                string part = dfs(s, i);
                ++i;
                while (n--) ans += part;
            } else {
                ans.push_back(s[i++]);
            }
        }
        return ans;
    }
public:
    string decodeString(string s) {
        string ans;
        int i = 0;
        return dfs(s, i);
    }
};