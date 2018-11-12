# [310. Minimum Height Trees (Medium)](https://leetcode.com/problems/minimum-height-trees/)

For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

**Format**  
The graph contains `n` nodes which are labeled from `0` to `n - 1`. You will be given the number `n` and a list of undirected `edges` (each edge is a pair of labels).

You can assume that no duplicate edges will appear in `edges`. Since all edges are undirected, `[0, 1]` is the same as `[1, 0]` and thus will not appear together in `edges`.

**Example 1 :**

**Input:** `n = 4`, `edges = [[1, 0], [1, 2], [1, 3]]`

        0
        |
        1
       / \
      2   3 

**Output:** `[1]`

**Example 2 :**

**Input:** `n = 6`, `edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]`

     0  1  2
      \ | /
        3
        |
        4
        |
        5 

**Output:** `[3, 4]`

**Note**:

*   According to the [definition of tree on Wikipedia](https://en.wikipedia.org/wiki/Tree_(graph_theory)): “a tree is an undirected graph in which any two vertices are connected by _exactly_ one path. In other words, any connected graph without simple cycles is a tree.”
*   The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

## Solution 1.

Find the leave nodes, trim them from the graph. Repeat this process until the graph only has 1 or 2 points left.

```cpp
// OJ: https://leetcode.com/problems/minimum-height-trees
// Author: github.com/lzl124631x
// Time: O(E)
// Space: O(E)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return { 0 };
        unordered_map<int, unordered_set<int>> neighbors;
        for (auto &e : edges) {
            neighbors[e.first].insert(e.second);
            neighbors[e.second].insert(e.first);
        }
        vector<int> leaves;
        for (auto &p : neighbors) {
            if (p.second.size() == 1) leaves.push_back(p.first);
        }
        while (neighbors.size() > 2) {
            vector<int> newLeaves;
            for (int leaf : leaves) {
                int neighbor = *neighbors[leaf].begin();
                neighbors[neighbor].erase(leaf);
                if (neighbors[neighbor].size() == 1) newLeaves.push_back(neighbor);
                neighbors.erase(leaf);
            }
            leaves = newLeaves;
        }
        vector<int> ans;
        for (auto &p : neighbors) ans.push_back(p.first);
        return ans;
    }
};
```

## Solution 2.

Same as Solution 1, except that `queue` is used to save computation.

```cpp
// OJ: https://leetcode.com/problems/minimum-height-trees
// Author: github.com/lzl124631x
// Time: O(E)
// Space: O(E)
class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    if (n == 1) return { 0 };
    unordered_map<int, unordered_set<int>> m;
    for (auto e : edges) {
      m[e.first].insert(e.second);
      m[e.second].insert(e.first);
    }
    queue<int> q;
    for (auto p : m) if (p.second.size() == 1) q.push(p.first);
    while (m.size() > 2) {
      int cnt = q.size();
      while (cnt--) {
        int leaf = q.front(), neighbor = *m[leaf].begin();
        q.pop();
        m[neighbor].erase(leaf);
        m.erase(leaf);
        if (m[neighbor].size() == 1) q.push(neighbor);
      }
    }
    vector<int> ans;
    for (auto p : m) ans.push_back(p.first);
    return ans;
  }
};
```