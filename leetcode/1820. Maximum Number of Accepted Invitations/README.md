# [1820. Maximum Number of Accepted Invitations (Medium)](https://leetcode.com/problems/maximum-number-of-accepted-invitations/)

<p>There are <code>m</code> boys and <code>n</code> girls in a class attending an upcoming party.</p>

<p>You are given an <code>m x n</code> integer matrix <code>grid</code>, where <code>grid[i][j]</code> equals <code>0</code> or <code>1</code>. If <code>grid[i][j] == 1</code>, then that means the <code>i<sup>th</sup></code> boy can invite the <code>j<sup>th</sup></code> girl to the party. A boy can invite at most<strong> one girl</strong>, and a girl can accept at most <strong>one invitation</strong> from a boy.</p>

<p>Return <em>the <strong>maximum</strong> possible number of accepted invitations.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,1],
               [1,0,1],
               [0,0,1]]
<strong>Output:</strong> 3<strong>
Explanation:</strong> The invitations are sent as follows:
- The 1<sup>st</sup> boy invites the 2<sup>nd</sup> girl.
- The 2<sup>nd</sup> boy invites the 1<sup>st</sup> girl.
- The 3<sup>rd</sup> boy invites the 3<sup>rd</sup> girl.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1,0,1,0],
               [1,0,0,0],
               [0,0,1,0],
               [1,1,1,0]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The invitations are sent as follows:
-The 1<sup>st</sup> boy invites the 3<sup>rd</sup> girl.
-The 2<sup>nd</sup> boy invites the 1<sup>st</sup> girl.
-The 3<sup>rd</sup> boy invites no one.
-The 4<sup>th</sup> boy invites the 2<sup>nd</sup> girl.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>grid.length == m</code></li>
	<li><code>grid[i].length == n</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/), [Matrix](https://leetcode.com/tag/matrix/)

## Solution 1. Maximum Bipartite Matching

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-accepted-invitations/
// Author: github.com/lzl124631x
// Time: O(?)
// Space: O(N)
class Solution {
public:
    int maximumInvitations(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<int> match(N, -1);
        vector<bool> seen;
        function<bool(int)> dfs = [&](int u) {
            for (int v = 0; v < N; ++v) {
                if (!A[u][v] || seen[v]) continue; // If there is no edge between (u, v), or this girl is visited already, skip
                seen[v] = true;
                if (match[v] == -1 || dfs(match[v])) {
                    match[v] = u;
                    return true;
                }
            }
            return false;
        };
        for (int i = 0; i < M; ++i) { // Try each node as the starting point of DFS
            seen.assign(N, false);
            if (dfs(i)) ++ans;
        }
        return ans;
    }
};
```