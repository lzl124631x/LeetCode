// OJ: https://leetcode.com/problems/clone-graph
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
  unordered_map<int, UndirectedGraphNode*> m;
  UndirectedGraphNode *dfs(UndirectedGraphNode *node) {
    if (m.count(node->label)) return m[node->label];
    auto copy = new UndirectedGraphNode(node->label);
    m[copy->label] = copy;
    for (auto n : node->neighbors) copy->neighbors.push_back(dfs(n));
    return copy;
  }
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) return NULL;
    return dfs(node);
  }
};