# [296. Best Meeting Point (Hard)](https://leetcode.com/problems/best-meeting-point/)

<p>Given an <code>m x n</code> binary grid <code>grid</code> where each <code>1</code> marks the home of one friend, return <em>the minimal <strong>total travel distance</strong></em>.</p>

<p>The <strong>total travel distance</strong> is the sum of the distances between the houses of the friends and the meeting point.</p>

<p>The distance is calculated using <a href="http://en.wikipedia.org/wiki/Taxicab_geometry" target="_blank">Manhattan Distance</a>, where <code>distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/meetingpoint-grid.jpg" style="width: 413px; height: 253px;">
<pre><strong>Input:</strong> grid = [[1,0,0,0,1],[0,0,0,0,0],[0,0,1,0,0]]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Given three friends living at (0,0), (0,4), and (2,2).
The point (0,2) is an ideal meeting point, as the total travel distance of 2 + 2 + 2 = 6 is minimal.
So return 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
	<li>There will be <strong>at least two</strong> friends in the <code>grid</code>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Sorting](https://leetcode.com/tag/sorting/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Shortest Distance from All Buildings (Hard)](https://leetcode.com/problems/shortest-distance-from-all-buildings/)
* [Minimum Moves to Equal Array Elements II (Medium)](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/best-meeting-point/
// Author: github.com/lzl124631x
// Time: O(MN^2)
// Space: O(MN)
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = INT_MAX, dist[201][201] = {}, up[201][201] = {}, down[201][201] = {}, cnt[201] = {};
        for (int i = 0; i < M; ++i) {
            int sum = 0, left = 0, right = 0;
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0) continue;
                sum += j;
                right++;
            }
            for (int j = 0; j < N; ++j) {
                dist[i][j] = sum;
                if (A[i][j]) ++left, --right;
                sum += left - right;
            }
            cnt[i] = left;
        }
        int c = cnt[0];
        for (int i = 1; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int mn = INT_MAX;
                for (int k = 0; k < N; ++k) {
                    mn = min(mn, dist[i - 1][k] + (abs(j - k) + 1) * c);
                }
                up[i][j] = up[i - 1][j] + mn;
            }
            c += cnt[i];
        }
        c = cnt[M - 1];
        for (int i = M - 2; i >= 0; --i) {
            for (int j = 0; j < N; ++j) {
                int mn = INT_MAX;
                for (int k = 0; k < N; ++k) {
                    mn = min(mn, dist[i + 1][k] + (abs(j - k) + 1) * c);
                }
                down[i][j] = down[i + 1][j] + mn;
            }
            c += cnt[i];
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                ans = min(ans, dist[i][j] + up[i][j] + down[i][j]);
            }
        }
        return ans;
    }
};
```

## TODO

Read the solution https://leetcode.com/problems/best-meeting-point/solution/