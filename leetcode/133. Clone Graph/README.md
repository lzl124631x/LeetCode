# [133. Clone Graph](https://leetcode.com/problems/clone-graph)
DFS/BFS即可, 利用`unordered_map`记录新旧节点的映射关系, 同时用来避免重复创建节点.

## Solution 1: DFS
```cpp
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
```

## Solution 2: BFS
```cpp
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
    auto ans = new UndirectedGraphNode(node->label);
    unordered_map<int, UndirectedGraphNode*> m {{ node->label, ans }};
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
```