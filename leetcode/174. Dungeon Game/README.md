# [174. Dungeon Game (Hard)](https://leetcode.com/problems/dungeon-game/)

<p>The demons had captured the princess and imprisoned her in <strong>the bottom-right corner</strong> of a <code>dungeon</code>. The <code>dungeon</code> consists of <code>m x n</code> rooms laid out in a 2D grid. Our valiant knight was initially positioned in <strong>the top-left room</strong> and must fight his way through <code>dungeon</code> to rescue the princess.</p>

<p>The knight has an initial health point represented by a positive integer. If at any point his health point drops to <code>0</code> or below, he dies immediately.</p>

<p>Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).</p>

<p>To reach the princess as quickly as possible, the knight decides to move only <strong>rightward</strong> or <strong>downward</strong> in each step.</p>

<p>Return <em>the knight's minimum initial health so that he can rescue the princess</em>.</p>

<p><strong>Note</strong> that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/13/dungeon-grid-1.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-&gt; RIGHT -&gt; DOWN -&gt; DOWN.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> dungeon = [[0]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == dungeon.length</code></li>
	<li><code>n == dungeon[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>-1000 &lt;= dungeon[i][j] &lt;= 1000</code></li>
</ul>


**Companies**:  
[Uber](https://leetcode.com/company/uber), [Google](https://leetcode.com/company/google), [Adobe](https://leetcode.com/company/adobe), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Unique Paths (Medium)](https://leetcode.com/problems/unique-paths/)
* [Minimum Path Sum (Medium)](https://leetcode.com/problems/minimum-path-sum/)
* [Cherry Pickup (Hard)](https://leetcode.com/problems/cherry-pickup/)

## Solution 1.

Let `dp[i][j]` be the minimum health required at `dungeon[i][j]`. `dp[i][j]` should be at least `1`.

We can compute it from `dp[M - 1][N - 1]` to `dp[0][0]` and `dp[0][0]` is the answer.

Let `need` be minimum health required in the previous step. `need = min(dp[i + 1][j], dp[i][j + 1])`.

If `dungeon[i][j] < 0`, `dp[i][j] = need - dungeon[i][j] > 1`.

If `dungeon[i][j] >= 0`, `dp[i][j] = max(1, need - dungeon[i][j])`.

So combining these two cases, `dp[i][j] = max(1, need - dungeon[i][j])` for `i` in `[0, M-1)` and `j` in `[0, N-1)`.

For the corner case `i = M - 1` or `j = N - 1`, either `dp[i + 1][j]` or `dp[i][j + 1]` is nonexistent and we can treat it as `Infinity`.

If both of them are `Infinity`, i.e. `i = M - 1, j = N - 1`, `dp[i][j] = max(1, 1 - dungeon[i][j])`. So we can regard `prev` as `1`.

So in sum:

```
dp[i][j] = max(1, (need === Infinity ? 1 : need) - dungeon[i][j])
           where need = min(dp[i + 1][j], dp[i][j + 1])
```

```cpp
// OJ: https://leetcode.com/problems/dungeon-game
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                int need = min(i + 1 < M ? A[i + 1][j] : INT_MAX, j + 1 < N ? A[i][j + 1] : INT_MAX);
                if (need == INT_MAX) need = 1;
                A[i][j] = max(1, need - A[i][j]);
            }
        }
        return A[0][0];
    }
};
```

Or, in case it's not allowed to change the input array.

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