# [886. Possible Bipartition (Medium)](https://leetcode.com/problems/possible-bipartition/)

<p>Given a set of <code>N</code>&nbsp;people (numbered <code>1, 2, ..., N</code>), we would like to split everyone into two groups of <strong>any</strong> size.</p>

<p>Each person may dislike some other people, and they should not go into the same group.&nbsp;</p>

<p>Formally, if <code>dislikes[i] = [a, b]</code>, it means it is not allowed to put the people numbered <code>a</code> and <code>b</code> into the same group.</p>

<p>Return <code>true</code>&nbsp;if and only if it is possible to split everyone into two groups in this way.</p>

<p>&nbsp;</p>

<div>
<div>
<ol>
</ol>
</div>
</div>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-1-1">4</span>, dislikes = <span id="example-input-1-2">[[1,2],[1,3],[2,4]]</span>
<strong>Output: </strong><span id="example-output-1">true</span>
<strong>Explanation</strong>: group1 [1,4], group2 [2,3]
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-2-1">3</span>, dislikes = <span id="example-input-2-2">[[1,2],[1,3],[2,3]]</span>
<strong>Output: </strong><span id="example-output-2">false</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-3-1">5</span>, dislikes = <span id="example-input-3-2">[[1,2],[2,3],[3,4],[4,5],[1,5]]</span>
<strong>Output: </strong><span id="example-output-3">false</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= N &lt;= 2000</code></li>
	<li><code>0 &lt;= dislikes.length &lt;= 10000</code></li>
	<li><code>1 &lt;= dislikes[i][j] &lt;= N</code></li>
	<li><code>dislikes[i][0] &lt; dislikes[i][1]</code></li>
	<li>There does not exist <code>i != j</code> for which <code>dislikes[i] == dislikes[j]</code>.</li>
</ol>
</div>
</div>
</div>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/possible-bipartition/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
    vector<unordered_set<int>> G;
    vector<int> id;
    bool dfs(int u, int prev = 1) {
        if (id[u]) return id[u] != prev;
        id[u] = -prev;
        for (int v : G[u]) {
            if (!dfs(v, id[u])) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& A) {
        G.assign(N + 1, {});
        id.assign(N + 1, 0);
        for (auto &v : A) {
            G[v[0]].insert(v[1]);
            G[v[1]].insert(v[0]);
        }
        for (int i = 1; i <= N; ++i) {
            if (id[i]) continue;
            if (!dfs(i)) return false;
        }
        return true;
    }
};
```

## Solution 2. BFS

```cpp
// OJ: https://leetcode.com/problems/possible-bipartition/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& A) {
        vector<vector<int>> G(N + 1);
        vector<int> id(N + 1, 0);
        for (auto &v : A) {
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
        }
        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (id[i]) continue;
            q.push(i);
            id[i] = 1;
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (int v : G[u]) {
                    if (id[v]) {
                        if (id[v] != -id[u]) return false;
                        else continue;
                    }
                    id[v] = -id[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
};
```