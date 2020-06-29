# [332. Reconstruct Itinerary (Medium)](https://leetcode.com/problems/reconstruct-itinerary/)

<p>Given a list of airline tickets represented by pairs of departure and arrival airports <code>[from, to]</code>, reconstruct the itinerary in order. All of the tickets belong to a man who departs from <code>JFK</code>. Thus, the itinerary must begin with <code>JFK</code>.</p>

<p><b>Note:</b></p>

<ol>
	<li>If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary <code>["JFK", "LGA"]</code> has a smaller lexical order than <code>["JFK", "LGB"]</code>.</li>
	<li>All airports are represented by three capital letters (IATA code).</li>
	<li>You may assume all tickets form at least one valid itinerary.</li>
	<li>One must use all the tickets once and only once.</li>
</ol>

<p><b>Example 1:</b></p>

<pre><code><strong>Input: </strong></code><code>[["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]</code>
<strong>Output: </strong><code>["JFK", "MUC", "LHR", "SFO", "SJC"]</code>
</pre>

<p><b>Example 2:</b></p>

<pre><code><strong>Input: </strong></code><code>[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]</code>
<strong>Output: </strong><code>["JFK","ATL","JFK","SFO","ATL","SFO"]</code>
<strong>Explanation: </strong>Another possible reconstruction is <code>["JFK","SFO","ATL","JFK","ATL","SFO"]</code>.
&nbsp;            But it is larger in lexical order.
</pre>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1. DFS

For each node, try each neighbor node in ascending lexical order. The first path that reaches `N + 1` nodes is the answer.

```cpp
// OJ: https://leetcode.com/problems/reconstruct-itinerary/
// Author: github.com/lzl124631x
// Time: O(E^2)
// Space: O(E)
class Solution {
    vector<bool> used;
    int N;
    unordered_map<string, vector<pair<string, int>>> G;
    bool dfs(vector<string> &path) {
        if (path.size() == N + 1) return true;
        for (auto &p : G[path.back()]) {
            if (used[p.second]) continue;
            used[p.second] = true;
            path.push_back(p.first);
            if (dfs(path)) return true;
            path.pop_back();
            used[p.second] = false;
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& E) {
        N = E.size();
        used.assign(N, false);
        for (int i = 0; i < E.size(); ++i) G[E[i][0]].emplace_back(E[i][1], i);
        for (auto &p : G) sort(begin(p.second), end(p.second));
        vector<string> path{"JFK"};
        dfs(path);
        return path;
    }
};
```

## Solution 2. Eulerian Path

```cpp
// OJ: https://leetcode.com/problems/reconstruct-itinerary/
// Author: github.com/lzl124631x
// Time: O(E^2)
// Space: O(E)
// Ref: https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C%2B%2B
class Solution {
    unordered_map<string, multiset<string>> G;
    vector<string> path;
    void visit(string u) {
        while (G[u].size()) {
            auto v = *G[u].begin();
            G[u].erase(G[u].begin());
            visit(v);
        }
        path.push_back(u);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& E) {
        for (auto &e : E) G[e[0]].insert(e[1]);
        visit("JFK");
        return vector<string>(path.rbegin(), path.rend());
    }
};
```