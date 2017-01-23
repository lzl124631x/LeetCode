class Solution {
private:
    set<string> ans;
    vector<int> rightNum;
    string s;
    int maxLen = 0;
    void dfs(int leftNum, int start, string &path) {
        for (int i = start; i < s.size(); ++i) {
            if ((s[i] != '(' && s[i] != ')')
            || (s[i] == '(' && rightNum[i] - leftNum > 0)
            || (s[i] == ')' && leftNum > 0)) {
                path.push_back(s[i]);
                int next = leftNum;
                if (s[i] == '(') ++next;
                else if (s[i] == ')') --next;
                dfs(next, i + 1, path);
                path.pop_back();
            }
        }
        if (leftNum == 0) {
            maxLen = max(maxLen, (int)path.size());
            ans.insert(path);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        this->s = s;
        rightNum = vector<int>(s.size());
        for (int i = s.size() - 1; i >= 0; --i) {
            if (i + 1 < s.size()) rightNum[i] = rightNum[i + 1];
            if (s[i] == ')') ++rightNum[i];
        }
        string path;
        dfs(0, 0, path);
        vector<string> v;
        for (string path : ans) {
            if (path.size() == maxLen) v.push_back(path);
        }
        return v;
    }
};