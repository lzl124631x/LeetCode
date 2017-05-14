# [133. Clone Graph (Medium)](https://leetcode.com/problems/clone-graph)
Clone an undirected graph. Each node in the graph contains a `label` and a list of its `neighbors`.

**OJ's undirected graph serialization:**
Nodes are labeled uniquely.

We use `#` as a separator for each node, and `,` as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph `{0,1,2#1,2#2,2}`.

The graph has a total of three nodes, and therefore contains three parts as separated by `#`.

1. First node is labeled as `0`. Connect node `0` to both nodes `1` and `2`.
2. Second node is labeled as `1`. Connect node `1` to node `2`.
3. Third node is labeled as `2`. Connect node `2` to node `2` (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

```
       1
      / \
     /   \
    0 --- 2
         / \
         \_/
```

## Solution 1. DFS

An `unordered_map` is used to record the mapping between the original and copied nodes, and to ensure each node is only copied once.

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

## Solution 2. BFS

An `unordered_map` is used for the same reason as solution 1.

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