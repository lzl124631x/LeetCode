# [947. Most Stones Removed with Same Row or Column (Medium)](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column)

<p>On a 2D plane, we place <code>n</code> stones at some integer coordinate points. Each coordinate point may have at most one stone.</p>

<p>A stone can be removed if it shares either <strong>the same row or the same column</strong> as another stone that has not been removed.</p>

<p>Given an array <code>stones</code> of length <code>n</code> where <code>stones[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> represents the location of the <code>i<sup>th</sup></code> stone, return <em>the largest possible number of stones that can be removed</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> stones = [[0,0]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> [0,0] is the only stone on the plane, so you cannot remove it.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= stones.length &lt;= 1000</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>No two stones are at the same coordinate point.</li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [TikTok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1. DFS Iterative

Let's call stone `A` and `B` are neighbors if they are in the same row/column.

Define a **component** as a set of stones where each of them are neighbors and none of them is neighbor of stones outside of this set.

For each component, we can always remove the stones until there is just one left.

So we use DFS to visit the stones in the same component, and each component can contribute `conponentSize - 1` moves.

```cpp
// OJ: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
// Ref: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/solution/
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int N = stones.size();
        vector<vector<int>> graph(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i][++graph[i][0]] = j;
                    graph[j][++graph[j][0]] = i;
                }
            }
        }
        int ans = 0;
        vector<bool> seen(N);
        for (int i = 0; i < N; ++i) {
            if (seen[i]) continue;
            stack<int> s;
            s.push(i);
            seen[i] = true;
            --ans;
            while (s.size()) {
                int node = s.top();
                s.pop();
                ++ans;
                for (int j = 1; j <= graph[node][0]; ++j) {
                    int n = graph[node][j];
                    if (!seen[n]) {
                        s.push(n);
                        seen[n] = true;
                    }
                }
            }
        }
        return ans;
    }
};
```

## Solution 2. DFS Recursive

```cpp
// OJ: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    void dfs(vector<vector<int>> &G, vector<bool> &visited, int start) {
        visited[start] = true;
        for (int n : G[start]) {
            if (visited[n]) continue;
            dfs(G, visited, n);
        }
    }
    int getComponentCount(vector<vector<int>> &G) {
        vector<bool> visited(G.size());
        int ans = 0;
        for (int i = 0; i < G.size(); ++i) {
            if (visited[i]) continue;
            ++ans;
            dfs(G, visited, i);
        }
        return ans;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int N = stones.size();
        vector<vector<int>> G(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        return stones.size() - getComponentCount(G);
    }
};
```

## Solution 3. BFS

```cpp
// OJ: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
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
public:
    int removeStones(vector<vector<int>>& stones) {
        int N = stones.size();
        vector<vector<int>> G(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        return stones.size() - getComponentCount(G);
    }
};
```


## Solution 4. Union Find

```cpp
// OJ: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Author: github.com/lzl124631x
// Time: O(N^2 * logN)
// Space: O(N)
class UnionFind {
    vector<int> id;
    int cnt;
public:
    UnionFind(int n) : cnt(n), id(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
        --cnt;
    }
    int getCount() { return cnt; }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& A) {
        int N = A.size();
        UnionFind uf(N);
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (A[i][0] == A[j][0] || A[i][1] == A[j][1]) {
                    uf.connect(i, j);
                }
            }
        }
        return N - uf.getCount();
    }
};
```

## Solution 5. Union Find

```cpp
// OJ: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column
// Author: github.com/lzl124631x
// Time: O(N * logN)
// Space: O(N)
class UnionFind {
    vector<int> id;
    int cnt;
public:
    UnionFind(int n) : id(n), cnt(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
        --cnt;
    }
    int getCount() { return cnt; }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& A) {
        int N = A.size();
        unordered_map<int, int> row, col; // row/col number -> index of the first stone exists on row/col
        UnionFind uf(N);
        for (int i = 0; i < N; ++i) {
            int x = A[i][0], y = A[i][1];
            if (row.count(x) == 0) row[x] = i;
            else uf.connect(i, row[x]);
            if (col.count(y) == 0) col[y] = i;
            else uf.connect(i, col[y]);
        }
        return N - uf.getCount();
    }
};
```