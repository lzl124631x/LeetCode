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

Since we only care if the sum is divisible by `3`, we can convert each `A[i]` to `A[i] % 3`, and count the frequency of `0, 1, 2`.

Firstly, let's ignore `0` for now.

* If Alice starts with `1`, Alice and Bob have to pick `11212...` in order.
* If Alice starts with `2`, Alice and Bob have to pick `22121...` in order.

For the case where Alice starts with `1`, after matching the `11212...` pattern, if there are still `1`s left, Alice wins; otherwise, Bob wins.

Now, consider the `0`s.
* If `cnt[0]` is even, Bob picks a `3`, Alice can always pick another `0`. The result won't be changed.
* If `cnt[0]` is odd, the final result will be reversed, expect the cases where Bob wins because all numbers are consumed.

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

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/stone-game-ix/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://youtu.be/8MTch2zTOoY
class Solution {
    bool win(array<int, 3> &cnt, int sum, int turn) { // turn: 0 - Alice, 1 - Bob
        if (cnt[0] + cnt[1] + cnt[2] == 0) return turn == 1;
        if (cnt[0]) {
            cnt[0]--; // If there is `0` left, use it first (because `0` will shift the "bomb" to the other player; the players must use the `0`s anyway)
            return !win(cnt, sum, 1 - turn);
        } else if (sum % 3 == 1) { // If the remainder is 1, the player must pick 1
            if (cnt[1]) {
                cnt[1]--;
                return !win(cnt, sum + 1, 1 - turn);
            } return false;
        } else if (cnt[2]) { // If the remainder is 2, the player must pick 2.
            cnt[2]--;
            return !win(cnt, sum + 2, 1 - turn);
        }
        return false;
    }
public:
    bool stoneGameIX(vector<int>& A) {
        array<int, 3> cnt = {};
        for (int n : A) cnt[n % 3]++;
        auto tmp = cnt;
        if (tmp[1]) { // If there is `1` available, Alice can try picking 1.
            tmp[1]--;
            if (!win(tmp, 1, 1)) return true;
        }
        tmp = cnt;
        if (tmp[2]) { // If there is `2` available, Alice can try picking 2.
            tmp[2]--;
            if (!win(tmp, 2, 1)) return true;
        }
        return false;
    }
};
```

## Solution 3.

Count the frequency of mod3 = 0, 1, 2.

Firstly, don't consider `0`.

* If Alice starts with `1`, Alice and Bob have to pick `1,1,2,1,2,...` in order.
* If Alice starts with `2`, Alice and Bob have to pick `2,1,2,1,2,...` in order.

If Alice starts with `1`, then Alice needs `1` and Bob needs `2`. If `1` is much more than `2`, then Bob is going to lose.

So, if `cnt[0] == 0`, the result can be determined by Alice.

Now, consider the `0`s.
* If `cnt[0]` is even, Bob picks a `3`, Alice can always one another `0`. The result won't be changed.
* If `cnt[0]` is odd, the final result will be reversed, expect the case where Bob wins because all numbers are consumed.

**Algorithm**:

If `cnt[1] == 0`, Alice needs to start with `2`.  
If `cnt[2] == 0`, Alice needs to start with `1`.  
Alice can win if `max(cnt[1], cnt[2]) > 2 && cnt[0] % 2 > 0`. Example: `[1,1,1,3]`.

If `cnt[0] % 2 == 0`, Alice can win in at least one of the two options, picking the less one.

If `cnt[0] % 2 == 1`, the result is reversed.

If `abs(cnt[1] - cnt[2]) > 2`:
* Alice will pick `2` if `2` is more
* Alice will pick `1` if `1` is more

If `abs(cnt[1] - cnt[2]) <= 2`, Alice will lose for no number remaining.

```cpp
// OJ: https://leetcode.com/problems/stone-game-ix/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/stone-game-ix/discuss/1500245/JavaC%2B%2BPython-Easy-and-Concise-6-lines-O(n)
class Solution {
public:
    bool stoneGameIX(vector<int>& A) {
        int cnt[3] = {};
        for (int n : A) cnt[n % 3]++;
        if (min(cnt[1], cnt[2]) == 0) return max(cnt[1], cnt[2]) > 2 && cnt[0] % 2; // If either one is `0`, Alice has to choose the non-zero one.
        return abs(cnt[1] - cnt[2]) > 2 || cnt[0] % 2 == 0;
    }
};
```