// OJ: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
// Author: github.com/lzl124631x
// Time:
//      TreeAncestor: O(N)
//      getKthAncestor: O(logN)
// Space: O(N)
class TreeAncestor {
    vector<int> nodeToId, idToNode, idToLevel;
    vector<vector<int>> tree;
    void preorder(vector<vector<int>> &G, int u, int &i, int level) {
        if (level >= tree.size()) tree.emplace_back();
        tree[level].push_back(i);
        nodeToId[u] = i;
        idToNode[i] = u;
        idToLevel[i] = level;
        ++i;
        for (int v : G[u]) preorder(G, v, i, level + 1);
    }
public:
    TreeAncestor(int n, vector<int>& parent) {
        nodeToId.assign(n, 0);
        idToNode.assign(n, 0);
        idToLevel.assign(n, 0);
        vector<vector<int>> G(n);
        for (int i = 1; i < n; ++i) G[parent[i]].push_back(i);
        int i = 0;
        preorder(G, 0, i, 0);
    }
    int getKthAncestor(int node, int k) {
        int id = nodeToId[node];
        int level = idToLevel[id] - k;
        if (level < 0) return -1;
        return idToNode[*(upper_bound(begin(tree[level]), end(tree[level]), id) - 1)];
    }
};