// OJ: https://leetcode.com/problems/letter-case-permutation/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
private:
    vector<string> ans;
    void dfs(string &S, int i) {
        while (i < S.size() && !isalpha(S[i])) ++i;
        if (i == S.size()) {
            ans.push_back(S);
            return;
        }
        dfs(S, i + 1);
        S[i] += ('A' - 'a') * ((S[i] >= 'a' && S[i] <= 'z') ? 1 : -1);
        dfs(S, i + 1);
    }
public:
    vector<string> letterCasePermutation(string S) {
        dfs(S, 0);
        return ans;
    }
};