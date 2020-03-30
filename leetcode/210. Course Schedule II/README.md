# [210. Course Schedule II (Medium)](https://leetcode.com/problems/course-schedule-ii/)

<p>There are a total of <em>n</em> courses you have to take, labeled from <code>0</code> to <code>n-1</code>.</p>

<p>Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: <code>[0,1]</code></p>

<p>Given the total number of courses and a list of prerequisite <strong>pairs</strong>, return the ordering of courses you should take to finish all courses.</p>

<p>There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 2, [[1,0]] 
<strong>Output: </strong><code>[0,1]</code>
<strong>Explanation:</strong>&nbsp;There are a total of 2 courses to take. To take course 1 you should have finished   
&nbsp;            course 0. So the correct course order is <code>[0,1] .</code></pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 4, [[1,0],[2,0],[3,1],[3,2]]
<strong>Output: </strong><code>[0,1,2,3] or [0,2,1,3]</code>
<strong>Explanation:</strong>&nbsp;There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
&nbsp;            So one correct course order is <code>[0,1,2,3]</code>. Another correct ordering is <code>[0,2,1,3] .</code></pre>

<p><strong>Note:</strong></p>

<ol>
	<li>The input prerequisites is a graph represented by <strong>a list of edges</strong>, not adjacency matrices. Read more about <a href="https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs" target="_blank">how a graph is represented</a>.</li>
	<li>You may assume that there are no duplicate edges in the input prerequisites.</li>
</ol>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/)

**Similar Questions**:
* [Course Schedule (Medium)](https://leetcode.com/problems/course-schedule/)
* [Alien Dictionary (Hard)](https://leetcode.com/problems/alien-dictionary/)
* [Minimum Height Trees (Medium)](https://leetcode.com/problems/minimum-height-trees/)
* [Sequence Reconstruction (Medium)](https://leetcode.com/problems/sequence-reconstruction/)
* [Course Schedule III (Hard)](https://leetcode.com/problems/course-schedule-iii/)

## Solution 1. Topological Sort (BFS)

```cpp
// OJ: https://leetcode.com/problems/course-schedule-ii/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& E) {
        unordered_map<int, vector<int>> G;
        vector<int> indegree(N);
        for (auto &e : E) {
            G[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while (q.size()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int v : G[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return ans.size() == N ? ans : vector<int>{};
    }
};
```

## Solution 2. Topological Sort (DFS)

```cpp
// OJ: https://leetcode.com/problems/course-schedule-ii/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
    vector<int> ans;
    unordered_map<int, vector<int>> G;
    vector<int> seen;
    bool dfs(int u) {
        if (seen[u]) return seen[u] == 1;
        seen[u] = -1;
        for (int v : G[u]) {
            if (!dfs(v)) return false;
        }
        seen[u] = 1;
        ans.push_back(u);
        return true;
    }
public:
    vector<int> findOrder(int N, vector<vector<int>>& E) {
        seen.assign(N, 0);
        for (auto &e : E) G[e[1]].push_back(e[0]);
        for (int i = 0; i < N; ++i) {
            if (seen[i]) continue;
            if (!dfs(i)) return {};
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```