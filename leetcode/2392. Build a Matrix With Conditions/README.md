# [2392. Build a Matrix With Conditions (Hard)](https://leetcode.com/problems/build-a-matrix-with-conditions)

<p>You are given a <strong>positive</strong> integer <code>k</code>. You are also given:</p>
<ul>
	<li>a 2D integer array <code>rowConditions</code> of size <code>n</code> where <code>rowConditions[i] = [above<sub>i</sub>, below<sub>i</sub>]</code>, and</li>
	<li>a 2D integer array <code>colConditions</code> of size <code>m</code> where <code>colConditions[i] = [left<sub>i</sub>, right<sub>i</sub>]</code>.</li>
</ul>
<p>The two arrays contain integers from <code>1</code> to <code>k</code>.</p>
<p>You have to build a <code>k x k</code> matrix that contains each of the numbers from <code>1</code> to <code>k</code> <strong>exactly once</strong>. The remaining cells should have the value <code>0</code>.</p>
<p>The matrix should also satisfy the following conditions:</p>
<ul>
	<li>The number <code>above<sub>i</sub></code> should appear in a <strong>row</strong> that is strictly <strong>above</strong> the row at which the number <code>below<sub>i</sub></code> appears for all <code>i</code> from <code>0</code> to <code>n - 1</code>.</li>
	<li>The number <code>left<sub>i</sub></code> should appear in a <strong>column</strong> that is strictly <strong>left</strong> of the column at which the number <code>right<sub>i</sub></code> appears for all <code>i</code> from <code>0</code> to <code>m - 1</code>.</li>
</ul>
<p>Return <em><strong>any</strong> matrix that satisfies the conditions</em>. If no answer exists, return an empty matrix.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/07/06/gridosdrawio.png" style="width: 211px; height: 211px;">
<pre><strong>Input:</strong> k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
<strong>Output:</strong> [[3,0,0],[0,0,1],[0,2,0]]
<strong>Explanation:</strong> The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row <u>1</u>, and number 2 is in row <u>2</u>, so 1 is above 2 in the matrix.
- Number 3 is in row <u>0</u>, and number 2 is in row <u>2</u>, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column <u>1</u>, and number 1 is in column <u>2</u>, so 2 is left of 1 in the matrix.
- Number 3 is in column <u>0</u>, and number 2 is in column <u>1</u>, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
<strong>Output:</strong> []
<strong>Explanation:</strong> From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
No matrix can satisfy all the conditions, so we return the empty matrix.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= k &lt;= 400</code></li>
	<li><code>1 &lt;= rowConditions.length, colConditions.length &lt;= 10<sup>4</sup></code></li>
	<li><code>rowConditions[i].length == colConditions[i].length == 2</code></li>
	<li><code>1 &lt;= above<sub>i</sub>, below<sub>i</sub>, left<sub>i</sub>, right<sub>i</sub> &lt;= k</code></li>
	<li><code>above<sub>i</sub> != below<sub>i</sub></code></li>
	<li><code>left<sub>i</sub> != right<sub>i</sub></code></li>
</ul>

**Companies**:
[Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Course Schedule (Medium)](https://leetcode.com/problems/course-schedule/)
* [Course Schedule II (Medium)](https://leetcode.com/problems/course-schedule-ii/)
* [Find Eventual Safe States (Medium)](https://leetcode.com/problems/find-eventual-safe-states/)
* [Loud and Rich (Medium)](https://leetcode.com/problems/loud-and-rich/)

## Solution 1. Topological Sort (BFS)

```cpp
// OJ: https://leetcode.com/problems/build-a-matrix-with-conditions
// Author: github.com/lzl124631x
// Time: O(R + C + K)
// Space: O(K^2)
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& R, vector<vector<int>>& C) {
        auto getOrder = [&](vector<vector<int>> &A) -> vector<int> {
            vector<unordered_set<int>> G(k + 1);
            vector<int> deg(k + 1), ans(k + 1);
            for (auto &e : A) {
                int u = e[0], v = e[1];
                if (G[u].count(v)) continue;
                G[u].insert(v);
                deg[v]++;
            }
            queue<int> q;
            for (int i = 1; i <= k; ++i) {
                if (deg[i] == 0) q.push(i);
            }
            int id = 0;
            while (q.size()) {
                int u = q.front();
                q.pop();
                ans[u] = id++;
                for (int v : G[u]) {
                    if (--deg[v] == 0) q.push(v);
                }
            }
            return id == k ? ans : vector<int>{};
        };
        auto r = getOrder(R);
        if (r.empty()) return {};
        auto c = getOrder(C);
        if (c.empty()) return {};
        vector<vector<int>> ans(k, vector<int>(k));
        for (int i = 1; i <= k; ++i) ans[r[i]][c[i]] = i;
        return ans;
    }
```