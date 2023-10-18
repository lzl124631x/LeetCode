# [1361. Validate Binary Tree Nodes (Medium)](https://leetcode.com/problems/validate-binary-tree-nodes)

<p>You have <code>n</code> binary tree nodes numbered from <code>0</code> to <code>n - 1</code> where node <code>i</code> has two children <code>leftChild[i]</code> and <code>rightChild[i]</code>, return <code>true</code> if and only if <strong>all</strong> the given nodes form <strong>exactly one</strong> valid binary tree.</p>

<p>If node <code>i</code> has no left child then <code>leftChild[i]</code> will equal <code>-1</code>, similarly for the right child.</p>

<p>Note that the nodes have no values and that we only use the node numbers in this problem.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/23/1503_ex1.png" style="width: 195px; height: 287px;" />
<pre>
<strong>Input:</strong> n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/23/1503_ex2.png" style="width: 183px; height: 272px;" />
<pre>
<strong>Input:</strong> n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
<strong>Output:</strong> false
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/23/1503_ex3.png" style="width: 82px; height: 174px;" />
<pre>
<strong>Input:</strong> n = 2, leftChild = [1,0], rightChild = [-1,-1]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == leftChild.length == rightChild.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>-1 &lt;= leftChild[i], rightChild[i] &lt;= n - 1</code></li>
</ul>


**Companies**:
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree), [Depth-First Search](https://leetcode.com/tag/depth-first-search), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search), [Union Find](https://leetcode.com/tag/union-find), [Graph](https://leetcode.com/tag/graph), [Binary Tree](https://leetcode.com/tag/binary-tree)

**Hints**:
* Find the parent of each node.
* A valid tree must have nodes with only one parent and exactly one node with no parent.

## NOTE

* A node at most have a single parent
* There is exactly one node without parent -- the root node
* There is no cycle in the graph
* We can visit all the nodes from a random node.

## Solution 1. Count Degree and BFS Topological Sort

```cpp
// OJ: https://leetcode.com/problems/validate-binary-tree-nodes/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> degree(n), parent(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int ch : { leftChild[i], rightChild[i] }) {
                if (ch == -1) continue;
                if (parent[ch] != -1) return false; // A node at most have a single parent
                ++degree[ch];
                ++degree[i];
                parent[ch] = i;
            }
        }
        // Must have exactly one root
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                if (root != -1) return false;
                root = i;
            }
        }
        if (root == -1) return false;
        // BFS Topological Sort to check cycle.
        queue<int> q;
        unordered_set<int> seen;
        for (int i = 0; i < n; ++i) {
            if (degree[i] <= 1) {
                seen.insert(i);
                q.push(i);
            }
        }
        while (q.size()) {
            int u = q.front(), p = parent[u];
            q.pop();
            if (p != -1 && seen.count(p) == 0 && --degree[p] <= 1) {
                seen.insert(p);
                q.push(p);
            }
        }
        return seen.size() == n;
    }
};
```

## Solution 2. Count Degree and DFS

```cpp
// OJ: https://leetcode.com/problems/validate-binary-tree-nodes
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> degree(n), parent(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int ch : { leftChild[i], rightChild[i] }) {
                if (ch == -1) continue;
                if (parent[ch] != -1) return false; // A node at most have a single parent
                ++degree[ch];
                ++degree[i];
                parent[ch] = i;
            }
        }
        // Must have exactly one root
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                if (root != -1) return false;
                root = i;
            }
        }
        if (root == -1) return false;
        // DFS to check cycle
        unordered_set<int> seen;
        function<bool(int)> dfs = [&](int u) {
            if (u == -1) return true;
            if (seen.count(u)) return false;
            seen.insert(u);
            return dfs(leftChild[u]) && dfs(rightChild[u]);
        };
        return dfs(root) && seen.size() == n;
    }
};
```

## Solution 3. Find Root and DFS

```cpp
// OJ: https://leetcode.com/problems/validate-binary-tree-nodes
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        auto findRoot = [&]() {
            unordered_set<int> s;
            s.insert(leftChild.begin(), leftChild.end());
            s.insert(rightChild.begin(), rightChild.end());
            for (int i = 0; i < n; ++i) {
                if (s.count(i) == 0) return i;
            }
            return -1;
        };
        int root = findRoot();
        if (root == -1) return false;
        unordered_set<int> seen;
        function<bool(int)> dfs = [&](int u) {
            if (u == -1) return true;
            if (seen.count(u)) return false;
            seen.insert(u);
            return dfs(leftChild[u]) && dfs(rightChild[u]);
        };
        return dfs(root) && seen.size() == n;
    }
};
```

## Solution 4. Find Root and BFS

```cpp
// OJ: https://leetcode.com/problems/validate-binary-tree-nodes
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        auto findRoot = [&]() {
            unordered_set<int> s;
            s.insert(leftChild.begin(), leftChild.end());
            s.insert(rightChild.begin(), rightChild.end());
            for (int i = 0; i < n; ++i) {
                if (s.count(i) == 0) return i;
            }
            return -1;
        };
        int root = findRoot();
        if (root == -1) return false;
        unordered_set<int> seen{{root}};
        queue<int> q{{root}};
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int ch : { leftChild[u], rightChild[u] }) {
                if (ch == -1) continue;
                if (seen.count(ch)) return false;
                q.push(ch);
                seen.insert(ch);
            }
        }
        return seen.size() == n;
    }
};
```

## Solution 5. Union Find

```cpp
// OJ: https://leetcode.com/problems/validate-binary-tree-nodes
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class UnionFind {
    vector<int> id;
    int cnt;
public:
    UnionFind(int n) : id(n), cnt(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) { return id[a] == a ? a : (id[a] = find(id[a])); }
    bool connect(int parent, int child) {
        int pp = find(parent), cp = find(child);
        if (pp == cp || cp != child) return false; // Return false if 1) parent and child are already connected, or 2) child already has a parent
        id[cp] = pp;
        --cnt;
        return true;
    }
    int getCount() { return cnt; }
};
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        UnionFind uf(n);
        for (int p = 0; p < n; ++p) {
            for (int ch : { leftChild[p], rightChild[p] }) {
                if (ch == -1) continue;
                if (!uf.connect(p, ch)) return false;
            }
        }
        return uf.getCount() == 1;
    }
};
```