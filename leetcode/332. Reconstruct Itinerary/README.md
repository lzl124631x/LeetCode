# [332. Reconstruct Itinerary (Hard)](https://leetcode.com/problems/reconstruct-itinerary/)

<p>You are given a list of airline <code>tickets</code> where <code>tickets[i] = [from<sub>i</sub>, to<sub>i</sub>]</code> represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.</p>

<p>All of the tickets belong to a man who departs from <code>"JFK"</code>, thus, the itinerary must begin with <code>"JFK"</code>. If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.</p>

<ul>
	<li>For example, the itinerary <code>["JFK", "LGA"]</code> has a smaller lexical order than <code>["JFK", "LGB"]</code>.</li>
</ul>

<p>You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/itinerary1-graph.jpg" style="width: 382px; height: 222px;">
<pre><strong>Input:</strong> tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
<strong>Output:</strong> ["JFK","MUC","LHR","SFO","SJC"]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/itinerary2-graph.jpg" style="width: 222px; height: 230px;">
<pre><strong>Input:</strong> tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
<strong>Output:</strong> ["JFK","ATL","JFK","SFO","ATL","SFO"]
<strong>Explanation:</strong> Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= tickets.length &lt;= 300</code></li>
	<li><code>tickets[i].length == 2</code></li>
	<li><code>from<sub>i</sub>.length == 3</code></li>
	<li><code>to<sub>i</sub>.length == 3</code></li>
	<li><code>from<sub>i</sub></code> and <code>to<sub>i</sub></code> consist of uppercase English letters.</li>
	<li><code>from<sub>i</sub> != to<sub>i</sub></code></li>
</ul>


**Companies**:  
[Media.net](https://leetcode.com/company/medianet), [Facebook](https://leetcode.com/company/facebook), [Uber](https://leetcode.com/company/uber), [Directi](https://leetcode.com/company/directi), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Twilio](https://leetcode.com/company/twilio), [DoorDash](https://leetcode.com/company/doordash), [Walmart Labs](https://leetcode.com/company/walmart-labs)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Eulerian Circuit](https://leetcode.com/tag/eulerian-circuit/)

**Similar Questions**:
* [Longest Common Subpath (Hard)](https://leetcode.com/problems/longest-common-subpath/)
* [Valid Arrangement of Pairs (Hard)](https://leetcode.com/problems/valid-arrangement-of-pairs/)

## Solution 1. DFS

For each node, try each neighbor node in ascending lexical order. The first path that reaches `N + 1` nodes is the answer.

```cpp
// OJ: https://leetcode.com/problems/reconstruct-itinerary/
// Author: github.com/lzl124631x
// Time: O(E^2)
// Space: O(E)
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& E) {
        int N = E.size();
        vector<bool> used(N);
        unordered_map<string, vector<pair<string, int>>> G;
        for (int i = 0; i < E.size(); ++i) G[E[i][0]].emplace_back(E[i][1], i);
        for (auto &[u, vs] : G) sort(begin(vs), end(vs));
        vector<string> path{"JFK"};
        function<bool()> dfs = [&]() {
            if (path.size() == N + 1) return true;
            for (auto &[v, index] : G[path.back()]) {
                if (used[index]) continue;
                used[index] = true;
                path.push_back(v);
                if (dfs()) return true;
                path.pop_back();
                used[index] = false;
            }
            return false;
        };
        dfs();
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
public:
    vector<string> findItinerary(vector<vector<string>>& E) {
        unordered_map<string, multiset<string>> G;
        for (auto &e : E) G[e[0]].insert(e[1]);
        vector<string> ans;
        function<void(string)> euler = [&](string u) {
            while (G[u].size()) {
                auto v = *G[u].begin();
                G[u].erase(G[u].begin());
                euler(v);
            }
            ans.push_back(u);
        };
        euler("JFK");
        return vector<string>(rbegin(ans), rend(ans));
    }
};
```