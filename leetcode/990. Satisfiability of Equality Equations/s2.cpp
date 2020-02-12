// OJ: https://leetcode.com/problems/satisfiability-of-equality-equations/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int uf[26];
    int find(int x) {
        return uf[x] == x ? x : (uf[x] = find(uf[x]));
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) uf[i] = i;
        for (auto e : equations) {
            if (e[1] == '=') uf[find(e[0] - 'a')] = find(e[3] - 'a'); 
        }
        for (auto e : equations) {
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a')) return false;
        }
        return true;
    }
};