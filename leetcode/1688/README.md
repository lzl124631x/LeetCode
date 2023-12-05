# [1688. Count of Matches in Tournament (Easy)](https://leetcode.com/problems/count-of-matches-in-tournament)

<p>You are given an integer <code>n</code>, the number of teams in a tournament that has strange rules:</p>

<ul>
	<li>If the current number of teams is <strong>even</strong>, each team gets paired with another team. A total of <code>n / 2</code> matches are played, and <code>n / 2</code> teams advance to the next round.</li>
	<li>If the current number of teams is <strong>odd</strong>, one team randomly advances in the tournament, and the rest gets paired. A total of <code>(n - 1) / 2</code> matches are played, and <code>(n - 1) / 2 + 1</code> teams advance to the next round.</li>
</ul>

<p>Return <em>the number of matches played in the tournament until a winner is decided.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 7
<strong>Output:</strong> 6
<strong>Explanation:</strong> Details of the tournament: 
- 1st Round: Teams = 7, Matches = 3, and 4 teams advance.
- 2nd Round: Teams = 4, Matches = 2, and 2 teams advance.
- 3rd Round: Teams = 2, Matches = 1, and 1 team is declared the winner.
Total number of matches = 3 + 2 + 1 = 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 14
<strong>Output:</strong> 13
<strong>Explanation:</strong> Details of the tournament:
- 1st Round: Teams = 14, Matches = 7, and 7 teams advance.
- 2nd Round: Teams = 7, Matches = 3, and 4 teams advance.
- 3rd Round: Teams = 4, Matches = 2, and 2 teams advance.
- 4th Round: Teams = 2, Matches = 1, and 1 team is declared the winner.
Total number of matches = 7 + 3 + 2 + 1 = 13.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 200</code></li>
</ul>


**Companies**:
[Adobe](https://leetcode.com/company/adobe), [Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[Math](https://leetcode.com/tag/math), [Simulation](https://leetcode.com/tag/simulation)

**Similar Questions**:
* [Count Distinct Numbers on Board (Easy)](https://leetcode.com/problems/count-distinct-numbers-on-board)

**Hints**:
* Simulate the tournament as given in the statement.
* Be careful when handling odd integers.

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/count-of-matches-in-tournament/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        for (; n > 1; n = n / 2 + n % 2) ans += n / 2;
        return ans;
    }
};
```

## Solution 2.

Each match removes a loser. To get one winner from the `n` teams, we need `n - 1` matches.

```cpp
// OJ: https://leetcode.com/problems/count-of-matches-in-tournament/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};
```