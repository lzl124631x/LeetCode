# [1244. Design A Leaderboard (Medium)](https://leetcode.com/problems/design-a-leaderboard/)

<p>Design a Leaderboard class, which has 3 functions:</p>

<ol>
	<li><code>addScore(playerId, score)</code>: Update the leaderboard by adding <code>score</code> to the given player's score. If there is no player with such id in the leaderboard, add him to the leaderboard with the given <code>score</code>.</li>
	<li><code>top(K)</code>: Return the score sum of the top <code>K</code> players.</li>
	<li><code>reset(playerId)</code>: Reset the score of the player with the given id&nbsp;to 0 (in other words erase it from the leaderboard). It is guaranteed that the player was added to the leaderboard before calling this function.</li>
</ol>

<p>Initially, the leaderboard is empty.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><b>Input: </b>
["Leaderboard","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"]
[[],[1,73],[2,56],[3,39],[4,51],[5,4],[1],[1],[2],[2,51],[3]]
<b>Output: </b>
[null,null,null,null,null,null,73,null,null,null,141]

<b>Explanation: </b>
Leaderboard leaderboard = new Leaderboard ();
leaderboard.addScore(1,73);   // leaderboard = [[1,73]];
leaderboard.addScore(2,56);   // leaderboard = [[1,73],[2,56]];
leaderboard.addScore(3,39);   // leaderboard = [[1,73],[2,56],[3,39]];
leaderboard.addScore(4,51);   // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
leaderboard.addScore(5,4);    // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
leaderboard.top(1);           // returns 73;
leaderboard.reset(1);         // leaderboard = [[2,56],[3,39],[4,51],[5,4]];
leaderboard.reset(2);         // leaderboard = [[3,39],[4,51],[5,4]];
leaderboard.addScore(2,51);   // leaderboard = [[2,51],[3,39],[4,51],[5,4]];
leaderboard.top(3);           // returns 141 = 51 + 51 + 39;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= playerId, K &lt;= 10000</code></li>
	<li>It's guaranteed that <code>K</code> is less than or equal to the current number of players.</li>
	<li><code>1 &lt;= score&nbsp;&lt;= 100</code></li>
	<li>There will be at most <code>1000</code>&nbsp;function calls.</li>
</ul>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Twitter](https://leetcode.com/company/twitter)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Design](https://leetcode.com/tag/design/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-a-leaderboard/
// Author: github.com/lzl124631x
// Time:
//      Leaderboard: O(1)
//      addScore: O(1)
//      top: O(NlogK)
//      reset: O(1)
// Space: O(N + K)
class Leaderboard {
    unordered_map<int, int> m;
public:
    Leaderboard() {}
    void addScore(int playerId, int score) {
        m[playerId] += score;
    }
    int top(int K) {
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto &[id, score] : m) {
            pq.push(score);
            if (pq.size() > K) pq.pop();
        }
        int ans = 0;
        while (pq.size()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
    void reset(int playerId) {
        m[playerId] = 0;
    }
};
```