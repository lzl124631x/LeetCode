# Topological Sort

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge `uv`, vertex `u` comes before `v` in the ordering.

## Implementation

### Kahn Algorithm (BFS)

1. Put all the vertices with 0 in-degree in to a `queue q`.
1. Get a vertex `u` at a time from `q`, and decrement the in-degree of all its neighbors.
1. If a neighbor has 0 in-degree, add it to `q`.
1. Keep repeating until we exhaust `q`.
1. If the number of visited vertices equals the total number of vertices, it's a DAG; otherwise, there must be a circle in the graph.

```cpp
// OJ: https://leetcode.com/problems/course-schedule-ii/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& E) {
        unordered_map<int, vector<int>> G;
        vector<int> indegree(N);
        for (auto &e : E) {
            G[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while (q.size()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int v : G[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return ans.size() == N ? ans : vector<int>{};
    }
};
```

### DFS

Each vertex has three states:

1. 0 =  unvisited
2. -1 = being visited in the current DFS session. If we visit a node with state -1, it means there is a circle in the graph.
3. 1 = has been visited in a prevous DFS session and this vertex is not in a circle.

```cpp
// OJ: https://leetcode.com/problems/course-schedule-ii/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
    vector<int> ans;
    unordered_map<int, vector<int>> G;
    vector<int> seen;
    bool dfs(int u) {
        if (seen[u]) return seen[u] == 1;
        seen[u] = -1;
        for (int v : G[u]) {
            if (!dfs(v)) return false;
        }
        seen[u] = 1;
        ans.push_back(u);
        return true;
    }
public:
    vector<int> findOrder(int N, vector<vector<int>>& E) {
        seen.assign(N, 0);
        for (auto &e : E) G[e[1]].push_back(e[0]);
        for (int i = 0; i < N; ++i) {
            if (seen[i]) continue;
            if (!dfs(i)) return {};
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```

## Problems

* [207. Course Schedule (Medium)](https://leetcode.com/problems/course-schedule/)
* [210. Course Schedule II (Medium)](https://leetcode.com/problems/course-schedule-ii/)