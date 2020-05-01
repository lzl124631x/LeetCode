# Component Count

A [**component**](https://en.wikipedia.org/wiki/Component_(graph_theory)) in a graph is a set of vertices where each of them are neighbors and none of them is neighbor of vertices outside of this set.

Count connected components in a graph.

## Implementation

Implement a function `int getComponentCount(vector<vector<int>> &G)`, where `G` is an adjacency list representation of the graph, and the return value is the count of components in the graph.

### DFS

```cpp
void bfs(vector<vector<int>> &G, vector<bool> &visited, int start) {
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            q.push(v);
        }
    }
}
int getComponentCount(vector<vector<int>> &G) {
    int ans = 0;
    vector<bool> visited(G.size());
    for (int i = 0; i < G.size(); ++i) {
        if (visited[i]) continue;
        ++ans;
        bfs(G, visited, i);
    }
    return ans;
}
```

### BFS

```cpp
void bfs(vector<vector<int>> &G, vector<bool> &visited, int start) {
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            q.push(v);
        }
    }
}
int getComponentCount(vector<vector<int>> &G) {
    int ans = 0;
    vector<bool> visited(G.size());
    for (int i = 0; i < G.size(); ++i) {
        if (visited[i]) continue;
        ++ans;
        bfs(G, visited, i);
    }
    return ans;
}
```

### Union Find


```cpp
class UnionFind {
    vector<int> id, rank;
    int cnt;
public:
    UnionFind(int n) : cnt(n), id(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        if (rank[x] <= rank[y]) {
            id[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        } else id[y] = x;
        --cnt;
    }
    int getCount() { return cnt; }
};
int getComponentCount(vector<vector<int>> &G) {
    UnionFind uf(G.size());
    for (int u = 0; u < G.size(); ++u) {
        for (int v : G[u]) uf.connect(u, v);
    }
    return uf.getCount();
}
```

## Problems

* [947. Most Stones Removed with Same Row or Column (Medium)](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)
* [200. Number of Islands (Medium)](https://leetcode.com/problems/number-of-islands/)