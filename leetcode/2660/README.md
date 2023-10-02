# [2660. Determine the Winner of a Bowling Game (Easy)](https://leetcode.com/problems/determine-the-winner-of-a-bowling-game)

<p>You are given two <strong>0-indexed</strong> integer arrays <code><font face="monospace">player1</font></code> and <code>player2</code>, that represent the number of pins that player 1 and player 2 hit in a bowling game, respectively.</p>
<p>The bowling game consists of <code>n</code> turns, and the number of pins in each turn is exactly <code>10</code>.</p>
<p>Assume a player hit <code>x<sub>i</sub></code> pins in the <code>i<sup>th</sup></code> turn. The value of the <code>i<sup>th</sup></code> turn for the player is:</p>
<ul>
	<li><code>2x<sub>i</sub></code> if the player hit <code>10</code> pins in any of the previous two turns.</li>
	<li>Otherwise, It is <code>x<sub>i</sub></code>.</li>
</ul>
<p>The score of the player is the sum of the values of their <code>n</code> turns.</p>
<p>Return</p>
<ul>
	<li><code>1</code> <em>if the score of player 1 is more than the score of player 2,</em></li>
	<li><code>2</code> <em>if the score of player 2 is more than the score of player 1, and</em></li>
	<li><code>0</code> <em>in case of a draw.</em></li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> player1 = [4,10,7,9], player2 = [6,5,2,3]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The score of player1 is 4 + 10 + 2*7 + 2*9 = 46.
The score of player2 is 6 + 5 + 2 + 3 = 16.
Score of player1 is more than the score of player2, so, player1 is the winner, and the answer is 1.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> player1 = [3,5,7,6], player2 = [8,10,10,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The score of player1 is 3 + 5 + 7 + 6 = 21.
The score of player2 is 8 + 10 + 2*10 + 2*2 = 42.
Score of player2 is more than the score of player1, so, player2 is the winner, and the answer is 2.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> player1 = [2,3], player2 = [4,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The score of player1 is 2 + 3 = 5
The score of player2 is 4 + 1 = 5
The score of player1 equals to the score of player2, so, there is a draw, and the answer is 0.

</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == player1.length == player2.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= player1[i], player2[i] &lt;= 10</code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [DE Shaw](https://leetcode.com/company/de-shaw)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [High Five (Easy)](https://leetcode.com/problems/high-five/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/determine-the-winner-of-a-bowling-game
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int score(vector<int> &A) {
        int a = -1, b = 1, ans = 0;
        for (int n : A) {
            if (a == 10 || b == 10) ans += 2 * n;
            else ans += n;
            a = b;
            b = n;
        }
        return ans;
    }
public:
    int isWinner(vector<int>& A, vector<int>& B) {
        int a = score(A), b = score(B);
        return a > b ? 1 : (a < b ? 2 : 0);
    }
};
```