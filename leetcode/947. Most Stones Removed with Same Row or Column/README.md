# [947. Most Stones Removed with Same Row or Column (Medium)](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)

<p>On a 2D plane, we place stones at some integer coordinate points.&nbsp; Each coordinate point may have at most one stone.</p>

<p>Now, a <em>move</em> consists of removing a stone&nbsp;that shares a column or row with another stone on the grid.</p>

<p>What is the largest possible number of moves we can make?</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>stones = <span id="example-input-1-2">[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]</span>
<strong>Output: </strong>5
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>stones = <span id="example-input-2-2">[[0,0],[0,2],[1,1],[2,0],[2,2]]</span>
<strong>Output: </strong>3
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>stones = <span id="example-input-3-2">[[0,0]]</span>
<strong>Output: </strong>0
</pre>

<p>&nbsp;</p>

<p><strong><span>Note:</span></strong></p>

<ol>
	<li><code>1 &lt;= stones.length &lt;= 1000</code></li>
	<li><code>0 &lt;= stones[i][j] &lt; 10000</code></li>
</ol>
</div>
</div>
</div>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Union Find](https://leetcode.com/tag/union-find/)

## Solution 1. DFS

Let's call stone `A` and `B` are neighbors if they are in the same row/column.

Define a **component** as a set of stones where each of them are neighbors and none of them is neighbor of stones outside of this set.

For each component, we can always remove the stones until there is just one left.

So we use DFS to visit the stones in the same component, and each component can contribute `conponentSize - 1` moves.

```cpp
// OJ: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
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

## Solution 2. Union Find

```cpp
// OJ: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class UnionFind {
private:
    vector<int> ids, ranks;
    int cnt;
    int find(int i) {
        if (ids[i] == i) return i;
        return ids[i] = find(ids[i]);
    }
public:
    UnionFind(int cnt) : cnt(cnt) {
        ids = vector<int>(cnt);
        ranks = vector<int>(cnt);
        for (int i = 0; i < cnt; ++i) ids[i] = i;
    }
    bool connected(int i, int j) {
        return find(i) == find(j);
    }
    void connect(int i, int j) {
        if (connected(i, j)) return;
        int a = find(i), b = find(j);
        int r1 = ranks[a], r2 = ranks[b];
        if (r1 > r2) ids[b] = a;
        else {
            ids[a] = b;
            if (r1 == r2) ranks[b]++;
        }
        --cnt;
    }
    int count() { return cnt; }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int N = stones.size();
        UnionFind uf(N);
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    uf.connect(i, j);
                }
            }
        }
        return stones.size() - uf.count();
    }
};
```