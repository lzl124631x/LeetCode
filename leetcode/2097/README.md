# [2097. Valid Arrangement of Pairs (Hard)](https://leetcode.com/problems/valid-arrangement-of-pairs/)

<p>You are given a <strong>0-indexed</strong> 2D integer array <code>pairs</code> where <code>pairs[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>. An arrangement of <code>pairs</code> is <strong>valid</strong> if for every index <code>i</code> where <code>1 &lt;= i &lt; pairs.length</code>, we have <code>end<sub>i-1</sub> == start<sub>i</sub></code>.</p>

<p>Return <em><strong>any</strong> valid arrangement of </em><code>pairs</code>.</p>

<p><strong>Note:</strong> The inputs will be generated such that there exists a valid arrangement of <code>pairs</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> pairs = [[5,1],[4,5],[11,9],[9,4]]
<strong>Output:</strong> [[11,9],[9,4],[4,5],[5,1]]
<strong>Explanation:
</strong>This is a valid arrangement since end<sub>i-1</sub> always equals start<sub>i</sub>.
end<sub>0</sub> = 9 == 9 = start<sub>1</sub> 
end<sub>1</sub> = 4 == 4 = start<sub>2</sub>
end<sub>2</sub> = 5 == 5 = start<sub>3</sub>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> pairs = [[1,3],[3,2],[2,1]]
<strong>Output:</strong> [[1,3],[3,2],[2,1]]
<strong>Explanation:</strong>
This is a valid arrangement since end<sub>i-1</sub> always equals start<sub>i</sub>.
end<sub>0</sub> = 3 == 3 = start<sub>1</sub>
end<sub>1</sub> = 2 == 2 = start<sub>2</sub>
The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also valid.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> pairs = [[1,2],[1,3],[2,1]]
<strong>Output:</strong> [[1,2],[2,1],[1,3]]
<strong>Explanation:</strong>
This is a valid arrangement since end<sub>i-1</sub> always equals start<sub>i</sub>.
end<sub>0</sub> = 2 == 2 = start<sub>1</sub>
end<sub>1</sub> = 1 == 1 = start<sub>2</sub>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pairs.length &lt;= 10<sup>5</sup></code></li>
	<li><code>pairs[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub>, end<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>start<sub>i</sub> != end<sub>i</sub></code></li>
	<li>No two pairs are exactly the same.</li>
	<li>There <strong>exists</strong> a valid arrangement of <code>pairs</code>.</li>
</ul>


**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Eulerian Circuit](https://leetcode.com/tag/eulerian-circuit/)

**Similar Questions**:
* [Reconstruct Itinerary (Hard)](https://leetcode.com/problems/reconstruct-itinerary/)
* [Find if Path Exists in Graph (Easy)](https://leetcode.com/problems/find-if-path-exists-in-graph/)

## Solution 1. Eulerian Circuit

```cpp
// OJ: https://leetcode.com/problems/valid-arrangement-of-pairs/
// Author: github.com/lzl124631x
// Time: O(N + U) where N is the number of pairs and U is the number of unique numbers in the pairs
// Space: O(N + U)
// Ref: https://leetcode.com/problems/valid-arrangement-of-pairs/discuss/1611978/C%2B%2B-Eulerian-Path-with-Explanation
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& E) {
        int N = E.size();
        unordered_map<int, vector<int>> G;
        unordered_map<int, int> indegree, outdegree;
        G.reserve(N);
        indegree.reserve(N);
        outdegree.reserve(N);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            outdegree[u]++;
            indegree[v]++;
            G[u].push_back(v);
        }
        int start = -1;
        for (auto &[u, vs] : G) {
            if (outdegree[u] - indegree[u] == 1) {
                start = u; // If there exists one node `u` that `outdegree[u] = indegree[u] + 1`, use `u` as the start node.
                break;
            }
        }
        if (start == -1) start = G.begin()->first; // If there doesn't exist such node `u`, use any node as the start node
        vector<vector<int>> ans;
        function<void(int)> euler = [&](int u) {
            auto &vs = G[u];
            while (vs.size()) {
                int v = vs.back();
                vs.pop_back();
                euler(v);
                ans.push_back({ u, v }); // Post-order DFS. The edge is added after node `v` is exhausted
            }
        };
        euler(start);
        reverse(begin(ans), end(ans)); // Need to reverse the answer array in the end.
        return ans;
    }
};
```