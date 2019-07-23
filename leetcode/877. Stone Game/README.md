# [877. Stone Game (Medium)](https://leetcode.com/problems/stone-game/)

<p>Alex and Lee play a game with piles of stones.&nbsp; There are an even number of&nbsp;piles <strong>arranged in a row</strong>, and each pile has a positive integer number of stones <code>piles[i]</code>.</p>

<p>The objective of the game is to end with the most&nbsp;stones.&nbsp; The total number of stones is odd, so there are no ties.</p>

<p>Alex and Lee take turns, with Alex starting first.&nbsp; Each turn, a player&nbsp;takes the entire pile of stones from either the beginning or the end of the row.&nbsp; This continues until there are no more piles left, at which point the person with the most stones wins.</p>

<p>Assuming Alex and Lee play optimally, return <code>True</code>&nbsp;if and only if Alex wins the game.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[5,3,4,5]</span>
<strong>Output: </strong><span id="example-output-1">true</span>
<strong>Explanation: </strong>
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>2 &lt;= piles.length &lt;= 500</code></li>
	<li><code>piles.length</code> is even.</li>
	<li><code>1 &lt;= piles[i] &lt;= 500</code></li>
	<li><code>sum(piles)</code> is odd.</li>
</ol>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Denote `F(A[0]..A[n-1])` as a pair of number representing the greatest stone difference the player moves first can get.

For example, `F(1,3) = (3, 1)`, `F(1,10,1,3) = (13, 2)`.

To get `F(A[0]..A[n-1])`, we simply use the result of `S = F(A[0]..A[n-2])` and `T = F(A[1]..A[n-1])`.

The result is either `(piles[0] + T[1], T[0])` or `(piles[n-1] + S[1], S[0])` whichever has greater difference.

For example, to compute `F(1, 10, 1, 3)`, we:
* first compute `F(1, 10, 1) = (2, 10)` and `F(10, 1, 3) = (11, 3)`
* compare `(1 + 3, 11) = (4, 11)` and `(3 + 10, 2) = (13, 2)`, pick the one with greater difference, i.e. `(13, 2)`.

So we can iteratively compute `F` from small scale to large scale.

```cpp
// OJ: https://leetcode.com/problems/stone-game/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();
        vector<vector<int>> memo(N);
        for (int i = 0; i < N; ++i) memo[i] = vector<int>{ piles[i], 0 };
        for (int len = 2; len <= N; ++len) {
            for (int i = 0; i <= N - len; ++i) {
                auto a = vector<int>{ memo[i + 1][1] + piles[i], memo[i + 1][0] };
                auto b = vector<int>{ memo[i][1] + piles[i + len - 1], memo[i][0] };
                memo[i] = a[0] - a[1] > b[0] - b[1] ? a : b;
            }
        }
        return memo[0][0] > memo[0][1];
    }
};
```

## Solution 2.

Notice that the length of `piles` is even. So Alex can always pick piles with either even indices (`piles[0], piles[2], ..., piles[n-2]`) or odd indices (`piles[1], piles[3], ..., piles[n-1]`). Since the total number of stones is odd, so Alex can simply pick the group with more stones.

```cpp
// OJ: https://leetcode.com/problems/stone-game/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
```