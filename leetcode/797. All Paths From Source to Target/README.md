# [797. All Paths From Source to Target (Medium)](https://leetcode.com/problems/all-paths-from-source-to-target/)

<p>Given a directed, acyclic graph of <code>N</code> nodes.&nbsp; Find all possible paths from node <code>0</code> to node <code>N-1</code>, and return them in any order.</p>

<p>The graph is given as follows:&nbsp; the nodes are 0, 1, ..., graph.length - 1.&nbsp; graph[i] is a list of all nodes j for which the edge (i, j) exists.</p>

<pre><strong>Example:</strong>
<strong>Input:</strong> [[1,2], [3], [3], []] 
<strong>Output:</strong> [[0,1,3],[0,2,3]] 
<strong>Explanation:</strong> The graph looks like this:
0---&gt;1
|    |
v    v
2---&gt;3
There are two paths: 0 -&gt; 1 -&gt; 3 and 0 -&gt; 2 -&gt; 3.
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li>The number of nodes in the graph will be in the range <code>[2, 15]</code>.</li>
	<li>You can print different paths in any order, but you should keep the order of nodes inside one path.</li>
</ul>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg), [Walmart Labs](https://leetcode.com/company/walmart-labs)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/all-paths-from-source-to-target/
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(N)
class Solution {
private:
    vector<vector<int>> ans;
    unordered_set<int> seen;
    vector<int> path;
    void dfs(vector<vector<int>>& graph, int from) {
        path.push_back(from);
        if (from == graph.size() - 1) ans.push_back(path);
        else {
            seen.insert(from);
            for (int n : graph[from]) {
                if (seen.find(n) != seen.end()) continue;
                dfs(graph, n);
            }
            seen.erase(from);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return ans;
    }
};
```