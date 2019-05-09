# [1025. Divisor Game (Easy)](https://leetcode.com/problems/divisor-game/)

<p>Alice and Bob take turns playing a game, with Alice starting first.</p>

<p>Initially, there is a number <code>N</code>&nbsp;on the chalkboard.&nbsp; On each player's turn, that player makes a <em>move</em>&nbsp;consisting of:</p>

<ul>
	<li>Choosing&nbsp;any <code>x</code> with <code>0 &lt; x &lt; N</code> and <code>N % x == 0</code>.</li>
	<li>Replacing&nbsp;the number&nbsp;<code>N</code>&nbsp;on the chalkboard with <code>N - x</code>.</li>
</ul>

<p>Also, if a player cannot make a move, they lose the game.</p>

<p>Return <code>True</code> if and only if Alice wins the game, assuming both players play optimally.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">2</span>
<strong>Output: </strong><span id="example-output-1">true</span>
<strong>Explanation:</strong> Alice chooses 1, and Bob has no more moves.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">3</span>
<strong>Output: </strong><span id="example-output-2">false</span>
<strong>Explanation:</strong> Alice chooses 1, Bob chooses 1, and Alice has no more moves.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= N &lt;= 1000</code></li>
</ol>
</div>
</div>

**Companies**:  
[Visa](https://leetcode.com/company/visa)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/divisor-game/
// Author: github.com/lzl124631x
// Time: O(N * sqrt(N))
// Space: O(N)
class Solution {
private:
    unordered_map<int, bool> m;
public:
    bool divisorGame(int N) {
        if (N == 1) return false;
        if (m.find(N) != m.end()) return m[N];
        bool ans = false;
        for (int x = sqrt(N); x >= 1 && !ans; --x) {
            if (N % x) continue;
            if (!divisorGame(N - x)) ans = true;
        }
        return m[N] = ans;
    }
};
```

## Solution 2.

Denote `F(N)` as the result.

1. If `F(N) = false`, then `F(N + 1) = true`. Because for case `N + 1`, Alice can simply pick `x = 1` to win.
2. If `N` is odd number, it only have odd factors. So after the first move, it will become even number.

* `F(1) = false`
* `F(2) = true` according to Rule #1.
* `F(3) = false` since `2` is the only possible situation for Bob and `F(2) = true`.
* `F(4) = true` according to Rule #1.
* `F(5) = false` since all even numbers (`2` and `4`) lead to `true` for Bob.
* ...

So we can see, even numbers always win; odd numbers lose.

```cpp
// OJ: https://leetcode.com/problems/divisor-game/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/divisor-game/discuss/274566/just-return-N-2-0-(proof)
class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 == 0;
    }
};
```