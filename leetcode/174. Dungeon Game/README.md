# [174. Dungeon Game (Hard)](https://leetcode.com/problems/dungeon-game/)

<style type="text/css">table.dungeon, .dungeon th, .dungeon td {
  border:3px solid black;
}

 .dungeon th, .dungeon td {
    text-align: center;
    height: 70px;
    width: 70px;
}
</style>
<p>The demons had captured the princess (<strong>P</strong>) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (<strong>K</strong>) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.</p>

<p>The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.</p>

<p>Some of the rooms are guarded by demons, so the knight loses health (<em>negative</em> integers) upon entering these rooms; other rooms are either empty (<em>0's</em>) or contain magic orbs that increase the knight's health (<em>positive</em> integers).</p>

<p>In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.</p>

<p>&nbsp;</p>

<p><strong>Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.</strong></p>

<p>For example, given the dungeon below, the initial health of the knight must be at least <strong>7</strong> if he follows the optimal path <code>RIGHT-&gt; RIGHT -&gt; DOWN -&gt; DOWN</code>.</p>

<table class="dungeon">
	<tbody>
		<tr>
			<td>-2 (K)</td>
			<td>-3</td>
			<td>3</td>
		</tr>
		<tr>
			<td>-5</td>
			<td>-10</td>
			<td>1</td>
		</tr>
		<tr>
			<td>10</td>
			<td>30</td>
			<td>-5 (P)</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ul>
	<li>The knight's health has no upper bound.</li>
	<li>Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Unique Paths (Medium)](https://leetcode.com/problems/unique-paths/)
* [Minimum Path Sum (Medium)](https://leetcode.com/problems/minimum-path-sum/)
* [Cherry Pickup (Hard)](https://leetcode.com/problems/cherry-pickup/)

## Solution 1.

Let `dp[i][j]` be the minimum health required at `dungeon[i][j]`. `dp[i][j]` should be at least `1`.

We can compute it from `dp[M - 1][N - 1]` to `dp[0][0]` and `dp[0][0]` is the answer.

Let `prev` be minimum health required in the previous step. `prev = min(dp[i + 1][j], dp[i][j + 1])`.

If `dungeon[i][j] < 0`, `dp[i][j] = prev - dungeon[i][j] > 1`.

If `dungeon[i][j] >= 0`, `dp[i][j] = max(1, prev - dungeon[i][j])`.

So combining these two cases, `dp[i][j] = max(1, prev - dungeon[i][j])` for `i` in `[0, M-1)` and `j` in `[0, N-1)`.

For the corner case `i = M - 1` or `j = N - 1`, either `dp[i + 1][j]` or `dp[i][j + 1]` is nonexistent and we can treat it as `Infinity`.

If both of them are `Infinity`, i.e. `i = M - 1, j = N - 1`, `dp[i][j] = max(1, 1 - dungeon[i][j])`. So we can regard `prev` as `1`.

So in sum:

```
dp[i][j] = max(1, (prev === Infinity ? 1 : prev) - dungeon[i][j])
           where prev = min(dp[i + 1][j], dp[i][j + 1])
```

```cpp
// OJ: https://leetcode.com/problems/dungeon-game
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int M = dungeon.size(), N = dungeon[0].size();
    for (int i = M - 1; i >= 0; --i) {
      for (int j = N - 1; j >= 0; --j) {
        int val = INT_MAX;
        if (i + 1 < M) val = min(val, dungeon[i + 1][j]);
        if (j + 1 < N) val = min(val, dungeon[i][j + 1]);
        dungeon[i][j] = max(1, (val == INT_MAX ? 1 : val) - dungeon[i][j]);
      }
    }
    return dungeon[0][0];
  }
};
```

## Solution 2.

In case it's not allowed to change the input array.

```cpp
// OJ: https://leetcode.com/problems/dungeon-game
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        vector<int> dp(N + 1, INT_MAX);
        dp[N - 1] = 1;
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                dp[j] = max(min(dp[j + 1], dp[j]) - A[i][j], 1);
            }
        }
        return dp[0];
    }
};
```