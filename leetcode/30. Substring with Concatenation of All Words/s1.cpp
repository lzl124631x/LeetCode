class Solution {
private:
    int len, n;
    string s;
    bool rec(int i, unordered_map<string, int> &m, int cnt) {
        if (cnt == n) return true;
        int &v = m[s.substr(i, len)];
        if (v) {
            v--;
            bool ret = rec(i + len, m, cnt + 1);
            v++;
            return ret;
        }
        return false;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) return {};
        this->s = s;
        len = words[0].size();
        n = words.size();
        unordered_map<string, int> m;
        for (string word : words) ++m[word];
        int end = s.size() - n * len;
        vector<int> v;
        for (int i = 0; i <= end; ++i) {
            if (rec(i, m, 0)) v.push_back(i);
        }
        return v;
    }
};