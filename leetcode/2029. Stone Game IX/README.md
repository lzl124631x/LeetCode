# [2029. Stone Game IX (Medium)](https://leetcode.com/problems/stone-game-ix/)

<p>Alice and Bob continue their games with stones. There is a row of n stones, and each stone has an associated value. You are given an integer array <code>stones</code>, where <code>stones[i]</code> is the <strong>value</strong> of the <code>i<sup>th</sup></code> stone.</p>

<p>Alice and Bob take turns, with <strong>Alice</strong> starting first. On each turn, the player may remove any stone from <code>stones</code>. The player who removes a stone <strong>loses</strong> if the <strong>sum</strong> of the values of <strong>all removed stones</strong> is divisible by <code>3</code>. Bob will win automatically if there are no remaining stones (even if it is Alice's turn).</p>

<p>Assuming both players play <strong>optimally</strong>, return <code>true</code> <em>if Alice wins and</em> <code>false</code> <em>if Bob wins</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> stones = [2,1]
<strong>Output:</strong> true
<strong>Explanation:</strong>&nbsp;The game will be played as follows:
- Turn 1: Alice can remove either stone.
- Turn 2: Bob removes the remaining stone. 
The sum of the removed stones is 1 + 2 = 3 and is divisible by 3. Therefore, Bob loses and Alice wins the game.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> stones = [2]
<strong>Output:</strong> false
<strong>Explanation:</strong>&nbsp;Alice will remove the only stone, and the sum of the values on the removed stones is 2. 
Since all the stones are removed and the sum of values is not divisible by 3, Bob wins the game.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> stones = [5,1,2,4,3]
<strong>Output:</strong> false
<strong>Explanation:</strong> Bob will always win. One possible way for Bob to win is shown below:
- Turn 1: Alice can remove the second stone with value 1. Sum of removed stones = 1.
- Turn 2: Bob removes the fifth stone with value 3. Sum of removed stones = 1 + 3 = 4.
- Turn 3: Alices removes the fourth stone with value 4. Sum of removed stones = 1 + 3 + 4 = 8.
- Turn 4: Bob removes the third stone with value 2. Sum of removed stones = 1 + 3 + 4 + 2 = 10.
- Turn 5: Alice removes the first stone with value 5. Sum of removed stones = 1 + 3 + 4 + 2 + 5 = 15.
Alice loses the game because the sum of the removed stones (15) is divisible by 3. Bob wins the game.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= stones.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= stones[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Similar Questions**:
* [Stone Game (Medium)](https://leetcode.com/problems/stone-game/)
* [Stone Game II (Medium)](https://leetcode.com/problems/stone-game-ii/)
* [Stone Game III (Hard)](https://leetcode.com/problems/stone-game-iii/)
* [Stone Game IV (Hard)](https://leetcode.com/problems/stone-game-iv/)
* [Stone Game V (Hard)](https://leetcode.com/problems/stone-game-v/)
* [Stone Game VI (Medium)](https://leetcode.com/problems/stone-game-vi/)
* [Stone Game VII (Medium)](https://leetcode.com/problems/stone-game-vii/)
* [Stone Game VIII (Hard)](https://leetcode.com/problems/stone-game-viii/)
* [Stone Game IX (Medium)](https://leetcode.com/problems/stone-game-ix/)

## Solution 1. Brain Teaser

Since we only care if the sum is divisible by `3`, we can convert each `A[i]` to `A[i] % 3`.

For the first round, Alice can't remove `0`, so we only consider case `1` and `2`.

If Alice removes `1` in the first round, Bob can only remove `0` or `1`.

Ignore all the `0`s for now. If Bob removes `1`, the sum becomes `2`. And then Alice must remove `2`, then Bob `1`... So the pattern is `1121212..`

Now consider `0`, since the sum modulo 3 won't change after removing `3`, it's the same as Alice and Bob swapping order. So, except the first removal, `0`s can be inserted into the `1` and `2` removal sequence freely. 

If Alice removes `2` in the first round, then the sequence is `2212121..`

Our goal is to get the length of the longest `112121...` sequence plus the number of `0`s.

If the length is odd, and there are remaining stones, then Bob has to remove a stone causing the sum to be divisible by `3`, i.e. Alice wins; otherwise, Bob wins.

```cpp
// OJ: https://leetcode.com/problems/stone-game-ix/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode-cn.com/problems/stone-game-ix/solution/guan-jian-zai-yu-qiu-chu-hui-he-shu-by-e-mcgv/
class Solution {
    bool check(int zero, int one, int two) {
        if (one == 0) return false; // Can't remove the leading one, must lose
        one--;
        int mn = min(one, two), len = 1 + mn * 2 + zero;
        one -= mn, two -= mn;
        if (one) {
            ++len;
            --one;
        }
        return len % 2 && one + two;
    }
public:
    bool stoneGameIX(vector<int>& A) {
        int c[3] = {};
        for (int n : A) c[n % 3]++;
        return check(c[0], c[1], c[2]) // Alice removes `1` first
            || check(c[0], c[2], c[1]); // Alice removes `2` first
    }
};
```