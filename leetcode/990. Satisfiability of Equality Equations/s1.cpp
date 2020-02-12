// OJ: https://leetcode.com/problems/satisfiability-of-equality-equations/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class UnionFind {
    unordered_map<char, char> id;
    unordered_map<char, int> rank;
public:
    void connect(char a, char b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        if (rank[x] <= rank[y]) {
            id[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        } else id[y] = x;
    }
    char find(char a) {
        if (!id.count(a)) {
            rank[a] = 1;
            id[a] = a;
        }
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf;
        for (auto e : equations) {
            if (e[1] == '=') uf.connect(e[0], e[3]);
        }
        for (auto e : equations) {
            if (e[1] == '!' && uf.find(e[0]) == uf.find(e[3])) return false;
        }
        return true;
    }
};