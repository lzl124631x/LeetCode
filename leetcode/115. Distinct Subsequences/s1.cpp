// OJ: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/lzl124631x
// Time: O(2^S), since there are O(2^S) subsequences. But the memo helps reduce lots of duplicate computation.
// Space: O(ST)
class Solution {
private:
    string S;
    string T;
    vector<vector<int>> v;
    int dfs(int start, int index) {
        if (index == T.size()) {
            return 1;
        }
        if (start >= S.size()) return 0;
        if (v[start][index] != -1) return v[start][index];
        int cnt = 0;
        for (int i = start; i < S.size(); ++i) {
            if (S[i] != T[index]) continue;
            int c = dfs(i + 1, index + 1);
            cnt += c;
        }
        v[start][index] = cnt;
        return cnt;
    }
public:
    int numDistinct(string s, string t) {
        S = s;
        T = t;
        v = vector<vector<int>>(s.size(), vector<int>(t.size(), -1));
        return dfs(0, 0);
    }
};