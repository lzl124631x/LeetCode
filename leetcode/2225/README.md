# [2225. Find Players With Zero or One Losses (Medium)](https://leetcode.com/problems/find-players-with-zero-or-one-losses/)

<p>You are given an integer array <code>matches</code> where <code>matches[i] = [winner<sub>i</sub>, loser<sub>i</sub>]</code> indicates that the player <code>winner<sub>i</sub></code> defeated player <code>loser<sub>i</sub></code> in a match.</p>

<p>Return <em>a list </em><code>answer</code><em> of size </em><code>2</code><em> where:</em></p>

<ul>
	<li><code>answer[0]</code> is a list of all players that have <strong>not</strong> lost any matches.</li>
	<li><code>answer[1]</code> is a list of all players that have lost exactly <strong>one</strong> match.</li>
</ul>

<p>The values in the two lists should be returned in <strong>increasing</strong> order.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>You should only consider the players that have played <strong>at least one</strong> match.</li>
	<li>The testcases will be generated such that <strong>no</strong> two matches will have the <strong>same</strong> outcome.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
<strong>Output:</strong> [[1,2,10],[4,5,7,8]]
<strong>Explanation:</strong>
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> matches = [[2,3],[1,3],[5,4],[6,4]]
<strong>Output:</strong> [[1,2,5,6],[]]
<strong>Explanation:</strong>
Players 1, 2, 5, and 6 have not lost any matches.
Players 3 and 4 each have lost two matches.
Thus, answer[0] = [1,2,5,6] and answer[1] = [].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= matches.length &lt;= 10<sup>5</sup></code></li>
	<li><code>matches[i].length == 2</code></li>
	<li><code>1 &lt;= winner<sub>i</sub>, loser<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>winner<sub>i</sub> != loser<sub>i</sub></code></li>
	<li>All <code>matches[i]</code> are <strong>unique</strong>.</li>
</ul>


**Companies**:  
[Indeed](https://leetcode.com/company/indeed)

**Related Topics**:  
[Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Lowest Common Ancestor of a Binary Tree (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

## Solution 1. Hash Set and Map

Traverse the array, store the unique winners in a set `win` and store a mapping from person to lose count in map `lose`.

Traverse `lose` map, for each pair `person, cnt`, add `person` to vector `oneLose` if `cnt == 1` (i.e. this person loses exactly once), and erase this `person` from `win`.

Lastly, return the elements in `win` and `oneLose`.

```cpp
// OJ: https://leetcode.com/problems/find-players-with-zero-or-one-losses/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& A) {
        set<int> win;
        map<int, int> lose; // person, count
        for (auto &m : A) {
            win.insert(m[0]);
            lose[m[1]]++;
        }
        vector<int> oneLose;
        for (auto &[p, cnt] : lose) {
            if (cnt == 1) oneLose.push_back(p);
            win.erase(p);
        }
        return {vector<int>(begin(win), end(win)), oneLose};
    }
};
```

## Discuss

https://leetcode.com/problems/find-players-with-zero-or-one-losses/discuss/1908802/