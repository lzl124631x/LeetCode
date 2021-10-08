# [749. Contain Virus (Hard)](https://leetcode.com/problems/contain-virus/)

<p>A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.</p>

<p>The world is modeled as an <code>m x n</code> binary grid <code>isInfected</code>, where <code>isInfected[i][j] == 0</code> represents uninfected cells, and <code>isInfected[i][j] == 1</code> represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two <strong>4-directionally</strong> adjacent cells, on the shared boundary.</p>

<p>Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region (i.e., the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night). There <strong>will never be a tie</strong>.</p>

<p>Return <em>the number of walls used to quarantine all the infected regions</em>. If the world will become fully infected, return the number of walls used.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/01/virus11-grid.jpg" style="width: 500px; height: 255px;">
<pre><strong>Input:</strong> isInfected = [[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]
<strong>Output:</strong> 10
<strong>Explanation:</strong> There are 2 contaminated regions.
On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/01/virus12edited-grid.jpg" style="width: 500px; height: 257px;">
On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/01/virus13edited-grid.jpg" style="width: 500px; height: 261px;">
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/01/virus2-grid.jpg" style="width: 653px; height: 253px;">
<pre><strong>Input:</strong> isInfected = [[1,1,1],[1,0,1],[1,1,1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Even though there is only one cell saved, there are 4 walls built.
Notice that walls are only built on the shared boundary of two different cells.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> isInfected = [[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],[1,1,1,0,0,0,0,0,0]]
<strong>Output:</strong> 13
<strong>Explanation:</strong> The region on the left only builds two new walls.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m ==&nbsp;isInfected.length</code></li>
	<li><code>n ==&nbsp;isInfected[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>isInfected[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
	<li>There is always a contiguous viral region throughout the described process that will <strong>infect strictly more uncontaminated squares</strong> in the next round.</li>
</ul>


**Companies**:  
[Accolite](https://leetcode.com/company/accolite), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Matrix](https://leetcode.com/tag/matrix/), [Simulation](https://leetcode.com/tag/simulation/)

## Solution 1. Union Find

1. Enumerate the components, find the one with the greatest infection
1. Compute the edge count of this component, and mark this component as locked.
1. Apply the infection of other components. Components might merge together.
1. Repeat until there is nothing to infect or all the components are locked.

```cpp
// OJ: https://leetcode.com/problems/contain-virus/
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        id[find(a)] = find(b);
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
class Solution {
public:
    int containVirus(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}, ans = 0;
        auto getKey = [&](int x, int y) { return x * N + y; };
        UnionFind uf(M * N);
        auto getState = [&](int x, int y) {
            int k = uf.find(getKey(x, y));
            return A[k / N][k % N];
        };
        while (true) {
            vector<int> cnt(M * N); // count of new infection
            for (int i = 0; i < M; ++i) { // connect infected components
                for (int j = 0; j < N; ++j) {
                    if (A[i][j] != 1) continue;
                    for (auto &[dx, dy] : dirs) {
                        int x = i + dx, y = j + dy;
                        if (x < 0 || x >= M || y < 0 || y >= N || A[x][y] != 1) continue;
                        uf.connect(getKey(i, j), getKey(x, y));
                    }
                }
            }
            for (int i = 0; i < M; ++i) { // get the greatest infection region
                for (int j = 0; j < N; ++j) {
                    if (getState(i, j) != 0) continue; // for each uninfected cell, check which infected regions can infect it.
                    vector<int> infect;
                    for (auto &[dx, dy] : dirs) {
                        int x = i + dx, y = j + dy;
                        if (x < 0 || x >= M || y < 0 || y >= N || A[x][y] != 1) continue;
                        infect.push_back(uf.find(getKey(x, y)));
                    }
                    sort(begin(infect), end(infect));
                    infect.erase(unique(begin(infect), end(infect)), end(infect));
                    for (int k : infect) cnt[k]++;
                }
            }
            int maxInfect = -1;
            for (int i = 0; i < M * N; ++i) {
                int x = i / N, y = i % N;
                if (A[x][y] == 1 && (maxInfect == -1 || cnt[uf.find(i)] > cnt[maxInfect])) maxInfect = uf.find(i); 
            }
            if (maxInfect == -1) break;
            for (int i = 0; i < M; ++i) { // build walls
                for (int j = 0; j < N; ++j) {
                    if (uf.find(getKey(i, j)) != maxInfect) continue; // Only visit the cells in the maxInfect region
                    A[i][j] = 2; // lock this region
                    for (auto &[dx, dy] : dirs) {
                        int x = i + dx, y = j + dy;
                        if (x < 0 || x >= M || y < 0 || y >= N || A[x][y] != 0) continue;
                        ++ans;
                    }
                }
            }
            for (int i = 0; i < M; ++i) { // infect new regions
                for (int j = 0; j < N; ++j) {
                    if (A[i][j] != 0) continue; // For each uninfected cells, test if it should be infected.
                    for (auto &[dx, dy] : dirs) {
                        int x = i + dx, y = j + dy;
                        if (x < 0 || x >= M || y < 0 || y >= N || A[x][y] != 1) continue;
                        uf.connect(getKey(i, j), getKey(x, y)); // connect this uninfected region with the infected region
                    }
                }
            }
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (A[i][j] == 0 && getState(i, j) == 1) A[i][j] = 1; // If this cell itself is not infected, but it should be, mark it as infected
                }
            }
        }
        return ans;
    }
};
```