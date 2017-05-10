// OJ: https://leetcode.com/problems/clone-graph
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
  unordered_map<int, UndirectedGraphNode*> m;
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) return NULL;
    auto copy = new UndirectedGraphNode(node->label);
    m[node->label] = copy;
    for (auto n : node->neighbors)
      copy->neighbors.push_back(m.count(n->label) ? m[n->label] : cloneGraph(n));
    return copy;
  }
};