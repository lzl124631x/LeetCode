# [1615. Maximal Network Rank (Medium)](https://leetcode.com/problems/maximal-network-rank/)

<p>There is an infrastructure of <code>n</code> cities with some number of <code>roads</code> connecting these cities. Each <code>roads[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is a bidirectional road between cities <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code>.</p>

<p>The <strong>network rank</strong><em> </em>of <strong>two different cities</strong> is defined as the total number of&nbsp;<strong>directly</strong> connected roads to <strong>either</strong> city. If a road is directly connected to both cities, it is only counted <strong>once</strong>.</p>

<p>The <strong>maximal network rank </strong>of the infrastructure is the <strong>maximum network rank</strong> of all pairs of different cities.</p>

<p>Given the integer <code>n</code> and the array <code>roads</code>, return <em>the <strong>maximal network rank</strong> of the entire infrastructure</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/ex1.png" style="width: 292px; height: 172px;"></strong></p>

<pre><strong>Input:</strong> n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only counted once.
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/ex2.png" style="width: 292px; height: 172px;"></strong></p>

<pre><strong>Input:</strong> n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> There are 5 roads that are connected to cities 1 or 2.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The network rank of 2 and 5 is 5. Notice that all the cities do not have to be connected.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= roads.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>roads[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub>&nbsp;&lt;= n-1</code></li>
	<li><code>a<sub>i</sub>&nbsp;!=&nbsp;b<sub>i</sub></code></li>
	<li>Each&nbsp;pair of cities has <strong>at most one</strong> road connecting them.</li>
</ul>


**Related Topics**:  
[Graph](https://leetcode.com/tag/graph/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximal-network-rank/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& E) {
        vector<unordered_set<int>> G(n);
        for (auto &e : E) {
            G[e[0]].insert(e[1]);
            G[e[1]].insert(e[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, (int)(G[i].size() + G[j].size() - G[i].count(j)));
            }
        }
        return ans;
    }
};
```

## Solution 2. 

Let `deg[i]` be the degree of node `i`. For node `u` and `v`, the answer is `deg[u] + deg[v]` if they are not connected, and `deg[u] + dev[v] - 1` otherwise.

Let `first` be the greatest degree, `second` be the second greatest degree (`first` and `second` can be the same if there are multiple nodes with the largest degree). We just need to consider the cities with `first` and `second` degrees because:

* The result of selecting from such nodes is at least `first + second - 1` (when they are connected).
* If we select a city with degree `x < second`, then the result is at best `first + x < first + second`, i.e. `first + x <= first + second - 1`, which is no better than selecting from `first` and `second`

So, selecting from `first` and `second` must be optimal.

Let `x` be the number of cities with `first` degree. So there are ${x \choose 2 } = \frac{x(x-1)}{2}$ pairs among these cities. Let `m` be the number of roads.

* If `x = 1`, then we must pick a city from the cities with `second` degree. Enumerating such cities takes `O(n)` time.
* If `x > 1` and ${x\choose 2} > m$, then the roads don't cover all the possible connections between those `first` degree cities, so there must be a pair of `first` degree cities unconnected. Picking them results in `first * 2`.
* IF `x > 1` and ${x\choose 2} <= m$, then we don't need to consider `second` degree city because its result `first + second` must be no better than the result of picking two `first` degree cities, `first + first - 1`. We just need to enumerate all the city pairs among `first` degree cities, which takes `O(x * (x-1) / 2) = O(m)` time.

So overall this solution takes `O(n + m)` time.

```cpp
// OJ: https://leetcode.com/problems/maximal-network-rank/
// Author: github.com/lzl124631x
// Time: O(N + M)
// Space: O(N + M)
// Ref: https://leetcode-cn.com/problems/maximal-network-rank/solution/onm-mei-ju-fa-by-zerotrac2/
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& A) {
        if (A.empty()) return 0;
        vector<unordered_set<int>> G(n);
        vector<int> deg(n), firstNodes, secondNodes;
        for (auto &e : A) {
            int u = e[0], v = e[1];
            G[u].insert(v);
            G[v].insert(u);
            deg[u]++;
            deg[v]++;
        }
        int first = 0, second = 0, m = A.size();
        for (int d : deg) {
            if (d > first) {
                second = first;
                first = d;
            } else if (d > second) second = d;
        }
        for (int i = 0; i < n; ++i) {
            if (deg[i] == first) firstNodes.push_back(i);
            else if (deg[i] == second) secondNodes.push_back(i);
        }
        if (firstNodes.size() == 1) {
            int u = firstNodes[0];
            for (int v : secondNodes) {
                if (G[u].count(v) == 0) return first + second;
            }
            return first + second - 1;
        } else {
            if (firstNodes.size() * (firstNodes.size() - 1) / 2 > m) return first * 2;
            for (int i = 0; i < firstNodes.size(); ++i) {
                for (int j = i + 1; j < firstNodes.size(); ++j) {
                    if (G[firstNodes[i]].count(firstNodes[j]) == 0) return first * 2;
                }
            }
            return first * 2 - 1;
        }
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/maximal-network-rank/
// Author: github.com/lzl124631x
// Time: O(N + M)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximal-network-rank/discuss/889206/Java-2ms-O(m)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& E) {
        vector<int> deg(n);
        for (auto &e : E) {
            deg[e[0]]++;
            deg[e[1]]++;
        }
        int first = 0, second = 0, firstCnt = 0, secondCnt = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (deg[i] > first) {
                second = first;
                first = deg[i];
            } else if (deg[i] > second) second = deg[i];
        }
        for (int i = 0; i < n; ++i) {
            firstCnt += deg[i] == first;
            secondCnt += deg[i] == second;
        }
        if (firstCnt == 1) {
            for (auto &e : E) {
                int u = e[0], v = e[1];
                cnt += (deg[u] == first && deg[v] == second) || (deg[u] == second && deg[v] == first);
            }
            return first + second - (secondCnt <= cnt); // cnt is the number of edges connecting the single `first`-tier node and all `second`-tier nodes. If `secondCnt <= cnt`, all `second`-tier nodes are connected with the `first`-tier node, and we need to subtract the answer by 1.
        } else {
            for (auto &e : E) {
                int u = e[0], v = e[1];
                cnt += deg[u] == first && deg[v] == first;
            }
            return first * 2 - ((firstCnt - 1) * firstCnt / 2 == cnt); // cnt is the number of edges connecting `first`-tier nodes. Only when all the `first`-tier nodes are interconnected ((firstCnt - 1) * firstCnt / 2 == cnt), we need to subtract the answer by 1
        }
    }
};
```