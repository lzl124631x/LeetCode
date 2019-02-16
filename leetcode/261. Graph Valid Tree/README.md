# [261. Graph Valid Tree (Medium)](https://leetcode.com/problems/graph-valid-tree/)

<p>Given <code>n</code> nodes labeled from <code>0</code> to <code>n-1</code> and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> <code>n = 5</code>, and <code>edges = [[0,1], [0,2], [0,3], [1,4]]</code>
<strong>Output:</strong> true</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> <code>n = 5, </code>and <code>edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]</code>
<strong>Output:</strong> false</pre>

<p><b>Note</b>: you can assume that no duplicate edges will appear in <code>edges</code>. Since all edges are undirected, <code>[0,1]</code> is the same as <code>[1,0]</code> and thus will not appear together in <code>edges</code>.</p>


**Companies**:  
[Google](https://leetcode.com/company/google), [LinkedIn](https://leetcode.com/company/linkedin)

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Course Schedule (Medium)](https://leetcode.com/problems/course-schedule/)
* [Number of Connected Components in an Undirected Graph (Medium)](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/graph-valid-tree/
// Author: github.com/lzl124631x
// Time: O(E)
// Space: O(N)
class UnionFind {
private:
    vector<int> rank;
    vector<int> id;
    int count;
    int find (int i) {
        if (id[i] == i) return i;
        return id[i] = find(id[i]);
    }
public:
    UnionFind(int n) : rank(n, 0), id(n), count(n) {
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
        --count;
    }
    int getCount() { return count; }
};
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1) return false;
        UnionFind uf(n);
        for (auto &e : edges) uf.connect(e.first, e.second);
        return uf.getCount() == 1;
    }
};
```