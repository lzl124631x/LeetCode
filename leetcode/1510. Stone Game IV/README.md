# [1510. Stone Game IV (Hard)](https://leetcode.com/problems/stone-game-iv/)

<p>Alice and Bob take turns playing a game, with Alice starting first.</p>

<p>Initially, there are <code>n</code> stones in a pile. On each player's turn, that player makes a <em>move</em> consisting of removing <strong>any</strong> non-zero <strong>square number</strong> of stones in the pile.</p>

<p>Also, if a player cannot make a move, he/she loses the game.</p>

<p>Given a positive integer <code>n</code>, return <code>true</code> if and only if Alice wins the game otherwise return <code>false</code>, assuming both players play optimally.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> true
<strong>Explanation: </strong>Alice can remove 1 stone winning the game because Bob doesn't have any moves.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> false
<strong>Explanation: </strong>Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -&gt; 1 -&gt; 0).
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> true
<strong>Explanation:</strong> n is already a perfect square, Alice can win with one move, removing 4 stones (4 -&gt; 0).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Game Theory](https://leetcode.com/tag/game-theory/)

**Similar Questions**:
* [Stone Game V (Hard)](https://leetcode.com/problems/stone-game-v/)
* [Stone Game VI (Medium)](https://leetcode.com/problems/stone-game-vi/)
* [Stone Game VII (Medium)](https://leetcode.com/problems/stone-game-vii/)
* [Stone Game VIII (Hard)](https://leetcode.com/problems/stone-game-viii/)
* [Stone Game IX (Medium)](https://leetcode.com/problems/stone-game-ix/)

## Solution 1. Bottom-up DP

Let `dp[i]` be whether Alice and win starting with `i` stones.

```
dp[i] = true    // If any dp[i - j * j] is false
      = false   // otherwise
      where 1 <= j * j <= i  -- the stone taken by Bob.
```

```cpp
// OJ: https://leetcode.com/problems/stone-game-iv/
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

Some tricks for saving computation

```cpp
// OJ: https://leetcode.com/problems/stone-game-iv/
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

Or

```cpp
// OJ: https://leetcode.com/problems/stone-game-iv/
// Author: github.com/lzl124631x
// Time: O(N * sqrt(N))
// Space: O(N)
int dp[100001] = {[0] = 0, [1 ... 100000] = -1}, last = 0;
class Solution {
public:
    bool winnerSquareGame(int n) {
        for (int i = last + 1; i <= n; ++i) {
            for (int j = 1; j * j <= i && dp[i] != 1; ++j) dp[i] = !dp[i - j * j];
        }
        last = max(last, n);
        return dp[n];
    }
};
```

## Solution 2. Top-down DP

```cpp
// OJ: https://leetcode.com/problems/stone-game-iv/
// Author: github.com/lzl124631x
// Time: O(N * sqrt(N))
// Space: O(N)
int dp[100001] = {[0] = 0, [1 ... 100000] = -1}; // -1 unvisited, 0 loss, 1 win
class Solution {
public:
    bool winnerSquareGame(int n) {
        if (dp[n] != -1) return dp[n];
        for (int i = 1; i * i <= n; ++i) {
            if (!winnerSquareGame(n - i * i)) return dp[n] = 1;
        }
        return dp[n] = 0;
    }
};
```