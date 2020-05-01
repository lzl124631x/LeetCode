# Union Find

## Implementation

### Basic

Note that there is a path compression in the `find` function.

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

### Get Size of Union

We can use a `size` array to keep track of the size of each union.

```cpp
class UnionFind {
    vector<int> id, size;
public:
    UnionFind(int n) : id(n), size(n, 1) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
        size[y] += size[x];
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    int getSize(int a) {
        return size[find(a)];
    }
};
```

## Problems

* [1319. Number of Operations to Make Network Connected (Medium)](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)
* [990. Satisfiability of Equality Equations (Medium)](https://leetcode.com/problems/satisfiability-of-equality-equations/)
* [924. Minimize Malware Spread (Hard)](https://leetcode.com/problems/minimize-malware-spread/)
* [947. Most Stones Removed with Same Row or Column (Medium)](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)

静态联通性
200
130
952 (等价类)
959 
990

动态连通性. find和union穿插的.
305

时光倒流
803

最小生成树
kruskal


线段树

懒标记
权值线段树
218
307
308
315
327
493
699
715
732
850
1157
1353

lazy tag / lazy propogation
延迟修改


树状数组
307

lowbit(x) = x & (-x)

12 = (01100)2
-12 = (10100)2
12 & (-12) = (00100)2