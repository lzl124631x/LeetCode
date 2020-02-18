# Component Coloring

Color each connected component in a graph with different colors.

## Implementation

Implement a function `int componentColoring(vector<vector<int>> &G, vector<int> &color) ` where `G` is an adjacency list representation of the graph, `color` should be updated such that `color[i]` is the color index (starting from `0`) of the component where `i`th node belongs, and the return value is the number of colors (i.e. components).

### DFS

```cpp
void dfs(vector<vector<int>> &G, int u, vector<int> &color, int k) {
    color[u] = k;
    for (int v : G[u]) {
        if (color[v] > -1) continue;
        dfs(G, v, color, k);
    }
}
int componentColoring(vector<vector<int>> &G, vector<int> &color) {
    int N = G.size(), k = 0;
    color.resize(N);
    fill(color.begin(), color.end(), -1);
    for (int i = 0; i < N; ++i) {
        if (color[i] > -1) continue;
        dfs(G, i, color, k++);
    }
    return k;
}
```

### BFS

```cpp
int componentColoring(vector<vector<int>> &G, vector<int> &color) {
    int N = G.size(), k = 0;
    color.resize(N);
    fill(color.begin(), color.end(), -1);
    for (int i = 0; i < N; ++i) {
        if (color[i] > -1) continue;
        queue<int> q;
        q.push(i);
        color[i] = k;
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) {
                if (color[v] > -1) continue;
                q.push(v);
                color[v] = k;
            }
        }
        ++k;
    }
    return k;
}
```

### Union Find

```cpp
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
};
int componentColoring(vector<vector<int>> &G, vector<int> &color) {
    int N = G.size(), k = 0;
    color.resize(N);
    fill(color.begin(), color.end(), -1);
    UnionFind uf(N);
    for (int u = 0; u < N; ++u) {
        for (int v : G[u]) uf.connect(u, v);
    }
    for (int i = 0; i < N; ++i) {
        int r = uf.find(i);
        if (color[r] == -1) color[r] = k++;
        color[i] = color[r];
    }
    return k;
}
```