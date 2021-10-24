# [851. Loud and Rich (Medium)](https://leetcode.com/problems/loud-and-rich/)

<p>There is a group of <code>n</code> people labeled from <code>0</code> to <code>n - 1</code> where each person has a different amount of money and a different level of quietness.</p>

<p>You are given an array <code>richer</code> where <code>richer[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that <code>a<sub>i</sub></code> has more money than <code>b<sub>i</sub></code> and an integer array <code>quiet</code> where <code>quiet[i]</code> is the quietness of the <code>i<sup>th</sup></code> person. All the given data in richer are <strong>logically correct</strong> (i.e., the data will not lead you to a situation where <code>x</code> is richer than <code>y</code> and <code>y</code> is richer than <code>x</code> at the same time).</p>

<p>Return <em>an integer array </em><code>answer</code><em> where </em><code>answer[x] = y</code><em> if </em><code>y</code><em> is the least quiet person (that is, the person </em><code>y</code><em> with the smallest value of </em><code>quiet[y]</code><em>) among all people who definitely have equal to or more money than the person </em><code>x</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
<strong>Output:</strong> [5,5,2,5,4,5,6,7]
<strong>Explanation:</strong> 
answer[0] = 5.
Person 5 has more money than 3, which has more money than 1, which has more money than 0.
The only person who is quieter (has lower quiet[x]) is person 7, but it is not clear if they have more money than person 0.
answer[7] = 7.
Among all people that definitely have equal to or more money than person 7 (which could be persons 3, 4, 5, 6, or 7), the person who is the quietest (has lower quiet[x]) is person 7.
The other answers can be filled out with similar reasoning.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> richer = [], quiet = [0]
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == quiet.length</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>0 &lt;= quiet[i] &lt; n</code></li>
	<li>All the values of <code>quiet</code> are <strong>unique</strong>.</li>
	<li><code>0 &lt;= richer.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i </sub>!= b<sub>i</sub></code></li>
	<li>All the pairs of <code>richer</code> are <strong>unique</strong>.</li>
	<li>The observations in <code>richer</code> are all logically consistent.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/)

## Solution 1. Topological Sort (BFS)

```cpp
// OJ: https://leetcode.com/problems/loud-and-rich/
// Author: github.com/lzl124631x
// Time: O(N + E)
// Space: O(N + E)
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& R, vector<int>& Q) {
        int N = Q.size();
        vector<vector<int>> G(N);
        vector<int> indegree(N);
        for (auto &r : R) {
            int u = r[0], v = r[1];
            G[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<int> ans(N), minQuite(N, INT_MAX);
        for (int i = 0; i < N; ++i) {
            minQuite[i] = Q[i];
            ans[i] = i;
            if (indegree[i] == 0) q.push(i);
        }
        while (q.size()) {
            auto u = q.front();
            q.pop();
            for (int v : G[u]) {
                if (minQuite[u] < minQuite[v]) {
                    ans[v] = ans[u];
                    minQuite[v] = minQuite[u];
                }
                if (--indegree[v]) continue;
                q.push(v);
            }
        }
        return ans;
    }
};
```

## Solution 2. Topological Sort (Post-order DFS)

```cpp
// OJ: https://leetcode.com/problems/loud-and-rich/
// Author: github.com/lzl124631x
// Time: O(N + E)
// Space: O(N + E)
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& R, vector<int>& Q) {
        int N = Q.size();
        vector<vector<int>> G(N);
        vector<int> ans(N, -1);
        for (auto &r : R) G[r[1]].push_back(r[0]);
        function<int(int)> dfs = [&](int u) {
            if (ans[u] != -1) return ans[u];
            ans[u] = u;
            for (int v : G[u]) {
                int minNode = dfs(v);
                if (Q[minNode] < Q[ans[u]]) ans[u] = minNode;
            }
            return ans[u];
        };
        for (int i = 0; i < N; ++i) dfs(i);
        return ans;
    }
};
```