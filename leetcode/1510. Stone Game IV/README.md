# [1510. Stone Game IV (Hard)](https://leetcode.com/problems/stone-game-iv/)

<p>Alice and Bob take turns playing a game, with Alice starting first.</p>

<p>Initially, there are <code>n</code> stones in a pile.&nbsp; On each player's turn, that player makes a&nbsp;<em>move</em>&nbsp;consisting of removing <strong>any</strong> non-zero <strong>square number</strong> of stones in the pile.</p>

<p>Also, if a player cannot make a move, he/she loses the game.</p>

<p>Given a positive&nbsp;integer <code>n</code>.&nbsp;Return&nbsp;<code>True</code>&nbsp;if and only if Alice wins the game otherwise return <code>False</code>, assuming both players play optimally.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> true
<strong>Explanation: </strong>Alice can remove 1 stone winning the game because Bob doesn't have any moves.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> false
<strong>Explanation: </strong>Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -&gt; 1 -&gt; 0).</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> true
<strong>Explanation:</strong> n is already a perfect square, Alice can win with one move, removing 4 stones (4 -&gt; 0).
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 7
<strong>Output:</strong> false
<strong>Explanation: </strong>Alice can't win the game if Bob plays optimally.
If Alice starts removing 4 stones, Bob will remove 1 stone then Alice should remove only 1 stone and finally Bob removes the last one (7 -&gt; 3 -&gt; 2 -&gt; 1 -&gt; 0). 
If Alice starts removing 1 stone, Bob will remove 4 stones then Alice only can remove 1 stone and finally Bob removes the last one (7 -&gt; 6 -&gt; 2 -&gt; 1 -&gt; 0).</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> n = 17
<strong>Output:</strong> false
<strong>Explanation: </strong>Alice can't win the game if Bob plays optimally.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Bottom-up DP

Let `dp[i]` be whether Alice and win starting with `i` stones.

```
dp[i] = true    // If any dp[i - j * j] is false
      = false   // otherwise
      where 1 <= j * j <= i  -- the stone taken by Bob.
```

```cpp
// OJ: https://leetcode.com/contest/biweekly-contest-30/problems/stone-game-iv/
// Author: github.com/lzl124631x
// Time: O(N * sqrt(N))
// Space: O(N)
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i && !dp[i]; ++j) dp[i] = !dp[i - j * j];
        }
        return dp[n];
    }
};
```

Or use `static` variable to save computation

```cpp
// OJ: https://leetcode.com/contest/biweekly-contest-30/problems/stone-game-iv/
// Author: github.com/lzl124631x
// Time: O(N * sqrt(N))
// Space: O(N)
class Solution {
public:
    bool winnerSquareGame(int n) {
        static vector<bool> dp(1);
        for (int i = dp.size(); i <= n; ++i) {
            dp.push_back(false);
            for (int j = 1; j * j <= i && !dp[i]; ++j) dp[i] = !dp[i - j * j];
        }
        return dp[n];
    }
};
```

## Solution 2. Top-down DP

```cpp
// OJ: https://leetcode.com/contest/biweekly-contest-30/problems/stone-game-iv/
// Author: github.com/lzl124631x
// Time: O(N * sqrt(N))
// Space: O(N)
class Solution {
    vector<int> dp; // -1 unvisited, 0 lose, 1 win
    bool dfs(int n) {
        if (n == 0) return false;
        if (dp[n] != -1) return dp[n];
        for (int i = 1; i * i <= n && dp[n] != 1; ++i) dp[n] = !dfs(n - i * i);
        return dp[n];
    }
public:
    bool winnerSquareGame(int n) {
        dp.assign(n + 1, -1);
        return dfs(n);
    }
};
```