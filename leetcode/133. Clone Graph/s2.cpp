// OJ: https://leetcode.com/problems/clone-graph
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) return NULL;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    unordered_map<int, UndirectedGraphNode*> m;
    UndirectedGraphNode *ans = new UndirectedGraphNode(node->label);
    m[ans->label] = ans;
    while (q.size()) {
      node = q.front();
      q.pop();
      auto copy = m[node->label];
      for (auto n : node->neighbors) {
        if (!m.count(n->label)) {
          q.push(n);
          m[n->label] = new UndirectedGraphNode(n->label);
        }
        copy->neighbors.push_back(m[n->label]);
      }
    }
    return ans;
  }
};