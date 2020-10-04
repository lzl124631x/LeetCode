# [1203. Sort Items by Groups Respecting Dependencies (Hard)](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/)

<p>There are&nbsp;<code>n</code>&nbsp;items each&nbsp;belonging to zero or one of&nbsp;<code>m</code>&nbsp;groups where <code>group[i]</code>&nbsp;is the group that the <code>i</code>-th item belongs to and it's equal to <code>-1</code>&nbsp;if the <code>i</code>-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.</p>

<p>Return a sorted list of the items such that:</p>

<ul>
	<li>The items that belong to the same group are next to each other in the sorted list.</li>
	<li>There are some&nbsp;relations&nbsp;between these items where&nbsp;<code>beforeItems[i]</code>&nbsp;is a list containing all the items that should come before the&nbsp;<code>i</code>-th item in the sorted array (to the left of the&nbsp;<code>i</code>-th item).</li>
</ul>

<p>Return any solution if there is more than one solution and return an <strong>empty list</strong>&nbsp;if there is no solution.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/09/11/1359_ex1.png" style="width: 191px; height: 181px;"></strong></p>

<pre><strong>Input:</strong> n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
<strong>Output:</strong> [6,3,4,1,5,2,0,7]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
<strong>Output:</strong> []
<strong>Explanation:</strong>&nbsp;This is the same as example 1 except that 4 needs to be before 6 in the sorted list.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m &lt;= n &lt;= 3*10^4</code></li>
	<li><code>group.length == beforeItems.length == n</code></li>
	<li><code>-1 &lt;= group[i] &lt;= m-1</code></li>
	<li><code>0 &lt;= beforeItems[i].length &lt;= n-1</code></li>
	<li><code>0 &lt;= beforeItems[i][j] &lt;= n-1</code></li>
	<li><code>i != beforeItems[i][j]</code></li>
	<li><code>beforeItems[i]&nbsp;</code>does not contain&nbsp;duplicates elements.</li>
</ul>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/)

## Solution 1. Topological Sort

```cpp
// OJ: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
// Author: github.com/lzl124631x
// Time: O(M + N + E)
// Space: O(M + N + E)
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int, vector<int>> itemGraph; // adjacency list of items. Edges between groups are considered in groupGraph so ignored here.
        unordered_map<int, vector<int>> groupGraph; // adjacency list of groups.
        vector<int> itemIndegree(n); // in-degree of each item
        unordered_map<int, int> groupIndegree; // in-degree of each group
        unordered_map<int, vector<int>> itemInGroup; // map from group id to items in the group
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) group[i] = i + m; // make items without group to be in group `i + m` so that we can treat all the items the same
            itemInGroup[group[i]].push_back(i);
        }
        for (int i = 0; i < beforeItems.size(); ++i) {
            for (int j = 0; j < beforeItems[i].size(); ++j) {
                int from = beforeItems[i][j], to = i, fromGroup = group[from], toGroup = group[to];
                if (fromGroup == toGroup) { // If the edge is in the same group, update itemGraph and itemIndegree
                    itemGraph[from].push_back(to);
                    itemIndegree[to]++;
                } else { // If the edge is cross groups, update groupGraph and groupIndegree
                    groupGraph[fromGroup].push_back(toGroup);
                    groupIndegree[toGroup]++;
                }
            }
        }
        queue<int> groupQueue;
        for (auto &p : itemInGroup) { // Get the initial set of groups without indegree
            if (groupIndegree[p.first] == 0) groupQueue.push(p.first);
        }
        vector<int> ans;
        while (groupQueue.size()) {
            int gid = groupQueue.front();
            groupQueue.pop();
            queue<int> itemQueue; // do topological sort within the same group
            int itemCnt = 0;
            for (int u : itemInGroup[gid]) {
                if (itemIndegree[u] == 0) itemQueue.push(u);
            }
            while (itemQueue.size()) {
                int itemId = itemQueue.front();
                itemQueue.pop();
                ans.push_back(itemId);
                ++itemCnt;
                for (int v : itemGraph[itemId]) {
                    if (--itemIndegree[v] == 0) itemQueue.push(v);
                }
            }
            if (itemCnt != itemInGroup[gid].size()) return {}; // has circle within group, return empty list
            for (int v : groupGraph[gid]) {
                if (--groupIndegree[v] == 0) groupQueue.push(v);
            }
        }
        if (ans.size() != n) return {}; // has circle between group, return empty list
        return ans;
    }
};
```

## Solution 2. Topological Sort

```cpp
// OJ: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
// Author: github.com/lzl124631x
// Time: O(M + N + E)
// Space: O(M + N + E)
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int, vector<int>> groupGraph, groupItems;
        unordered_map<int, int> groupIndegree;
        vector<int> groupOrder, ans;
        for (int i = 0; i < n; ++i) {
            int a = group[i] == -1 ? m + i : group[i];// For those items belonging to no group, let the groupId be `m + i`.
            if (a < m) groupItems[group[i]].push_back(i);
            if (groupGraph.count(a) == 0) groupGraph[a] = {};
            for (int j : beforeItems[i]) {
                int b = group[j] == -1 ? m + j : group[j];
                if (a == b) continue; // skip intra dependency
                groupGraph[b].push_back(a);
                groupIndegree[a]++;
            }
        }
        queue<int> q;
        for (auto &[g, _] : groupGraph) {
            if (groupIndegree[g] == 0) q.push(g); 
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            groupOrder.push_back(u);
            for (int v : groupGraph[u]) {
                if (--groupIndegree[v] == 0) q.push(v);
            }
        }
        if (groupOrder.size() != groupGraph.size()) return {};
        for (int g : groupOrder) {
            if (g >= m) {
                ans.push_back(g - m);
                continue;
            }
            unordered_map<int, vector<int>> itemGraph;
            unordered_map<int, int> itemIndegree;
            for (int u : groupItems[g]) {
                for (int v : beforeItems[u]) {
                    if (group[v] != g) continue;
                    itemGraph[v].push_back(u);
                    itemIndegree[u]++;
                }
            }
            for (int u : groupItems[g]) {
                if (itemIndegree[u] == 0) q.push(u);
            }
            int cnt = 0;
            while (q.size()) {
                int u = q.front();
                q.pop();
                ans.push_back(u);
                ++cnt;
                for (int v : itemGraph[u]) {
                    if (--itemIndegree[v] == 0) q.push(v);
                }
            }
            if (cnt != groupItems[g].size()) return {};
        }
        return ans;
    }
};
```