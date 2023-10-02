# [1690. Stone Game VII (Medium)](https://leetcode.com/problems/stone-game-vii/)

<p>Alice and Bob take turns playing a game, with <strong>Alice starting first</strong>.</p>

<p>There are <code>n</code> stones arranged in a row. On each player's turn, they can <strong>remove</strong> either the leftmost stone or the rightmost stone from the row and receive points equal to the <strong>sum</strong> of the remaining stones' values in the row. The winner is the one with the higher score when there are no stones left to remove.</p>

<p>Bob found that he will always lose this game (poor Bob, he always loses), so he decided to <strong>minimize the score's difference</strong>. Alice's goal is to <strong>maximize the difference</strong> in the score.</p>

<p>Given an array of integers <code>stones</code> where <code>stones[i]</code> represents the value of the <code>i<sup>th</sup></code> stone <strong>from the left</strong>, return <em>the <strong>difference</strong> in Alice and Bob's score if they both play <strong>optimally</strong>.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> stones = [5,3,1,4,2]
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
- Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
- Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
- Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
- Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
- Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
The score difference is 18 - 12 = 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> stones = [7,90,5,1,100,10,10,2]
<strong>Output:</strong> 122</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == stones.length</code></li>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= stones[i] &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Stone Game (Medium)](https://leetcode.com/problems/stone-game/)
* [Stone Game II (Medium)](https://leetcode.com/problems/stone-game-ii/)
* [Stone Game III (Hard)](https://leetcode.com/problems/stone-game-iii/)
* [Stone Game IV (Hard)](https://leetcode.com/problems/stone-game-iv/)
* [Stone Game V (Hard)](https://leetcode.com/problems/stone-game-v/)
* [Stone Game VI (Medium)](https://leetcode.com/problems/stone-game-vi/)

## Solution 1. Bottom-up DP

Let `dp[i][j]` be the maximum difference the first player can get if the players play on `A[i..j]`.

```
dp[i][j] = max(
                sum(i + 1, j) - dp[i + 1][j],   // if the first player chooses `A[i]`
                sum(i, j - 1) - dp[i][j - 1]    // if the first player chooses `A[j]`
              )
```
where `sum(i, j)` is `A[i] + ... + A[j]`. We can get `sum(i, j)` using prefix sum array.

**Explanation of the DP formula**

Each player needs to play optimally to get as many points as possible and make the other player get as less as possible. So the game is actually the same for both of them.

After Alice finshes the her first round, ignoring the points Alice made there, the game to Bob is exactly the same as if he is the first player.

So each round on `A[i..j]`, no matter who plays first, the first player always has two options:
1. pick `A[i]`, the first player get `sum(i + 1, j)` points, and we need to deduct the maximum point difference the next player can get in the remaining game, i.e. `dp[i + 1][j]`
2. pick `A[j]`, the first player get `sum(i, j - 1)` points, and we need to deduct the maximum point difference the next player can get in the remaining game, i.e. `dp[i][j - 1]`

And the first player simply pick the option more advantageous to him/her.

```cpp
// OJ: https://leetcode.com/problems/stone-game-vii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int stoneGameVII(vector<int>& A) {
        int N = A.size();
        vector<int> sum(N + 1);
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + A[i];
        vector<vector<int>> dp(N, vector<int>(N));
        for (int len = 2; len <= N; ++len) {
            for (int i = 0; i <= N - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = max(sum[j + 1] - sum[i + 1] - dp[i + 1][j], sum[j] - sum[i] - dp[i][j - 1]);
            }
        }
        return dp[0][N - 1];
    }
};
```