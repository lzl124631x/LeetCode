# Union Find

## Implementation

### Basic
```cpp
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    void connect(int a, int b) {
        id[find(a)] = find(b);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
```

### Merge using Rank

The time complexity of one operation in `UnionFind` containing `N` elements is `O(alpha(N))` where `alpha(N)` is the inverse function of Ackermann function. Note that `O(alpha(N))` is even more efficient than `O(logN)`.

```cpp
class UnionFind {
private:
    vector<int> id, rank;
    int cnt;
    int find (int i) {
        if (id[i] == i) return i;
        return id[i] = find(id[i]);
    }
public:
    UnionFind(int n) : id(n), rank(n, 0), cnt(n) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    void connect(int i, int j) {
        int p = find(i), q = find(j);
        if (p == q) return;
        if (rank[p] > rank[q]) id[p] = q;
        else {
            id[q] = p;
            if (rank[p] == rank[q]) rank[p]++;
        }
        --cnt;
    }
    bool connected(int i, int j) { return find(i) == find(j); }
    int getCount() { return cnt; }
};
```

## Problems

* [1319. Number of Operations to Make Network Connected (Medium)](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)
* [990. Satisfiability of Equality Equations (Medium)](https://leetcode.com/problems/satisfiability-of-equality-equations/)